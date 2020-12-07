/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: **/

#include <bits/stdc++.h>

#define task                "xorpath"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)
#define rep(i, a, b)        for(int (i) = (a); (i) <= (b); ++(i))
#define repd(i, a, b)       for(int (i) = (a); (i) >= (b); --(i))
#define repa(a, u)          for(auto (a) : (u))

#define bit(a, i)           (((a) >> (i)) & 1)
#define mask(i)             (1LL << (i))
#define turnon(a, i)        ((a) | mask(i))
#define turnoff(a, i)       ((a) & (~mask(i)))

#define ft                  first
#define sd                  second
#define pb                  push_back
#define mp                  make_pair

#define sz(a)		        (int(a.size()))
#define all(a)		        a.begin(),a.end()

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define rand()              rng()

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minqueue;
typedef priority_queue<pii> maxqueue;

const int maxn = 20 + 5;
const long long mod = 1e9 + 7;
const int base = 26;
const double pi = 3.14159265359;

int counterr = 0;

#define start_debug cerr << "Debug status: \n"
#define debug(...)  cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...) cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << "(" << v.ft.ft << ";" << v.ft.sd << "):" << v.sd; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug   cerr << "\n"

/** End of template **/

int m, n;
ll k, a[maxn][maxn];
int dx[2][2] = {{1, 0}, {-1, 0}}, dy[2][2] = {{0, 1}, {0, -1}};
vector<pair<pii, ll>> s[2];
long long ans;

void bfs(int id, int u, int v, int step, ll _k) {
    if(step == 0) {
        s[id].pb(mp(mp(u, v), _k));
        return ;
    }

    rep(i, 0, 1) {
        int x = u + dx[id][i], y = v + dy[id][i];
        if(0 < x && x <= m && 0 < y && y <= n) {
            if(id == 0)
                bfs(id, x, y, step - 1, _k ^ a[x][y]);
            else
                bfs(id, x, y, step - 1, _k ^ a[u][v]);
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    fi(task".inp");
    fo(task".out");

    cin >> m >> n >> k;

    rep(i, 1, m)
        rep(j, 1, n)
            cin >> a[i][j];

    bfs(0, 1, 1, (m + n - 2) / 2 + (m + n - 2) % 2, a[1][1]);
    bfs(1, m, n, (m + n - 2) / 2, 0);

//    debuga(s[0]) << "\n";
//    debuga(s[1]) << "\n";

    sort(s[1].begin(), s[1].end());
    repa(u, s[0]) {
        pii cell = u.ft;
        ll xval = u.sd;
        auto it = equal_range(s[1].begin(), s[1].end(), mp(cell, k ^ xval));
        ans += 1LL * (it.sd - it.ft);
    }

    cout << ans << "\n";
}
