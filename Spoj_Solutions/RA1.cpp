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
bool cmp(int  a,int b)
{
	return a>b;
}
vector<string> arr;
vector<string> arr1;
vector<string> arr2;
int main()
{
	int t,n,l,i,j,k;
	int ans,mn,ind=1;
	ifstream cin("RA1L.in");
	ofstream cout("RA1A.txt");
	if(cin.is_open())
	{
	cin>>t;
	while(t--)
	{
		cin>>n>>l;
		ans=0;
		mn=100000000;
		arr.clear();
		arr.resize(n);
		arr1.clear();
		arr1.resize(n);
		for(i=0;i<n;i++)
		cin>>arr[i];
		for(i=0;i<n;i++)
		cin>>arr1[i];
		sort(arr1.begin(),arr1.end());
		
		for(i=0;i<n;i++)
		{
			arr2=arr;
			ans=0;
			for(j=0;j<l;j++)
			{
				
				if(arr1[i][j]!=arr2[0][j])
				{
					ans++;
					for(k=0;k<n;k++)
					arr2[k][j]^=1;
				}
			}
			sort(arr2.begin(),arr2.end());
			if(arr1==arr2)
			{
				mn=min(mn,ans);
			}
			
		}
		cout<<"Case #"<<ind++<<": ";
		if(mn==100000000)
		cout<<"NOT POSSIBLE"<<endl;
		else
		cout<<mn<<endl;
	}
	
	
	}
}
