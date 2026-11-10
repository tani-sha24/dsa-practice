#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Node;
Node* createnode(int item)
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=item;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void inorder(Node* Node)
{
    if (Node==NULL)
        return;
    else
    {
        inorder(Node->left);
        printf("%d \n",Node->data);
        inorder(Node->right);
    }
}
void preorder(Node* Node)
{
    if (Node==NULL)
        return;
    else
    {
        printf("%d \n",Node->data);
        preorder(Node->left);
        preorder(Node->right);
    }
}
void postorder(Node* Node)
{
    if (Node==NULL)
        return;
    else
    {
        postorder(Node->left);
        postorder(Node->right);
        printf("%d \n",Node->data);
    }
}
Node* insert(Node* root,int value)
{
    if (root==NULL)
        return createnode(value);
    if (value < root->data)
        root->left=insert(root->left,value);
    if (value > root->data)
        root->right=insert(root->right,value);
    return root;
}
Node* deletenode(Node* root,int data)
{
    if (root==NULL)
        return root;
    else if(data < root->data)
    {
        root->left=deletenode(root->left,data);
        return root;
    }
    else if (data > root->data)
    {
        root->right=deletenode(root->right,data);
        return root;
    }
    else
    {
       if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->right == NULL)
        {
            Node* temp= root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            Node* temp= root->right;
            free(root);
            return temp;
        }
        else
        {
            Node* child= root->left;
            Node* parent=root;
            while(child->right)
            {
                parent=child;
                child=child->right;
            }
            if(root != parent)
            {
                parent->right=child->left;
                child->left=root->left;
                child->right=root->right;
                free(root);
                return child;
            }
            else
            {
                child->right=root->right;
                free(root);
                return child;
            }
        }
    }
}
int main()
{
    Node* root=NULL;
    int n,a,value;
    printf("enter number of nodes to insert:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter value %d:",i+1);
        scanf("%d",&value);
        root=insert(root,value);
    }
    printf("\n inorder traversal: ");
    inorder(root);
    printf("\n preorder traversal: ");
    preorder(root);
    printf("\n postorder traversal: ");
    postorder(root);
    printf("enter the value you want to delete:");
    scanf("%d",&a);
    root=deletenode(root,a);
    printf("after deletion:");
    printf("\n inorder traversal: ");
    inorder(root);
    printf("\n preorder traversal: ");
    preorder(root);
    printf("\n postorder traversal: ");
    postorder(root);
    return 0;
}
