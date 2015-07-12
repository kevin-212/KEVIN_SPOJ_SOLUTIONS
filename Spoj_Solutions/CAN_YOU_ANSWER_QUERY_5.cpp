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
struct node{
	int premax,sufmax,midmax;

	
};
int arr[10001];
int sum[10001];
node st[40004];
int st2[40004];
void build1(int sl,int sr,int ind)
{
	if(sl==sr)
	{
		st[ind].premax=st[ind].midmax=st[ind].sufmax=arr[sl];
		return;
	}
	int mid=(sl+sr)/2;
	build1(sl,mid,2*ind);
	build1(mid+1,sr,2*ind+1);
node left=st[2*ind];
node right=st[2*ind+1];
st[ind].premax=max(left.premax,sum[mid]-sum[sl-1]+right.premax);
st[ind].sufmax=max(right.sufmax,sum[sr]-sum[mid]+left.sufmax);
st[ind].midmax=max(left.midmax,max(right.midmax,left.sufmax+right.premax));
}
node query(int sl,int sr,int ind,int l,int r)
{
	if(l>r)
	return st[0];
	if(sl==l && sr==r)
	return st[ind];
	int mid=(sl+sr)/2;
	if(r<=mid)
	return query(sl,mid,2*ind,l,r);
	if(l>mid)
	return query(mid+1,sr,2*ind+1,l,r);
	
	node left=query(sl,mid,2*ind,l,mid);
	node right=query(mid+1,sr,2*ind+1,mid+1,r);
	node temp;
	temp.premax=max(left.premax,sum[mid]-sum[l-1]+right.premax);
temp.sufmax=max(right.sufmax,sum[r]-sum[mid]+left.sufmax);
temp.midmax=max(left.midmax,max(right.midmax,left.sufmax+right.premax));

return temp;	
}	

int main()
{
	int t,n,i,j,k,m,x1,y1,x2,y2,temp1,temp2,temp3;
	rd(t);
	st[0].premax=-100000001;
	st[0].sufmax=-100000001;
	st[0].midmax=-100000001;
	node one,two,three,four;
	while(t--)
	{
		rd(n);
	
		for(i=1;i<=n;i++)
		rdl(arr[i]),sum[i]=arr[i]+sum[i-1];
		build1(1,n,1);
		rd(m);
		while(m--)
		{
			rd(x1);
			rd(y1);
			rd(x2);
			rd(y2);
		if(y1<x2)
		{
			
		 one =query(1,n,1,x1,y1);
		 two =query(1,n,1,x2,y2);
		 if(y1+1<=x2-1)
		 temp1=sum[x2-1]-sum[y1];
		 else
		 temp1=0;
		 pd(one.sufmax+two.premax+temp1);
		}
		else{
		one=query(1,n,1,x2,y1);
		temp2=one.midmax;
//		cout<<temp2<<endl;
		two=query(1,n,1,x1,x2-1);
		three=query(1,n,1,x2,y2);
		temp2=max(temp2,two.sufmax+three.premax);
//		cout<<temp2<<two.sufmax<<" "<<three.premax<<endl;
		two=query(1,n,1,x1,y1);
		three=query(1,n,1,y1+1,y2);
		temp2=max(temp2,two.sufmax+three.premax);
		pd(temp2);
		}
		}
	}
}
