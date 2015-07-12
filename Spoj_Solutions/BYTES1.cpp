#include<iomanip>
#include<iostream>
#include <cstdio>
#include <cstring>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
 
#define MAX_VAL 45
#define cin(n) scanf("%d",&n)
#define cinl(n) scanf("%lld",&n)
#define mp make_pair
#define inf 10000000000000LL
#define ill long long
#define pb push_back
#define mod 1000000
#define mn 100009
 
ill max(ill a,ill b)
{
    return a>b?a:b;
}
ill min(ill a,ill b)
{
    return a<b?a:b;
}
 
int main()
{
    int n,t,i,j,k,l,z,len,count1,count2;
    //freopen("inn.txt","r",stdin);
    //freopen("outt.txt","w",stdout);
    cin(t);
    while(t--)
    {
        //cin(n);
        string s;
        cin>>s;
        n=s.length();
        int dp[n+9];
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            if(!i)
            {
                dp[i]=(s[i]=='1'?1:0);
                continue;
            }
            count1=count2=0;
            j=i;
            while(1)
            {
                if(s[j]=='1')
                    count1++;
                else
                    count2++;
 
                if(!j)
                {
                    if(count1>count2)
                        dp[i]=max(dp[i],i+1);
                    break;
                }
                if(count1>count2)
                    dp[i]=max(dp[i],i-j+1+dp[j-1]);
                j--;
            }
            for(j=0;j<i;j++)
                dp[i]=max(dp[i],dp[j]);
        }
        cout<<dp[n-1]<<"\n";
 
    }
 
 
    return 0;
}
