#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rdl(long long int &x)
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
long long int arr[100001];
bool st[400004];
void build(int sl,int sr,int ind)
{
	if(sl==sr)
	{
		st[ind]=true;
		return;
	}
	int mid=(sl+sr)/2;
	build(sl,mid,2*ind+1);
	build(mid+1,sr,2*ind+2);
	
	bool check;
	if(mid==sl && mid+1==sr)
	st[ind]=check;
	
	else if(mid==sl)
	st[ind]= check&&((1LL*(arr[sl]-arr[mid+1]))==((1LL*arr[mid+1]-arr[mid])));
	
	else if(mid+1==sr)
	st[ind]= check&&((1LL*(arr[sr]-arr[mid]))==((1LL*arr[mid]-arr[mid-1])));
	else
	st[ind]= check&&(1LL*((arr[mid+2]-arr[mid+1]))==(1LL*(arr[mid]-arr[mid-1])));
	
}
void update(int sl,int sr,int in,int ind)
{
	if(sl==sr && sl==in)
	{
		st[ind]=true;
		return;
	}
	int mid=(sl+sr)/2;
	if(in<=mid)
	update(sl,mid,in,2*ind);
	else
	update(mid+1,sr,in,2*ind+2);
	
	st[ind]=(st[2*ind+1]&& st[2*ind+2]&& ( sl==mid ||((1LL*(arr[mid+1]-arr[mid]))==(1LL*(arr[mid]-arr[mid-1])))));
	
}
bool query(int sl,int sr,int l,int r,int ind)
{
	if(sl==l && sr==r)
	return st[ind];
	int mid=(sl+sr)/2;
	if(r<=mid)
	return query(sl,mid,l,r,2*ind+1);
	if(l>mid)
	return query(mid+1,sr,l,r,2*ind+2);
	
	bool check;
	
	check=query(sl,mid,l,mid,2*ind+1) && query(mid+1,sr,mid+1,r,2*ind+2);
	if(mid==l && mid+1==r)
	return check;
	
	if(mid==l)
	return check&&((1LL*(arr[r]-arr[mid+1]))==((1LL*arr[mid+1]-arr[mid])));
	
	if(mid+1==r)
	return check&&((1LL*(arr[r]-arr[mid]))==((1LL*arr[mid]-arr[mid-1])));
	else
	return check&&(1LL*((arr[mid+2]-arr[mid+1]))==(1LL*(arr[mid]-arr[mid-1])));
	
}
int main()
{
	int n,q;
	int i,j,k;
	rd(n);
	for(i=0;i<n;i++)
	rdl(arr[i]);
	build(0,n-1,0);
	rd(q);
	while(q--)
	{
		rd(i);
		rd(j);
		rd(k);
		if(i==0)
		j--,arr[j]=k,update(0,n-1,j,0);
		else
		{
		j--,k--;
		if(query(0,n-1,j,k,0))
		pd(1);
		else
		pd(0);
		}	
	}
}
