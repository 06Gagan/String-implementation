#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString
{
private:
    char *data; // pointer to char array data
    int length; // size of my string

public:
    // default ctor
    MyString();

    // parameter ctor
    MyString(const char *str);

    // copy ctor
    MyString(const MyString &other);

    ~MyString();
    int size() const;
    int empty() const;
};

#endif // MYSTRING_H
