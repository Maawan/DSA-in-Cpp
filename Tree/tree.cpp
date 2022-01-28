#include<iostream>
#include<vector>
using namespace std;
typedef struct node {
    int data;
    struct node *left , *right;
}Tree;
void insertElements(Tree** root ,int data){
    if(*root == NULL){
        (*root) = new Tree(); 
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
        
    }
    if((*root)->data > data){
        insertElements(&((*root)->left) , data);
    }else{
        insertElements(&((*root)->right) , data);
    }
   
}

void display(Tree* root){
    if(root == NULL) return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}
Tree* getPostSuffix(Tree* root){
    while(root->left != NULL){
        root = root -> left;
    }
    return root;
}
Tree* deleteElement(Tree* root , int element){
    if(root == NULL){
        cout << "Oops ! Element not Found ";
        return NULL;
    }
    if(root->data == element){
        if(root->left == NULL || root->right == NULL){
            if(root->left != NULL){
                return root->left;
            }
            if(root->left != NULL){
                return root->left;
            }
            return NULL;
        }
        if(root->left != NULL && root->right != NULL){
            Tree* post = getPostSuffix(root->right);

            root = deleteElement(root->right , post->data);
            post->left = root->left;
            post->right = root->right;
            return post;
        }
    }
    if(root->data > element){
        root->left = deleteElement(root->left , element);
    }else{
        root->right = deleteElement(root->right , element);
    }
    return root;
}
int main(){
    Tree* root = NULL;
    vector<int> v = {1,2,3,1,2,9,5,4,834,75,45,34,6,7,54,3,43,23,32};
    for(int i = 0 ; i < v.size() ; i++){
        insertElements(&root , v[i]);
    }
    root = deleteElement(root , 23);
    display(root);
    
    return 0;
}