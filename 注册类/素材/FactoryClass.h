#include <iostream>
#include <map>
#include "BaseClass.h"

class ZBSCreatorBase
{
public:
    ZBSCreatorBase(){}
    virtual ZBSMessage* Create() = 0;
};

template<class T>
class ZBSCreator :public ZBSCreatorBase
{
public:
    ZBSCreator(const std::string& strkey = "") :m_strKey(strkey) {}

    ZBSMessage* Create()
    {
        return new T;
    }
private:
    std::string m_strKey;
};

class ZBSFactoryMgr
{
    ZBSFactoryMgr(){}

public:
    static ZBSFactoryMgr& Instance()
    {
        static ZBSFactoryMgr s_Instance;

        return s_Instance;
    }

    void AddZBSCreator(const std::string& strClassName, ZBSCreatorBase* pZBSCreator)
    {
        if (m_mapZBSCreator.find(strClassName) == m_mapZBSCreator.end())
        {
            m_mapZBSCreator.insert(make_pair(strClassName, pZBSCreator));
        }
    }

    ZBSMessage* CreatorZBSInstace(const std::string& strKey)
    {
        ZBSMessage* pZBSObj = NULL;
        std::map<std::string, ZBSCreatorBase*>::iterator it;

        it = m_mapZBSCreator.find(strKey);
        if (it != m_mapZBSCreator.end())
        {
            pZBSObj = it->second->Create();
        }

        return pZBSObj;
    }

    int GetMapSize()
    {
        return m_mapZBSCreator.size();
    }

private:
    std::map<std::string, ZBSCreatorBase*> m_mapZBSCreator;
};

#define REGISTER_ZBSFACTORY(ClassName)\
    ZBSFactoryMgr::Instance().AddZBSCreator(#ClassName, new ZBSCreator<ClassName>());

extern "C" ZBSMessage* CreateZBSMessage(const std::string& strKey)
{
    return ZBSFactoryMgr::Instance().CreatorZBSInstace(strKey);
}