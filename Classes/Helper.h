#ifndef __HELPER_H__
#define __HELPER_H__

template <class T>
class SingleInstance
{
protected:
	static T* instance;
public:
	static T* getInstance()
	{
		return instance;
	}
	SingleInstance()
	{
		instance = static_cast<T*>(this);
	}
	~SingleInstance()
	{
		instance = nullptr;
	}
};

template <class T>
T* SingleInstance<T>::instance = nullptr;

template <class T, typename... ARGS>
T* Create(ARGS... args)
{
	T* pRet = new T(args...);
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		return nullptr;
	}
}
#endif //__HELPER_H__