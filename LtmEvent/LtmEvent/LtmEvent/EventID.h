/******************************************************

					事件ID定义
			1、不能强制指定事件ID的值

******************************************************/


#ifndef __EVENTID__
#define __EVENTID__

// 定义消息ID集合
#define DECLARE_EVENT_MAP enum EVENT_MAP{ EGS_EVENT_DECLARE_BEGIN,
#define DECLARE_EVENT_MAP_END EGS_EVENT_DECLARE_END, };
// 定义消息数量
#define EVENT_SENTINEL EGS_EVENT_DECLARE_END


DECLARE_EVENT_MAP



    // 事件ID只能在以下插入
	//////////////////////////////////////////////////////

	EGS_TEST_1,
	EGS_TEST_2,
	EGS_TEST_3,
	EGS_TEST_4,
	EGS_TEST_5,

	//////////////////////////////////////////////////////
	// 事件ID只能在以上插入


DECLARE_EVENT_MAP_END



#endif