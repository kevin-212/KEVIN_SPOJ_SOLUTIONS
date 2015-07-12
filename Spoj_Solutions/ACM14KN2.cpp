#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define piii pair<int,pii>
typedef long long ll;
typedef vector<vector<ll> > matrix;

matrix mul(matrix a,matrix b)
{
	
	int sz=(int)a.size();
	matrix ans(sz,vector< ll >(sz));
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<sz;j++)
		{
			for(int k=0;k<sz;k++)
			ans[i][j]+=a[i][k]*b[k][j];
		}
	}
	return ans;
}
int main()
{
	int a,b,c,d,e,f,i,j,sz;
	int n,k,t;
	cin>>t;
	while(t--){
	
	map<int,piii>mp;
	cin>>n>>k;
	if(k>0){
	
	i=0;
	for(a=0;a<k;a++)
	{
		for(b=0;b<2;b++)
		{
			for(c=0;c<2;c++)
			{
				mp[i]=piii(a,pii(b,c));		
				i++;			
			}
		}
	}
	
	 sz=k*4;
	matrix arr(sz,vector<ll> (sz));
	for(i=0;i<sz;i++)
	{
		a=mp[i].first;
		b=mp[i].second.first;
		c=mp[i].second.second;
		for(j=0;j<sz;j++)
		{
			arr[i][j]=0;
			d=mp[j].first;
			e=mp[j].second.first;
			f=mp[j].second.second;
			if(f==c)
			{
				if(e==1)
				{
					if(b==0)
					{
						arr[i][j]=f+(a==((d+1)%k));
					}
				}
				else if(e==0)
				{
					if(b==1)
					{
						arr[i][j]=(a==d);
					}
					else
					arr[i][j]=(a==(d+1)%k)+f;
				}
			}
			else if(f==0 && c==1)
			{
				if(e==0 || e==1)
				arr[i][j]=(a==d && (b==0));
			
				
			}
			
			
		}
	}
	
	
	matrix I(sz,vector<ll>(sz));
	
for(i=0;i<sz;i++)	
I[i][i]=1;


for(i=0;i<sz;i++)
	{
		for(j=0;j<sz;j++)
		cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

while(n)
{
	if(n&1)
	I=mul(I,arr);
	arr=mul(arr,arr);
	n>>=1;
	for(i=0;i<sz;i++)
	{
		for(j=0;j<sz;j++)
		cout<<I[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(i=0;i<sz;i++)
	{
		for(j=0;j<sz;j++)
		cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}
	cout<<I[1][0]+I[3][0]<<endl;
}
else
{
	cout<<pow(2,n)-1<<endl;
}
}
}
