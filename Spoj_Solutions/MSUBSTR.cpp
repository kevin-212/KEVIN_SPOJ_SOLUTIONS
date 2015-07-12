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
//	pc('\n');
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
int main()
{
	char s[3001];
	int lps[6010];
	int t,mx=1,diff,i,j,k,i_mirror,r,c,l,l1;
	rd(t);
	lps[0]=0;
	lps[1]=1;
	while(t--)
	{
		mx=1;
		scanf("%s",&s);
		l=strlen(s);
		l1=l;
		l=2*l+1;
		c=1;
		r=2;
		j=1;
		for(i=2;i<l;i++)
		{
			diff=r-i;
			i_mirror=2*c-i;
			if(diff>0)
			lps[i]=min(diff,lps[i_mirror]);
			else
			lps[i]=0;
			
			while(((i+lps[i]<l)&&(i-lps[i]>0)) &&(((i+lps[i]+1)%2==0)||(s[(i+lps[i]+1)/2]==s[(i-lps[i]-1)/2])))
			lps[i]++;
			
			if(mx<lps[i])
			mx=lps[i],j=1;
			else if(mx==lps[i])
			j++;
		
			if(i+lps[i]>r)
			{
				c=i;
				r=i+lps[i];
			}
			
		}
		
	pd(mx);
	pc(' ');
	pd(j);
	pc('\n');
	}
	
	
}
