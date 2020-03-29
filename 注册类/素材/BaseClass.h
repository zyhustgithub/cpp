#include <iostream>

#define USERS_PARAM(X) (std::cout << X << std::endl);

class ZBSBase
{
public:
    ZBSBase(){}
    virtual bool InitParam(const std::string& strParam) = 0;
    virtual void Excute() = 0;
    virtual void End() = 0;
};

class ZBSMessage : public ZBSBase
{
public:
    ZBSMessage():m_bInit(false) {}

    virtual bool InitParam(const std::string& strParam)
    {
        m_bInit = true;
        USERS_PARAM(strParam);
        return true;
    }

    virtual void Disp()
    {
        std::cout << "ZBSMessage::Disp!" << std::endl;
    }

    virtual void End()
    {
        std::cout << "ZBSMessage::End!" << std::endl;
    }

    virtual void Excute()
    {
        if (!m_bInit) return;
        std::cout << "ZBSMessage::Excute!" << std::endl;
        Disp();
        End();
    }

protected:
    bool m_bInit;
};