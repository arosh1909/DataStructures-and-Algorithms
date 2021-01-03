#include <iostream>

using namespace std;
const int Ssize=100;
int stack[Ssize];
int top=-1;

bool stackEmpty(){
    if(top==-1)
        return true;
    else
        return false;
}

void push(int x){
    if(top+1<Ssize)
    {
        top+=1;
        stack[top]=x;
    }   
    else
    {
        cout<<"Overflow...";
    }
}

int pop(){
    if(stackEmpty())
        {
            cout<<"underflow";
            return -99999;
        }
    else if(top==0){
        top=-1;
        return stack[0];
    }
    else{
        top-=1;
        return stack[top+1];
    }
}

int main(){
    int x;
    push(7);
    push(6);
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    push(19);
    cout<<pop()<<endl;
    for(int i=0;i<110;i++){
        push(1);
    }
    cout<<endl<<pop();
}