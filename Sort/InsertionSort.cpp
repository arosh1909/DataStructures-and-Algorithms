#include <iostream>

using namespace std;

// Taken from cormen
int main(){
    cout<<"::::Insertion Sort in increasing order:::";
    int a[3]={12,1,2,};
    // pick one element at a time starting from the second element
    // a[1...j-1] is always sorted
    for(int j=1;j<3;j++){
        int key=a[j];
        // Insert A[j] into the sorted sequence a[1...j-1]
        int i=j-1;
        while(i>=0 && a[i]>key){
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
    }
    // Print sorted
    for(int j=0;j<3;j++){
        cout<<a[j]<< " ";
    }
    cout<<endl;
    // Just flip a[i]>key to a[i]<key to get descending.
    cout<<"Insertion sort :: Descending order";
    int b[10]={12,3,2,4,55,6,1,11,4,10};
    for(int j=1;j<10;j++){
        int key=b[j];
        // Insert A[j] into the sorted sequence a[1...j-1]
        int i=j-1;
        while(i>=0 && b[i]<key){
            b[i+1]=b[i];
            i=i-1;
        }
        b[i+1]=key;
    }
    for(int j=0;j<10;j++){
        cout<<b[j]<< " ";
    }

}