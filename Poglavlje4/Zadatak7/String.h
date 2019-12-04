//
// Created by Andrija Jelenkovic on 12/3/19.
//

#ifndef ZADATAK7_STRING_H
#define ZADATAK7_STRING_H

#include <iostream>

class String {
public:
    String();
    String(const String& string);
    String(String&& string);
    String(char* char_array);
    ~String();
    String& operator=(const String& string);
    String& operator=(String&& string)noexcept ;
    int getLength() const;
    friend String operator+(const String& string1, const String& string2);
    String& operator+=(const String& string);
    String& concat(const String &string);
    String& concat(char c);
    char& operator[](int index);
    String substring(int left_index, int right_index);
    int find(const String& substring);
    friend std::ostream& operator<<(std::ostream& os, const String& string);
    friend std::istream& operator>>(std::istream& is, String& string);
private:
    char* _string;
    int _length;
    void copy(const String&);
    void move(String& s);
    void delete_string();
    void duplicate_char_array(char* s);
};


#endif //ZADATAK7_STRING_H
