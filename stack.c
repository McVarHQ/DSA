#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* push(struct node *top,int x)
{   
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top;
    top=temp;
    return top;
}
void printstack(struct node *top)
{
    struct node *printer=(struct node*)malloc(sizeof(struct node));
    printer=top;
    while(printer!=NULL)
    {
        printf("%d ",printer->data);
        printer=printer->next;
    }
}
struct node* pop(struct node *top)
{
    if(top!=NULL)
    {
        struct node *temp=top;
        top=top->next;
        free(temp);
        return top;
    }
}
int main()
{
    int n;
    struct node* head=(struct node*)malloc(sizeof(struct node)),*ptr,*top;
    head->next=NULL;
    printf("Enter head node value:");
    scanf("%d",&head->data);
    top=head;
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        printf("Enter node %d value:",i);
        scanf("%d",&x);
        top=push(top,x);
    }
    printf("Stack using linked list:");
    printstack(head);
    printf("\n");
    printf("Stack after pop operation:");
    top=pop(top);
    printstack(head);
    printf("\n");
}