#include<stdio.h>
#include<iostream>
#include<queue>
#include<Windows.h>
using namespace std;
#define INF 1000000
struct node
{
int p1,p2;
node* parent;
node* child;
node(int i,int j)
{
p1=i;
p2=j;
parent=child=0;
}
};
int main()
{
int t,i,j,k,l;
int n,m;
scanf("%d",&t);
while(t--)
{

scanf("%d%d",&n,&m);
int dest[n][m];
char a[n][m];
char c;
queue<pair<int,int> > p;

scanf("%c",&c);

for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
//a[i][j]=
scanf("%c",&a[i][j]);
dest[i][j]=INF;
if(a[i][j]=='1')
{
dest[i][j]=0;
if(j-1>=0&&a[i][j-1]=='0'&&dest[i][j-1]==INF)
{
dest[i][j-1]=1;
p.push(make_pair (i,j-1));
//printf("inserted %d %d\n",i,j-1);
}
if(i-1>=0&&a[i-1][j]=='0'&&dest[i-1][j]==INF)
{
dest[i-1][j]=1;
p.push(make_pair (i-1,j));

//printf("inserted %d %d\n",i-1,j);

}
}
else
{
if(i-1>=0&&a[i-1][j]=='1'&&dest[i][j]==INF)
{
dest[i][j]=1;
dest[i-1][j]=0;
p.push(make_pair (i,j));
//printf("inserted %d %d\n",i,j);
}
else
if(j-1>=0&&a[i][j-1]=='1'&&dest[i][j]==INF)
{
dest[i][j]=1;
dest[i][j-1]=0;
p.push(make_pair (i,j));
//printf("hi\n");

//printf("inserted %d %d\n",i,j);
}
}
}
scanf("%c",&c);
}
while(!p.empty())
{
pair<int,int> p1=p.front();
p.pop();
//printf("checking adjacencies for %d %d\n",p1.first,p1.second);
if(p1.first-1>=0&&dest[p1.first-1][p1.second]>dest[p1.first][p1.second]+1)
{
dest[p1.first-1][p1.second]=dest[p1.first][p1.second]+1;
//printf("p1.first:%d p1.second:%d\n",p1.first-1,p1.second);
p.push(make_pair (p1.first-1,p1.second));
}
if(p1.first+1<n&&dest[p1.first+1][p1.second]>dest[p1.first][p1.second]+1)
{
dest[p1.first+1][p1.second]=dest[p1.first][p1.second]+1;
//printf("p1.first:%d p1.second:%d\n",p1.first+1,p1.second);
p.push(make_pair (p1.first+1,p1.second));
}
if(p1.second-1>=0&&dest[p1.first][p1.second-1]>dest[p1.first][p1.second]+1)
{
dest[p1.first][p1.second-1]=dest[p1.first][p1.second]+1;
//printf("p1.first:%d p1.second:%d\n",p1.first,p1.second-1);
p.push(make_pair (p1.first,p1.second-1));

}
if(p1.second+1<m&&dest[p1.first][p1.second+1]>dest[p1.first][p1.second]+1)
{
dest[p1.first][p1.second+1]=dest[p1.first][p1.second]+1;
//printf("p1.first:%d p1.second:%d\n",p1.first,p1.second+1);
p.push(make_pair (p1.first,p1.second+1));

}
}
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
printf("%d ",dest[i][j]);
printf("\n");
}
}
}
