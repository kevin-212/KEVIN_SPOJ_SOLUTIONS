#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rdl(long long int &x)
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
int arr[100001];
vector< vector <int > >graph;

bool dfs(int i)
{
	bool check=true;
	int sz=graph[i].size();
	int j,k;
	for(j=0;j<sz && check;j++)
	{
		k=graph[i][j];
		if(arr[k]==arr[i])
		return false;
		if(arr[k]==0)
		{
			arr[k]=-arr[i];
			check=(check && dfs(k));
		}
	}
	return check;
}
int main()
{
	
	int n,m;
	char s[100001],c;
	rd(n);
	rd(m);
	
	graph.resize(n+1);
	int i,j,k;
	for(i=0;i<n;i++)
		{
			register char c=gc();
			for(;c<'A';c=gc());
			s[i]=c;
		}
		for(i=0;i<m;i++)
		{
			rd(j);
			rd(k);
			j--;
			k--;
			graph[j].push_back(k);
			graph[k].push_back(j);
		}
		bool check=true;
		for(i=0;i<n && check;i++)
		{
			if(arr[i]==0){
			
			if(s[i]=='B')
			arr[i]=1;
			else
			arr[i]=-1;
	
			check=(check&& dfs(i));
		}
		}
		
		if(check)
		{
			j=0;
			for(i=0;i<n;i++)
			{
				if(s[i]=='B')
				{
					if(arr[i]!=1)
					j++;
				}
				else
				{
					if(arr[i]!=-1)
					j++;
				}
			}
			j=min(j,n-j);
			pd(j);
		}
		else
		printf("Not possible\n");
		
}
