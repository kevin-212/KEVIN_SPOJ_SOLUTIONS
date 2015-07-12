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
double struc[201][201];
vector<vector <int> >graph(201);
int in[201];
int main()
{
	
	int t,c,p,b,x,i,j,k,child,parent,sz;
	double ans;
	bool check;
	queue<int>Q;
	rd(t);
	while(t--)
	{
		
		memset(struc,0,sizeof struc);
		
		rd(c);
		rd(p);
		for(i=0;i<p;i++)
		{
			rd(child);
			rd(parent);
			in[child]++;
			graph[parent].push_back(child);
		}
		rd(x);
		rd(b);
		
		for(i=0;i<x;i++)
		{
			rd(j);
			rd(k);
			struc[j][k]++;
			struc[j][0]++;
			Q.push(j);
			
		}
		while(!Q.empty())
		{
			parent=Q.front();
			Q.pop();
			sz=graph[parent].size();
			for(i=0;i<sz;i++)
			{
				child=graph[parent][i];
				in[child]--;
				struc[child][0]++;
				if(in[child]==0)
				Q.push(child);
				for(k=1;k<=b;k++)
				{
					if(struc[parent][k]>0)
					struc[child][k]+=struc[parent][k]/struc[parent][0];
					
				}
				
			}
			graph[parent].clear();
		}
		for(i=1;i<=b;i++)
		{
			ans=0;
			for(j=1;j<=c;j++){
			
				ans+=(1.00*struc[j][i]/struc[j][0]);
			}
			printf("%.9f ",ans);
			
			
		}
		putchar('\n');
		
	}
	
	
}
