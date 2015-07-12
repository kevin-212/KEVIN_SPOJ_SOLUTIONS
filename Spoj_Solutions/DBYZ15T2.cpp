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
int lps[200005];
char s[100001];
long long int dp[100001];
int main()
{
	int n,n1,expand,i,j,k;
	long long int ans=0;
	
	
	dp[1]=0;
	dp[2]=2;
for(i=3;i<=100000;i++)
{
	dp[i]=(dp[i-1]+(1LL*i*i*(i-1)/2LL))%MOD;
}
//	gets(s);
scanf("%s",s);
n=strlen(s);
n1=n;
	n=2*n+1;
	
	lps[0]=0;
	lps[1]=1;
	int c=1;
	int r=2,diff;
	int mx=0,i_mirror=0;
	
	
	for(i=2;i<n;i++)
	{
		
		i_mirror=2*c-i;
		diff=r-i;
		

		if(diff>0)
		lps[i]=min(lps[i_mirror],diff);
		
	
		else
		lps[i]=0;
		
		while(((i+lps[i]<n) && (i-lps[i]>0)) && (((i+lps[i]+1)%2==0)|| (s[(i+lps[i]+1)/2]==s[(i-lps[i]-1)/2])))
		lps[i]++;
		
		mx=max(lps[i],mx);
//		if(mx==n1)
//		break;
		if(lps[i]+i>r)
		{
			c=i;
			r=i+lps[i];
			
		}
	
		
	}
	i=0;
	
	while(i<n-1)
	{
		while( i<n-1 && lps[i]<lps[i+1] )
		i++;
		ans=(ans+dp[lps[i]])%MOD;
		while(i<n-1 && lps[i]!=0)
		i++;
	}
	pdl(ans);
}

