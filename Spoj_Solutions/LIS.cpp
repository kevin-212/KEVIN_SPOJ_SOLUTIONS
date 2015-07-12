#include<bits/stdc++.h>
using namespace std;
int arr[1000001];
int m[1000001];
int main(){

int n;
cin>>n;
int i;
for(i=0;i<n;i++)
cin>>arr[i];
m[0]=0;
int len=0;
int lo,high,mid;
for(i=0;i<n;i++)
{
	lo=1;
	high=len;
	while(lo<=high)
	{
		mid=(lo+high)/2;
		if(arr[m[mid]]<arr[i])
		lo=mid+1;
		else
		high=mid-1;
	}
	m[lo]=i;
	if(len<lo)
	len=lo;
}
cout<<len<<endl;
}
