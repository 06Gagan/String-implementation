#include "MyString.h"
#include <cstring> //strcpy

// defination of all the functions declared in MyString.h
MyString::MyString()
{
    data = new char[1];
    length = 0;
    data[0] = '\0';
}
// paramaties constrction
MyString::MyString(const char *str)
{
    data = new char[strlen(str) + 1];
    length = strlen(str);
    strcpy(data, str);
}
// copy construction
MyString::MyString(const MyString &other)
{
    data = new char[other.length + 1];
    length = other.length;
    strcpy(data, other.data);
}

MyString::~MyString()
{
    delete[] data;
}

int MyString::size() const
{
    return length;
}

bool MyString::empty() const
{
    return length == 0;
}