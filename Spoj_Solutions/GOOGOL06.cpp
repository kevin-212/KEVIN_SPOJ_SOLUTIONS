#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rdl(unsigned long long int &x)
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
inline void pdl(unsigned long long int x)
{
	char c[31];
	
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
unsigned long long int arr[100001];
unsigned long long int st[400004];
int n,i,j,k,q,x,y;
void build(int sl,int sr,int ind)

{
		if(sl==sr)
		{
			st[ind]=arr[sl];
			return;
		}
		int mid=(sl+sr)/2;	
		build(sl,mid,2*ind+1);
		build(mid+1,sr,2*ind+2);
		st[ind]=st[2*ind+1]^st[2*ind+2];
	
}

void update(int sl,int sr,int l,int r,int ind)
{
	if(sl>r || sr<l)
	return;
	if(l==r && sl==sr && sl==l)
	{
		if((l-x)&1)
		return;
		st[ind]= ~st[ind];
		return;
		
	}
	int mid=(sl+sr)/2;
	if(r<=mid)
	update(sl,mid,l,r,2*ind+1);
	else if(l>mid)
	update(mid+1,sr,l,r,2*ind+2);
	else
	{
		update(sl,mid,l,mid,2*ind+1);
		update(mid+1,sr,mid+1,r,2*ind+2);
	}
	
	st[ind]=st[2*ind+1]^st[2*ind+2];
	
}
void updatee(int sl,int sr,int pos,int ind)
{
	if(sl==sr && sl==pos)
	{
		st[ind]=arr[pos];
		return;
	}
	int mid=(sl+sr)/2;
	if(pos<=mid)
	updatee(sl,mid,pos,2*ind+1);
	else
	updatee(mid+1,sr,pos,2*ind+2);
	st[ind]=st[2*ind+1]^st[2*ind+2];
}
unsigned long long int query(int sl,int sr,int l,int r,int ind)
{
	
	if(sl==l && sr==r)
	{
		
		return st[ind];
	}
	int mid=(sl+sr)/2;
	if(r<=mid)
	return query(sl,mid,l,r,2*ind+1);
	if(l>mid)
	return query(mid+1,sr,l,r,2*ind+2);
	
	
	return query(sl,mid,l,mid,2*ind+1)^query(mid+1,sr,mid+1,r,2*ind+2);
	
	
}
int main()
{
	
	unsigned long long int y1;
	char c;
	rd(n);
	for(i=0;i<n;i++)
	{
		rdl(arr[i]);
	}
	build(0,n-1,0);
	rd(q);
	while(q--)
	{
		c=gc();
		
		if(c=='A')
		{
			
			rd(x);
			rdl(y1);
			x--;
			arr[x]=y1;
			updatee(0,n-1,x,0);
			
		}
		else if(c=='B')
		{
			
			rd(x);
			rd(y);
			x--;
			y--;
			update(0,n-1,x,y,0);
			
		}
		else if(c=='C')
		{
			rd(x);
			x--;
			cout<<arr[x]<<endl;
		}
		else
		{
			rd(x);
			rd(y);
			x--;
			y--;
			
			cout<<query(0,n-1,x,y,0)<<endl;
		}
	}
}

