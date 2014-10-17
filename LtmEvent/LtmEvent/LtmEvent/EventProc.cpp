#include "EventProc.h"

#include <stdio.h>

void EventProc::InitOnEventFuncArray()
{
#ifndef ALREADY_INIT_ON_EVENT_FUNC_ARRAY
#define ALREADY_INIT_ON_EVENT_FUNC_ARRAY

#define IMPL_ON_EVENT_FUNC(ID) IMPL_EVENT_FUNC(EventProc,ID)
#define REG_ON_EVENT_FUNC(ID) REG_EVENT_FUNC(EventProc,ID)

	/****************************************/
	// ×¢²áÊÂ¼þ
	REG_ON_EVENT_FUNC(EGS_TEST_1);
	REG_ON_EVENT_FUNC(EGS_TEST_2);
	REG_ON_EVENT_FUNC(EGS_TEST_3);
	REG_ON_EVENT_FUNC(EGS_TEST_4);
	REG_ON_EVENT_FUNC(EGS_TEST_5);

#endif
}

IMPL_ON_EVENT_FUNC(EGS_TEST_1)
{
	HWG_EVENT(EGS_TEST_1);
	printf("%d,%s\n", KEvent.EventID, KEvent.buf);

}

IMPL_ON_EVENT_FUNC(EGS_TEST_2)
{
	HWG_EVENT(EGS_TEST_2);
	printf("%d,%s\n", KEvent.EventID, KEvent.buf);
}

IMPL_ON_EVENT_FUNC(EGS_TEST_3)
{
	HWG_EVENT(EGS_TEST_3);
	printf("%d,%s\n", KEvent.EventID, KEvent.buf);
}

IMPL_ON_EVENT_FUNC(EGS_TEST_4)
{
	HWG_EVENT(EGS_TEST_4);
	printf("%d,%s\n", KEvent.EventID, KEvent.buf);
}

IMPL_ON_EVENT_FUNC(EGS_TEST_5)
{
	HWG_EVENT(EGS_TEST_5);
	printf("%d,%s\n", KEvent.EventID, KEvent.buf);
}