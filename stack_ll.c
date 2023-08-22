#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
    int val;
    struct node *link;
};

int isEmpty(struct node *top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct node* push(struct node *top, int k){
    struct node *temp=(struct node*) malloc(sizeof(struct node));
    temp->val=k;
    temp->link=NULL;
    temp->link=top;
    top=temp;
}

struct node* pop(struct node *top){
    if (isEmpty(top)==1){
        printf("Underflow");
    }
    else{
        struct node *temp=top;
        top=top->link;
        free(temp);
    }
    return top;
}

int decode(struct node *top){
    switch (top->val)
    {
    case 0:
        return 2;
        break;
    case 1:
        return 1;
        break;
    case 2:
        return 5;
        break;
    case 3:
        return 6;
        break;
    case 4:
        return 7;
        break;
    case 5:
        return 3;
        break;
    case 6:
        return 0;
        break;
    case 7:
        return 9;
        break;
    case 8:
        return 8;
        break;
    case 9:
        return 4;
        break;
    
    default:
        break;
    }
}

void display(struct node *top){
    struct node *ptr=top;
    while(ptr!=NULL){
        printf("%d", &ptr->val);
        ptr=ptr->link;
    }
}

int main(){
    struct node *top1=(struct node*)malloc(sizeof(struct node));
    struct node *top2=(struct node*)malloc(sizeof(struct node));
    top1->link=NULL;
    top2->link=NULL;
    int n1, n2, x;
    int a=0, b=0, sum=0;
    printf("Enter no of digits of 1st number:\n");
    scanf("%d", &n1);
    printf("Enter digits of 1st number:\n");
    scanf("%d", &top1->val);
    for (int i=0; i<n1-1; i++){
        scanf("%d", &x);
        top1=push(top1, x);
    }

    printf("Enter no of digits of 2nd number:\n");
    scanf("%d", &n2);
    printf("Enter digits of 2nd number:\n");
    scanf("%d", &top2->val);
    for (int i=0; i<n2-1; i++){
        scanf("%d", &x);
        top2=push(top2, x);
    }

    int p=n1-1;
    while(top1!=NULL){
        a+=(top1->val)*(pow(10, p));
        top1=pop(top1);
        p--;
    }

    p=n2-1;
    while(top2!=NULL){
        b+=(top2->val)*(pow(10, p));
        top2=pop(top2);
        p--;
    }

    printf("The new number formed are\n%d\n%d", a, b);


    return 0;
}

