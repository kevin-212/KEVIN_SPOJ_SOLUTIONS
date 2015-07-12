#include<bits/stdc++.h>
using namespace std;
int  main()
{
	int t;
	map<string,int>mp;
	int i,j,k;
	string s;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>s;
		mp[s]++;
	}
	map<string,int>::iterator it=mp.begin();
		map<string,int>::iterator iend=mp.end();
		while(it!=iend)
		{
			cout<<it->first<<" "<<it->second<<endl;
			it++;
		}
	//sort(mp,mp.size());
	
}
