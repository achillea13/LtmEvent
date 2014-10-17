/**************************************************************
					事件路由
			1、接受事件放入事件队列				
			2、按事件队列顺序依次进行事件处理
			3、单独占用一个线程
***************************************************************/


#ifndef __LTM_EVENT_ROUTE__
#define __LTM_EVENT_ROUTE__

#include "common\Define.h"
#include "common\ThreadBase.h"
#include "impl\Performer.h"

#include "ProcInterface.h"

namespace ltm_event{


template< class T, int Size >			// 要传入的对象类型
class Route : public Performer, public ThreadBase
{

public:
	Route(){ _procImpl = NULL; };
	virtual ~Route(){};

	// 设置执行消息处理的对象
	// 必须在使用之前执行此函数
	virtual bool SetProcImpl( ProcInterface<T,Size>* pImpl )
	{ 
		if ( pImpl == NULL )
			return false;

		_procImpl = pImpl; 
		_procImpl->InitOnEventFuncArray();
	
		// 开始事件处理线程
		return InitThread( this );
	}


	// 放入消息
	void QueueEvent(int exe_id, char* pBuf, int len)
	{
		if ( pBuf == NULL || exe_id <= 0 || len <= 0 )
		{
			// 失败，加入日志
			return;
		}

		boost::shared_ptr< EventBuf > pEvent(new EventBuf(exe_id, pBuf, len));
		if ( pEvent == NULL )
		{
			// 失败，加入日志
			return;
		}
		QueueingEvent(pEvent);
	}

	void QueueEvent( int exe_id, BaseEvent* pBEvent, int len )
	{
		if ( pBEvent == NULL || exe_id <= 0 || len <= 0 )
		{
			// 失败，加入日志
			return;
		}

		boost::shared_ptr< EventBuf > pEvent(new EventBuf(exe_id, (char*)pBEvent, len));
		if ( pEvent == NULL )
		{
			// 失败，加入日志
			return;
		}
		QueueingEvent(pEvent);
	}


protected:
	virtual void ProcessEvent( EventBufPtr Event )
	{
		{
			if ( _procImpl == NULL )
			{
				// 失败，加入日志
				return;
			}

			BaseEvent* pBaseEvent = reinterpret_cast<BaseEvent*>(Event->_buff);
			if ( pBaseEvent == NULL )
			{
				// 失败，加入日志
				return;
			}

			_procImpl->OnDispatch(*pBaseEvent);
		}
	}

	virtual unsigned long ThreadProcReal()
	{
		Performer::Tick();
		return 0;
	}



protected:
	
	ProcInterface<T,Size>*		_procImpl;

};

}

#endif