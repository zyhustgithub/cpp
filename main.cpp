#include <iostream>
using namespace std;

class Line
{
    public:
        int getLength(void);
        Line(int len); //构造函数
        Line(const Line &obj); //拷贝构造函数
        ~Line(); //析构函数
    private:
        int *ptr;
};

Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数并为指针ptr分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr;
}

Line::~Line(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}

int Line::getLength(void)
{
    return *ptr;
}

void display(Line obj)
{
    cout << "Line 大小:" << obj.getLength() << endl;
}

int main()
{
    Line line(10);
    Line line_copy = line;
    __asm__("nop\n\t"
        :
        :
        :
    );
    display(line);
    display(line_copy);
    
    return 0;
}
