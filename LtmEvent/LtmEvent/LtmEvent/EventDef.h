#ifndef __EVENTDEF__
#define __EVENTDEF__


#include "EventID.h"
#include "impl\Event.h"
using namespace ltm_event;

#define DECL_EVENT(EVENT_ID) struct E##EVENT_ID : public BaseEvent
#define INIT_EVENT(EVENT_ID) E##EVENT_ID(){ BaseEvent::EventID = EVENT_ID; }



// 定义消息数据

DECL_EVENT(EGS_EVENT_DECLARE_BEGIN)
{
	INIT_EVENT(EGS_EVENT_DECLARE_BEGIN);

	char buf[128];

};

DECL_EVENT(EGS_TEST_1)
{
	INIT_EVENT(EGS_TEST_1)
	int code;
	char buf[128];

};

DECL_EVENT(EGS_TEST_2)
{
	INIT_EVENT(EGS_TEST_2)
	int code;
	char buf[128];
};

DECL_EVENT(EGS_TEST_3)
{
	INIT_EVENT(EGS_TEST_3)
	int code;
	char buf[128];
};

DECL_EVENT(EGS_TEST_4)
{
	INIT_EVENT(EGS_TEST_4)
	int code;
	char buf[128];
};

DECL_EVENT(EGS_TEST_5)
{
	INIT_EVENT(EGS_TEST_5)
	int code;
	char buf[128];
};


#endif