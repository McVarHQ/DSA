#include<stdio.h>
#include<stdlib.h>
//deletion of node
int count=0;
int nodelist[100];
int leaves=0;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* insert(struct node *root,int x)
{
    if(root==NULL)
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    if(x<root->data)
    {
        root->left=insert(root->left,x);
    }
    if(x>root->data)
    {
        root->right=insert(root->right,x);
    }
    return root;
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        nodelist[count]=root->data;
        count++;
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int minimum(struct node *root)
{
    if(root->left!=NULL)
    {
        minimum(root->left);
    }
    else
    {
        printf("Minimum element of tree is:%d",root->data);
        return 0;
    }
}
int maximum(struct node *root)
{
    if(root->right!=NULL)
    {
        maximum(root->right);
    }
    else
    {
        printf("Maximum element of tree:%d",root->data);
        return 0;
    }
}
void kth(int k)
{
    if(k>0 && k<=count)
    {
        printf("maximum element %d:%d",k,nodelist[count-k]);
        printf("\n");
        printf("minimum element %d:%d",k,nodelist[k-1]);
        printf("\n");
    }
    else
    {
        printf("Invalid k value");
        printf("\n");
    }
}
int search(struct node *root,int x)
{
    if(root!=NULL)
    {
        if(x<root->data)
        {
            search(root->left,x);
        }
        if(x>root->data)
        {
            search(root->right,x);
        }
        if(x==root->data)
        {
            printf("Element %d found",x);
            return 1;
        }
    }
    else
    {
        printf("Element %d not found",x);
        return 0;
    }
}
void children(struct node *root)
{
    if(root->left!=NULL)
    {
        printf("\nLeft child of %d:%d",root->data,root->left->data);
    }
    if(root->right!=NULL)
    {
        printf("\nRight child of %d:%d",root->data,root->right->data);
    }
}
void leaf(struct node *root)
{
    if(root!=NULL)
    {
        if(root->left==NULL && root->right==NULL)
        {
            leaves++;
            printf("\n%d is a leaf node",root->data);
        }
        if(root->left!=NULL || root->right!=NULL)
        {
            children(root);
        }
        leaf(root->left);
        leaf(root->right);
    }
}
int main()
{
    int n,k,s;
    struct node *root=NULL;
    printf("Enter number of elements:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        printf("Enter element %d value:",i);
        scanf("%d",&x);
        root=insert(root,x);
    }
    printf("Inorder traversal:");
    inorder(root);
    printf("\n");
    printf("Preorder traversal:");
    preorder(root);
    printf("\n");
    printf("Postorder traversal:");
    postorder(root);
    printf("\n");
    printf("Number of nodes:");
    printf("%d",count);
    printf("\n");
    minimum(root);
    printf("\n");
    maximum(root);
    printf("\n");
    printf("Enter value of k:");
    scanf("%d",&k);
    kth(k);
    printf("Enter element to be searched:");
    scanf("%d",&s);
    search(root,s);
    printf("\n");
    leaf(root);
    printf("\nNumber of leaf nodes:");
    printf("%d",leaves);
    printf("\n");
}

