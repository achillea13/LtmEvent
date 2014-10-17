#include "Buff.h"

#include <string.h>

namespace ltm_event{

EventBuf::EventBuf(int id, char* pBuf, int len)
{
	_ExeID	= id;
	memset( _buff, '\0', sizeof(_buff) );
	memcpy( _buff, pBuf, len );
}

EventBuf::~EventBuf()
{
}

}