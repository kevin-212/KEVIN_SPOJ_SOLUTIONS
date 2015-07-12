#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define piii pair<int,pii>
int main()
{
	
	int tc,n,count,l,r,u,v,id,ans;
	vector<piii>arr(40000);
	bool check[40001];
	bool check1;
	scanf("%d",&tc);
	while(tc--)
	{
		arr.clear();
		scanf("%d",&n);
		ans=0;
		memset(check,false,sizeof(check));
		count=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&l,&r);
			
			for(int j=0;j<count;j++)
			{
				check1=true;
				u=arr[j].first;
				v=arr[j].second.first;
				id=arr[j].second.second;
				if(l<=v && u<=r)
				{
					if(u<l)
					{
						
							arr[j]=piii(u,pii(l-1,id));
							check1=false;
					}
					if(v>r)
					{
						if(check1){
							arr[j]=piii(r+1,pii(v,id));
							check1=false;
						}
						else{
						arr.push_back(piii(r+1,pii(v,id)));
						count++;
						}
					}
					if(check1)
					{
						arr[j]=piii(-1,pii(-1,-1));
					}
				}
				
			}
			arr.push_back(piii(l,pii(r,i)));
			count++;
			
		}
		int sz=arr.size();
		for(int i=0;i<sz;i++)
		{
			id=arr[i].second.second;

			if(id>=0){
			if(!check[id] )
			{
				ans++;
				check[id]=true;
			}
			}
		}
		printf("%d\n",ans);
	}
}
