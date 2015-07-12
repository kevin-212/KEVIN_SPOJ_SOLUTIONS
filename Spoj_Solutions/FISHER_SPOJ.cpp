#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
#define piii pair<int,pii>
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

bool operator()(piii a,piii b)
{
	if(a.second.second==b.second.second)
	return a.second.first>b.second.first;
	return a.second.second>b.second.second;
}	
};

int graph[51][51];
int cost[51][51];
bool visited[51][1001];

priority_queue<piii,vector<piii>,cmp>Q;
int main()
{
	int n,t,i,j,k,s,d,c,v,t1,cst;
	while(true)
	{
		memset(visited,false,sizeof visited);
		cst=0,t1=0;
		rd(n);
		d=n-1;
		rd(t);
		if(n==0)
		break;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				rd(graph[i][j]);
			}	
			
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				rd(cost[i][j]);
			}	
			
		}
		
		Q.push(piii(0,pii(0,0)));
		while(!Q.empty())
		{
			s=Q.top().first;
			t1=Q.top().second.first;
			cst=Q.top().second.second;
			Q.pop();
			if(s==d)
			break;
			if(visited[s][t1])
			continue;
			visited[s][t1]=true;
			for(v=0;v<n;v++)
			{
				if(v==s)
				continue;
				if(t1+graph[s][v]<=t)
				Q.push(piii(v,pii(t1+graph[s][v],cst+cost[s][v])));
				
			}
			
		}
		while(!Q.empty())
		Q.pop();
		
		
		
		pd(cst),pc(' '),pd(t1);
		pc('\n');
	}
}
