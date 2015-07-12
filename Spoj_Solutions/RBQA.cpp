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
long long int rev(long long int a)
{
	
	long long int ans=0;
	while(a)
	{
		ans=1LL*ans*10;
		ans+=(a%10);
		a/=10LL;
	}
	return ans;
}
int main()
{
	//ifstream cin("RB1.in");
	//ofstream cout("RB1A.txt");
	int t,ind=1,cnt,i,j;
	long long int n,ans,aprev,bprev,a,b,c,d;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		if(n<=20)
		ans=n;
		else
		{
			if(n%10==0)
			{
			n-=9;
			ans+=9;
			}
			a=n;
			cnt=0;
			c=1LL;
			while(a)
			{
				cnt++;
				a/=10;
				c=1LL*c*10;
			}
			c/=10;
			j=cnt;
			cnt-=2;
			ans+=10;
			i=1;
			a=9;
			b=10;
			while(cnt)
			{
			if(i<2)
			b+=a,ans+=b,i++,cnt--;
			else
			{
				a=1LL*a*10;
				b+=a;
				ans+=b;
				i=1;
				cnt--;
			}
				
			}
			cnt=j;
			a=n;
			b=rev(n);
			
			while(cnt--)
			{
				i=a/c;
				ans+=i;
				a=a%c;
				c/=10;
			}
			if(b==n)
			ans--;
			
		}
		
				cout<<"Case #"<<ind++<<": "<<ans<<endl;
	}
}
