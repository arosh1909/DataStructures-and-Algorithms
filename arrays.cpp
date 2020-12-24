#include <iostream>
// This file contains basics of arrays in c/cpp and python;
using namespace std;
// In cpp:
int main(){
    //Two things are very important:
    // 1- Header files
    // 2- using namespace std; to avoid typing std::cout<< everytime
    //    I use cout.


    // Arrays are created either statically or dynamically by allocating a chunk of memory
    int a[5];// allocates 5 elements of int contiguously
    // Let's see their addresses
    for(int i=0; i<5; i++){
        cout<<"Address of "<< i << &a[i]<<endl;
        cout<<"Size of each index "<< i << sizeof(a[i])<<endl;
    }

    // Arrays and pointers are intimately connected
    int *ptr;
    ptr = a;
    cout<<"Now ptr and a are same thing."<< endl;
    cout<< ptr[1] << a[0];

}
