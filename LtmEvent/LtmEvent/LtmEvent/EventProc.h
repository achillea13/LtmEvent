

/*******************************************************************

				�¼�ִ�з���ʵ����
			��Ӧÿ���¼���ִ�з�����ʵ��

			1���̳��麯��InitOnEventFuncArray���ڴ˺����е���REG_ON_EVENT_FUNCע���¼�����
			2��DECL_ON_EVENT_FUNC�����¼�����
			3��IMPL_ON_EVENT_FUNC�����¼�����

*******************************************************************/

#ifndef __EVENTPROC__
#define __EVENTPROC__


#include "impl\Event.h"
#include "EventDef.h"
#include "ProcInterface.h"

using namespace ltm_event;

#define DECL_ON_EVENT_FUNC(EventID) void ON_##EventID( BaseEvent& Msg);
#define REG_EVENT_FUNC(_Class_Name,EventID) m_fpHwgOnEvent[EventID] = &_Class_Name::ON_##EventID;
#define IMPL_EVENT_FUNC(_Class_Name,EventID) void _Class_Name::ON_##EventID( BaseEvent& Msg )

// ��BaseEventת��Ϊ�¼�ID��Ӧ�����ݽṹ
#define HWG_EVENT(EVENT_ID) E##EVENT_ID KEvent;							\
			KEvent = *(static_cast<E##EVENT_ID *>(&Msg));						\

class EventProc : public ProcInterface<EventProc,EVENT_SENTINEL>
{



public:
	EventProc(){};
	virtual ~EventProc(){};

	virtual void InitOnEventFuncArray();



	/**********************		����¼�������	****************************/
	DECL_ON_EVENT_FUNC(EGS_TEST_1);
	DECL_ON_EVENT_FUNC(EGS_TEST_2);
	DECL_ON_EVENT_FUNC(EGS_TEST_3);
	DECL_ON_EVENT_FUNC(EGS_TEST_4);
	DECL_ON_EVENT_FUNC(EGS_TEST_5);
	/**********************		����¼�������	****************************/




};



#endif