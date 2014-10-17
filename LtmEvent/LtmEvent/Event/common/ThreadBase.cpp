#include "ThreadBase.h"

#include "common\Mutex.h"

namespace ltm_event{


ThreadBase::ThreadBase()
{
	_hThread		= 0;
	_ulThreadID	= 0;
	_pData			= 0;
	_ulProcessorID	= 0;
	_bExitSignal	= false;

}

ThreadBase::~ThreadBase()
{
	SAFE_CLOSE_HANDLE( _hThread );
}


bool ThreadBase::InitThread( void *pData )
{
	// 保存自定义数据
	_pData = pData;

	// 自定义初始化操作
	if ( !CustomInitBeforeThread() )
		return false;

	// 创建线程
	_hThread	= CreateThread( 0, 0, _ThreadProcCallBack, this, 0, &_ulThreadID );

	_ulProcessorID		= AdjustProcessor( _hThread, true );

	return _hThread != NULL;
}

unsigned long ThreadBase::WaitForThreadEnd( unsigned long ulWaitMillisecond )
{
	return _hThread ? WaitForSingleObject( _hThread, ulWaitMillisecond ) : 0;
}

void ThreadBase::SafeExitThread( unsigned long ulExitCode )
{
	if ( _hThread )
		::ExitThread( ulExitCode );
}

void ThreadBase::ForceEndThread()
{
	if ( _hThread )
		::TerminateThread( _hThread, 0 );
}

unsigned long ThreadBase::SetProcessorID( unsigned long ulProcessorID )
{
	_ulProcessorID		= AdjustProcessor( _hThread, false, ulProcessorID );

	return _ulProcessorID;
}

unsigned long ThreadBase::AdjustProcessor( HANDLE hThread, bool bAuto, unsigned long ulSpecID )
{
	static Mutex			s_mutex;
	static bool				s_bInit = false;
	static unsigned long	s_ulProcessorNum	= 1;
	static unsigned long	s_ulProcessorID		= 0;
	static unsigned long	s_ulMarkAry[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };

	MutexLock kLock( s_mutex );

	unsigned long ulRet;


	if ( !s_bInit )
	{
		srand( time(0) );

		SYSTEM_INFO xInfo;
		GetSystemInfo( &xInfo );
		s_ulProcessorNum = xInfo.dwNumberOfProcessors;
		if ( s_ulProcessorNum > 0 )
			s_ulProcessorID = rand() % s_ulProcessorNum;

		// 此处可以插入日志

		unsigned long ulVal = 0;
		for ( unsigned long k = 0; k < s_ulProcessorNum && k < ARRAY_COUNT(s_ulMarkAry); k++ )
		{
			ulVal |= s_ulMarkAry[k];
		}

		HANDLE hHandle = GetCurrentProcess();
		ulRet = SetProcessAffinityMask( hHandle, ulVal );
		if ( ulRet == 0 )
		{
			// 插入错误日志
		}

		s_bInit = true;

	}
	

	if ( !hThread )
		return 0;

	unsigned long ulProccID;

	// 自动
	if ( bAuto )
	{
		ulProccID = s_ulProcessorID;

		ulRet = SetThreadIdealProcessor( hThread, ulProccID );
		if ( ulRet == (unsigned long)-1 )
		{
			// 插入错误日志 SetThreadIdealProcessor failed.
		}

		ulRet = SetThreadAffinityMask( hThread, s_ulMarkAry[ulProccID] );
		if ( ulRet == 0 )
		{
			// 插入错误日志 SetThreadAffinityMask failed.
		}

		s_ulProcessorID++;
		if ( s_ulProcessorID >= s_ulProcessorNum )
			s_ulProcessorID = 0;

	}
	// 指定
	else
	{
		ulProccID = ulSpecID;

		if ( ulProccID >= s_ulProcessorNum )
			ulProccID = 0;


		ulRet = SetThreadIdealProcessor( hThread, ulProccID );
		if ( ulRet == (unsigned long)-1 )
		{
			// 插入错误日志 SetThreadIdealProcessor failed.
		}

		ulRet = SetThreadAffinityMask( hThread, s_ulMarkAry[ulProccID] );
		if ( ulRet == 0 )
		{
			// 插入错误日志 SetThreadAffinityMask failed.
		}


	}


	return ulProccID;

}


unsigned long WINAPI ThreadBase::_ThreadProcCallBack( void *pData )
{
	if ( pData == NULL )
		return 0;

	ThreadBase* pThreadBase = (ThreadBase*)pData;

	return pThreadBase->ThreadProcReal();
}


}