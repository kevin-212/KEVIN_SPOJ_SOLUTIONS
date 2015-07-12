#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
#define mod 1000000007
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


bool check;
int mx;
struct node{
	node *child[8];
	int count1,lps;
	
};
node*getnode()
{
	node*temp=new node;
	for(int i=0;i<8;i++)
	temp->child[i]=NULL;
	temp->count1=0,temp->lps=0;
	return temp;
}
struct trie{
	node*root;
	
};
trie* gettree()
{
	trie*temp=new trie;
	temp->root=getnode();
	return temp;
}

char s[100001];
int l,ans;

void add(trie*st,int i,int*lps,int*count)
{
	
	int t1,left,right,len2,len,ans1;
	node*pcrawl=st->root;
	len=i;
	lps[i]=i;
	count[i]=0;
	int j;
	j=i;
	t1=s[j]-'a';
	mx=len;
	if(pcrawl->child[t1]==NULL)
			pcrawl->child[t1]=getnode();
			
		pcrawl=pcrawl->child[t1],j++;
	for( ;j<l;)
	{
		t1=s[j]-'a';
		ans1=0;
		if(pcrawl->child[t1]==NULL)
		{
			pcrawl->child[t1]=getnode();
			while(true)
			{
			if(s[j]==s[len])
			{
			len++,lps[j]=len;
			len2=len;
			while(len2!=i)
			{
			
			if(mx<len2){
			
			left=i,right=len2-1;
			check=true;
			while(left<right)
			{
				if(s[left]!=s[right])
				{
				check=false;
				break;
				}
				left++;
				right--;
				
			}
			if(check)
			ans1++;
			len2=lps[len2-1];
		}
		else
			{
			ans1+=count[len2];
			break;
			}
			
		
			}
			count[len]=ans1;
			mx=len;
			break;
		}
		else
		{
			if(len!=i)
			len=lps[len-1];
			else
			{
			lps[j]=i;
			break;
			}
		}
		
		}
		pcrawl=pcrawl->child[t1];
		pcrawl->count1=ans1;
		pcrawl->lps=len;
	}
	else
	{
		pcrawl=pcrawl->child[t1];
		ans1+=pcrawl->count1;
		len=pcrawl->lps;
		lps[j]=len;
		if(mx<len)
		count[len]=pcrawl->count1,mx=len;
		if(ans1>=mod)
			ans1-=mod;
	}
	
	j++;
	ans+=ans1;
	cout<<ans1<<" "<<ans<<endl;
	if(ans>=mod)
	ans-=mod;
	
	}
	
}
int main()
{
	trie*st=gettree();
	
	
	scanf("%s",s);
	 l=strlen(s);
	 int lps[l];
	 int count[l];
	 memset(count,-1,sizeof count);
	 int i;
	 ans=0;
	 for(i=0;i<l;i++)
	 add(st,i,lps,count);
	 pd(ans);
}
