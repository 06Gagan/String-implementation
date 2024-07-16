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
    const char *c_str() const;

    char operator[](int index);

    // fing substring
    int find(const MyString &substr) const;

    // overload insertion operator << for easy outpu
    friend std::ostream &operator<<(std::ostream &os, const MyString &str);
};

#endif // MYSTRING_H
