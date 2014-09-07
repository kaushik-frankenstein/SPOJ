#include<stdio.h>
int main()
{
int t;
long long int n,ans,i;
scanf("%lld",&n);
while(n)
{
ans=0;
long long int a[n];
ans=0;

for(i=0;i<n;i++)
{
scanf("%lld",&a[i]);
if(i)
{
if(i>(n/2))
ans+=(n-i)*(a[i]-a[i-1]-1);
else
{
//printf("");
ans+=(i-0)*(a[i]-a[i-1]-1);
}
//printf("ans:%lld\n",ans);
}

}

/*for(i=0;i<n;i++)
{
if(i)
{
if(i>(n/2))
ans+=(n-i)*(a[i]-a[i-1]-1);
else
{
//printf("");
ans+=(i-0)*(a[i]-a[i-1]-1);
}
//printf("ans:%lld\n",ans);
}
}*/
printf("%lld\n",ans);
scanf("%lld",&n);
}
return 0;
}
