#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
 
using namespace std;
 
#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
 
typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;
 
const int N = 100005;
int K[N];
vector<int> M[20];
int P[22];
 
LL max(int a, int b) {
  return a > b ? a : b;
}
 
void pre(int n) {
 
 K[0] = -1;
  rep(i,1,N) {
    
    if((i & (i-1)) == 0) {
      K[i] = K[i-1] + 1;
    } else {
      K[i] = K[i-1];
    }
  }
 
  rep(i,0,21) P[i] = (1 << i) - 1;  
 
  for(int j = 1; (1 << j) <= n; j++) {
    for(int i = 0; i + (1 << j) <= n; i++) {
      if(M[j-1][i] >= M[j-1][i+(1<<(j-1))]) {
        M[j].push_back(M[j-1][i]);
      } else {
        M[j].push_back(M[j-1][i+(1<<(j-1))]);
      }
    }
  }
}
 
int main() {
  int n;
  S(n);
  rep(i,0,n) {
    int x;
    S(x);
    M[0].push_back(x);
  }
  pre(n);
  int m,x,y;
  scanf("%d%d%d",&m,&x,&y);
  int idx, a, b;
  LL ans = 0;
  while(m--) {
    if(x <= y) {
      idx = K[y-x+1];
      a = M[idx][x];
      b = M[idx][y-P[idx]];
    } else {
      idx = K[x-y+1];
      a = M[idx][y];
      b = M[idx][x-P[idx]];
    }
    if(a > b) ans += a;
    else ans += b;
 
    x += 7;
    while(x >= (n-1)) x -= n - 1;
 
    y += 11;
    while(y >= n) y -= n;
  }
  printf("%lld\n",ans);
  return 0;
} 
