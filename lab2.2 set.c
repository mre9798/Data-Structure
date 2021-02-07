#include<stdio.h>

int uset[10],seta[10],setb[10];
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
          uset[i]=1;
     }
     for(i=0;i<10;i++)
     {
          for (j=0;j<10;j++)
          {
               if(u[i]==a[j])
               {
                    seta[i]=1;
                    break;
               }
               else
                    seta[i]=0;
          }
      }
      for(i=0;i<10;i++)
      {
           for (j=0;j<10;j++)
           {
                     if(u[i]==b[j])
                     {
                          setb[i]=1;
                          break;
                     }
                     else
                         setb[i]=0;
            }
      }
      printf("Universal set:");
      for(i=0;i<10;i++)
      {
           printf("%d",uset[i]);
      }
      printf("\nSet A:");
      for(i=0;i<10;i++)
      {
           printf("%d",seta[i]);
      }
      printf("\nSet B:");
      for(i=0;i<10;i++)
      {
           printf("%d",setb[i]);
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
            if(uset[i]==seta[i] || uset[i]==setb[i])
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

            if(uset[i]==seta[i] && uset[i]==setb[i])
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
        if(seta[i]==1 && seta[i]!=setb[i])
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
