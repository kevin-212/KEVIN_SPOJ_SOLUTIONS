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
long long int x[100001];
long long int y[100001];
pii stx[400004];
pii sty[400004];

void buildx(int sl,int sr,int index)
{
	if(sl==sr)
	{
	stx[index]=pii(sl,sl);
	return;
	}
	int mid=(sl+sr)/2;
	buildx(sl,mid,2*index+1);
	buildx(mid+1,sr,2*index+2);
	if(x[stx[2*index+1].first]>x[stx[2*index+2].first])
	stx[index].first=stx[2*index+1].first;
	else 
	stx[index].first=stx[2*index+2].first;
	
	if(x[stx[2*index+1].second]<x[stx[2*index+2].second])
	stx[index].second=stx[2*index+1].second;
	else 
	stx[index].second=stx[2*index+2].second;
}

void buildy(int sl,int sr,int index)
{
	if(sl==sr)
	{
	sty[index]=pii(sl,sl);
	return;
	}
	int mid=(sl+sr)/2;
	buildy(sl,mid,2*index+1);
	buildy(mid+1,sr,2*index+2);
	if(y[sty[2*index+1].first]>y[sty[2*index+2].first])
	sty[index].first=sty[2*index+1].first;
	else 
	sty[index].first=sty[2*index+2].first;
	
	if(y[sty[2*index+1].second]<y[sty[2*index+2].second])
	sty[index].second=sty[2*index+1].second;
	else 
	sty[index].second=sty[2*index+2].second;
	
	
}
void updatex(int in,int sl,int sr,long long int val,int index)
{
	if(sl==in && sr==in)
	{
		x[sl]=val;
		return;
	}
	int mid=(sl+sr)/2;
	if(in<=mid)
	updatex(in,sl,mid,val,2*index+1);
	else
	updatex(in,mid+1,sr,val,2*index+2);
	
	if(x[stx[2*index+1].first]>x[stx[2*index+2].first])
	stx[index].first=stx[2*index+1].first;
	else 
	stx[index].first=stx[2*index+2].first;
	
	if(x[stx[2*index+1].second]<x[stx[2*index+2].second])
	stx[index].second=stx[2*index+1].second;
	else 
	stx[index].second=stx[2*index+2].second;
	
	
}

void updatey(int in,int sl,int sr,long long int val,int index)
{
	if(sl==in && sr==in)
	{
		y[sl]=val;
		return;
	}
	int mid=(sl+sr)/2;
	if(in<=mid)
	updatey(in,sl,mid,val,2*index+1);
	else
	updatey(in,mid+1,sr,val,2*index+2);
	
	if(y[sty[2*index+1].first]>y[sty[2*index+2].first])
	sty[index].first=sty[2*index+1].first;
	else 
	sty[index].first=sty[2*index+2].first;
	
	if(y[sty[2*index+1].second]<y[sty[2*index+2].second])
	sty[index].second=sty[2*index+1].second;
	else 
	sty[index].second=sty[2*index+2].second;
	
	
}

pii queryx(int l,int r,int sl,int sr,int index)
{
	
	if(l==sl && r==sr)
	return stx[index];
	int mid=(sl+sr)/2;
	if(sr<=mid)
	queryx(l,r,sl,mid,2*index+1);
	else if(sl>mid)
	queryx(l,r,mid+1,sr,2*index+2);
	else
	{
		pii x3;
		pii x1=queryx(l,mid,sl,mid,2*index+1);
		pii x2=queryx(mid+1,r,mid+1,sr,2*index+2);
		if(x[x1.first]>x[x2.first])
		x3.first=x1.first;
		else
		x3.first=x2.first;
		if(x[x1.second]<x[x2.second])
		x3.second=x1.second;
		else
		x3.second=x2.second;
		
		
		return x3;
		
	}
	
	
}

pii queryy(int l,int r,int sl,int sr,int index)
{
	
	if(l==sl && r==sr)
	return sty[index];
	int mid=(sl+sr)/2;
	if(sr<=mid)
	queryy(l,r,sl,mid,2*index+1);
	else if(sl>mid)
	queryy(l,r,mid+1,sr,2*index+2);
	else
	{
		pii y3;
		pii y1=queryy(l,mid,sl,mid,2*index+1);
		pii y2=queryy(mid+1,r,mid+1,sr,2*index+2);
		if(y[y1.first]>y[y2.first])
		y3.first=y1.first;
		else
		y3.first=y2.first;
		if(y[y1.second]<y[y2.second])
		y3.second=y1.second;
		else
		y3.second=y2.second;
		
		
		return y3;
		
	}
	
	
}


int  main()
{
	
	int n,i,q,in,l,r;
	char c1;
	long long int j,k,a,b,c,d,e,f,x1,y1;
	rd(n);
	for(i=0;i<n;i++)
	{
		rdl(j);
		rdl(k);
		x[i]=(j+k)/2LL;
		y[i]=(j-k)/2LL;
		
		cout<<x[i]<<" "<<y[i]<<endl;		
	}
		buildx(0,0,0);
		buildy(0,0,0);
	rd(q);
	while(q--)
	{
		c1=gc();
		for(;c1!='U' && c1!='Q';c1=gc());
		cout<<c1<<endl;
		if(c1=='U')
		{
			rd(in);
			rdl(x1);
			rdl(y1);
			
			updatex(in,0,n-1,(1LL*x1+y1)/2,0);
			updatey(in,0,n-1,(1LL*x1-y1)/2,0);
			
		}
		else
		{
			rd(l);
			rd(r);
			pii x1=queryx(l,r,0,n-1,0);
			pii y1=queryy(l,r,0,n-1,0);
			cout<<x1.first<<" "<<x1.second<<endl;
			cout<<y1.first<<" "<<y1.second<<endl;
			a=x[x1.first]-x[x1.second];
			b=x[y1.first]-y[y1.second];
			cout<<a<<" "<<b<<endl;
			if(a>b)
			{
				c=x[x1.first]+y[x1.first];
				d=x[x1.second]+y[x1.second];
				e=x[x1.first]-y[x1.first];
				f=x[x1.second]-y[x1.second];
				pdl(abs(c-d)+abs(e-f));
				
				
			}
			else
			{
				c=x[y1.first]+y[y1.first];
				d=x[y1.second]+y[y1.second];
				e=x[y1.first]-y[y1.first];
				f=x[y1.second]-y[y1.second];
				pdl(abs(c-d)+abs(e-f));
				
				
			}
			
		}
		
	}
}

