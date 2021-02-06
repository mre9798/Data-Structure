#include<stdio.h>

int bu[10],ba[10],bb[10];
void main()
{
   int u[10]={1,2,3,4,5,6,7,8,9,10};
    int a[10]={3,5,7,9};
    int b[10]={1,2,5,7,8,9};

    convertion(u,a,b);
    unionop();
    intersection();
    difference();
}
void convertion(int u[],int a[],int b[])
{
    int i=0,j=0;
    for(i=0;i<10;i++)
    {
       bu[i]=1;
    }

    for(i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
        {
            if(u[i]==a[j])
            {
                ba[i]=1;
                break;
            }
            else
                ba[i]=0;
        }
    }
    for(i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
        {
            if(u[i]==b[j])
            {
                bb[i]=1;
                break;
            }
             else
                bb[i]=0;
        }
    }
    printf("Universal set:");
    for(i=0;i<10;i++)
    {
        printf("%d",bu[i]);
    }
     printf("\nSet A:");
    for(i=0;i<10;i++)
    {
        printf("%d",ba[i]);
    }
      printf("\nSet B:");
    for(i=0;i<10;i++)
    {
        printf("%d",bb[i]);
    }
}
void unionop()
{
    int m[10],i,j;
    for(i=0;i<10;i++)
    {
       m[i]=0;
    }
    printf("\nUnion operation:");
     for(i=0;i<10;i++)
    {

            if(bu[i]==ba[i] || bu[i]==bb[i])
            {
                m[i]=1;

            }
    }
    for(i=0;i<10;i++)
    {
        printf("%d",m[i]);
    }
}
void intersection()
{
    int m[10],i,j;
    for(i=0;i<10;i++)
    {
       m[i]=0;
    }
    printf("\nIntersection operation:");
     for(i=0;i<10;i++)
    {

            if(bu[i]==ba[i] && bu[i]==bb[i])
            {
                m[i]=1;

            }
    }
    for(i=0;i<10;i++)
    {
        printf("%d",m[i]);
    }
}
void difference()
{
     int m[10],i,j;
    for(i=0;i<10;i++)
    {
       m[i]=0;
    }
    for(i=0;i<10;i++)
    {
        if(ba[i]==1 && ba[i]!=bb[i])
        {
            m[i]=1;
        }
    }
    printf("\n Difference:");
    for(i=0;i<10;i++)
    {
        printf("%d",m[i]);
    }
}
