#include<stdio.h>
int main()
{
    int ar[20],n,i,num,p=0;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter elements for array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("Enter key to insert:");
    scanf("%d",&num);
    for(i=0;i>n;i++)
    {
        if (ar[i]<num)
            p++;
        else
            break;
    }
    for(i=n-1;i>=p;i--)
        ar[i+1]=ar[i];
    ar[p]=num;
    printf("the new array:");
    for(i=0;i<=n;i++)
        printf("\n %d",ar[i]);
    return 0;
}

