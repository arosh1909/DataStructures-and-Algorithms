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
    node *root;

    bst()
    {
        root = nullptr;
    }

    void insert(int x)
    {
        node *prev = nullptr;
        node *temp = root;

        while (temp)
        {
            prev = temp;
            if (temp->data < x)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        node *newNode = new node();
        newNode->data = x;
        if (x > prev->data)
        {
            prev->right = newNode;
            newNode->p = prev;
        }
        else
        {
            prev->left = newNode;
            newNode->p = prev;
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

    void preorder(node *p)
    {
        if (p != nullptr)
        {
            cout << " " << p->data;
            preorder(p->left);
            preorder(p->right);
        }
    }

    node *recursiveSearch(node *p, int x)
    {
        if (p == nullptr || p->data == x)
            return p;
        if (x < p->data)
            return recursiveSearch(p->left, x);
        else
            return recursiveSearch(p->right, x);
    }

    //Iterative
    void search(int x)
    {
        node *t = root;
        while (t)
        {
            if (t->data == x)
            {
                cout << "found::";
                return;
            }
            if (x > t->data)
            {
                t = t->right;
            }
            else
            {
                t = t->left;
            }
        }
        cout << "Not found::";
    }

    node *minimum(node *x)
    {
        node *t = x;
        while (t->left)
        {
            t = t->left;
        }
        return t;
    }

    void maximum(node *x)
    {
        node *t = root;
        while (t->right)
        {
            t = t->right;
        }
        cout << "maximum value::" << t->data;
    }

    node *successor(node *x)
    {
        if (x->right != nullptr)
        {
            return minimum(x->right);
        }
        node *y = x->p;
        while (y != nullptr && x == y->right)
        {
            x = y;
            y = y->p;
        }
        return y;
    }

    void treeInsert(int x)
    {
        node *s = new node();
        s->data = x;
        treeInsert(s);
    }
    void treeInsert(node *z)
    {
        node *y = nullptr; //parent of x
        node *x = root;
        while (x)
        {
            y = x;
            if (z->data < x->data)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }
        z->p = y;
        if (y == nullptr)
        { //if tree is empty
            root = z;
        }
        else if (z->data < y->data)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }
    }
    void transplant(node *u, node *v)
    {
        if (u->p == nullptr)
        {
            root = v;
        }
        else if (u == u->p->left)
            u->p->left = v;
        else
        {
            u->p->right = v;
        }
        if (v != nullptr)
        {
            v->p = u->p;
        }
    }
    void treeDelete(node *z)
    {
        if (z->left == nullptr)
        {
            transplant(z, z->right);
        }
        else if (z->right == nullptr)
        {
            transplant(z, z->left);
        }
        else
        {
            node *y = minimum(z->right);
            if (y->p != z)
            {
                transplant(y, y->right);
                y->right = z->right;
                y->right->p = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->p = y;
        }
    }
    void leftView(node *root, int level, int *maxlevel)
    {
        if (root == nullptr)
            return;
        if (*maxlevel < level)
        {
            cout << " " << root->data;
            *maxlevel = level;
        }
        leftView(root->left, level + 1, maxlevel);
        leftView(root->right, level + 1, maxlevel);
    }
    void checkBST(node *s, int &flag)
    {
        if (s != nullptr && flag == 0)
        {
            if (s->left != nullptr)
            {
                if (s->data > s->left->data)
                {
                    checkBST(s->left, flag);
                }
                else
                {
                    cout << "0";
                    flag = 1;
                }
            }

            if (s->right != nullptr)
            {
                if (s->right->data > s->data)
                {
                    checkBST(s->right, flag);
                }
                else
                {
                    cout << "0";
                    flag = 1;
                }
            }
        }
    }
    int checkBST2(node *node)
    {
        if (node == NULL)
            return 1;

        /* false if left is > than node */
        if (node->left != NULL && node->left->data > node->data)
            return 0;

        /* false if right is < than node */
        if (node->right != NULL && node->right->data < node->data)
            return 0;

        /* false if, recursively, the left or right is not a BST */
        if (!checkBST2(node->left) || !checkBST2(node->right))
            return 0;

        /* passing all that, it's a BST */
        return 1;
    }
};

int main()
{
    bst *tree = new bst();
    tree->treeInsert(12);
    tree->treeInsert(5);
    tree->treeInsert(18);
    tree->treeInsert(111);
    tree->treeInsert(81);
    tree->treeInsert(31);
    tree->treeInsert(1100);
    tree->treeInsert(19);
    // node *x = new node();
    // x->data = 10;
    // tree->root->left->left = x;

    // Question1:
    // tree->preorder(tree->root);
    // int m=0;
    // cout<<endl;
    // tree->leftView(tree->root,1,&m);

    // Question2:
    int flag = 0;
    // tree->checkBST(tree->root, flag);
    cout<<tree->checkBST2(tree->root);
}