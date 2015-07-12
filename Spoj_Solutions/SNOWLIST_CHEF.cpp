#include<bits/stdc++.h>
using namespace std;
 
const int mx = 102, mod = 100003;
 
int dp[mx][mx], a, b, c;
 
int solve(int rem, int n) {
    if(n == 0) return rem == 0;
    int &ret = dp[rem][n];
    if(ret != -1) return ret;
    ret = 0;
 
    int old = 0;
    if(a - rem > b) old = a - rem - b;
 
    ret = 1ll * old * solve(rem, n - 1) % mod;
    if(rem) ret = (ret + 1ll * rem * solve(rem - 1, n - 1)) % mod;
 
    return ret;
}
 
int main() {
    scanf("%d %d %d", &a, &b, &c);
 
 
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(a, c));
 
    return 0;
}
