#ifndef __LTM_EVENT_PROCINTERFACE__
#define __LTM_EVENT_PROCINTERFACE__


namespace ltm_event{


template< typename T, int EventIDSize >
class ProcInterface
{

	typedef void (T::*FPHWGONEVENT) ( BaseEvent& );
protected:

	FPHWGONEVENT m_fpHwgOnEvent[EventIDSize+1];			// �¼�����ָ�뼯��

public:

	ProcInterface(){};
	virtual ~ProcInterface(){};

	// ��ʼ����������Ҫ����
	virtual void InitOnEventFuncArray(){};

	// �����¼���Ӧ��������
	bool OnDispatch( BaseEvent& msg )
	{
		(((T*)this)->*m_fpHwgOnEvent[msg.EventID])(msg);

		return true;
	}




};


}


#endif