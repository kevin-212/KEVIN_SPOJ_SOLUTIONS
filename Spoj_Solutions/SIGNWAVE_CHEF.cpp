#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rd(int &x)
{
	x=0;
	register int c=gc();
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}
}

inline void pd(long long int x)
{
	char c[21];
	int k=-1;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	while(k>=0)
	pc(c[k--]);
	pc('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}
int main()
{
	int t,s,c,k,temp;
	long long int prev,i,j;
	long long int lim,ans,lim1,lim2;
	rd(t);
	while(t--)
	{
		rd(s);
		rd(c);
		rd(k);
		temp=s;
		ans=0;
		i=1;
		prev=0;
		
		while(temp>=k)
		{
			ans+=i;
			i=ans;
			temp--;
		}
		lim1=(long long int)pow(2,c);
		lim=(long long int)pow(2,s-1);
		if(k>1)
		{
		lim2=(long long int)pow(2,k-2);
		lim2=(lim/lim2);
	
		if(lim2<=lim1)
		ans+=(lim2>>1);
		}
		else
		{
			while(lim1>lim)
			{
				ans+=(lim1>>1);
				lim1>>=1;
				
			}
		}
		
		ans<<=1;
		if(s>=k)
		ans++;
		pd(ans);
	}
	
}
