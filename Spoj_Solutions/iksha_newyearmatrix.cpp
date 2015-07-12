#include<iostream>
#include<climits>

using namespace std;

int arr[10000];
int count;
int check[101][101];
int search(int key,int i,int j)
{
	
	if(check[i][j]!=-1)
	return check[i][j];
	int l=0,mid;
	int h=count;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(arr[mid]==key)
		return check[i][j]=0;
		if(arr[mid]<key)
		l=mid+1;
		else
		h=mid-1;
	}
	if(arr[l]>key)
	return check[i][j]=arr[l]-key;
	else
	return check[i][j]=arr[l+1]-key;
}
int main()
{
	
	arr[0]=2;
	arr[1]=3;
	count=1;
	int j;
	for(int i=5;i<11000;i+=2)
	{
		for(j=0;j<=count;j++)
		{
			if(i%arr[j]==0)	
				break;
			
		}
		if(j==count+1)
		{
			count++;
			arr[count]=i;
		}
	}
	int n,l;
	cin>>n>>l;
	int arr1[101][101];
	for(int i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin>>arr1[i][j];
			check[i][j]=-1;
		}
	int temp,temp1;
	bool check1=true;
	int ans=INT_MAX;
	int u,v;
	for(int i=1;i<=n-2 && check1;i++)
	{
		for(j=1;j<=n-2;j++)
		{
			
			temp1=0;
			
				temp=search(arr1[i][j],i,j);
				
					if(temp%l==0)
						temp1+=(temp/l)	;
						else
						continue;
				
					
					temp=search(arr1[i][j+2],i,j+2);
				
					if(temp%l==0)
						temp1+=(temp/l);	
						else
						continue;
				
				
				temp=search(arr1[i+1][j+1],i+1,j+1);
				
					if(temp%l==0)
						temp1+=(temp/l);	
						else
						continue;
				
				
				temp=search(arr1[i+2][j],i+2,j);
				
					if(temp%l==0)
						temp1+=(temp/l);	
						else
						continue;
				
				
				temp=search(arr1[i+2][j+2],i+2,j+2);
				
					if(temp%l==0)
						temp1+=(temp/l)	;
						else
						continue;
				
			if(ans>temp1)
			{
				ans=temp1;
				u=i+1;
				v=j+1;
			}		
			
			
			
		}
	}

	
	if(ans!=INT_MAX)
	{
		cout<<"yes"<<endl;
		cout<<ans<<endl;
		cout<<u<<" "<<v<<endl;
	}
	else
	cout<<"no"<<endl;
	
}
