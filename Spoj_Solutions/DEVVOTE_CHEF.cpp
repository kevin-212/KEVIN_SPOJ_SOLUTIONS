#include <cstdio>
 
using namespace std;
 
//typedef long long ll;
typedef double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
 
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
ld solve(int n) {
  vector<pair<int, int> > ls0;
  ls0.pb(mp(0, n - 1));
  ls0.pb(mp(1, 1));
  map<pair<vector<pair<int, int> >, int>, ld> dp;
  dp[mp(ls0, 1)] = 1;
  for (int i = 2; i <= n; i++) {
    map<pair<vector<pair<int, int> >, int>, ld> dp2;
    for (auto it = dp.begin(); it != dp.end(); ++it) {
      const vector<pair<int, int> >& ls = it->x.x;
      for (int j = 0; j < sz(ls); j++) {
        int k = ls[j].y;
        if (j == it->x.y) {
          k--;
        }
        if (k == 0) continue;
        vector<pair<int, int> > ls2;
        bool was = false;
        int ps = -1;
        for (int t = 0; t < sz(ls); t++) {
          if (ls[t].x < ls[j].x) {
            ls2.pb(ls[t]);
          } else 
          if (ls[t].x == ls[j].x) {
            if (ls[t].y - 1 > 0) {
              ls2.pb(mp(ls[t].x, ls[t].y - 1));
            }
          } else
          if (ls[t].x == ls[j].x + 1) {
            was = true;
            ps = sz(ls2);
            ls2.pb(mp(ls[t].x, ls[t].y + 1));
          } else {
            if (!was) {
              ps = sz(ls2);
              ls2.pb(mp(ls[j].x + 1, 1));
              was = true;
            }
            ls2.pb(ls[t]);
          }
        }
        if (!was) {
          ps = sz(ls2);
          ls2.pb(mp(ls[j].x + 1, 1));
          was = true;
        }
        dp2[mp(ls2, ps)] += it->y * k / (n - 1);
      }
    }
    dp = dp2;
  }
  ld ans = 0;
  for (auto it = dp.begin(); it != dp.end(); ++it) {
    ans += it->y * it->x.x[sz(it->x.x) - 1].y;
  }
  return ans;
}        
ld A[37];
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  for (int n = 1; n <= 36; n++) {
    printf("A[%d] = %.18f;\n", n, solve(n));
  }
A[1] = 1.000000000000000000;
A[2] = 2.000000000000000000;
A[3] = 2.000000000000000000;
A[4] = 1.777777777777777679;
A[5] = 1.656250000000000000;
A[6] = 1.660800000000000276;
A[7] = 1.733667695473250614;
A[8] = 1.828591828234834127;
A[9] = 1.920742034912109375;
A[10] = 1.999589469311728429;
A[11] = 2.062218799000001823;
A[12] = 2.109256410904062573;
A[13] = 2.142717008349191765;
A[14] = 2.164972013791609751;
A[15] = 2.178301282186746235;
A[16] = 2.184725343116017626;
A[17] = 2.185963810197957713;
A[18] = 2.183446322326592970;
A[19] = 2.178342615395763460;
A[20] = 2.171597290773807032;
A[21] = 2.163963429387752768;
A[22] = 2.156032951560819644;
A[23] = 2.148263202439923969;
A[24] = 2.140999872784911773;
A[25] = 2.134496589756263329;
A[26] = 2.128931569455456252;
A[27] = 2.124421713786911248;
A[28] = 2.121034501288350249;
A[29] = 2.118797982369810207;
A[30] = 2.117709150792956851;
A[31] = 2.117740927704674370;
A[32] = 2.118847962812395291;
A[33] = 2.120971429343438519;
A[34] = 2.124042964992685079;
A[35] = 2.127987889782128050;
A[36] = 2.132727813269748030;
  int T;
  scanf("%d", &T);
  for (int ti = 0; ti < T; ti++) {
    int n;
    scanf("%d", &n);
    printf("%.6f\n", A[n]);
  }
  return 0;
}
