#ifndef __LTM_EVENT_THREADBASE__
#define __LTM_EVENT_THREADBASE__

/***************************			�̻߳���	win32	****************************/
#include "Define.h"
#include <Windows.h>

namespace ltm_event{

class ThreadBase
{

protected:

	HANDLE				_hThread;				// �߳̾��
	unsigned long		_ulThreadID;			// �߳�ID
	void*				_pData;					// �û��Զ�������
	unsigned long		_ulProcessorID;		// ��¼�Ĵ����ID

	bool				_bExitSignal;			// �Ƿ�������˳��źţ���������ʹ�ã��˻������޶�����壩

public:

	ThreadBase();
	virtual ~ThreadBase();


	// ��ʼ�������߳�
	bool InitThread( void* pData = NULL );


	// ����˳��ź�
	bool GetExitSignal() { return _bExitSignal; }

	// �����˳��ź�
	void SetExitSignal() { _bExitSignal = true; }


	// �ȴ��߳̽���
	// ulWaitMillisecond	:�ȴ�ʱ�䣨���룩��Ĭ��������ʱ
	unsigned long WaitForThreadEnd( unsigned long ulWaitMillisecond = ULONG_MAX );

	// ǿ�ƽ����߳�
	void ForceEndThread();

	// ��ȡ��¼�Ĵ����ID
	unsigned long GetProcessorID() { return _ulProcessorID; }

	// ���ô����
	unsigned long SetProcessorID( unsigned long ulProcessorID );


	// �����̵߳Ĵ����
	// hThread			:�߳̾��
	// bAuto			:�Ƿ��Զ�����
	// ulSpecID			:ָ�������ID������bAutoΪfalseʱ��Ч��
	// ����ֵ			:�����ID
	static unsigned long AdjustProcessor( HANDLE hThread, bool bAuto, unsigned long ulSpecID = 0 );




protected:

	// ��ȫ�����̣߳����̴߳������е��ã�
	// ulExitCode	:�����ķ���ֵ
	void SafeExitThread( unsigned long ulExitCode = 0 );


	// �û��Զ����ʼ��������λ�ڴ����߳�֮ǰ�� ��������������������Ҫ��ʼ���������ش˺���
	// ����ֵ		:true�ɹ�
	virtual bool CustomInitBeforeThread() { return true; }

	// ��ʵ���̴߳���������������Ҫ���ش˺���
	// ����ֵ		:��ʾ���߳̽���ʱ���ص�ֵ
	virtual unsigned long ThreadProcReal() { return 0; }

	// �߳���ڻص�����
	// pData		:ʵ�����߳�������ʵ���ĵ�ַ
	// ����ֵ		:��ʾ���߳̽���ʱ���ص�ֵ
	static unsigned long WINAPI _ThreadProcCallBack( void *pData );


};

}

#endif