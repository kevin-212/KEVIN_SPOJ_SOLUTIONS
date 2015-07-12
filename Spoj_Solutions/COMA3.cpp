/*Chef has started learning trees. After finishing the theoretical concepts , he started solving exercise questions. 
He successfully solved all the question but got stuck in this one. Given a rooted tree with N nodes numbered from 1 – N with node 1 as root. 
You are also given two types of operation.
Type 1 : x y val ( Add the value val to all the nodes that are coming in the from node x to node y inclusively )
Type 2 : x ( Find the sum of values of all the children of node x inclusively)
There are total U operations of Type 1 and Q operations of Type 2. For each operation of Type 2, Chef has to calculate the required answer modulo 1000000007.
 Please help the chef, to successfully complete the exercise by completely solving this problem.
Initially all the nodes have value zero.
Input

First line of input contain three space separated numbers N U Q.

Then next N-1 lines contain two space separated integers x y, meaning there is an edge between node x and node y describing the nodes position in the tree.

Next U lines follow the Type 1 operation. Then next Q lines follow the Type 2 operation.
Output

For each operation of Type 2 output the required answer modulo 1000000007
Constraints

1 = N = 100000
1 = U = 100000
1 = Q = 100000
-10^9 = val = 10^9
1 = x,y = N
Example

Input:
3 1 3
1 2
1 3
2 3 3
1
2
3

Output:
9
3
3*/

#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#else
#include "header.h"
#include "debug.h"
#endif
#define sz(s) int((s).size())
#define clr(a) memset(a,0,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int(i)=0; (i)<(n);++(i))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef pair <int,int> pii;
typedef long long LL;
template <class T> inline T gcd(T a,T b){return (!b? a : gcd(b,a%b));}
inline int inp() {int n=0,s=1;char p=getchar_unlocked();if(p=='-')s=-1;while((p<'0'||p>'9')&&p!=EOF&&p!='-')p=getchar_unlocked();if(p=='-')s=-1,p=getchar_unlocked();while(p>='0'&&p<='9')n=(n<<3)+(n<<1)+(p-'0'),p=getchar_unlocked();return n*s;}
inline void out_(int x){if(x<0)putchar_unlocked('-'),x=-x;int ll=0,dd[10];while(x)dd[ll++]=x%10,x/=10;if(!ll)dd[ll++]=0;while(ll--)putchar_unlocked(dd[ll]+48);putchar_unlocked('\n');}
template <class T> inline T ABS(T x){return ((x)>0?(x):(-(x)));}
const int N = 1 << 17;
 
vector <int> g[N];
 
const int LOGN = (log2 (N) + 2);
int anc [N][LOGN], lev [N], in [N], out [N], timer, logn;
void dfs (int u, int p) {
  in [u] = ++timer;
  anc [u][0] = p;
  for (int i = 1; i <= logn; ++i) {
    if (anc [u][i-1] == -1) break;
    else anc [u][i] = anc [anc [u][i-1]] [i-1];
  }
  for (int v: g [u]) {
    if (v != p) {
      lev [v] = lev [u] + 1;
      dfs (v,u);
    }
  }
  out[u] = timer;
}
 
inline bool upper (int p, int q) {
  return in [q] >= in [p] && out [q] <= out [p];
}
 
inline int lca (int a, int b) {
  if (upper (a,b)) return a;
  if (upper (b,a)) return b;
  for (int i = logn; i >= 0; --i) {
    if (anc [a][i] > 0) {
      if (!upper (anc [a][i], b)) {
        a = anc [a][i];
      }
    }
  }
  return anc [a][0];
}
 
inline int dist (int p, int q) {
  return lev [p] + lev [q] - 2 * lev [lca (p, q)];
}
 
LL dp [N];
LL temp [N];
const int md = 1000000007;
 
inline void mod (LL &res) {
  if (res >= md) {
    res %= md;
  }
  if (res < 0) {
    res += md;
  }
}
 
void dfs1 (int u, int p) {
  for (int v : g [u]) {
    if (v != p) {
      dfs1 (v, u);
      dp [u] += dp [v];
      mod (dp [u]);
    }
  }
}
 
int main () {
  #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
  #endif
  int n = inp (), U = inp (), Q = inp ();
  for (int i = 1; i < n; ++i) {
    int u = inp (), v = inp ();
    g [u].pb (v);
    g [v].pb (u);
  }
  int root = 1;
  logn = 1; while ((1 << logn) <= n) ++logn;
  memset (anc, -1, sizeof (anc));
  timer = lev [root] = 0, dfs (root, -1);
  for (int i = 1; i <= U; ++i) {
    int u = inp (), v = inp (), val = inp ();
    dp [u] += val;
    dp [v] += val;
    int l = lca (u, v);
    dp [l] -= 2 * val;
    temp [l] += val;
    mod (dp [u]);
    mod (dp [v]);
    mod (dp [l]);
    mod (temp [l]);
  }
  dfs1 (1, 0);
  for (int i = 1; i <= n; ++i) {
    dp [i] += temp [i];
    mod (dp [i]);
  }
  dfs1 (1, 0);
  while (Q--) {
    int u = inp ();
    out_ (dp [u]);
  }
}
