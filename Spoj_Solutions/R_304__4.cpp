#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
stack<int> stk;
int a[maxn] , dpl[maxn] , dpr[maxn] , ans[maxn];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for(int i = 1; i <= n; i++) {
        while(!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
        if(stk.empty()) dpl[i] = 1;
        else dpl[i] = stk.top()+1;
        stk.push(i);
    }
    while(!stk.empty()) stk.pop();
    for(int i = n; i >= 1; i--) {
        while(!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
        if(stk.empty()) dpr[i] = n;
        else dpr[i] = stk.top()-1;
        stk.push(i);
    }
    memset(ans , 0 , sizeof(int)*(n+1));
    for(int i = 1; i <= n; i++) ans[dpr[i]-dpl[i]+1] = max(ans[dpr[i]-dpl[i]+1] , a[i]);
    for(int i = n-1; i >= 1; i--) ans[i] = max(ans[i] , ans[i+1]);
    for(int i = 1; i <= n; i++) printf("%d%c",ans[i]," \n"[i == n]);
    return 0;
}
