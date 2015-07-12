#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
 
#define MD 1000000007
 
int LAST; // the next character of reading integer
#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)
void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);LAST=k;}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}
 
int T, N, K = 100;
int S[10][100], used[100];
 
int main(){
  int i, j, x;
  int dp[1111];
 
  reader(&T);
  while(T--){
    reader(&N);
    rep(i,N) rep(j,K) S[i][j] = 0;
    rep(i,N) for(;;){
      reader(&j); j--;
      used[j] = S[i][j] = 1;
      if(LAST!=' ') break; // the end of line
    }
 
    rep(i,1<<N) dp[i] = 0; dp[(1<<N)-1] = 1;
    rep(j,K) if(used[j]){ // if someone has T-Shirt j
      rep(i,1<<N) rep(x,N) if(S[x][j] && (i&1<<x)){ // if x has T-Shirt j and x hasn't determined which T-Shirt is worn
        dp[i^(1<<x)] = (dp[i^(1<<x)] + dp[i]) % MD;
      }
    }
 
    writer(dp[0], '\n');
  }
 
  return 0;
}
 
