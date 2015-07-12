//gshkrtiladze

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define pb push_back
#define getcx getchar//_unlocked

using namespace std;

inline void inp(int &n )
 {n=0; int ch=getcx();
  while(ch<'0'||ch>'9') ch=getcx();
  while(ch>='0'&&ch<='9') n=(n<<3)+(n<<1)+ch-'0',ch=getcx(); }

int n,k,b,a,i;
int xr[1000001];
bool f[1000001];

vector < int > nx[1000001];
priority_queue < int > st;

int main() {
   inp(n);
   while (n--) {
     inp(k);
     cin>>b; f[b]=1;
     for (i=2;i<=k;i++) {
       inp(a); xr[a]++;
       nx[b].pb(a);
       b=a; f[b]=1;
      }
    }
   for (i=0;i<=1000000;i++)
    if (f[i] && xr[i] == 0)
     st.push(-i);
   while (st.size() > 0)
    {
     k=-st.top();
     printf("%d ",k);
     st.pop();
     for (i=0;i<nx[k].size();i++) {
      xr[nx[k][i]]--; if (xr[nx[k][i]] == 0) st.push(-nx[k][i]); }
    }
   printf("\n");
 }

