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
char s[10001];
int bkt,i,j,k,l,h;
int cnt[10001];
bool bh[10001];
bool b2h[10001];
int head,temp;
int nxt[10001];
int str[10001];
int pos[10001];
int rank[10001];
bool cmp(int a,int b)
{
	return str[a]<str[b];
}

bool solve()
{
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;i++)
	pos[i]=i,str[i]=s[i]-47;
	
	sort(pos,pos+l,cmp);
	bh[0]=true;
	b2h[0]=false;
	for(i=1;i<l;i++)
	{
		bh[i]=(str[pos[i]]!=str[pos[i-1]]);
		b2h[i]=false;
	}

	for(h=1;h<l;h<<=1)
	{
		bkt=0;
	for(i=0;i<l;i=j)
	{
		j=i+1;
		while(j<l && !bh[j])j++;
		nxt[i]=j;
		bkt++;
		
	}
	if(bkt==l)
	break;
	for(i=0;i<l;i=nxt[i])
	{
		cnt[i]=0;
		for(j=i;j<nxt[i];j++)
		rank[pos[j]]=i;
	}
		
		cnt[rank[l-h]]++;
		b2h[rank[l-h]]=true;
		for(i=0;i<l;i=nxt[i])
		{
			for(j=i;j<nxt[i];j++)
			{
				head=pos[j]-h;
				if(head>=0)
				{
				temp=rank[head];
				rank[head]=temp+cnt[temp]++;
				b2h[rank[head]]=true;
				}
			}
				
			for(j=i;j<nxt[i];j++)
			{
				head=pos[j]-h;
				if(head>=0 && b2h[rank[head]])
				{
					for(k=rank[head]+1;!bh[k] && b2h[k];k++)b2h[k]=false;
				}
			}	
		}
		for(i=0;i<l;i++)
		{
			bh[i]|=b2h[i];
			pos[rank[i]]=i;
		}
		
	}
	for(i=0;i<l;i++)
	pd(pos[i]);
}


int main()
{
	solve();
	
}
