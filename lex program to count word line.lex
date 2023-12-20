%{
#include<stdio.h>
int lc=0,wc=0,cc=0,sc=0;
%}
%%
[\n] {lc++; cc+=yyleng;} // space imp after ] and ;
[ \t] {sc++; cc+=yyleng;}
[^\t\n ]+ {wc++; cc+leng;}
%%
int main(int argc, char * argv[]) // here *
{
printf("enter::");
yylex();
printf("lc::%d\n",lc);
printf("sc::%d\n",sc);
printf("wc::%d\n",wc);
printf("cc::%d\n",cc);
}
int yywarp()
return 1;
}