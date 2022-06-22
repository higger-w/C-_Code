#ifndef __MYSTR__
#define __MYSTR__

//class String;

class String{
public:
    String(const char* cstr = 0);
    String(const String& str);
    String& operator=(const String& str);
    ~String();
    char* get_c_str() const {   return m_data;  }
private:
    char* m_data; // 指针
};

#include<cstring> //关键的导入！！
// constructor 
inline String::String(const char* cstr)
{
    if(cstr){   // cstr 非空
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else{       // cstr = 0 空字符串
        m_data = new char[1];
        *m_data = '\0';
    }
}
// destructor 
inline String::~String()
{
    delete[] m_data;
}
// 拷贝构造，属于深拷贝
inline String::String(const String& str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}
// 拷贝赋值，先清空原有内存释放，重新申请一样大的内存赋值
// 成员函数，包含 this
inline String& String::operator=(const String& str)
{
    if (this == &str) // 避免自我赋值
        return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1 ];
    strcpy(m_data, str.m_data);
    return *this;
}

#include<iostream>
using namespace std;
// 非成员函数，不包含this
ostream& operator<<(ostream& os, const String& str){
    os<< str.get_c_str();
    return os;
}
#endif