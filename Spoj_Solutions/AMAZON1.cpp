#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool comp(map<char,int>mp,map<char,int>mp1,string str)	
{
	for(int i=0;i<str.size();i++)
	{
		if(mp[str[i]]!=mp1[str[i]])
		return false;
	}
	return true;
}
int main()
{
	string str1,str2,str3;
	getline(cin,str1);
	cout<<str1<<endl;
	
	getline(cin,str2);
	cout<<str2<<endl;
	str3=str2;
	cout<<str3<<endl;
	int l1=str1.size();
	int l2=str2.size();
	map<char,int>mp;
	map<char,int>mp1;	
	int index[100];
	bool arr[256];
	memset(arr,false,sizeof(arr));
	for(int i=0;i<l2;i++)
	{
		arr[str2[i]]=true;
		mp[str2[i]]++;
	}
	for(int i=0;i<l2;i++)
	{
		cout<<mp[str2[i]]<<endl;
	}
	str2="";
	int j=0;
	for(int i=0;i<l1;i++)
	{
		if(arr[str1[i]])
		{
			str2+=str1[i];
			index[j++]=i;
		}
	}
	cout<<str2<<endl;
	if(j<l2)
	{
		cout<<"not possible"<<endl;
	}
	else{
	for(int i=0;i<l2;i++)
	{
		mp1[str2[i]]++;
		cout<<mp1[str2[i]]<<endl;
	}
	
	for(int i=l2;i<j;i++)
	{
		if(comp(mp,mp1,str3))
		{
			cout<<index[i-l2]<<" "<<index[i-1]<<endl;
		}
		mp1[str2[i-l2]]--;
		mp1[str2[i]]++;
		
	}
	
	if(comp(mp,mp1,str3))
	{
		cout<<index[j-l2]<<" "<<index[j-1]<<endl;
	}
}
}
