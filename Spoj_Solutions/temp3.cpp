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

char s[1001];
bool bh[1001];
bool b2h[1001];
int rank[1001];
int pos[1001];
int str[1001];
int i,j,k,l;
int next[1001];
int bucket;
int cnt[1001];

bool cmp(int a,int b)
{
	return str[a]<str[b];
}
void solve()
{

	scanf("%s",s);
	l=strlen(s);
	
	for(i=0;i<l;i++)
	{
		bh[i]=b2h[i]=false;
		pos[i]=i;
		str[i]=s[i]-65;
	}
	sort(pos,pos+l,cmp);
	bh[0]=true;
	for(i=1;i<l;i++)
	{
		bh[i]=str[pos[i]]!=str[pos[i-1]];
		b2h[i]=false;
		if(bh[i])
		cout<<"bh["<<i<<"]"<<" "<<"true"<<endl;
		else
		cout<<"bh["<<i<<"]"<<" "<<"false"<<endl;
	}
	
	
	
	
	for(int h=1;h<l;h<<=1)
	{
		bucket=0;
		for(i=0;i<l;i=j)
		{
			j=i+1;
			while(j<l && !bh[j])j++;
			next[i]=j;
			bucket++;
		}
		cout<<"bucket"<<" "<<bucket<<endl;
		if(bucket==l)
		break;
		for(i=0;i<l;i=next[i])
		{
			cnt[i]=0;
			for(j=i;j<next[i];j++)
			{
				rank[pos[j]]=i;
				cout<<"rank[pos["<<j<<"]]"<<" "<<i<<endl;
			}
			
			
		}
	cnt[rank[l-h]]++;
	b2h[rank[l-h]]=true;
		for(i=0;i<l;i=next[i])
		{
			for(j=i;j<next[i];j++)
			{
				int s=pos[j]-h;
				cout<<"s"<<" "<<s<<endl; 
				if(s>=0){
				int head=rank[s];
				rank[s]=head+cnt[head]++;
				cout<<"rank["<<s<<"]"<<" "<<rank[s]<<endl;
				b2h[rank[s]]=true;
				}
			
			}
			
			for(j=i;j<next[i];j++)
			{
				int s=pos[j]-h;
				if(s>=0 && b2h[rank[s]])
				{
					for(k=rank[s]+1; !bh[k] && b2h[k];k++)b2h[k]=false,cout<<"k"<<" "<<k<<endl;
			
				}
				
			}
			
		}
		for(i=0;i<l;i++)
		{
			pos[rank[i]]=i;
			cout<<"pos[rank["<<i<<"]]"<<i<<endl;
			bh[i]|=b2h[i];
		}
		
		
	}
	for(i=0;i<l;i++)
	rank[pos[i]]=i,cnt[i]=0;
	
	for(i=0,k=0;i<l;i++)
	{
		if(rank[i]>0)
		{
			j=pos[rank[i]-1];
			while(i+k<l && j+k<l && str[i+k]==str[j+k])k++;
			cnt[rank[i]]=k;
			if(k>0)
			k--;
			
		}
		
	}
	k=0;
	k+=(l-pos[0]);
	for(i=1;i<l;i++)
	{
		k+=(l-pos[i]-cnt[i]);
		
	}
	pd(k);
	
}


int main()
{
	int t;
	rd(t);
	while(t--)
	{
		solve();
	}
	
	
}
