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
char s1[200001];
char s2[200001];
set<pii>arr[26];
int visited[26];
pii ans,temp;
bool check;
set<pii>::iterator it1,it2;
bool dfs(int i)
{

	int sz=arr[i].size(),j,k;
	if(sz==0)	
	return false;
	visited[i]=i;
	it1=arr[i].begin();
	it2=arr[i].end();
	
	while(it1!=it2)
	{
		j=it1->first;
		
		if(visited[j]==-1)
		 {	
		 ans.first=it1->second;
		 if(dfs(j))
		 return true;
		}
		else
		{
			
			ans.second=it1->second;
			return true;	
		}
		
		it1++;
	}
	visited[i]=-1;
	return false;
}

bool dfs2(int i)
{
	int sz=arr[i].size();
	if(sz>0)
	{
		it1=arr[i].begin();
		it2=arr[i].end();
		while(it1!=it2)
		{
			int j=it1->first;
			if(arr[j].size()>0)
			{
				check=true;
				temp.first=it1->second;
				temp.second=((arr[j].begin())->second);
				return true;
			}
			it1++;
		}
		
	}
	return false;
}
int main()
{
	int l1,l2,n,i,j,k,count=0,sz;
	rd(n);
	scanf("%s",s1);
	scanf("%s",s2);
	memset(visited,-1,sizeof visited);
	check=false;
	for(i=0;i<n;i++)
	{
		j=s1[i]-97;
		k=s2[i]-97;
		if(j!=k)
		{
			arr[j].insert(pii(k,i+1));
			count++;
		}
		
	}
	
	for(i=0;i<26;i++)
	{
		if(visited[i]==-1)
		if(dfs(i))
		break;
		
	}
	if(i==26)
	{
		for(j=0;j<26;j++)
		if(dfs2(j))
		break;
		
		if(j<26)
		{
			pd(count-1);
			printf("%d %d\n",temp.first,temp.second);
		
		}
		else
		{
			
			pd(count);
		printf("-1 -1\n");
			
		}
		
	}
	else
	pd(count-2),printf("%d %d\n",ans.first,ans.second);
}
