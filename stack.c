#include <stdio.h>
#define MAX 3
int s[MAX];
int top;
void push(int);
int pop();
int peep();
void display();
main()
{
    int ch,data;
    top=-1;
    while(1)
    {
        printf("\n stack implementation using arrays");
        printf("\n 1. push");
        printf("\n 2.pop");
        printf("\n 3.peep");
        printf("\n 4.display");
        printf("\n 5.exit");
        printf("\n enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(top==MAX-1)
                    printf(" stack overflow\n");
                    else
                    {
                        printf("\n enter the data to be inserted:");
                        scanf("%d",&data);
                        push(data);
                    }
                    break;
            case 2: if(top==-1)
                    printf(" stack under flow\n");
                    else
                    printf("\n popped element is %d \n",pop());
                    break;
            case 3: if(top==-1)
                    printf(" stack under flow\n");
                    else
                    printf(" peeped element is %d",peep());
                    break;
            case 4: display();
                    break;
            default: exit(0);
            }
            }
}
            void push(int data)
            {
                s[++top]=data;
                printf("\n data pushed to stack successfully");
            }
            int pop()
            {
                return(s[top--]);
            }
            int peep()
            {
                return(s[top]);
            }
            void display()
            {
                int i;
                if(top==-1)
                printf(" stack is empty \n");
                else
                {
                    printf("\n stack contents are\n");
                    for(i=top;i>=0;i--)
                    printf("%d\n",s[i]);
                }
            }
