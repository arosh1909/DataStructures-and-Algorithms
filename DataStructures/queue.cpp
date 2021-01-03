#include <iostream>

using namespace std;

const int Qsize=100;
int Q[Qsize];
int head=-1, tail=-1;

void enqueue(int x){
    if(tail==-1)
     head=tail=0;
    if(head==tail+1 || (head==0 && tail==Qsize-1)){
        cout<<endl<<"Overflow";
        return;
    }
    Q[tail]=x;
    if(tail==Qsize-1)
        tail=0;
    else
    {
        tail+=1;
    }
}

int dequeue(){
    if(head==tail ){
        cout<<"Underflow";
        return -9999;
    }
    int x = Q[head];
    if(head==Qsize-1)
        head =0;
    else
    {
        head+=1;
    }
    return x;
}

int main(){
    enqueue(2);
    enqueue(3);
    // cout<<head<<"  "<<tail<<endl;
    cout<<dequeue();
    
    enqueue(199);
    cout<<endl<<dequeue();
    enqueue(2000);
    cout<<endl<<dequeue();
    for(int i=0;i<110;i++){
        enqueue(1);
    }
    cout<<endl<<dequeue();
}