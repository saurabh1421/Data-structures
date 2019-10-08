/***
  *
 ***/
#include<stdio.h>

int max(int x, int y)
{
	return ((x>y)?x:y);
}
void ks(int cap,int wt[],int pf[],int n)
{
	int t[n+1][cap+1], i, j;
	for(i=0;i<=n;++i)
	{
		for(j=0;j<=cap;++j)
		{
			if(i==0 || j==0)
				t[i][j]=0;
			else if(wt[i-1]<=j)
				t[i][j] = max((pf[i-1]+t[i-1][j-wt[i-1]]),t[i-1][j]);
			else
				t[i][j]=t[i-1][j];
		}
	}
	printf("\n The matrix is : \n");
	for(i=0;i<=n;++i)
	{
		for(j=0;j<=cap;++j)
			printf(" %2d",t[i][j]);
		printf("\n");
	}
	printf("\n The max profit is: %d \n",t[n][cap]);
}
int main()
{
	int i, n, cap;
	printf("\n Enter the value of n : ");
	scanf("%d",&n);
	int wt[n], pf[n];
	printf("\n Enter the profits : ");
	for(i=0;i<n;++i)
		scanf("%d",&pf[i]);
	printf("\n Enter the weights : ");
	for(i=0;i<n;++i)
		scanf("%d",&wt[i]);
	printf("\n Enter the capacity of the knapsack : ");
	scanf("%d",&cap);
	ks(cap,wt,pf,n);
	return 0;
}
