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
        data = -11221;
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

    void treeInsert(int x){
        node* s=new node();
        s->data=x;
        treeInsert(s);
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
    void leftView(node* root, int level, int* maxlevel){
        if(root==nullptr)
            return;
        if(*maxlevel<level){
            cout<<" "<<root->data;
            *maxlevel=level;
        }
        leftView(root->left,level+1,maxlevel);
        leftView(root->right,level+1,maxlevel);
    }

    node *root;
};

int main()
{
    bst *tree = new bst();
    tree->treeInsert(12);
    tree->treeInsert(5);
    tree->treeInsert(18);
    tree->treeInsert(1);
    
    tree->preorder(tree->root);
    int m=0;
    cout<<endl;
    tree->leftView(tree->root,1,&m);
}