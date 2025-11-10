#include <iostream>
#include <vector>
#include <algorithm>
#include "Fraction.hpp"


int main(){
    // std::vector<int> test ={0,2,3,1,0,9};
    // for (auto i=0;i<test.size();i++){
    //     std::cout << test[i];
    // }
    // std::cout << std:: endl;
    
    // std::sort(test.begin(),test.end());
    // for (auto i=0;i<test.size();i++){
    //     std::cout << test[i];
    // }
    //

    Fraction test;
    test.setnum(5);
    test.setden(1);
    
    
    Fraction test2(5,2);
    Fraction test3 = test * test2;

    test3.print();
    std::cout<<test3<<std::endl;

    // std::string feur;
    // std::cin >> feur;
    // std::cout<< feur<<std::endl;
    //

    std::cout<<(double)test3<<std::endl;

    return 0;
}
