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
char s[250001];
int pos[500001];
int cnt[500001];
bool bh[500001];
bool b2h[500001];
int nxt[500001];
int i,l,l1,l2,j,k,h,bkt,S,temp;
int ans;
int str[500001];
int rank[500001];

bool cmp(int a,int b)
{
	return str[a]<str[b];
}
bool check(int a,int b)
{
	return a<b;
}
 


void func()
{
gets(s);
l=strlen(s);

for(i=0;i<l;i++)
pos[i]=i,bh[i]=false,str[i]=s[i]-97;
pos[l]=l,bh[l]=false,str[l]='$'-97;
gets(s);
l1=strlen(s);

l2=l+l1+1;
for(i=l+1,j=0;i<l2;i++,j++)
pos[i]=i,bh[i]=false,str[i]=s[j]-97;


bh[0]=true;
b2h[0]=false;
sort(pos,pos+l2,cmp);
for(i=1;i<l2;i++)
	bh[i]=str[pos[i]]!=str[pos[i-1]],b2h[i]=false;
	
	for(h=1;h<l2;h<<=1){
	
	bkt=0;
	for(i=0;i<l2;i=j)
	{
		j=i+1;
		while(j<l2 && !bh[j])j++;
		nxt[i]=j;
		bkt++;
	}
	if(bkt==l2)
	break;
	
	for(i=0;i<l2;i=nxt[i])
	{
		cnt[i]=0;
		for(j=i;j<nxt[i];j++)
		{
			rank[pos[j]]=i;
		}
	}
	cnt[rank[l2-h]]++;
	b2h[rank[l2-h]]=true;
	for(i=0;i<l2;i=nxt[i])
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
			for(k=rank[S]+1; !bh[k]&& b2h[k];k++)b2h[k]=false;
		}
	}
	for(i=0;i<l2;i++)
	{
		pos[rank[i]]=i;
		bh[i]|=b2h[i];
	}
}
for(i=0;i<l2;i++)
rank[pos[i]]=i,cnt[i]=0;

for(i=0,h=0;i<l2;i++)
{
	
	if(rank[i]>0)
	{
		j=pos[rank[i]-1];
		while(i+h<l2 && j+h<l2 && str[i+h]==str[j+h])h++;
		cnt[rank[i]]=h;
		if(h>0)
		h--;
	}
}
ans=0;

for(i=1;i<l2;i++)
{
	if(check(pos[i],l)!=check(pos[i-1],l))
	ans=max(ans,cnt[i]);
	
}
pd(ans);
	
}
int main()
{
clock_t start,end;
start=clock();	
		//func();	
cout<<(double)((clock()-start)/CLOCKS_PER_SEC)<<endl;		
}
