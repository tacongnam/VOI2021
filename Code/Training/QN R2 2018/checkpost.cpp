/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: checkpost **/

#include <bits/stdc++.h>

#define task                "checkpost"
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

const int maxn = 3e5 + 5;
const long long mod = 1e9 + 7;
const int base = 26;
const double pi = 3.14159265359;

int counterr = 0;

#define start_debug cerr << "Debug status: \n"
#define debug(...)  cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...) cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug   cerr << "\n"

/** End of template **/

int low[maxn], num[maxn], cnt, k;
stack<int> st;
vector<int> adj[maxn], scc[maxn];
long long a[maxn];

void dfs(int u, int p) {
    low[u] = num[u] = ++k;
    st.push(u);

    repa(v, adj[u]) {
        if(num[v] > 0)
            low[u] = min(low[u], num[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
    }

    if(num[u] == low[u]) {
        cnt++;
        int v;
        do {
            v = st.top();
            st.pop();
            num[v] = low[v] = mod;
            scc[cnt].pb(a[v]);
        } while(v != u);
    }
}

int n, m;
long long ans = 0, way = 1;
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    fi(task".inp");
    fo(task".out");

    cin >> n;
    rep(i, 1, n)
        cin >> a[i];
    cin >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    rep(i, 1, n)
        if(num[i] == 0)
            dfs(i, i);


    rep(i, 1, cnt) {
        if(sz(scc[i]) == 0) break;
        sort(scc[i].begin(), scc[i].end());
        int len = 0;
        repa(u, scc[i])
            if(u > scc[i][0]) break;
            else len++;
        way = (way * len) % mod;
        ans += scc[i][0];
    }

    cout << ans << " " << way << "\n";
}
