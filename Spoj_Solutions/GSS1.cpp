#include<bits/stdc++.h>

using namespace std;

/*void ini(int&n)
{
	n=0;
	char ch;
	ch=getcx();
	while(ch<48 || ch>58)
	ch=getcx();
	while(ch>=48 && ch<=57)
	{
		n=(n<<3)+(n<<1)+ch-'0';
	}
}*/
struct node{
	long int left,ans,right,sum;
};
 int temp[100100];
node arr[400400];

/*int maxcross(int low,int mid,int high)
{
	int ls=-16000;
	int rs=-16000;
	int i;
	int sum=0;
	for(i=mid;i>=low;i--)
	{
		sum+=temp[i];
		if(sum>ls)
		ls=sum;
	}
	sum=0;
	for(i=mid+1;i<=high;i++)
	{
		sum+=temp[i];
		if(sum>rs)
		rs=sum;
	}
	return ls+rs;
}*/
void build( int ss, int se, int index)
{
	if(ss==se)
	{
		arr[index]=((node){temp[ss],temp[ss],temp[ss],temp[ss]});
		return;
		
	}
	 int mid=(ss+se)/2;
	build(ss,mid,2*index);
	build(mid+1,se,2*index+1);
	node lft=arr[2*index];
	node rgt=arr[2*index+1];
	arr[index]=((node){max(lft.left,lft.sum+rgt.left),max(lft.ans,max(rgt.ans,lft.right+rgt.left)),max(rgt.right,rgt.sum+lft.right),lft.sum+rgt.sum});
	
}

node query(int ss,int se, int qs, int qe, int index)
{
	if(qs==ss && qe==se)
	return arr[index];
	int mid=(ss+se)/2;
	if(qe<=mid)
	return  query(ss,mid,qs,qe,2*index);
	if(qs>mid)
	return query(mid+1,se,qs,qe,2*index+1);

	node lft=query(ss,mid,qs,mid,2*index);
	node rgt=query(mid+1,se,mid+1,qe,2*index+1);
	return ((node){max(lft.left,lft.sum+rgt.left),max(lft.ans,max(rgt.ans,lft.right+rgt.left)),max(rgt.right,rgt.sum+lft.right),lft.sum+rgt.sum});
}

int main()
{
	 int n;
	scanf("%d",&n);
	
	 int i,j;
map<int,int>mp;

	int t;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(mp[t]==0){
		
		mp[t]++;
		temp[i]=t;
		}
		else
		temp[i]=0;
	}
	
	build(1,n,1);
	int m;
	int x,y;

	scanf("%d",&m);
	
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		
		printf("%ld\n",query(1,n,x,y,1).ans);
	}
}
