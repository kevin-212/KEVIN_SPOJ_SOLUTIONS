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
struct cmp1{
	
	bool operator()(int a,int b)
	{
		return a>b;
	}
	
};
vector<pii>vec;
vector<pii>vec1;
vector<int>temp;
priority_queue<int,vector<int>,cmp1>Q;
int cnt[100001];
int main()
{
	int t,n,a,b,i,j,k,mx,mxi,ans,c,ind=0;
	rd(t);
	while(t--)
	{
		
		mx=-1;
		rd(n);
		vec.resize(n);
		for(i=0;i<n;i++)
		{
			rd(a);
			rd(b);
			vec[i]=pii(a,b);
		}
		sort(vec.begin(),vec.end());
		for(i=0;i<n;i++)
		{
			a=vec[i].first;
			b=vec[i].second;
			while(!Q.empty())
			{
				c=Q.top();
				if(a>c)
				Q.pop();
				else
				break;
			}
			Q.push(b);
			cnt[i]=Q.size();
				if(cnt[i]>mx)
			mx=cnt[i],mxi=i;
		}
		ans=mx;
	
		vec1.resize(n-mx);
		
		k=0;
		b=vec[mxi].first;
		for(i=0;i<mxi;i++)
		{
			if(vec[i].second<b)
			vec1[k++]=vec[i];
		}
		for(i=mxi+1;i<n;i++,k++)
		vec1[k]=vec[i];
		
		while(!Q.empty())
		Q.pop();
		mx=-1;	
		for(i=0;i<k;i++)
		{
			a=vec1[i].first;
			b=vec1[i].second;
			while(!Q.empty())
			{
				c=Q.top();
			
				if(a>c)
				Q.pop();
				else
				break;
			}
			Q.push(b);
			cnt[i]=Q.size();
			
			if(cnt[i]>mx)
			mx=cnt[i];
			
		}
		if(mx!=-1)
		ans+=mx;
		cout<<"Case "<<++ind<<": ";
		pd(ans);
		while(!Q.empty())
		Q.pop();
	}
	
}
