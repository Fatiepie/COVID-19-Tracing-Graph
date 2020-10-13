#include <stdio.h>
#include <iostream>
#include "final_assignment.hpp"
#include "final_assignment_tests.hpp"

using namespace std;

int main(){
    ContactTracingGraphTest t;
    
    if(t.test1()){
        cout << "Test 1: PASSED" << endl;
    }
    if(t.test2()){
        cout << "Test 2: PASSED" << endl;
    }
    if(t.test3()){
        cout << "Test 3: PASSED" << endl;
    }
}
