#define prog 2

#if prog == 1

//
//  main.cpp
//  LAB STL I Vector and Templates
//
//  Created by ax on 5/21/17.
//  Copyright © 2017 COMP235. All rights reserved.
//


/*
 √ create vector of size 100
 √ generate 20 random uppercase letters
 √ populate letters into the vecor
 √ no duplicates
 
 [ √ ] sort the vector
 
 display the vector and observe missing letters
 
 use an iterator and insert function
 add missing letters into vector
 
 display the vector; show full 26 letters
 
 shrink vector capacity to 26 to match size
 
 display vector capacity and size
 
 */

#include <iostream>
#include <vector>
#include <algorithm>

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
    int placed_chars = 0;
    while (placed_chars < 20) {
        char rand_char =  get_random_char();
        bool char_duplicate = false;
        // check to see if the rand char is in the vector already
        for (int i = 0; i < placed_chars; i++) {
            if (alpha[i] == rand_char) {
                char_duplicate = true;
            }
        }
        if ( ! char_duplicate) {
            alpha[placed_chars++] = rand_char;
        }
    }
    
    
    // loop through vector, start at 0 position
    std::cout << "looping throug vec\n";
    
    // sort it out
    std::sort (alpha.begin(), alpha.begin()+20);
    
    // display the vector and observe missing letters
    std::cout << "What letters are missing? \n";
    int idx = 0;
    while (alpha[idx] != '\0') {
        std::cout << alpha[idx++] << std::endl;
    }
    
    
    std::cout << "Insert missing letters? \n";
    // use an iterator and insert function
    // add missing letters into vector
    
    std::vector<char>::iterator itr = alpha.begin();
    
    idx = 0;

    while (idx < 26) {
        std::cout << "IDX: " << idx << std::endl;
        
        int current_char_int_val = static_cast<int>(alpha[idx]);
        
        if (current_char_int_val-97 != idx) {
            std::cout << "letter in wrong spot!\n";
            // insert the correct char
            char missing_char = static_cast<char>(97+idx);
            alpha.insert(itr, missing_char);
            itr = alpha.begin()+idx;
        } else {
            idx++;
            itr++;
        }
    }
    
    
    alpha.resize(26);
    
    // output vector capacity and size
    std::cout << "Vector capacity: " << alpha.capacity() << std::endl;
    std::cout << "Vector size: " << alpha.size() << std::endl;
    
    return 0;
}

char get_random_char() {
    return 97 + rand() % 25;
}


#elif prog == 2

#include <iostream>
#include <vector>

template<typename T>
void swapValue(T objA, T objB) {
    T temp = new T();
    temp = objA;
    objA = objB;
    objB = temp;
}

class MyClass {
public:
    MyClass() {
        int new_data_mem = * new int;
        m_data = &new_data_mem;
    };
    MyClass(int p_data) { m_data = 0;};
    
    // overloaded copy constructor
    MyClass(const MyClass &p_myclass_obj) {
        this->m_data = p_myclass_obj.m_data;
    };
    
    // overloaded assignment operator
    MyClass& operator= (const MyClass &p_myclass_obj) {
        this->m_data = p_myclass_obj.m_data;
        return *this;
    };
    int * m_data;
};

int main() {
    
    std::cout << "Ex 2\n";
    
    MyClass obj0 = * new MyClass();
    
    MyClass obj1(10);
    MyClass obj2(20);
    
    int * ptr1 = new int(10);
    int * ptr2 = new int(20);
    obj1.m_data = ptr1;
    obj2.m_data = ptr2;
    
    std::cout << "data check..\n";
    
    
    
    std::cout << "swap time..\n";
    
    int a = 1;
    int b = 2;
    
    swapValue(a, b);
    
    //
    obj0 = obj1;
    obj1 = obj2;
    obj2 = obj0;
    // swap back?
    // swapValue(obj1, obj2);
    
    std::cout << "data check..\n";
    
    
    return 0;
}



#endif





