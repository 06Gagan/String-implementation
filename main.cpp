#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
    MyString s("Gagandeep Maurya ");
    cout << s[0] << endl;
    cout << s.find("Maurya") << endl;
    return 0;
}