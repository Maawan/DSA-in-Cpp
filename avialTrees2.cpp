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
Tree* LLRotation(Tree* root){
    Tree* rightNode = root;
    Tree* nextLeftNode = root->left->right;
    root = root->left;
    root->right = rightNode;
    root->right->left = nextLeftNode;
    root->right->height = 1 + max(getHeight(root->right->left) , getHeight(root->right->right));
    root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
    return root;
}
Tree* RRRotation(Tree* root){
    Tree* leftNode = root;
    Tree* nextRight = root->right->left;
    root = root->right;
    root->left = leftNode;
    root->left->right = nextRight;
    root->left->height = 1 + max(getHeight(root->left->left) , getHeight(root->left->right));
    return root;
}
Tree* LRroTation(Tree* root){
    root->left = RRRotation(root->left);
    return LLRotation(root);
}
Tree* RlRotation(Tree* root){
    root->right = LLRotation(root->right);
    return RRRotation(root);
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
    int bf = getBalanceFactor(root);
    if(abs(getBalanceFactor(root)) > 1){
        cout << "Tree is Imbalance " << endl;
    }
    if(bf > 1){
        if(root->left != NULL){
            if(root->left->val > val){
                cout << "Its a case of LL ROtation" << endl;
                return LLRotation(root);
            }else if(root->left->val < val){
                cout << "Its a case of LR Rotataion " << endl;
                return LRroTation(root);
            }
            
        }
    }else if(bf < -1){
        if(root->right != NULL){
            if(root->right->val < val){
                cout << "Its a Case of RR Rotation " << endl;
                return RRRotation(root);
            }else{
                cout << "Its a Case of RL Rotation " << endl;
                return RlRotation(root);
            }
        }
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
    vector<int> vals = {3,5,4};
    for(int i = 0 ; i < vals.size() ; i++){
        root = insertVal(root , vals[i]);
    }
    inOrder(root);
    if(isBalanced(root)){
        cout << " Yes ! Your Tree is Balanced :) " << endl;
    }else{
        cout << " Oops ! Tree is getting Imbalanced :( " << endl;
    }
    return 0;
}