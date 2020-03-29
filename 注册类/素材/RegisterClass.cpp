#include <string>
#include <map>
#include <list>
#include <iostream>
#include "FactoryClass.h"
using namespace std;

class ZBSEncodeMessage : public ZBSMessage
{
public:
    ZBSEncodeMessage(){}

    virtual void Disp()
    {
        cout << "ZBSEncodeMessage::Disp" << endl;
    }
};

class ZBSJsonMessage : public ZBSMessage
{
public:
    ZBSJsonMessage(){}

    virtual void Disp()
    {
        cout << "ZBSJsonMessage::Disp" << endl;
    }
};

class ZBSXMLMessage : public ZBSMessage
{
public:
    ZBSXMLMessage(){}

    virtual void Disp()
    {
        cout << "ZBSXMLMessage::Disp" << endl;
    }
};

int main()
{
    REGISTER_ZBSFACTORY(ZBSXMLMessage);
    REGISTER_ZBSFACTORY(ZBSJsonMessage);
    REGISTER_ZBSFACTORY(ZBSEncodeMessage);

    ZBSMessage *pm1;
    ZBSMessage *pm2;
    ZBSMessage *pm3;

    std::list<ZBSMessage*> ls;
    std::list<ZBSMessage*>::iterator it;

    pm1 = CreateZBSMessage("ZBSXMLMessage");
    pm2 = CreateZBSMessage("ZBSJsonMessage");
    pm3 = CreateZBSMessage("ZBSEncodeMessage");
    ZBSEncodeMessage c1;

    ls.push_back(pm1);
    ls.push_back(pm2);
    ls.push_back(pm3);

    ls.push_back(&c1);

    int nSize = ls.size();
    it = ls.begin();
    for (; it != ls.end(); it++)
    {
        (*it)->InitParam("");
        (*it)->Excute();
    }
    return 0;
}