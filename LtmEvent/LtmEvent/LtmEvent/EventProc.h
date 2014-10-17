

/*******************************************************************

				事件执行方法实现类
			对应每个事件的执行方法的实现

			1、继承虚函数InitOnEventFuncArray，在此函数中调用REG_ON_EVENT_FUNC注册事件方法
			2、DECL_ON_EVENT_FUNC声明事件方法
			3、IMPL_ON_EVENT_FUNC定义事件方法

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

// 将BaseEvent转化为事件ID对应的数据结构
#define HWG_EVENT(EVENT_ID) E##EVENT_ID KEvent;							\
			KEvent = *(static_cast<E##EVENT_ID *>(&Msg));						\

class EventProc : public ProcInterface<EventProc,EVENT_SENTINEL>
{



public:
	EventProc(){};
	virtual ~EventProc(){};

	virtual void InitOnEventFuncArray();



	/**********************		添加事件处理函数	****************************/
	DECL_ON_EVENT_FUNC(EGS_TEST_1);
	DECL_ON_EVENT_FUNC(EGS_TEST_2);
	DECL_ON_EVENT_FUNC(EGS_TEST_3);
	DECL_ON_EVENT_FUNC(EGS_TEST_4);
	DECL_ON_EVENT_FUNC(EGS_TEST_5);
	/**********************		添加事件处理函数	****************************/




};



#endif