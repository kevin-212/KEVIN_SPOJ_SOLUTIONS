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

vector<vector<int > >vec(100001);
map<string,int>mp;
int main()
{
	int n;
	rd(n);
	int i,j,k,l,r,q,count,sz,lo,high,mid;
	string s;
	
	k=1;
	for(i=0;i<n;i++)
	{
		cin>>s;	
		if(mp[s]!=0)
		{
			vec[mp[s]].push_back(i);
		}
		else
		mp[s]=k,vec[k++].push_back(i);
	
	}
	rd(q);
	while(q--)
	{
		rd(l);
		rd(r);
		l--,r--;
		cin>>s;
		count=0;
		if(mp[s]==0)
		{
			pd(0);
		}
		else
		{
			j=mp[s];
			sz=vec[j].size();
			lo=0;
			high=sz-1;
			while(lo<=high)
			{
				mid=(lo+high)/2;
				if(vec[j][mid]==l)
				break;
				if(vec[j][mid]<l)
				lo=mid+1,mid=lo;
				else
				high=mid-1;
			}	
			for(i=mid;i<sz;i++)
			{
				if(vec[j][i]<=r)
				count++;
				else
				break;
			}
			pd(count);
		}
	}
	
	
}

