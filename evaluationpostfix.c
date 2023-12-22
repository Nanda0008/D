#include <stdio.h>
#include<math.h>
#include<ctype.h>
float eval();
char postfix[10];
main()
{
    float result;
    printf("\n enter the postfix expression terminated by #\n");
    fgets(postfix, sizeof(postfix), stdin);
    result=eval();
    printf("\n result of postfix evaluation is %f",result);
    return(0);
}
float eval()
{
    int i=0,Top=-1;
    float s[15],op1,op2;
    char ch;
    while(((ch=postfix[i++]))!='#'){
        if(isdigit(ch))
            s[++Top]=(ch-'0');
            else {
                op1=s[Top--];
                op2=s[Top--];
                switch(ch) {
                    case '+':
                        s[++Top]=op2+op1;
                        break;
                    case '-':
                        s[++Top]=op2-op1;
                        break;
                    case '*':
                        s[++Top]=op2*op1;
                        break;
                    case '/':
                        s[++Top]=op2/op1;
                        break;
                    case '^':
                        s[++Top]=pow(op2,op1);
                        break;
                    default:
                        printf("\n invalid option\n");
                    return -1;
                }
            }
    }
    return(s[Top]);
}

