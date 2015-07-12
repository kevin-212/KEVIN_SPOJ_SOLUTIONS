#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x)
{
	x=0;
	register int c=getchar_unlocked();
	for(;c<48 || c>57;c=getchar_unlocked());
	for(;c>47 && c<58;c=getchar_unlocked()){
		x=(x<<1)+(x<<3)+c-48;
	}
}

inline void pd(int x)
{
	char c[11];
	int k=-1;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	while(k>=0)
	putchar_unlocked(c[k--]);
	putchar_unlocked('\n');
}
struct node{
	int one,two,rem;
}st[400004];

void update(int sl,int sr,int l,int r,int ind)
{
	if(sr<l || sl>r)
	return;
	if(l<=sl && r>=sr)
	{
		int temp=st[ind].one;
		st[ind].one=(sr-sl+1)-st[ind].two-temp;
		st[ind].two=temp;
		st[ind].rem=(st[ind].rem+1)%3;
		return;
	}
	int mid=(sl+sr)/2;
	update(sl,mid,l,r,2*ind+1);
	update(mid+1,sr,l,r,2*ind+2);
	st[ind].one=st[2*ind+1].one+st[2*ind+2].one;
	st[ind].two=st[2*ind+1].two+st[2*ind+2].two;
	if(st[ind].rem==1)
	{
		int temp=st[ind].one;
		st[ind].one=(sr-sl+1)-st[ind].two-temp;
		st[ind].two=temp;
	}
	else if(st[ind].rem==2){
	int temp=st[ind].one;
	st[ind].one=st[ind].two;
	st[ind].two=(sr-sl+1)-st[ind].two-temp;
	}
}

int query(int sl,int sr,int l,int r,int ind,int rem)
{
	if(sr<l || sl>r)
	return 0;
	if(l<=sl && r>=sr)
	{
		if(rem==1)
		return st[ind].two;
		if(rem==2)
		return st[ind].one;
		return (sr-sl+1)-st[ind].one-st[ind].two;
	}
	int mid=(sl+sr)/2;
	rem=(rem+st[ind].rem)%3;
	return query(sl,mid,l,r,2*ind+1,rem)+query(mid+1,sr,l,r,2*ind+2,rem);
	
}
int main()
{
	int n,q;
	rd(n);
	rd(q);

	int t,l,r;
	while(q--)
	{
		rd(t);
		rd(l);
		rd(r);
	
		if(t==1)
		pd(query(0,n-1,l,r,0,0));
		else
		update(0,n-1,l,r,0);
	}
}
