#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
}*start=NULL;
void DSLL_create()
{
    struct node *newnode,*current;
    int i,n;
    printf("Enter number of node of linked list:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Error.\n");
            exit(0);
        }
        printf("Enter data of node %d:\n",i+1);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
            current=newnode;
        }
        else
        {
            current->next=newnode;
            current=newnode;
        }
    }
}
void SLL_display()
{
    struct node *newnode=NULL;
    newnode=start;
    if(newnode==NULL)
    {
        printf("\nThere is no existing linked list.\n");
    }
    else
    {
    printf("Linked list is:",newnode->data);
    while(newnode->next!=NULL)
    {
        printf("%d-> ",newnode->data);
        newnode=newnode->next;
    }
    printf("%d-> ",newnode->data);
    printf("NULL... \n");
    }
}
SLL_Minsert()
{
    struct node *newnode,*temp,*tempo;
    if(start==NULL)
    {
        printf("Enter first node:\n");
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Error.\n");
            exit(0);
        }
       // printf("Enter data of node:\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        start=newnode;
    }
    else
    {
    int i,n;
    printf("Enter position after which node will be added:\n");
    scanf("%d",&n);
    //struct node *newnode,*temp,*tempo;
    temp=start;
    newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Error.\n");
            exit(0);
        }
        printf("Enter data of node:\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
            temp=newnode;
        }
        else
        {
        for(i=1;i<n;i++)
        {
            temp=temp->next;
        }
        tempo=temp->next;
        temp->next=newnode;
        newnode->next=tempo;
        }
    }
}
int SLL_search(int a)
{
    struct node *temp;
    int t=0,pos=1;
    temp=start;
    while(temp->next!=NULL)
    {
        if(temp->data==a)
        {
            t++;
            return pos;
        }
        temp=temp->next;
        pos++;
    }
    if(temp->next==NULL)
    {
    if(temp->data==a)
        {
            t++;
            return pos;
        }
    }
    if(t==0)
    {
        printf("Not found.\n");
        return 0;
    }
    else
    {
        printf("Found at %d.",pos);
        return pos;
    }

}
void SSL_delete(int b)
{
    int i;
    struct node *temp,*temp1,*tempo,*temp4;
    temp=start;
    if(b==1)
    {
        temp4=temp->next;
        start=temp4;
    }
    else
    {
    for(i=1;i<b-1;i++)
    {
        temp=temp->next;
    }
    temp1=temp->next;
    tempo=temp1->next;
    temp->next=tempo;
    }
}
int count()
{
    int z=0;
    struct node *temp;
    temp=start;
    while(temp->next!=NULL)
    {
        ++z;
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        z++;
        return z;
    }
}
int main()
{
    int n,pos,z;
    DSLL_create();
    SLL_display();
    SLL_Minsert();
    SLL_display();
    printf("Enter key to search:\n");
    scanf("%d",&n);
    pos=SLL_search(n);
    printf("Position is %d\n",pos);
    SSL_delete(pos);
    SLL_display();
    z=count();
    printf("Number of node is %d.\n",z);
}
