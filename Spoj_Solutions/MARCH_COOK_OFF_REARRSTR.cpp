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
struct node{
	
	char c;
	node* next;
	nede* prev;
};
bool cmp(int  a,int b)
{
	return cnt[a]>cnt[b];
}
int cnt[26];
int main()
{
	int t,i,j,k,l,sum;
	node* head=new node[100001];
	node*pnt;
	head->prev=NULL;
	char c;
	rd(t);
	for(i=0;i<26;i++)
	index[i]=i;
	while(t--)
	{
		c=gc();
		memset(cnt,0,sizeof(cnt));
		sum=0;
		for(;c<'a' || c>'z';c=gc());
		for(;c>='a' && c<='z';c=gc())
		cnt[c-'a']++,sum++;
		
		
	}
	sort(index,index+26,cmp);
	sum-=cnt[index[0]];
	sum++;
	if((sum<cnt[index[0]])
	pd(-1);
	else
	{
		j=cnt[index[0]];
		head->c=(char)index[0]+'a';
		pnt=head->next;
		pnt->prev=head;
		j--;
		while(j>0)
		{
			pnt->c=(char)index[0]+'a';
			pnt=pnt->next;
			
		}
		
		
		
	}
	
	
	
}
