/// DH ---------------------------------------
// #include "testlib.h"
#include <bits/stdc++.h>

#define task            "LCS"
#define FIO             ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fi(a)           freopen(a, "r", stdin)
#define fo(a)           freopen(a, "w", stdout)

#define ft              first
#define sd              second
#define ll              long long
#define mp              make_pair
#define pb              push_back
#define pii             pair<int, long long>

#define rep(i,a,b)      for(int (i) = (a); (i) <= (b); (i)++)
#define repd(i,a,b)     for(int (i) = (a); (i) >= (b); (i)--)

#define bit(a,i)        (((a) >> (i)) & 1)
#define mask(i)         (1LL << (i))
#define turn(a,i)       ((a) ^ mask(i))

#define size(U)         (int(U.size()))
#define active(u)       U.begin(),U.end
#define st_range        1,1,n

using namespace std;

const ll mod = 1e9 + 7;
const int maxn = 5e3 + 5;

/// Main code

int n, m, a[maxn], b[maxn];
ll ans = 0;
ll f[maxn][maxn];
int nx[maxn][maxn], pre[maxn][maxn];

void Prepare() {
    rep(i, 1, n) {
        nx[i][n + 1] = m + 1;
        repd(j, m, 1) {
            if(b[j] == a[i])
                nx[i][j] = j;
            else nx[i][j] = nx[i][j + 1];
        }
    }

    rep(i, 1, m) {
        pre[i][0] = 0;
        rep(j, 1, n) {
            if(b[i] == a[j])
                pre[i][j] = j;
            else pre[i][j] = pre[i][j - 1];
        }
    }
}

main() {
    FIO;
    fi(task".inp");
    fo(task".out");

    cin >> n >> m;
    rep(i, 1, n)
        cin >> a[i];
    rep(i, 1, m)
        cin >> b[i];

    Prepare();

    rep(u, 1, n)
        rep(j, 1, m) {
            int v = nx[u][j + 1];
            int i = pre[j][u - 1];

            f[u][v] = max(f[u][v], f[i][j] + (i != 0) * abs(1LL * a[u] - a[i]));
            ans = max(ans, f[u][j]);
        }

    cout << ans << "\n";
    return 0;
}
