//
//  main.cpp
//  SLinkedList
//
//  Created by Yuval Klein on 9/23/16.
//  Copyright © 2016 Yuval Klein. All rights reserved.
//
#include "SLinkedList.hpp"
#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    
    SLinkedList<int> intList;
    
    if (intList.empty())
        std::cout << "Empty List..." << std::endl;
    
    intList.addFront(5);
    intList.addFront(10);
    
    std::cout << "the front element is " << intList.front() << std::endl;
    
    SLinkedList<float> floatList;
    
    floatList.addFront(5.567);
    floatList.addFront(6.98);
    floatList.addFront(1.23);
    
    floatList.print();
    
    SLinkedList<std::string> strList;
    
    strList.addFront("Yuval");
    strList.addBack(" is a ");
    strList.addBack(" bad ass!");
    
    strList.print();
    
    return 0;
}
