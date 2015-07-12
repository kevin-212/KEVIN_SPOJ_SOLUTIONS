#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
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
	char c[15];
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
/*struct node{
	int lft,rgt,midd;
};*/
char s[100001];
int one[100001];
long long  st[400010];


int k;
long long int perm(int x)
{
	return (1LL*x*(x+1))/2;
}

long long int merge(int l,int m,int r)
{
	int i,x,y,z;
	
	 int onel;
	 int zerol;
long long  int ans=0;
	for(i=m;i>=l;i--)
	{
		x=m+1;
		y=r;
		while(x<=y)
		{
			z=(x+y)/2;
			onel=one[z]-one[i-1];
			zerol=z-i+1-onel;
			if(onel<=k && zerol<=k)
			x=z+1;
			else
			y=z-1,z=y;
		}			
		ans+=z-m;
	}
	return ans;
	
}
/*long long int  func(int l,int r)
{
	int m;
	while(l<r)
	{
		 m=(l+r)/2;
		long long int left=func(l,m);
		long long int right=func(m+1,r);
		
		int onel=one[m]-one[l-1];
	int zerol=m-l+1-onel;
	int oner=one[r]-one[m];
	int zeror=r-m-oner;
	if(onel+oner<=k && zerol+zeror<=k )
	return perm(r-l+1);
	int mid=merge(l,m,r);
	return left+right+mid;
	
	}
	return 1;
}*/

long long int build(int sl,int sr,int ind)
{
	if(sl==sr)
	{
	st[ind]=1;
	return 1;
	}
	int m=(sl+sr)/2;
	long long int left=build(sl,m,2*ind+1);
	long long int right=build(m+1,sr,2*ind+2);
	
		
	int onel=one[m]-one[sl-1];
	int zerol=m-sl+1-onel;
	int oner=one[sr]-one[m];
	int zeror=sr-m-oner;
	if(onel+oner<=k && zerol+zeror<=k )
	st[ind]=perm(sr-sl+1);
	else{
	int mid=merge(sl,m,sr);
	st[ind]= left+right+mid;
	}
	return st[ind];
}
long long int query(int sl,int sr,int l,int r,int ind)
{
	if(l==sl && r==sr)
	return st[ind];
	int m=(sl+sr)/2;
	if(r<=m)
	return query(sl,m,l,r,2*ind+1);
	if(l>m)
	return query(m+1,sr,l,r,2*ind+2);
	
	long long int left=query(sl,m,l,m,2*ind+1);
	long long int right=query(m+1,sr,m+1,r,2*ind+2);
	int onel=one[m]-one[l-1];
	int zerol=m-l+1-onel;
	int oner=one[r]-one[m];
	int zeror=r-m-oner;
	if(onel+oner<=k && zerol+zeror<=k )
	return perm(r-l+1);
	else{
	int mid=merge(l,m,r);
	return left+right+mid;
	}
}
int main()
{
	int t,n,q,i,j,l,r;
	int count1;
	rd(t);
	one[0]=0;
	while(t--)
	{
		rd(n);
		rd(k);
		rd(q);
		
		
		count1=0;
		scanf("%s",s);
	
		for(i=1;i<=n;i++)
		{
			if(s[i-1]=='1')
			count1++;
			one[i]=count1;	
		
		
		}
		build(1,n,0);
		for(i=0;i<q;i++)
		{
			rd(l);
			rd(r);
				
			pd(query(1,n,l,r,0));
			
			
		}
	}
}
