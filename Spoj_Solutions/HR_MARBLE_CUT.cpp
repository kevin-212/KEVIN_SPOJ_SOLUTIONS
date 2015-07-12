#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,l,b,ans;
	cin>>t;
	while(t--)
	{
		cin>>l>>b;
		ans=(l%3)*(b%3);
		if(ans)
		cout<<"NO"<<" "<<ans<<endl;
		else
		cout<<"YES"<<endl;
	}
}
