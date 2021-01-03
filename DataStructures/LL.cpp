#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(){
        cout<<"constructor called";
        data = 0;
        next = nullptr;
    }
};

class LinkedList{
    private:
        Node* head;

    public:
        LinkedList(){
            head=nullptr;
        }
        void add(int x){
            Node *newNode= new Node();
            newNode->data = x;
            newNode->next = head;
            head= newNode;
        }
        void print(){
            Node *t=head;
            while(t){
                cout<<" "<<t->data;
                t=t->next;
            }
        }

    
};

int main()
{
    LinkedList *ll= new LinkedList();
    ll->add(2);
    ll->print();
    return 0;
}