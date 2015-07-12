#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k;
	vector<int>v;
	for(i=0;i<100;i++)
	v.push_back(i);
	sort(v.begin(),v.end());
	for(i=0;i<100;i++)
	cout<<v[i]<<endl;
	
}
