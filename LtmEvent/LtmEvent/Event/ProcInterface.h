#ifndef __LTM_EVENT_PROCINTERFACE__
#define __LTM_EVENT_PROCINTERFACE__


namespace ltm_event{


template< typename T, int EventIDSize >
class ProcInterface
{

	typedef void (T::*FPHWGONEVENT) ( BaseEvent& );
protected:

	FPHWGONEVENT m_fpHwgOnEvent[EventIDSize+1];			// 事件函数指针集合

public:

	ProcInterface(){};
	virtual ~ProcInterface(){};

	// 初始化操作，需要重载
	virtual void InitOnEventFuncArray(){};

	// 调用事件对应函数处理
	bool OnDispatch( BaseEvent& msg )
	{
		(((T*)this)->*m_fpHwgOnEvent[msg.EventID])(msg);

		return true;
	}




};


}


#endif