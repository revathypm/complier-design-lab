#include<stdio.h>
#include<string.h>
void main()
{
char str[20],icode[20][20],op[20];
int i=0;
printf("enter 3 add code::(type exit to stop)\n");
do
{
scanf("%s",icode[i]);
}while(strcmp(icode[i++],"exit")!=0);

i=0;
printf("target code::\n");
do
{
strcpy(str,icode[i]);
switch(str[3])
{
case '+':strcpy(op,"ADD");
break;
case '-':strcpy(op,"SUB");
break;
case '*':strcpy(op,"MUL");
break;
case '/':strcpy(op,"DIV");
break;
}
printf("\n\tMOV %c,R%d",str[2],i);
printf("\n\t%s %c,R%d",op,str[4],i);
printf("\n\tMOV R%d,%c",i,str[0]);
}while(strcmp(icode[++i],"exit")!=0);
}