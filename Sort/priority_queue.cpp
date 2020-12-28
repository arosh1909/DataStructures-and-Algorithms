// # 2 heaps are there max heap and min heap. Max heap require that every node is at most the value of it's parent.
// opposite for minheaps.
#include <iostream>

using namespace std;

int heapsize;
int arraysize;
int parent(int i){
    if(i%2==0){
        return (i-2)>>1;
    }
    else{
        return i>>1;
    }
}

int left(int i){
    return (i<<1)+1;
}

int right(int i){
    return (i<<1)+2;
}

void maxHeapify(int a[], int i){
    int l= left(i);
    int r= right(i);
    int largest;

    if(l<=heapsize && a[l]>a[i])
        largest = l;
    else largest = i;

    if(r<=heapsize && a[r]>a[largest])
        largest = r;
    if(largest!=i){
        int temp = a[i];
        a[i]=a[largest];
        a[largest]=temp;

        maxHeapify(a, largest);
    }           
}

void buildHeap(int a[], int size){
    heapsize=size;
    for(int i=size/2 ;i>=0;i--){
        maxHeapify(a,i);
    }

}

int heapextractMax(int a[]){
    if(heapsize<0){
        cout<<endl<<"UNDERFLOW";
        return -1;
    }
    int max = a[0];
    a[0]=a[heapsize];
    heapsize-=1;
    maxHeapify(a,0);
    return max;
}

void heapIncreaseKey(int a[], int i, int key){
    if(key<a[i]){
        cout<<"New key is smaller than current key";
        return;
    }
    a[i]=key;
    while(i>0 && a[parent(i)]<a[i]){
        //swap both
        int temp= a[i];
        a[i]=a[parent(i)];
        a[parent(i)]=temp;

        i=parent(i);
    }
}

void maxHeapInsert(int a[], int key){
    heapsize=heapsize+1;
    a[heapsize]= INT16_MIN;
    heapIncreaseKey(a,heapsize, key);

}

int main(){
    arraysize=10;
    int a[arraysize]={16,4,10,14,7,9,3,2,8,1};
    buildHeap(a, 9);
    cout<<heapextractMax(a);
    cout<<endl;
    for (int i = 0; i < arraysize; i++)
    {
        cout<<" "<<a[i];
    }
    heapIncreaseKey(a,3,100);
    cout<<endl;
    for (int i = 0; i < arraysize; i++)
    {
        cout<<" "<<a[i];
    }

    maxHeapInsert(a,1000);
    cout<<endl;
    for (int i = 0; i < arraysize; i++)
    {
        cout<<" "<<a[i];
    }

    cout<<endl<<heapsize<<"   "<<arraysize;
}