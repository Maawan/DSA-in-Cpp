#include<iostream>
#include<vector>
using namespace std;
typedef struct node{
    int val;
    struct node *left , *right;
    int height;
}Tree;
int max(int a , int b){
    return a > b ? a : b;
} 
int abs(int a){
    if(a >= 0){
        return a;
    }
    return -1 * a;
}
Tree* createNode(int v){
    Tree* node = new Tree();
    node->val = v;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int getHeight(Tree* root){
    if(root == NULL) return 0;
    return root->height;
}
int getBalanceFactor(Tree* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 0;
    if(root->left == NULL){
        return -1 * getHeight(root->right);
    }
    if(root->right == NULL){
        return getHeight(root->left);
    }
    return getHeight(root->left) - getHeight(root->right);
}
Tree* insertVal(Tree* root , int val){
    if(root == NULL){
        return createNode(val);
    }
    if(root->val > val){
        root->left = insertVal(root->left , val);
    }else{
        root->right = insertVal(root->right , val);
    }
    root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
    if(abs(getBalanceFactor(root)) > 1){
        cout << "Tree is Imbalance " << endl;
    }
    return root;
}
bool isBalanced(Tree* root){
    if(root == NULL) return true;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    if(abs(left - right) == 0 || abs(left - right) == 1){
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        if(l && r) return true;
    }
    return false;
} 
void inOrder(Tree* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}
int main(){
    Tree* root = NULL;
    vector<int> vals = {4,5,2};
    for(int i = 0 ; i < vals.size() ; i++){
        root = insertVal(root , vals[i]);
    }
    inOrder(root);
    return 0;
}