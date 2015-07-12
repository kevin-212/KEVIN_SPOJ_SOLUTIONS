#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include <iostream> 
#include <stdlib.h> 
#include <ctime> 
#include <cmath> 
#include <stdio.h> 
#include <vector> 
#include <algorithm> 
#include <queue> 
#include <string.h> 
#include <map> 
#include <set> 
#include <assert.h>
#define x first 
#define y second 
#define pb push_back 
#define mp make_pair 
#define vi vector<int> 
#define pii pair<int,int> 
#define ll long long 
#define inf 1000000007 
#define mod 1000000009
#define all(x) x.begin(),x.end() 
#define N 100010
#define pi acos(-1.)
#define DBG(x) cerr<<#x<<"="<<x<<"\n"; 
#define FOREACH(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++) 
using namespace std; 
 
struct node{
    int x;
    ll y,w;
    bool operator <(const node&a)const{
        return x<a.x;
    }
}a[20010];
int n,m,debug=0;
int solve(ll p)
{
    int i,j,k;
    ll t=p;
    for(i=0;i<n;i++){
        //if(debug)cerr<<p<<" "<<a[i].x<<" "<<a[i].y<<" "<<a[i].w<<"\n";
        if(a[i].w==-1){
            if(p<=a[i].y)return 0;
            p-=a[i].y;
        }
        else{
            if(p>=a[i].w)p+=a[i].y;
        }
    }
    return 1;
}
int main()
{
    //freopen("1.txt","w",stdout);
    int i,j,k,T;
    scanf("%d",&T);
    while(T--){
        ll d;
        cin>>d>>m;
        for(i=0;i<m;i++)cin>>a[i].x>>a[i].y,a[i].w=-1;
        cin>>n;
        for(i=0;i<n;i++)cin>>a[m+i].x>>a[m+i].w>>a[m+i].y;
        n+=m;
        sort(a,a+n);
        ll l=1,r=1e18;
        while(l<=r){
            ll t=l/2+r/2+((l&1)&&(r&1));
            if(solve(t))r=t-1;
            else l=t+1;
        }
        //debug=1;
       // DBG(solve(r+1))
        printf("%lld\n",r+1);
    }
    return 0;
}
