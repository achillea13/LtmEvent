#ifndef __LTM_EVENT_EVENT__
#define __LTM_EVENT_EVENT__


#include "common/Define.h"


namespace ltm_event{

struct BaseEvent
{
	BaseEvent()
	{
		EventID = 0;
	}

	int 	EventID; 			// ÏûÏ¢ID
};



}


#endif
