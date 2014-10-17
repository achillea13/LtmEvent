#ifndef __LTM_EVENT_SINGLETON__
#define __LTM_EVENT_SINGLETON__

/*************************		��ʵ������			*************************/

namespace ltm_event{

template< typename T >
class Singleton
{
    
public:
    static T* GetInstance()
    {
      
        if ( _pInstance == NULL )
        {
            _pInstance = new T();
        }
        
        return _pInstance;
    };
    
protected:
    Singleton(){};
    virtual ~Singleton(){ if( _pInstance != NULL ){ delete _pInstance; };  _pInstance=NULL; };
    
    static T* _pInstance;
    


};

template< typename T > T* Singleton<T>::_pInstance = NULL;

}

#endif