#include <stdio.h>
#include<malloc.h>
void create_SLL();
void display_SLL();
void search_SLL();
void insert_first_SLL();
void insert_last_SLL();
void insert_pos_SLL();
void delete_first_SLL();
void delete_last_SLL();
void delete_pos_SLL();
struct node
{
    int data;
    struct node*next;
};
struct node*start=NULL;
int main()
{
    int choice;
    while(1)
{
    printf("\n 1.create singly linked list");
    printf("\n 2.display the content of singly linked list");
    printf("\n 3.search a key in a singly linked list");
    printf("\n 4.insert at first position");
    printf("\n 5.insert at last position");
    printf("\n 6.insert at position");
    printf("\n 7.delete the key element at first position");
    printf("\n 8.delete the key element at last position");
    printf("\n 9.delete the key element at position");
    printf("\n enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:create_SLL();break;
        case 2:display_SLL();break;
        case 3:search_SLL();break;
        case 4:insert_first_SLL();break;
        case 5:insert_last_SLL();break;
        case 6:insert_pos_SLL();break;
        case 7:delete_first_SLL();break;
        case 8:delete_last_SLL();break;
        case 9:delete_pos_SLL();break;
        default:exit(0);
    }
}
}

void create_SLL()
{
    int i,n;
    char choice;
    struct node*ntemp;
    printf("enter the no of nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        ntemp=(struct node*)malloc(sizeof(struct node));
        printf("\n enter the data to be inserted:");
        scanf("%d",&ntemp->data);
        ntemp->next=NULL;
        if(start==NULL)
            start=ntemp;
        else
        {
            ntemp->next=start;
            start=ntemp;
        }
        scanf("%c",&choice);
    }
        printf("\n singly linked list created\n");
}

void display_SLL()
{
    struct node*temp;
    int count=0;
    if(start==NULL)
        printf("singly linked list is empty");
    else
    {
        printf("\n contents of singly licked list are\n ");
        for(temp=start;temp!=NULL;temp=temp->next)
        {
            printf("%d->",temp->data);
            count++;
        }
        printf("\n total nodes in singly linked list is %d",count);
    }
}

void search_SLL()
{
    struct node*temp;
    int key,flag=0;
    printf("\n enter key to be searched in SLL:");
    scanf("%d",&key);
    if(start==NULL)
        printf("singly linked list is empty!!!search connot be done\n");
    else
    {
        temp=start;
        while(temp!=NULL)
        {
            if(temp->data==key)
            {
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==0)
            printf("\n key not found in SLL\n");
        else
            printf(" key found in SLL\n");
        }
}

void insert_first_SLL()
{
    struct node*ntemp;
    ntemp=(struct node*)malloc(sizeof(struct node));
    printf("\n enter the data to be inserted at begining of SLL:");
    scanf("%d",&ntemp->data);
    ntemp->next=NULL;
    if(start==NULL)
        start=ntemp;
    else
    {
        ntemp->next=start;
        start=ntemp;
    }
    printf("\n new node inserted at first position\n");
}

void insert_last_SLL()
{
    struct node*ntemp,*cur;
    ntemp=(struct node*)malloc(sizeof(struct node));
    printf(" enter the data to be inserted at last position of SLL\n");
    scanf("%d",&ntemp->data);
    ntemp->next=NULL;
    if(start==NULL)
    printf("\n empty SLL insertion cannot be performed at last position\n");
    else
    {
        cur=start;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=ntemp;
        printf("\n new node inserted at last position\n");
    }
}

void insert_pos_SLL()
{
    struct node*ntemp,*prev,*cur,*tprev;
    int count,pos;
    ntemp=(struct node*)malloc(sizeof (struct node));
    ntemp->next=NULL;
    printf("enter data for new node to be inserted\n");
    scanf("%d",&ntemp->data);
    printf("\n enter the position for insertion:");
    scanf("%d",&pos);
    if(start==NULL &&pos>1)
    {
        printf("invalid position");
        return;
    }
    if(pos==1)
    {
        ntemp->next=start;
        start=ntemp;
        return;
    }
    count=1;
    prev=NULL;
    cur=start;
    while(cur!= NULL&& count!=pos)
    {
        tprev=cur;
        cur=cur->next;
        count++;
    }
    if(count==pos)
    {
        tprev->next=ntemp;
        ntemp->next=cur;
    }
    else
    {
        printf("invalid data position !! insertion connot be done in SLL\n");
    }
}

void delete_first_SLL()
{
    struct node*temp;
    if(start==NULL)
    printf(" display deletion not possible !!! SLL empty\n");
    else
    {
        temp=start;
        printf(" node delete at first position is %d\n",start->data);
        start=start->next;
        free(temp);
    }
}

void delete_last_SLL()
{
    struct node*cur,*tprev,next;
    if(start==NULL)
    {
        printf("\n emoty SLL deletion cannot be done");
        return;
    }
    if(start->next==NULL)
    {
        printf("node deleted at last position is %d",start->data);
        start=NULL;
        return;
    }
    cur=start;
    tprev=NULL;
    while(cur->next!=NULL)
    {
        tprev=cur;
        cur=cur->next;
    }
    printf("node deleted at last position is %d",cur->data);
    tprev->next=NULL;
    free(cur);
}

void delete_pos_SLL()
{
    struct node*tnext,*tprev,*cur;
    int count,pos;
    if(start==NULL)
    {
        printf("empty SLL !!! deletion connot be done\n");
        return;
    }
    printf("\n enter the position for deletion \n");\
    scanf("%d",&pos);
    count=1;
    tprev=NULL;
    cur=start;
    while(cur!=NULL && count !=pos)
    {
        tprev=cur;
        cur=cur->next;
        count++;
    }
    if(cur==NULL)
    {
        printf("\n invalid position !!! deletion cannot be done\n");
        return;
    }
    if(count==pos)
    {
        if(pos==1)
        {
            printf("node deleted is %d",cur->data);
            start=start->next;
            return;
        }
    else
    {
        tnext=cur->next;
        tprev->next=tnext;
        printf("\n node deleted is %d\n",cur->data);
        free(cur);
        return;
    }
    }
}
