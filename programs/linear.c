#include<stdio.h>
int main()
{
    int ar[20],i,j,n,key,flag=0;
    printf("enter the size of element:");
    scanf("%d",&n);
    printf("enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("enter element you want to search:");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if (key==ar[i])
        {
             flag=1;
             break;
        }
    }
    if(flag==1)
    {
        printf("Element found at index %d and position %d", i, i + 1);
    }
    else
        printf("element not found");
    return 0;
}
