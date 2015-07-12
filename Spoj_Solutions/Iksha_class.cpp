#include<iostream>
using namespace std;
#define MOD 1000000007
int fact[100001];
int parent[100001];
int count[100001];
int facto(int num)
{
	if(fact[num]!=-1)
	return fact[num];
	else
	return fact[num]=((num*facto(num-1))%MOD);
}
int findp(int num)
{
	if(parent[num]!=num)
	return parent[num]=findp(parent[num]);
	return num;
}
int main()
{
	unsigned long long int ans=1,temp;
	int n,k,a,b;
	
	
	cin>>n>>k;
	for(int i=0;i<=n;i++)
	parent[i]=-1,count[i]=0,fact[i]=-1;
	
	fact[0]=1;
	fact[1]=1;
	for(int i=0;i<k;i++)
	{
		cin>>a>>b;
		if(parent[a]==-1 && parent[b]==-1)
		parent[a]=a,parent[b]=a,count[a]=2;
		else if(parent[a]==-1)
		parent[a]=findp(b),count[parent[a]]++;
		else if(parent[b]==-1)
		parent[b]=findp(a),count[parent[b]]++;
		else
		{
			int u=findp(a);
			int v=findp(b);
			if(u!=v){
			parent[v]=u;
			count[u]+=count[v];
			count[v]=0;
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
	
		if(count[i]!=0)
		{
			temp=facto(count[i]);
			ans=(ans*temp)%MOD;
		}
		
	}
	cout<<ans<<endl;
}
