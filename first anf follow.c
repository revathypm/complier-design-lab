
#include<stdio.h>
#include<ctype.h>

int cnt,col,num;
char a[8][8],b[8];     //cnt=0;


struct first
{
    int n;
    char f[5];
}first[5];

struct follow
{
    int n;
    char f[5];
}follow[5];

void findfirst(char ip, int pos)
{
   for(int i=0;i<num;i++)
   {
       if(ip==a[i][0])                        //no ; here
       {
            if(isupper(a[i][3]))
             findfirst(a[i][3],pos);
            else
             {
                 first[pos].f[col]=a[i][3];
                 first[pos].n++;
                 col++;
             }
       }
   }
}
void foltabop(char nt ,int pos)
{
    for(int i=0;i<cnt;i++)
    {
        if(nt==follow[i].f[0])
        {
            for(int j=0;j<=follow[i].n;j++)         //j=1 keep in mind
            {
                follow[pos].f[col]=follow[i].f[j];
                follow[pos].n++;
                col++;
            }
        }
    }
}
void firtabop(char nt ,int pos)
{
    for(int i=0;i<cnt;i++)
    {
        if(nt==a[i][0])
        {
            for(int j=0;j<=first[i].n;j++)              //j=1 keep in mind
            {
                follow[pos].f[col]=first[i].f[j];
                follow[pos].n++;
                col++;
            }
        }
    }
}
void findfollow(char nt,int pos)
{
    for(int i=0;i<cnt;i++)
    {
        for(int j=3;j<7;j++)
        {
            if(pos==0&&col==1)
            {
                follow[pos].f[col]='$';
                follow[pos].n++;
                col++;
            }
            if(nt==a[i][j])
            {
                if(a[i][j+1]=='\0')
                {
                 if(a[i][j]!=a[i][0])
                   foltabop(a[i][0],pos);
                }
                else if(isupper(a[i][j+1]))
                {
                 if(a[i][j+1]!=a[i][0])
                   firtabop(a[i][j+1],pos);
                }
                else
                {
                   follow[pos].f[col]=a[i][j+1];
                   follow[pos].n++;
                   col++;
                }
            }
        }
    }
}
void main()
 {
     int i,j,c=0;
     printf("enter::");
     scanf("%d",&num);
     
     for(i=0;i<num;i++)
     {
         scanf("%s",a[i]);   // read prod
     }
     
     for(i=0;i<num;i++)
     {
         c=0;
         for(j=0;j<i+1;j++)
         {
             if(a[i][0]==b[j])
             {
             c=1;
             break;
             }
         }
         if(c!=1)
         {
             b[cnt]=a[i][0];
             cnt++;
         }
     }
     
     for(i=0;i<cnt;i++)
     {
         col=1;
         first[i].f[0]=b[i];
         first[i].n=0;
         findfirst(b[i],i);
     }
     
     for(i=0;i<cnt;i++)
     {
         col=1;
         follow[i].f[0]=b[i];
         follow[i].n=0;
         findfollow(b[i],i);
     }
     
     for(i=0;i<cnt;i++)
     {
         for(j=0;j<=first[i].n;j++)
         {
             if(j==0)
             printf("\nFIRST(%c)={",first[i].f[j]);
             else
             printf("%c ",first[i].f[j]);
         }
         printf("}\n");
     }
     for(i=0;i<cnt;i++)
     {
         for(j=0;j<=follow[i].n;j++)
         {
             if(j==0)
             printf("\nFollow(%c)={",follow[i].f[j]);
             else
             printf("%c ",follow[i].f[j]);
         }
         printf("}\n");
     }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 