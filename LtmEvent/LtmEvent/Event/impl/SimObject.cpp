#include "SimObject.h"


namespace ltm_event{

SimObject::SimObject() : _iUID(0)
{
	char buff1[128] = {0};
	char buff2[128] = {0};
	char buff3[128] = {0};

	static unsigned __int64 sSeedNum = 0;

//	swprintf( buff3, "M_%s_%s_%020d", _wstrdate(buff1), _wstrtime(buff2), sSeedNum++ );
	sprintf( buff3, "M_%020d", sSeedNum++ );

	_strName = buff3;
}

SimObject::~SimObject()
{
}

}