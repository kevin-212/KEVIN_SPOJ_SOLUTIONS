#include<bits/stdc++.h> 
#define pii pair<int,int> 
#define rep(i,n) for(i=0;i<n;i++)
bool visited[1050000];
using namespace std;int main(){int n,m,i,c,j,t,a,b;long ans;int arr[100001];cin>>t;while(t--){ans=0;memset(visited,false,sizeof(visited));cin>>n;rep(i,n){
cin>>a;arr[i]=a;if(!visited[a])ans++,visited[a]=true;}rep(i,n){a=arr[i];for(j=i+1;j<n;j++){a|=arr[j];if(!visited[a])ans++,visited[a]=true;}}cout<<ans<<endl;}}

