%{
#include<stdio.h>
%}
%%
"#include".* {printf("%s\t Preprocessor directive\n",yytext);}
"void"|"int"|"float"|"char"|"if"|"else"|"for"|"do"|"while"|"switch"|"case"|"break"|"return"|"main" {printf("%s\tKeyword\n",yytext);}
[a-zA-Z] {printf("%s\tIdentifier\n",yytext);}                       // here [a-zA-Z]+ , + needed ,check
"%d"|"%c"|"%s" {printf("%s\tFormat specifier\n",yytext);}
"=" {printf("%s\tAssignment operator\n",yytext);}
"+"|"-"|"*"|"/" {printf("%s\tArithmetic operator\n",yytext);}
"<"|">"|"<="|">="|"!="|"==" {printf("%s\tRelational operator\n", yytext);}
"&&"|"|"|"||" {printf("%s\tLogical operator\n",yytext);}
"@"|"#"|"$"|"^"|"&"|"*" { printf("%s\tSpecial Symbols\n",yytext);}
[+-]?[0-9]*[.][0-9]+ {printf("%s\tReal number\n",yytext);}
[+-]?[0-9]+ {printf("%s\tWhole number\n",yytext);}
.|\n {;}                                                 // to ignore space and newline
%%
int main()
{
yyin=fopen("input.c","r+");
while(yylex());
}
Int yywrap()
{
}
