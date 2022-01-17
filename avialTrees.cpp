#include<iostream>
#include<vector>
using namespace std;
typedef struct node {
    int val;
    struct node* left , *right;
    int height;
}Tree;
int max(int a , int b){
    return a > b ? a : b;
}
int abs(int val){
    if(val > 0) return val;
    return -1 * val;
}
Tree* createNewNode(int data){
    Tree* node = new Tree();
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    node->val = data;
    
    return node;
}
int getHeight(Tree* root){
    if(root == NULL) return 0;
    return root->height;
}
bool isBalanced(Tree* root){
    if(root == NULL) return true;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    if(abs(left - right)== 1 || abs(left - right) == 0){
        bool isLeft = isBalanced(root->left);
        bool isRight = isBalanced(root->right);
        if(isLeft && isRight) return true;
    }
    return false;
}

int getBalancedFactor(Tree* root){
    if(root == NULL) return 0;
    if(root->left == NULL) {
        return -1 * getHeight(root->right);
    }
    if(root->right == NULL){
        return getHeight(root->left);
    }
    return getHeight(root->left) - getHeight(root->right);
}
Tree* LLRotation(Tree* root){
    Tree* rightNode = root;
    Tree* nextLeft = root->left->right;
    root = root->left;
    root->right = rightNode;
    root->right->left = nextLeft;
    root->right->height = 1 + max(getHeight(root->right->right) , getHeight(root->right->left));
    root->height = 1 + max(getHeight(root->right) , getHeight(root->left));
    return root;
}
Tree* RrRotataion(Tree* root){
    Tree* leftNode = root;
    Tree* nectRight = root->right->left;
    root = root->right;
    root->left = leftNode;
    root->left->right = nectRight;
    root->left->height = 1 + max(getHeight(root->left->left) , getHeight(root->left->right));
    root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
    return root;
}
Tree* LRroTation(Tree* root){
    root->left = RrRotataion(root->left);
    root = LLRotation(root);
    return root;
}
Tree* RLRotation(Tree* root){
    root->right = LLRotation(root->right);
    root = RrRotataion(root);
    return root;
}
Tree* insertVals(Tree* root , int key){
    if(root == NULL){
        return createNewNode(key);
    }
    if(root->val > key){
        root->left = insertVals(root->left , key);
    }else{
        root->right = insertVals(root->right , key);
    }
    root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
    int bf = getBalancedFactor(root);
    if(abs(bf) > 1){
        cout << "Node " << root->val << " is ImBalanced" << endl;
    }
    if(bf < -1){
        if(root->right != NULL){
            if(root->right->val < key){
                cout << "This is a Case of RR ROtation " << endl;
                return RrRotataion(root);
            }else if(root->right->val > key){
                cout << "THis is a Case of RL Rotataion " << endl;
                return RLRotation(root);
            }
        }
        
    }else if(bf > 1){
        if(root->left != NULL){
            if(root->left->val > key){
                cout << "This is a case of LL Rotataion " << endl;
                return LLRotation(root);
            }else if(root->left->val < key){
                cout << "This is a case of LR Rotataion " << endl;
                return LRroTation(root);
            }
        }
    }
    return root;
}
bool isElementExist(Tree* root , int key , int& count){
    if(root == NULL) return false;
    if(root->val == key) {
        
        return true;
    }
    count++;
    if(root->val > key){
        return isElementExist(root->left , key , count);
    }else{
        return isElementExist(root->right , key , count);
    }
}
int main(){
    vector<int> list = {1,2,3,4,5,6,7,8,9 ,10,11,12,13,14,15,16,17,18,19,20};
    Tree* root = NULL;
    for(int i = 0 ; i < list.size() ; i++){
        root = insertVals(root , list[i]);
    }
    if(isBalanced(root)){
        cout << "Tree is Completely Balanced :) " << endl;
    }else{
        cout << "Oops ! Your Tree is not Completly Balanced " << endl;
    }
    int count = 0;
    if(isElementExist(root  , 500 , count)){
        cout << "Yes with " << count << " Number of Searching" << endl;
    }else{
        cout << "No " << count << endl;
    }
    return 0;
}
