#include <iostream>

using namespace std;

int partition(int a[], int p, int r){
    int x=a[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(a[j]<=x){
            i+=1;
            //swap a[i] and a[j]
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    //swap a[i+1] and a[r]
    int t=a[i+1];
    a[i+1]=a[r];
    a[r]=t;
    return i+1;
}

void quicksort(int a[], int p, int r){
    if(p<r){
        int q=partition(a,p,r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}

int main(){
    int a[8]={41,2,61,1,2,2,-1,-1111111};
    quicksort(a,0,7);
    for(int i=0;i<8;i++){
        cout<<" "<<a[i]<<" ";
    }
}