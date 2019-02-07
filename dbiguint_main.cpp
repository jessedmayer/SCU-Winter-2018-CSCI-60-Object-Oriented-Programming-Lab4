#include "dbiguint.h"

int main(){
    dbiguint a;
    dbiguint b("991");
    dbiguint c("4355");
    std::cout << b <<std::endl;
    //b.reserve(5);
    //std::cout << b <<std::endl;
    b+=c;
    std::cout << b <<std::endl;
    return 0;
}