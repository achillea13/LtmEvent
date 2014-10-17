// LtmEvent.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "Route.h"

#include "EventProc.h"

#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{

	EventProc ep;
//	ep.InitOnEventFuncArray();

	ltm_event::Route<EventProc,EVENT_SENTINEL> r;

	r.SetProcImpl( &ep );
	

	int i = 1;
	while (1)
	{
		switch( i )
		{
		case EGS_TEST_1:
			{
				EEGS_TEST_1 pack;
				sprintf( pack.buf, "加入事件%d", i );
				r.QueueEvent( 1, (BaseEvent*)&pack, sizeof(pack) );
			}
			break;

		case EGS_TEST_2:
			{
				EEGS_TEST_2 pack;
				sprintf( pack.buf, "加入事件%d", i );
				r.QueueEvent( 1, (char*)&pack, sizeof(pack) );
			}
			break;

		case EGS_TEST_3:
			{
				EEGS_TEST_3 pack;
				sprintf( pack.buf, "加入事件%d", i );
				r.QueueEvent( 1, (char*)&pack, sizeof(pack) );
			}
			break;

		case EGS_TEST_4:
			{
				EEGS_TEST_4 pack;
				sprintf( pack.buf, "加入事件%d", i );
				r.QueueEvent( 1, (char*)&pack, sizeof(pack) );
			}
			break;

		case EGS_TEST_5:
			{
				EEGS_TEST_5 pack;
				sprintf( pack.buf, "加入事件%d", i );
				r.QueueEvent( 1, (char*)&pack, sizeof(pack) );
			}
			break;

		}

		i++;
		if (i > 5)
			i=1;

		Sleep(3000);
		
	}


	getchar();
	return 0;
}

