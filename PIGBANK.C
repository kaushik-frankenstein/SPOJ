#include<stdio.h>
#define INF 100000
int min0(int i,int j)
{
if(i==0)
return j;
else
{
if(i<j)
return i;
else
return j;
}
}
int main()
{
int t;
int e,f;
scanf("%d",&t);
while(t--)
{
scanf("%d%d",&e,&f);
int *arr=(int*)calloc(sizeof(int),f-e+1);
int n;
scanf("%d",&n);
int p[n],w[n];
int i,j;
for(i=0;i<n;i++)
{
scanf("%d%d",&p[i],&w[i]);
if(w[i]<=f-e)
arr[w[i]]=min0(arr[w[i]],p[i]);
}
for(i=1;i<=f-e;i++)
{
int min=arr[i];
for(j=1;j<=i/2;j++)
{
if(arr[j]!=0&&arr[i-j]!=0)
min=min0(min,arr[j]+arr[i-j]);
}
arr[i]=min;
}
if(arr[f-e])
printf("The minimum amount of money in the piggy-bank is %d.\n",arr[f-e]);
else
printf("This is impossible.\n");
}
return 0;
}
