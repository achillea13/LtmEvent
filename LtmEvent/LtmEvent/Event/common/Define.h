#ifndef __LTM_EVENT_DEFINE__
#define __LTM_EVENT_DEFINE__


#include <time.h>
#include <math.h>
#include <string.h>



#include <list>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <string>
#include <algorithm>


#include "boost/shared_ptr.hpp"



namespace ltm_event{


#define UidType unsigned __int64

#define SmartPointer(_Class_Name) class _Class_Name; typedef boost::shared_ptr<_Class_Name> _Class_Name##Ptr


#ifndef SAFE_DELETE
#define SAFE_DELETE(p)	{ if(p){ delete p; p = 0; } }
#endif


#ifndef SAFE_CLOSE_HANDLE
#define SAFE_CLOSE_HANDLE(p)	{ if(p){CloseHandle(p); p = 0; } }
#endif


#ifndef ARRAY_COUNT
#define ARRAY_COUNT(a)	(sizeof(a) / sizeof(a[0]))
#endif


#define EVENT_LEN_LMT 8 * 1024			// 长度限制

}


#endif