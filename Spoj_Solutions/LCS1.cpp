#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
#define MOD 1000000007
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

int l,l1,l2;
int mx=0;
int pos[500010];
int nxt[500010];
int rank[500010];
int str[500010];
bool bh[500010];
bool b2h[500010];
int cnt[500010];
char s[500010];
char s2[250001];
bool cmp(int  a,int b)
{
	return str[a]<str[b];
}


void suffixarray()
{
	int i,j,k,h,S,temp,bkt;
	pos[0]=0;
	for(i=0;i<l;i++)
	bh[i]=false,str[i]=s[i]-65,pos[i]=i;
	sort(pos,pos+l,cmp);
	b2h[i]=false;
	bh[i]=true;
	for(i=1;i<l;i++)
	bh[i]=(str[pos[i]]!=str[pos[i-1]]),b2h[i]=false;
	for(h=1;j<l;h<<=1)
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
		b2h[rank[l-h]]=true;
		cnt[rank[l-h]]++;
		
		for(i=0;i<l;i=nxt[i])
		{
			
			for(j=i;j<nxt[i];j++)
			{
				S=pos[j]-h;
				if(S>=0)
				{
					temp=rank[S];
					rank[S]=temp+cnt[temp]++;
					b2h[rank[S]]=true;
				
				}
				
				
			}
			
			
			for(j=i;j<nxt[i];j++)
			{
				S=pos[j]-h;
				temp=rank[S];
				if(S>=0 && b2h[rank[S]])
				{
					
					for(k=rank[S]+1; !bh[k] && b2h[k];k++)b2h[k]=false;					
				}
			}
		}
		
		for(i=0;i<l;i++)
		pos[rank[i]]=i,bh[i]|=b2h[i];
		
	}
	for(i=0;i<l;i++)
	rank[pos[i]]=i,cnt[i]=0;
	
	for(i=0,h=0;i<l;i++)
	{
		
		if(rank[i]>0)
			{
				j=pos[rank[i]-1];
				while(i+h<l && j+h<l && str[i+h]==str[j+h])h++;
				cnt[rank[i]]=h;
				if(h>0)
				h--;
				
				
			}	
		
		
	}
	for(i=1;i<l;i++)
	{
		j=cnt[i];
		if((pos[i]<l1 && pos[i-1]>l1) || (pos[i]>l1 && pos[i-1]<l1))
		mx=max(j,mx);
	}
	pd(mx);
	
	
}

int main()
{
	
	scanf("%s",s);
	l1=strlen(s);
	s[l1]='#';
	scanf("%s",s2);
	l2=strlen(s2);
	strcat(s,s2);
	l=strlen(s);
	suffixarray();
	
	
}
