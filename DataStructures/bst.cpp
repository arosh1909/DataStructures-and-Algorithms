//
#include <iostream>

using namespace std;

class node
{
public:
    node *left;
    node *right;
    node *p;
    int data;
    node()
    {
        left = right = p = nullptr;
        data = -111;
    }
};

class bst
{
public:
    bst()
    {
        root = nullptr;
    }

    void insert(int x)
    {
        node* prev=nullptr;
        node *temp = root;

        while (temp)
        {
            prev=temp;
            if (temp->data < x)
            {
                    temp = temp->right;
            }
            else
            {
                    temp = temp->left;
            }
        }
        node* newNode= new node();
        newNode->data=x;
        if(x>prev->data){
            prev->right=newNode;
            newNode->p=prev;
        }
        else{
            prev->left=newNode;
            newNode->p=prev;
        }
    }

    void inorder(node *t)
    {
        if (t != nullptr)
        {
            inorder(t->left);
            cout << " " << t->data << " ";
            inorder(t->right);
        }
    }

    void preorder(node* p){
        if(p!=nullptr){
            cout<<" "<<p->data;
            preorder(p->left);
            preorder(p->right);
        }
    }

    node* recursiveSearch(node*p, int x){
        if(p==nullptr || p->data==x)
            return p;
        if(x<p->data)
            return recursiveSearch(p->left,x);
        else
            return recursiveSearch(p->right,x);
    }

    //Iterative
    void search(int x){
        node *t=root;
        while(t){
            if(t->data==x){
                cout<<"found::";
                return;
            }
            if(x>t->data){
                t=t->right;
            }
            else{
                t=t->left;
            }
        }
        cout<<"Not found::";
    }

    node* minimum(node* x){
        node* t= x;
        while(t->left){
            t=t->left;
        }
        return t;
    }

    void maximum(node* x){
        node* t=root;
        while(t->right){
            t=t->right;
        }
        cout<<"maximum value::"<<t->data;
    }

    node* successor(node* x){
        if(x->right!=nullptr){
            return minimum(x->right);
        }
        node *y=x->p;
        while(y!=nullptr && x==y->right){
            x=y;
            y=y->p;
        }
        return y;
    }

    void treeInsert(node* z){
        node* y= nullptr; //parent of x
        node* x=root;
        while(x){
            y=x;
            if(z->data<x->data){
                x=x->left;
            }
            else{
                x=x->right;
            }
        }
        z->p=y;
        if(y==nullptr){  //if tree is empty
            root=z;
        }
        else if(z->data<y->data){
            y->left=z;
        }
        else{
            y->right=z;
        }
    }
    void transplant(node* u, node* v){
        if(u->p==nullptr){
            root=v;
        }
        else if(u==u->p->left)
            u->p->left=v;
        else
        {
            u->p->right=v;
        }
        if(v!=nullptr){
            v->p=u->p;
        }
        
    }
    void treeDelete(node* z){
        if(z->left==nullptr){
            transplant(z,z->right);
        }
        else if(z->right==nullptr){
            transplant(z,z->left);
        }
        else{
            node* y= minimum(z->right);
            if(y->p!=z){
                transplant(y,y->right);
                y->right=z->right;
                y->right->p=y;
            }
            transplant(z,y);
            y->left=z->left;
            y->left->p=y;
        }
    }

    node *root;
};

int main()
{
    bst *tree = new bst();
    
    node *p = new node();
    p->data = 10;
    tree->root = p;
    
    node *q = new node();
    q->data = 2;
    q->p=p;
    p->left = q;
    
    node *r = new node();
    r->p=p;
    r->data = 15;
    p->right = r;

    tree->insert(21);
    // tree->insert(22);
    tree->insert(1);
    tree->insert(3);
    tree->insert(13);

    tree->inorder(tree->root);
                             // root
                        //    .  10  .
                        // 2           15
                     // 1    3      13    21
                       
    node* x= tree->recursiveSearch(tree->root, 3);

    // node* y=tree->successor(x);
    // cout<<endl<<y->data<<endl;   
    tree->treeDelete(x);
    cout<<endl;
    tree->inorder(tree->root);
}