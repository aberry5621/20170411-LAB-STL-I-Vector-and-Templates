//
//  main.cpp
//  LAB STL I Vector and Templates
//
//  Created by ax on 5/21/17.
//  Copyright © 2017 COMP235. All rights reserved.
//


/*
 create vector of size 100
 generate 20 random uppercase letters
 populate letters into the vecor
 no duplicates
 
 sort the vector
 
 display the vector and observe missing letters
 use an iterator and insert function
 add missing letters into vector
 
 display the vector; show full 26 letters
 
 shrink vector capacity to 26 to match size
 
 display vector capacity and size
 
 */

#include <iostream>
#include <vector>

char get_random_char();

int main() {

    std::cout << "STL Vector and Templates\n";
    
    // create vector of size 100
    std::vector<char> alpha(100);
    
    // rand seed
    srand(static_cast<int>(time(0)));
    
    std::cout << "Alphabet vector\n";
    
    std::vector<char> alphabet(26);
    for (int i = 0; i < 26; i++) {
        alphabet[i] = i + 97;
    }
    
    std::cout << "Random populate alpha vector with chars\n";
    
    // gen random alpha

    for (int i = 0; i < 20; i++) {
        alpha[i] = get_random_char();
    }
    
    std::cout << "Vector capacity: " << alpha.capacity() << std::endl;
    std::cout << "Vector size: " << alpha.size() << std::endl;
    
    return 0;
}

char get_random_char() {
    return 97 + rand() % 25;
}
