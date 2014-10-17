#ifndef __LTM_EVENT_SIMOBJECT__
#define __LTM_EVENT_SIMOBJECT__


#include <string>


namespace ltm_event{

class SimObject
{
	public:
		SimObject();
		virtual ~SimObject();


		const std::string &GetName() const { return _strName; }
		void SetName(const std::string &strName) { _strName = strName; }
		void SetName( const char* szName ) { _strName = szName; }


		__int64 GetUID() const { return _iUID; }
		void SetUID( __int64 iUID ) { _iUID = iUID; }




	protected:
		std::string 	_strName;
		__int64 		_iUID;

};

}

#endif
