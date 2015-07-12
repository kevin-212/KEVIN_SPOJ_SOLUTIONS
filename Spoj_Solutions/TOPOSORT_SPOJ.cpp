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
struct cmp{
	
	bool operator()(int a,int b)
	{
		return a>b;
	}
};
int in[10001];
int arr[10001];
vector<vector<int > >graph(10001);
int main()
{
	int n,m,i,j,k,count=0,x,y,sz;
	rd(n);
	rd(m);
	for(i=0;i<m;i++)
	{
		rd(x);
		rd(y);
		in[y]++;
		graph[x].push_back(y);
	}
	priority_queue<int,vector<int>,cmp>Q;
	
	for(i=1;i<=n;i++)
	if(in[i]==0)Q.push(i);
	while(!Q.empty())
	{
		x=Q.top();
		Q.pop();
		arr[count++]=x;
		sz=graph[x].size();
		for(i=0;i<sz;i++)
		{
			y=graph[x][i];
			in[y]--;
			if(in[y]==0)
			Q.push(y);
		}
		
	}
	if(count==n)
	{
		for(i=0;i<n;i++)
		pd(arr[i]),pc(' ');
		pc('\n');
	}
	else
	printf("Sandro fails.\n");
}
