#include "Performer.h"


namespace ltm_event{

Performer::Performer()
{
}

Performer::~Performer()
{
	if ( !m_queEvent.empty() )
	{
		// ��Ϣû�д�����
	}
}


void Performer::Tick()
{
	while ( true )
	{
		EventBufPtr pEvent = GetEvent();

		if ( pEvent == 0 )
			continue;

		ProcessEvent(pEvent);
	}
}


void Performer::QueueingEvent( EventBufPtr pEvent )
{
 	m_queEvent.push( pEvent );
}


EventBufPtr Performer::GetEvent()
{
	if ( m_queEvent.empty() )
		return 0;

	EventBufPtr pEvent = m_queEvent.front();
	m_queEvent.pop();

	return pEvent;
}

}






