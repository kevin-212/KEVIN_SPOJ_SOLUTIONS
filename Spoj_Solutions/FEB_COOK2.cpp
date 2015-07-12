#include<bits/stdc++.h>
#define mod 10000007
using namespace std;
typedef  vector<vector<int > > matrix;

	
matrix I;
int x;
matrix mul(matrix a,matrix b)
	{
		matrix f(x,vector<int>(x));
		for(int i=0;i<x;i++)
		for(int j=0;j<x;j++)
		for(int k=0;k<x;k++)
		f[i][j]+=a[i][k]*b[k][j];
		return f;
}
matrix powe(matrix T,int n)
{
	if(n==0)
	return I;
	if(n==1)
	return T;
matrix ret=powe(T,n/2);
matrix ret1=mul(ret,ret);
if(n&1)
return mul(ret1,T);
else 
return ret1;

	
}
int powe2(int n)
{
	int ans=1;
	int p=2;
	while(n)
	{
		if(n&1)
		{
			ans*=p;
			if(ans>=mod)
			ans-=mod;
		}
		p*=p;
		if(p>=mod)
		p-=mod;
		n>>=1;
	}
	return ans;
}
int main()
{
	int i,j,k,r,b,l,t,y,w,sz,ans;
	cin>>t;

	while(t--)
	{
		
		cin>>r>>b>>l;
		if(r>b*6 || r==2 || r==1)
		cout<<0<<endl;
		else if(r&1)
		cout<<0<<endl;
		else if(r==0)
		cout<<powe2(min(l,b))<<endl;
		else
		{
			if(l>b)
			l=b;
			y=l+1;
			
			x=(r/2+1)*y;
			matrix arr(x+30,vector<int>(3+20));
			for(i=0;i<x;i++)
			{
				for(j=0;j<x;j++)
				cout<<arr[i][j]<<" ";
				cout<<endl;
			}
			w=0;
			for(i=0;i<x;i++)
			{
				
				w++;
				if(w<y){
				
					arr[i][i]=1;
					arr[i+1][i]=1;
					arr[i+2*y][i]=1;
					arr[3*y+i][i]=1;
				}
				else
				{
						arr[i][i]=1;
					arr[i+2*y][i]=1;
					arr[3*y+i][i]=1;
					w=0;
				}
				
			}
			cout<<"ok"<<endl;
			I.clear();
			I.resize(x);
			
			for(i=0;i<x;i++)
			{
				I[i].resize(x);
				I[i][i]=1;
			}
			for(i=0;i<x;i++)
			{
				for(j=0;j<x;j++)
				cout<<I[i][j]<<" ";
				cout<<endl;
			}
			matrix final=powe(arr,b);
			cout<<"ok"<<endl;
			ans=0;
			for(i=0;i<x;i++)
			{
				for(j=0;j<x;j++)
				cout<<final[i][j]<<" ";
				cout<<endl;
			}
			for(i=x-1;i>=x-y;i--)
			{
				
				ans+=final[i][0];
				if(ans>=mod)
				ans-=mod;
			}
			cout<<ans<<endl;
		}
	}
}
