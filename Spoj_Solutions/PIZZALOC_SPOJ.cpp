#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rdl(int &x)
{
	x=0;
	bool check=false;
	register int c;
	do{
		c=gc();
		if(c=='-')
		check=true;
	}while(c<48 || c>57);
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}
	if(check)
	x=-x;
}
inline void rd(int &x)
{
	x=0;
	bool check=false;
	register int c=gc();
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}

}
inline void pd(int x)
{
	char c[11];
	bool check=false;
	int k=-1;
	if(x<0)
	check=true,x=-x;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	if(check)
	c[++k]='-';
	while(k>=0)
	pc(c[k--]);
	pc('\n');
}
inline void pdl(long long int x)
{
	char c[21];
	bool check=false;
	int k=-1;
	if(x<0)
	check=true,x=-x;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	if(check)
	c[++k]='-';
	while(k>=0)
	pc(c[k--]);
	pc('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}
struct bt{
	int total,set;
	bool visited[100];
	bt()
	{
		total=set=0;
		memset(visited,false,sizeof visited);
		
	}
};

int cords[101][3];
int cordh[20][2];
int n,loc;

int  d,r;

int main()
{
	int i,j,k;
	int mx=0,x,y,temp,x2,y2,sol,lim,temp1;
	rd(n);
	rd(r);
	r*=r;
	rd(loc);
bt*arr=new bt[1<<loc];
	for(i=0;i<loc;i++)
	scanf("%d%d",&cordh[i][0],&cordh[i][1]);
	rd(sol);

	for(i=0;i<sol;i++)
		scanf("%d%d%d",&cords[i][0],&cords[i][1],&cords[i][2]);
		lim=(1<<loc);
		
	for(i=0;i<lim;i++)
	{
		
		if(arr[i].set==n)
		{
			mx=max(arr[i].total,mx);
			continue;
		}
		for(j=0;j<loc;j++)
		{
			if((i>>j)&1)
			continue;
			temp1=(i|(1<<j));
			if(arr[temp1].set==0)
			{
				arr[temp1].set=arr[i].set+1;
				
			temp=0;
			x=cordh[j][0],y=cordh[j][1];
			for(k=0;k<sol;k++)
			{
				if(arr[i].visited[k])
			{
				arr[temp1].visited[k]=true;
				continue;
			}
				x2=cords[k][0],y2=cords[k][1];
				d=((x-x2)*(x-x2)+(y-y2)*(y-y2));	
				if(d<=r)
				{
					arr[temp1].visited[k]=true;
					temp+=cords[k][2];
				}
				
			}
			arr[temp1].total=arr[i].total+temp;
			
			}
			
		}
		
	}
	pd(mx);
	
}
