#include <iostream>
#include <limits> // For Sentinal element(max)

using namespace std;

void merge(int a[], int p, int q, int r){
    // cout<<endl;
    // for(int i=p; i<=r; i++){
    //     cout<<a[i]<<" ";
    // }
    int n1=q-p+1;
    int n2=r-q;
    // cout<<"Size n1: "<<n1<<" n2: "<<n2<<endl;
    int L[n1+1], R[n2+1]; // +1 for the sentinal element
    
    for(int i=0; i<n1;i++){
        L[i]=a[p+i];
    }
    // cout<<"L: ";
    // for(int i=0; i<n1;i++){
    //     cout<<L[i];
    // }
    // cout<<endl;
    for(int j=0;j<n2;j++){
        R[j]=a[q+j+1];
    }
    // cout<<"R: ";
    // for(int j=0;j<n2;j++){
    //     cout<<R[j];
    // }
    cout<<endl;
    L[n1]=numeric_limits<int>::max();
    R[n2]=numeric_limits<int>::max();
    int i=0;
    int j=0;
    for(int k=p;k<=r;k++){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i+=1;
        }
        else{
            a[k]=R[j];
            j+=1;
        }
    }
    
}

void merge_sort(int a[],int p, int r){
    if(p<r){
        int q=(p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}
int main(){
    cout<<":::This is merge Sort:::"<<endl;
    int a[8]={116,53,4,32,11,1,0,-1};
    merge_sort(a,0,7);
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
}