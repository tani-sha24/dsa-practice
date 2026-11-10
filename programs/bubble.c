#include<stdio.h>
int main()
{
    int ar[20],i,j,n;
    printf("enter the size of element:");
    scanf("%d",&n);
    printf("enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if (ar[j]>ar[j+1])
            {
                int t=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=t;
            }
        }
    }
    printf("after sorting:");
    for(i=0;i<n;i++)
    {
        printf("%d \n",ar[i]);
    }
    return 0;
}
