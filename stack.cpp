*/ Code Contributed by Mohd Mawan Ahmad */
#include<iostream>
using namespace std;
typedef struct node{
    int data;
    struct node* link;
}Node;

Node* getNewNode(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->link = NULL;
    return node;
}
void insertInStack(Node** top , int value){
    if(top == NULL){
        (*top) = getNewNode(value);
    }else {
        Node* node = getNewNode(value);
        node->link = (*top);
        (*top) = node;
    }
}
int pop(Node** top){
    int ele = (*top)->data;
    (*top) = (*top)->link;
    return ele;

}
bool isEmpty(Node** top){
    if((*top) == NULL) return true;
    return false;
}
void display(Node** top){
    cout << "Normal Order of Elements " << endl;
    Node* temp = (*top);
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->link;
    }
}
void reverseDisplay(Node** top){
    if(isEmpty(top)) return;
    int ele = pop(top);
    reverseDisplay(top);
    cout << ele << " ";
}
int main(){
    Node* top = NULL;
    int n;
    cout << "Enter Elements " << endl;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int ele;
        cin >> ele;
        insertInStack(&top , ele);
    }
    display(&top);
    reverseDisplay(&top);
}
