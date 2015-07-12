#include<iostream>
#include<set>
#include<cstring>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

int main()
{
	int t,n;
	scanf("%d",&t);
set<string>S;
map<string,int>mp;
char c;
	string str;
	while(t--)
	{
		S.clear();
		mp.clear();
		scanf("%d",&n);
		scanf("%c",&c);
		for(int i=0;i<n;i++)
		{
			getline(cin,str);
			S.insert(str);
			mp[str]++;
		}
		
		set<string>::iterator it=S.begin();
		for(;it!=S.end();it++)
		{
			cout<<(*it)+" "<<mp[(*it)]<<endl;
		}
		cout<<endl;
	}
}
