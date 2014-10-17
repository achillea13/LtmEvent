#ifndef __LTM_EVENT_PERFORMER__
#define __LTM_EVENT_PERFORMER__


#include "SimObject.h"
#include "Event.h"
#include "queue"

#include "buff.h"


namespace ltm_event{

SmartPointer(EventBuf);
class Performer : public SimObject
{

public:
 	Performer();
	virtual ~Performer();

	
	void QueueingEvent( EventBufPtr pEvent );
	unsigned int GetQueueSize()
	{
		return m_queEvent.size();
	}



protected:

	virtual void Tick();

	EventBufPtr GetEvent();


protected:
	virtual void ProcessEvent( EventBufPtr pEvent ) = 0;


protected:

	std::queue<EventBufPtr>	m_queEvent;

};


}

#endif
