#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* newNode(int x){
    struct Node* node=(struct Node *)malloc(sizeof(struct Node));
    node->data= x;
    node->next=NULL;
    return node;
}

int main(){
    struct Node* root=newNode(1);
    root->next=newNode(2);
    root->next->next=newNode(3);
    root->next->next->next=newNode(4);
    root->next->next->next->next=newNode(5);

    struct Node* n=root;
    while(n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
}
