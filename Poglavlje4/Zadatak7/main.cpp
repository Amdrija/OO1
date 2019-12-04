#include <iostream>
#include "String.h"

int main() {
    String s;
    String p("Andrija");
    std::cout<<s.getLength()<<" "<<p.getLength()<<std::endl;
    std::cout<<p<<std::endl;
    s.concat('a');
    std::cout<<s.getLength()<<" "<<p.getLength()<<std::endl;
    std::cout<< (p+= s)<<std::endl;
    std::cin >> s;
    std::cout<<p + s<<std::endl;
    std::cout<<p.substring(5,7)<<std::endl;
    std::cout<<p.find("jaa")<<std::endl;
    return 0;
}