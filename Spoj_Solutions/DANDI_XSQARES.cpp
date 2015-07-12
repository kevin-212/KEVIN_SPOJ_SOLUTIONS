#include<bits/stdc++.h>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define s(i) scanf("%d",&i)
#define sl(i) scanf("%ld",&i)
#define sll(i) scanf("%lld",&i)
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define NREP(i,a,b) \
for (int i = int(a); i >= int(b); i--)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
//#define INF 2000000000 // 2 billion

int n;
map <int,vi> vals;
ll a[500009];
ii que[500009];
ll ans[500009];
ll sum[500009];
ll preans;
ll INF;

void check(int i)
{
    //cout << sum[i] << endl;
    preans = max(preans,a[i]);
    sum[i] = a[i];
    //cout << preans << endl;
    if( i - 1 >= 0 && sum[i - 1] > 0 )
    {
        sum[i] = a[i] + sum[i - 1];
        preans = max(preans,sum[i]);
    }
    if( sum[i] > 0)
    {
        while( 1 && ( i + 1 ) < n )
        {
            if( sum[i] + a[i + 1] > 0 )
            {
                sum[i + 1] = a[i + 1] + sum[i];
                preans = max(preans,sum[i + 1]);
            }
            else
                break;
            i++;
        }
    }
    //cout << preans << endl;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","r",stdout);
    INF = 100000000;
    int q;s(n);s(q);
    REP(i,0,n - 1)
    {
        int p;s(p);
        vals[p].push_back(i);
    }
    REP(i,0,n - 1)
    {
        ans[i] = -1*INF*1ll*INF;
        sum[i] = -1*INF*1ll*INF;
        a[i] = -1 * INF * 1ll * INF;
    }
 //   int q;s(q);
    REP(i,0,q - 1)
    {
        int p;s(p);
        que[i].first = p;
        que[i].second = i;
    }
    sort(que ,que + q);
    preans = -1 * INF * 1ll * INF;
    //cout << preans << endl;
    map <int,vi>::iterator it = vals.begin();
    REP(i,0,q - 1)
    {
        while( it != vals.end() )
        {
            if( it -> first > que[i].first)
                break;
            //cout << it -> first << " " << que[i].first << endl;
            TRvi(it -> second , it1)
            {
                a[*it1] = it -> first;
                //cout << *it1 << endl;
                check(*it1);
            }
            //vals.erase(it);
            it++;
        }
        ans[que[i].second] = preans;
    }
    REP(i,0,q - 1)
    {
        if( ans[i] >= (-1 * INF * 100 ) )
            printf("%lld\n",ans[i]);
        else
            printf("No Solution\n");
    }
    return 0;
}

