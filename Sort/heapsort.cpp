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
void heapsort(int a[], int size){
    buildHeap(a, size);
    cout<<"Build Heap: ";
    for (int i = 0; i < arraysize; i++)
    {
        cout<<" "<<a[i];
    }
    cout<<endl;
    for(int i=size; i>0; i--){
        //cout<<" "<< i;
        int temp = a[0];
        a[0]=a[i];
        a[i]=temp;
        heapsize=heapsize-1;
        maxHeapify(a,0);
    }
}

int main(){
    arraysize=10;
    int a[arraysize]={16,4,10,14,7,9,3,2,8,1};
    //buildHeap(a,arraysize-1);
    heapsort(a, arraysize-1);
    cout<<endl<<"sorted:";
    for (int i = 0; i < arraysize; i++)
    {
        cout<<" "<<a[i];
    }
    
}