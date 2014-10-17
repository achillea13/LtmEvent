/**************************************************************
					�¼�·��
			1�������¼������¼�����				
			2�����¼�����˳�����ν����¼�����
			3������ռ��һ���߳�
***************************************************************/


#ifndef __LTM_EVENT_ROUTE__
#define __LTM_EVENT_ROUTE__

#include "common\Define.h"
#include "common\ThreadBase.h"
#include "impl\Performer.h"

#include "ProcInterface.h"

namespace ltm_event{


template< class T, int Size >			// Ҫ����Ķ�������
class Route : public Performer, public ThreadBase
{

public:
	Route(){ _procImpl = NULL; };
	virtual ~Route(){};

	// ����ִ����Ϣ����Ķ���
	// ������ʹ��֮ǰִ�д˺���
	virtual bool SetProcImpl( ProcInterface<T,Size>* pImpl )
	{ 
		if ( pImpl == NULL )
			return false;

		_procImpl = pImpl; 
		_procImpl->InitOnEventFuncArray();
	
		// ��ʼ�¼������߳�
		return InitThread( this );
	}


	// ������Ϣ
	void QueueEvent(int exe_id, char* pBuf, int len)
	{
		if ( pBuf == NULL || exe_id <= 0 || len <= 0 )
		{
			// ʧ�ܣ�������־
			return;
		}

		boost::shared_ptr< EventBuf > pEvent(new EventBuf(exe_id, pBuf, len));
		if ( pEvent == NULL )
		{
			// ʧ�ܣ�������־
			return;
		}
		QueueingEvent(pEvent);
	}

	void QueueEvent( int exe_id, BaseEvent* pBEvent, int len )
	{
		if ( pBEvent == NULL || exe_id <= 0 || len <= 0 )
		{
			// ʧ�ܣ�������־
			return;
		}

		boost::shared_ptr< EventBuf > pEvent(new EventBuf(exe_id, (char*)pBEvent, len));
		if ( pEvent == NULL )
		{
			// ʧ�ܣ�������־
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
				// ʧ�ܣ�������־
				return;
			}

			BaseEvent* pBaseEvent = reinterpret_cast<BaseEvent*>(Event->_buff);
			if ( pBaseEvent == NULL )
			{
				// ʧ�ܣ�������־
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