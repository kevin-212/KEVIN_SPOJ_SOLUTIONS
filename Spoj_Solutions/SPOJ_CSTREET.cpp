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
struct cmp{
	
bool operator()(pii a,pii b)
{
	
	return a.second>b.second;
}	
};
vector<vector<pii> >graph;
bool check[1001];
long long int D[1001]; 
int main()
{
	
	int t,n,m,i,j,k,u,v,w,sz,p;
	long long int ans;
	priority_queue<pii,vector<pii>,cmp> Q;
	rd(t);
	while(t--)
	{
		rd(p);
		rd(n);
		rd(m);
		graph.clear();
		graph.resize(n+1);
		fill(check,check+n+1,false);
		fill(D,D+n+1,1000000000);
		ans=0;
		for(i=0;i<m;i++)
		{
			rd(u);
			rd(v);
			rd(w);
			graph[u].push_back(pii(v,w));
			graph[v].push_back(pii(u,w));
			
		}
		D[1]=0;
		D[0]=0;
		Q.push(pii(1,0));
		while(!Q.empty())
		{
			u=Q.top().first;
			w=Q.top().second;
			Q.pop();
			if(check[u])
			continue;
			check[u]=true;
			
			ans+=w;
			
			sz=graph[u].size();
			for(i=0;i<sz;i++)
			{
				v=graph[u][i].first;
				w=graph[u][i].second;
				if(!check[v]  &&   w<D[v])
				{
					D[v]=w;
					Q.push(pii(v,w));
				}
			}
		}
		
		pdl(1LL*p*ans);
	}
	
}
