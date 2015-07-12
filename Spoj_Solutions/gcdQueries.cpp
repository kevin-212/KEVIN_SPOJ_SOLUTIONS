
#include<cstdio>
#include<cmath>
using namespace std;


int gcdq(int a,int b)
{
	int temp;
	while(b!=0)
	{
		temp=a;
		a=b;
		b=temp%b;
	}
	return a;
}		
int constructst(int *arr,int* st,int ss,int se,int index)
{
	
	
	if(ss==se)
	{
	 st[index]=arr[ss];
	 return arr[ss];
	}
	int mid=(ss+se)/2;
	st[index]=gcdq(constructst(arr,st,ss,mid,2*index+1),constructst(arr,st,mid+1,se,2*index+2));
	return st[index];
	
}

int gcdutill(int*st,int ss,int se,int qs,int qe,int index)
{
	if(qs<=ss && qe>=se)
	return st[index];
	if(qe<ss || qs>se)
	return -1;
	int mid=(ss+se)/2;
	int temp1=gcdutill(st,ss,mid,qs,qe,2*index+1);
	int temp2=gcdutill(st,mid+1,se,qs,qe,2*index+2);
	if(temp1==-1 && temp2==-1)
	return -1;
	if(temp1==-1)
	return temp2;
	if(temp2==-1)
	return temp1;
	
	return gcdq(temp1,temp2);
}
int main()
{
	int tc,q;
	int arr[100000];
int n;
	scanf("%d",&tc);
	while(tc--)
	{
	
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	int maxheight=(int)(ceil(log2(n)));
	int maxsize=2*(pow(2,maxheight))-1;
	int*st=new int[maxsize];
	int mid=(n-1)/2;
	constructst(arr,st,0,n-1,0);

	int a, b;
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&a,&b);
		a--,b--;
		int temp1=gcdutill(st,0,n-1,0,a-1,0);
		int temp2=gcdutill(st,0,n-1,b+1,n-1,0);
		if(temp1==-1)
		printf("%d\n",temp2);
		else if(temp2==-1)
		printf("%d\n",temp1);
		else
		printf("%d\n",gcdq(temp1,temp2));
		
	}
	}
	
}
