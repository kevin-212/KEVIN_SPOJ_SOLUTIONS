#include<bits/stdc++.h>
using namespace std;
char pat[100001];
char txt[100001];
int kmp[100001];
bool kmpfunc()
{
	kmp[0]=0;
	int len=0,i;
	int sz=strlen(pat);
	for(i=1;i<sz;i++)
	{
		if(pat[i]==pat[len])
		{
			len++;
			kmp[i]=len;
		}
		else
		{
			if(len!=0)
				len=kmp[len-1];
				
			else
			kmp[i]=0;
		}
	}
	int szt=strlen(txt);
	int j=0;
	for(i=0;i<szt;)
	{
		while(txt[i]==pat[j])
		i++,j++;
		if(j==sz)
		{
			return true;
		}
		else
		if(j!=0)
		j=kmp[j-1];
		else
		i++;
	}
	return false;
}
int main()
{
	bool ch[123];
	int t,szp,szt,i;
	cin>>t;
	while(t--)
	{
		memset(ch,false,sizeof ch);
		cin>>txt;
		cin>>pat;
		szt=strlen(txt);
		szp=strlen(pat);
		for(i=0;i<szt;i++)
			ch[txt[i]]=true;
		for(i=0;i<szp;i++)
		{
			if(ch[pat[i]])
			break;
		}
		if(i==szp)
		cout<<"NO"<<endl;
		else
		cout<<"YES"<<endl;
	}
}
