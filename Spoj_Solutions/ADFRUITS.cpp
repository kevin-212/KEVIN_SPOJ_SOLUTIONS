#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int main()
{
	char str1[103],str2[103];
	int l1,l2,miN;
	int arr[103][103];
	vector<pii>index;
	while(scanf("%s %s",str1,str2)==2)
	{
		miN=0;

		l1=strlen(str1);
		l2=strlen(str2);
		memset(arr,0,sizeof(arr));
		index.clear();
		for(int i=1;i<=l1;i++)
		{
			for(int j=1;j<=l2;j++)
			{
				if(str1[i-1]==str2[j-1])
				{
					arr[i][j]=1+arr[i-1][j-1];
				}
				else
				arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
				
			}
		}
		
		int i=l1,j=l2;
		while(i>0 && j>0)
		{
			if(str1[i-1]==str2[j-1])
			{
				index.push_back(pii(i-1,j-1));
				i--;
				j--;
			}
			else
			{
				if(arr[i-1][j]>arr[i][j-1])
				i--;
				else
				j--;
			}
		}
		
		
		string ans="";
		int u,v,count1=0,count2=0;
		for(i=index.size()-1;i>=0;i--)
		{
			u=index[i].first;
			v=index[i].second;
			while(count1<u)
			{
				ans+=str1[count1++];
			}
			count1++;
			while(count2<=v)
			ans+=str2[count2++];
		}
		while(count1<l1)
		{
			ans+=str1[count1++];
		}
		while(count2<l2)
		{
			ans+=str2[count2++];
		}
		cout<<ans<<endl;
	}
}
