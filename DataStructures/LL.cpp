#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(){
        data = 0;
        next = nullptr;
        prev = nullptr;
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
            newNode->prev = nullptr;
            head= newNode;
        }
        void print(){
            Node *t=head;
            while(t){
                cout<<" "<<t->data;
                t=t->next;
            }
        }
    void search(int x){
        Node *t=head;
        while(t&&t->data!=x){
            t=t->next;
        }
        if(t!=nullptr&&t->data==x){
            cout<<"found;";
        }
        else{
            cout<<"Not found;;";
        }
    }
    
};

int main()
{
    LinkedList *ll= new LinkedList();
    ll->add(2);
    ll->add(3);
    ll->add(3);
    ll->add(3);
    ll->add(2343);
    ll->add(333);
    ll->add(311);
    ll->add(31);
    ll->add(3);
    ll->print();
    ll->search(2343);
    return 0;
}