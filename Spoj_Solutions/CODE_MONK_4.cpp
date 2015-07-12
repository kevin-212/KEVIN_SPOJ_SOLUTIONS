#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
#define MOD 1000000007
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
	
	bool operator()(const long long int a,const long long int b)
	{
		return a>b;
	}
};
int N[201][201];
priority_queue<long long int,vector<long long int>,cmp>Q1;
	priority_queue<long long int,vector<long long int>,cmp>Q2;
int main()
{
	int i,j,k,l,t,n,o1,o2;
	long long int ans,a,b;
	
	rd(t);
	while(t--)
	{
			cin>>n>>k;
	
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>N[i][j];
		for(i=0;i<n;i++)
		{
			
			a=b=0;
			for(j=0;j<n;j++)
			a+=N[i][j],b+=N[j][i];
			Q1.push(a);
			Q2.push(b);
			
		}
		ans=0;
		o1=o2=0;
		while(k--)
		{
			a=Q1.top();
			b=Q2.top();
			a+=o1;
			b+=o2;
			if(a<=b)
			{
				ans+=a;
				Q1.pop();
				Q1.push(a+n);
				o2++;	
			}
			else
			{
				ans+=b;
				Q2.pop();
				Q2.push(b+n);
				o1++;
			}
			
		}
		while(!Q1.empty())
		Q1.pop();
		while(!Q2.empty())
		Q2.pop();
		cout<<ans<<endl;
		
	}
}