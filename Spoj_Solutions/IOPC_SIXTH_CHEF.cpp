#include<bits/stdc++.h>
#include<string>
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
set<string>S;
string arr[10];
char C[1001];
bool visited[1001];
vector<vector <int > >graph;
void dfs(int u,string s)
{
	visited[u]=true;
	s+=C[u];
	S.insert(s);
	int sz=graph[u].size();
	int i,j,k;
	for(i=0;i<sz;i++)
	{
		j=graph[u][i];
		if(!visited[j])
		dfs(j,s);
	}
	visited[u]=false;
}
int main()
{
	int n,m,t,i,j,k,l1,l2,mx,lo,high,a,b,mid;
	string temp,temp1,temp2,mxs;
	size_t one;
	set<string>::iterator it1,it2;
	bool check;
	char c;
	rd(t);
while(t--)
 { 
	rd(n);
	rd(m);
	graph.resize(n+1);
	for(i=1;i<=n;i++)
	{
		c=gc();
		for(;c<97 || c>122;c=gc());
		C[i]=c;
		
	}
	
	for(i=1;i<n;i++)
	{
		rd(j);
		rd(k);
		graph[j].push_back(k);
		graph[k].push_back(j);
	}
	for(i=1;i<=n;i++)
	temp="",dfs(i,temp);
	it2=S.end();
	
	for(k=0;k<m;k++)
	 { 
		mx=0;
		mxs="";
		cin>>temp;
		lo=0;
		l1=temp.length();
		high=temp.length();
		while(lo<=high){
		mid=(lo+high)/2;
		check=false;
		for(i=0;i<l1-mid+1;i++)
		{
			temp1=temp.substr(i,mid);
			it1=S.find(temp1);
			
			if(it1!=it2)
			{
				check=true;
				break;
			}
			
		}
		if(check)
		lo=mid+1;
		else
		high=mid-1,mid=high;
	  }
	  for(i=0;i<l1-mid+1;i++)
	  {
	  		temp1=temp.substr(i,mid);
			it1=S.find(temp1);
			if(it1!=it2)
			{
				if(mx==0)
				{
					mx=mid;
					mxs=temp1;
				}
				else
				{
					
					mxs=min(mxs,temp1);
				}
				
			}
	  	
	  }
	  cout<<mxs<<endl;
	  arr[k]=mxs;
	 }
	 temp1="";
	sort(arr,arr+m);
	
 }
}
