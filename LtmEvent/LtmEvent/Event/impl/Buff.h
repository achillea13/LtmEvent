#ifndef __LTM_EVENT_BUFF__
#define __LTM_EVENT_BUFF__


#include "common/Define.h"

namespace ltm_event{



class EventBuf
{

public:

	EventBuf( int id, char* pBuf, int len );
	virtual ~EventBuf();

public:

	int			_ExeID;						// ExeID
	char		_buff[EVENT_LEN_LMT];		// ÏûÏ¢buff
};

}

#endif