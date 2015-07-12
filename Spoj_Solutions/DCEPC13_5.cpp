#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rd(int &x)
{
	x=0;
	register int c=gc();
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
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
	pc(c[k--]);
	pc('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}
struct node{
	 node* arr[2];
	 int value;
	
};
node* getnode()
{
	node*temp=new node();
	temp->arr[0]=temp->arr[1]=NULL;
	temp->value=0;
	return temp;
	
}
struct tree{
	node*root;
};
tree* gettree()
{
	tree*temp=new tree();
	temp->root=getnode();
	return temp;
	
}

void add(tree*st,int num)
{
	int i,j;
	node*pcrawl=st->root;
	for(i=29;i>=0;i--)
	{
		j=((num>>i)&1);
		if(pcrawl->arr[j]==NULL)
		{
			pcrawl->arr[j]=getnode();
		}
		pcrawl->value++;
		pcrawl=pcrawl->arr[j];
	}
	pcrawl->value++;
	
}

int find(node*st,int n)
{
	
	int left,right;
	int ans=0;
	bool checkl,checkr;
	checkl=checkr=false;
	if(st->arr[0] !=NULL)
	{
		if(st->arr[0]->value>=2)
		left=find(st->arr[0],n+1),checkl=true;
		
	}
	if(st->arr[1]!=NULL)
	{
		if(st->arr[1]->value>=2)
		right=find(st->arr[1],n+1),checkr=true;	
	}
	if(checkl && checkr)
	return min(left,right);
	if(checkl)
	return left;
	if(checkr)
	return right;
	else{
		node* temp=st->arr[0];
		node*temp1=st->arr[1];
		if(temp && temp1)
		ans|=(1<<(29-n));
		n++;
		while(n<=29){
		if(temp->arr[0]!=NULL)
		{
			temp=temp->arr[0];
			if(temp1->arr[0]!=NULL)
			temp1=temp1->arr[0],n++;
			else
			{
			temp1=temp->arr[1];
			ans|=(1<<(29-n));n++;
			}
		}
		else
		{
			temp=temp->arr[1];
			if(temp1->arr[1]!=NULL)
			temp1=temp1->arr[1],n++;
			else
			{
			temp1=temp->arr[0];
			ans|=(1<<(29-n));n++;
			}
		}
		}
		return ans;
	}
	
}
int main()
{
	int n,i,j,k,ans;
	int arr[100001];
	rd(n);
	for(i=0;i<n;i++)
	rd(arr[i]);
	tree* st=gettree();
	for(i=0;i<n;i++)
	add(st,arr[i]);
	

	ans=find(st->root,0);
	pd(ans);
}
