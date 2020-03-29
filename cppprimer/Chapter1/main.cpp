#include "Sales_item.h"
#include <iostream>
using namespace std;
int main( int argc, char *argv[] )
{
    Sales_item book;
    cout << "录入书籍信息：";
    while( cin >> book ){
        cout << "ISBN \t sold \t price \t revenue" << endl;
        cout << book << endl;
    }
    return EXIT_SUCCESS;
}
