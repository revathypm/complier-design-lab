#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int n;
struct exp
{
    char op[10],op1[10],op2[10],res[10];
    int f;
}a[10];

void change(char *res1, int i);

void constant()
{
     int op1,op2,res,i;
     char res1[10],op;
     for(i=0;i<n;i++)
     {
         if(isdigit(a[i].op1[0]) && isdigit(a[i].op2[0]) || strcmp(a[i].op,"=")==0)  //here a[i].op
         {
             op1=atoi(a[i].op1);
             op2=atoi(a[i].op2);
             op=a[i].op[0];
             switch(op)
             {
                 case '+':res=op1+op2;
                          break;
                 case '-':res=op1-op2;
                          break;
                 case '*':res=op1*op2;
                          break;
                 case '/':res=op1/op2;
                          break;
                 case '=':res=op1;
                          break;
             }
             sprintf(res1,"%d",res);
             a[i].f=1;
             change(res1,i);  // here change(res1,i);
             
         }
     }
    
}
void output()
{
    for(int i=0;i<n;i++)
    {
        if(a[i].f==0)
        {
            printf("\n%s %s %s %s",a[i].op,a[i].op1,a[i].op2,a[i].res);
        }
    }
    
}
void change(char *res1, int i)
{
    for(int j=i+1;j<n;j++)
    {
        if(strcmp(a[j].op1,a[i].res)==0)
        strcpy(a[j].op1,res1);
        else if(strcmp(a[j].op2,a[i].res)==0)
        strcpy(a[j].op2,res1);
    }
    
}
 void main()
 {
     printf("enter no of exp::");
     scanf("%d",&n);
     printf("enter the input::\n");
     for(int i=0;i<n;i++)
     {
         scanf("%s",a[i].op);
         scanf("%s",a[i].op1);
         scanf("%s",a[i].op2);
         scanf("%s",a[i].res);
         a[i].f=0;
     }
     constant();
     output();
 }