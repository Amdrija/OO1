//
// Created by Andrija Jelenkovic on 12/3/19.
//

#include "String.h"

String::String():_length(0), _string(nullptr){}

String::String(const String &s) {
    copy(s);
}

String::String(String &&s) {
    move(s);
}

String::String(char *char_array) {
    duplicate_char_array(char_array);
}

String::~String() {
    delete_string();
}

String &String::operator=(const String &s) {
    if(this != &s) {
        delete_string();
        copy(s);
    }
    return *this;
}

String &String::operator=(String &&s) noexcept {
    if(this != &s){
        delete_string();
        move(s);
    }
    return *this;
}

void String::copy(const String &s) {
    duplicate_char_array(s._string);
}

void String::move(String &s) {
    _length = s._length;
    _string = s._string;
    s._string = nullptr;
}

void String::duplicate_char_array(char *s) {
    _length = strlen(s);
    _string = new char[strlen(s) + 1];
    for(int i = 0; i < _length; i++){
        _string[i] = s[i];
    }
    _string[_length] = '\0';
}

int String::getLength() const {
    return _length;
}

String operator+(const String &string1, const String &string2) {
    String s;
    s._length = string1._length + string2._length;
    s._string = new char[s._length + 1];

    for(int i = 0; i < string1._length; i++){
        s._string[i] = string1._string[i];
    }
    for(int i = string1._length;i < s._length; i++){
        s._string[i] = string2._string[i - string1._length];
    }
    s._string[s._length] = '\0';
    return s;
}

String &String::operator+=(const String &string) {
    return *this = *this + string;
}

std::ostream &operator<<(std::ostream &os, const String &string) {
    if(string._string == nullptr)
        os << "";
    else
        os << string._string;
    return os;
}

std::istream &operator>>(std::istream &is, String &string) {
    string.delete_string();

    char new_string[100];
    is >> new_string;
    string = String(new_string);
    return is;
}

void String::delete_string() {
    delete[] _string;
    _string = nullptr;
    _length = 0;
}

String &String::concat(char c) {
    char c_str[2] = {c, '\0'};
    return *this += String(c_str);
}

String &String::concat(const String &string) {
    return *this += string;
}

char &String::operator[](int index) {
    return _string[index];
}

String String::substring(int left_index, int right_index) {
    String s;

    if(right_index < left_index || left_index > _length || right_index < 0)
        return s;

    if(right_index > _length)
        right_index = _length - 1;

    s._length = right_index - left_index + 1;
    s._string = new char[s._length];

    for(int i = left_index; i <= right_index; i++){
        s._string[i - left_index] = _string[i];
    }
    s._string[s._length] = '\0';
    return s;
}

int String::find(const String &substring) {
    for(int i = 0; i < _length; i++){
        if(_string[i] == substring._string[0]){
            bool found = true;
            for(int j = 1; j < substring._length; j++){
                if(_string[i + j] != substring._string[j]){
                    found = false;
                }
            }
            if(found)
                return i;
        }
    }
    return -1;
}
