#include <iostream>

using namespace std;

int minimum(int a[], int s){
    int min = a[0];
    for(int i=1;i<s;i++){
        if(a[i]<min){
            min=a[i];
        }
    }
    return min;
}

int main(){
    int a[6]={1,-5,2,4,2,-1};
    cout<<minimum(a,6);
}