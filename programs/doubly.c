#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
    struct node*prev;
}Node;
void print_DLL(Node *head)
{
    Node *temp=head;
    if (head==NULL)
        printf("\n overflow");
    else
    {
        while(temp!=NULL)
        {
            printf(" %d",temp->data);
            temp=temp->next;
        }
    }
}
Node *insert_begin(Node *head,int d)
{
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=d;
    newnode->next=newnode->prev=NULL;
    if (head==NULL)
        printf("\n overflow");
    else 
    {
        head->prev=newnode;
        newnode->next=head;
    }
    head=newnode;
    return head;
}
Node *insert_end(Node *tail,int d)
{
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=d;
    newnode->next=newnode->prev=NULL;
    if (tail==NULL)
        printf("\n overflow");
    else
    {
            newnode->prev=tail;
            tail->next=newnode;
    }
    tail=newnode;
    return head; 
}
Node *insert_position(Node *head,int d)
{
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=d;
    newnode->next=newnode->prev=NULL;
    Node* temp;
    int loc;
    if (head==NULL)
        printf("\n overflow");
    else 
    {
        printf("enter location:");
        scanf("%d",&loc);
        temp=head;
        while(temp->data!=loc)
            temp=temp->next;
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        temp->next->prev=newnode;
        return head;
    }
}
Node *insert_spnode(Node *head,int d)
{
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=d;
    newnode->next=newnode->prev=NULL;
    Node* temp;
    int key;
    if (head==NULL)
        printf("\n overflow");
    else 
    {
        printf("enter key:");
        scanf("%d",&key);
        temp=head;
        while(temp->data!=key)
            temp=temp->next;
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        temp->next->prev=newnode;
        return head;
    }
Node *del_begin(Node *head)
{
    node *temp=head;
    if (head==NULL)
        printf("overflow");
    else 
    {
        head->next->prev=NULL;
        head=head->next;
        free(temp);
        return head;
    }
}
Node *del_end(Node *head)
{
    node *temp=head;
    if (head==NULL)
        printf("overflow");
    else 
    {
        while(temp->next!=NULL)
            temp=temp->next;
        temp=NULL;
        free(temp);
        return head;
    }
}       
Node *del_key(Node *head,int key)
{
    node *temp=head;
    if (head==NULL)
        printf("overflow");
    else 
    {
        while(temp->data!=NULL)
            temp=temp->next;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        return head;
    }
}
Node *del_pos(Node *head,int loc)
{
    node *temp=head;
    int loc;
    if (head==NULL)
        printf("overflow");
    else 
    {
        printf("enter location:");
        scanf("%d",&loc);
        while(temp->next!=NULL)
            temp=temp->next;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        return head;
    }
}
void search(node *head)
{
    node *temp=head;
    int key;
    if (head==NULL)
        printf("\n overflow");
    else
    {
        printf("enter key to be searched:");
        scanf("%d",&key);
        while(temp->data==key)
        {
            printf(" %d",temp->data);
        }
    }
}
int main()
{
    Node *head=(Node *)malloc(sizeof(Node));
    head->data=2;
    head->prev=head->next=NULL;
    int ch=0;
    while(ch>=10)
    {
        printf("\n 1. insert at beginning \n 2. insert at end \n 3. insert at specific position \n 4. insert after specific node \n 5.delete from beginning \n 6. delete at end \n 7. delete from specifc position \n 8. delete after particular key \n 9. print doubly linked list \n 10. search \n 11. exit");
        printf("enter your choice:");
        scanf("&d",&ch);
        switch(ch)
        {
            case 1:
            insert_begin();
            break;
            case 2:
            insert_end();
            break;
            case 3:
            insert_position();
            break;
            case 4:
            insert_spnode();
            break;
            case 5:
            del_begin();
            break;
            case 6:
            del_end();
            break;
            case 7:
            del_pos();
            break;
            case 8:
            del_key();
            break;
            case 9:
            print_DLL();
            break;
            case 10;
            search();
            break;
            default:
            printf("enter valid choice");
            exit(0);
        }
    }

}