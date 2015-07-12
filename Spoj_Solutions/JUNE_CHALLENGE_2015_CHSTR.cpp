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
bool cmp(int  a,int b)
{
	return a>b;
}
long long int ncr[5001][5001];
long long int ans[5001];
int cnt[5001];
unordered_map<string,int>mp;
int  main()
{
	int i,n,j,k,l,t,q,mx;
	string str;
	for(i=0;i<=5000;i++)
	ncr[i][0]=1LL;
	for(i=1;i<=5000;i++)
	{
		for(j=1;j<=i;j++)
		ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%MOD;
	}
	rd(t);
	while(t--)
	{
	mx=0;
	rd(l);
	rd(q);
	cin>>str;
	for(i=1;i<=l;i++)
	{
		k=l-i+1;
		for(j=0;j<k;j++)
			mp[str.substr(j,i)]++;
	}
	unordered_map<string,int>::iterator it1,it2;
	it1=mp.begin();
	it2=mp.end();
	while(it1!=it2)
		cnt[it1->second]++,mx=max(mx,it1->second),it1++;
	
	for(i=1;i<=mx;i++)
	{
		k=cnt[i];
		for(j=1;j<=i;j++)
			ans[j]=(ans[j]+1LL*k*ncr[i][j])%MOD;
		
	}
	while(q--)
	{
		rd(k);
		if(k>l)
		pd(0);
		else
		pdl(ans[k]);
		
	}
	memset(ans,0,sizeof(ans));
	memset(cnt,0,sizeof(cnt));
	mp.clear();
	}
}
