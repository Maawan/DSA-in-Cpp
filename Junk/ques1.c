#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *link;
}A;
struct node* insertElements(struct node* head){
    printf("\n Enter Value");
    int val;
    struct node* h = head;
    scanf("%d" , &val);
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = val;
    temp->link = NULL;
    if(head == NULL){
        return temp;
    }else{
        while(h->link != NULL){
            h = h->link;
        }
        h->link = temp;
    }
    return head;
}
void displayElements(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
}
struct node* deleteE(struct node* head , int key){
    if(key == head->data){
        return head->link;
    }
    struct node* temp = head;
    int i = 0;
    int found = 0;
    while(temp != NULL){
        if(key == temp->data){
            found = 1;
            break;
        }
        i++;
        temp = temp->link;
    }
    if(found == 0){
        printf("Element not found !!!");
        return;
    }
    temp = head;
    int j = 0;
    while(temp != NULL){
        if(j == (i-1)){
            break;
        }
        j++;
        temp = temp->link;
    }
    if(temp->link != NULL){
        temp->link = temp->link->link;
        printf("Successfully Deleted Element");
    }
    return head;
}
int main(){
    struct node *head = NULL;
    int n;
    printf("Program Developed by Mohd Mawan Ahmad");
    printf("\n Enter Number of Inputs you want to take\n");
    scanf("%d" ,&n);
    for(int i = 0 ;i < n ; i++){
        head = insertElements(head);
    }
    displayElements(head);
    int key ;
    printf("\n Enter the key Please ");
    scanf("%d" , &key);
    head = deleteE(head , key);
    displayElements(head);
    return 0;
}