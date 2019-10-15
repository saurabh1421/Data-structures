#include<stdio.h>
#include<conio.h>
#define size 10
int large(int arr[],int n);
void radix_sort(int arr[],int n);
int main()
{
int arr[size],i,n;
printf("enter the number of element in the array:");
scanf("%d",&n);
printf("\nenter the element of array");
for(i=0;i<0;i++);
{
scanf("%d",&arr[i]);
}
radix_sort(arr,n);
printf("\n the sorted array is :");
for(i=0;i<n;i++)
    printf("%d",arr[i]);
getch();
}
int large(int arr[],int n)
{
    int large=arr[0],i;
    for(i=0;i<n;i++)
    {
        if(arr[i]>large)
            large=arr[i];
    }
    return large;
}
void radix_sort(int arr[],int n)
{
    int exp;
    int m=large(arr,n)
    for(exp=1;m/exp>0;exp*=10)
        count sort(arr,n,exp);
}
