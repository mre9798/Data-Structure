#include<stdio.h>
int ar[10],a,b,i,j;
void main()
{
    int ch;
    create();
    while(1)
    {
        printf("\n\n1.Union\n2.Find\n3.Display\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:unionop();
            break;
            case 2:find();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            default:printf("\nInvalid choice");
        }
    }
}
void create()
{
    for(i=0;i<10;i++)
    {
        ar[i]=i;
    }
}
void display()
{
    printf("\n");
    for(i=0;i<10;i++)
    {
        printf("%d\t|",ar[i]);
    }
}
void unionop()
{
    int t,m;
    while(1)
    {   a="";
    b="";
         printf("\nEnter the elements (a,b):");
    scanf("%d,%d",&a,&b);
    if(a==NULL|| b==NULL)
    {
         printf("\nEnter the input as->a,b");

    }

    else if((a<10)&& (a>=0)&&(b<10)&& (b>=0))
    {
        break;
    }

    else
        printf("Invalid input Please enter again\nEnter the input as->a,b");
    }

      int TEMP = ar[ a ];
for(int i = 0; i < 10;i++)
    {
    if(ar[ i ] == TEMP)
    ar[ i ] = ar[ b ];
    }
    display();
}
void find()
{
   while(1)
    {

         printf("\nEnter the elements (a,b):");
    scanf("%d,%d",&a,&b);
    if(a==NULL|| b==NULL)
    {
         printf("\nEnter the input as->a,b");

    }

    else if((a<10)&& (a>=0)&&(b<10)&& (b>=0))
    {
        break;
    }

    else
        printf("Invalid input Please enter again\nEnter the input as->a,b");
    }

    if(ar[ a ] == ar[ b ])
        printf("\nTrue");
    else
        printf("\nAbsent");
}
