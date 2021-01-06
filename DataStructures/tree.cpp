#include <iostream>

using namespace std;

class treeNode{
    private:
        treeNode* left;
        treeNode* right;
        int data;
    public: 
        treeNode(){
            left=right=nullptr;
            data=-1;
        }
};

class tree{
    private:
        treeNode* root;
    public:           
        tree(){
            root=nullptr;
        }
        void insert(){

        }
        void search(){
            
        }

};

int main(){

}