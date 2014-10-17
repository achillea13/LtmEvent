#ifndef __LTM_EVENT_THREADBASE__
#define __LTM_EVENT_THREADBASE__

/***************************			线程基类	win32	****************************/
#include "Define.h"
#include <Windows.h>

namespace ltm_event{

class ThreadBase
{

protected:

	HANDLE				_hThread;				// 线程句柄
	unsigned long		_ulThreadID;			// 线程ID
	void*				_pData;					// 用户自定义数据
	unsigned long		_ulProcessorID;		// 记录的处理核ID

	bool				_bExitSignal;			// 是否产生了退出信号（供派生类使用，此基类中无多大意义）

public:

	ThreadBase();
	virtual ~ThreadBase();


	// 初始化创建线程
	bool InitThread( void* pData = NULL );


	// 获得退出信号
	bool GetExitSignal() { return _bExitSignal; }

	// 产生退出信号
	void SetExitSignal() { _bExitSignal = true; }


	// 等待线程结束
	// ulWaitMillisecond	:等待时间（毫秒），默认永不超时
	unsigned long WaitForThreadEnd( unsigned long ulWaitMillisecond = ULONG_MAX );

	// 强制结束线程
	void ForceEndThread();

	// 获取记录的处理核ID
	unsigned long GetProcessorID() { return _ulProcessorID; }

	// 设置处理核
	unsigned long SetProcessorID( unsigned long ulProcessorID );


	// 调整线程的处理核
	// hThread			:线程句柄
	// bAuto			:是否自动调整
	// ulSpecID			:指定处理核ID（仅当bAuto为false时有效）
	// 返回值			:处理核ID
	static unsigned long AdjustProcessor( HANDLE hThread, bool bAuto, unsigned long ulSpecID = 0 );




protected:

	// 安全结束线程（在线程处理函数中调用）
	// ulExitCode	:结束的返回值
	void SafeExitThread( unsigned long ulExitCode = 0 );


	// 用户自定义初始化操作，位于创建线程之前， 派生类如有其他数据需要初始化，则重载此函数
	// 返回值		:true成功
	virtual bool CustomInitBeforeThread() { return true; }

	// 真实的线程处理函数，派生类需要重载此函数
	// 返回值		:标示该线程结束时返回的值
	virtual unsigned long ThreadProcReal() { return 0; }

	// 线程入口回调函数
	// pData		:实质是线程派生类实例的地址
	// 返回值		:标示该线程结束时返回的值
	static unsigned long WINAPI _ThreadProcCallBack( void *pData );


};

}

#endif