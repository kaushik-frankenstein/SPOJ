#include<stdio.h>
int a[5002];
int visited[5002];
int find(int a[],int start,int end,int numb)
{
//	printf("finding %d\n",numb);
	int i;
	for(i=start;i<end;i++)
	{
		if(a[i]==numb)
			return i;
	}
//	printf("cannot find %d\n",numb);
	return -1;


}
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int count=0;
	for(i=1;i<n;i++)
	{
		int set=0;
		int d=a[i]-a[0];
		if(visited[i]==0)
		{
			set=1;
			count++;
		}
		for(j=i+1;j<n;j++)
		{
			int index=find(a,j,n,a[j-1]+d);
			if(index==-1)
				break;
			if(set!=1&&visited[index]==0)
			{
				set=1;
				count++;
			}
			visited[index]=1;

			j=index;
		}

	}
    printf("%d\n",count);
	return 0;
}
