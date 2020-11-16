/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: ELECT_SPOJ **/
/** Tag: 2-SAT **/

#include <bits/stdc++.h>

#define task                "ELECT_SPOJ"
#define fi(a)                freopen(a, "r", stdin)
#define fo(a)                freopen(a, "w", stdout)
#define rep(i, a, b)        for(int (i) = (a); (i) <= (b); ++(i))
#define repd(i, a, b)        for(int (i) = (a); (i) >= (b); --(i))
#define repa(a, u)            for(auto (a) : (u))

#define bit(a, i)            (((a) >> (i)) & 1)
#define mask(i)                (1LL << (i))
#define turnon(a, i)        ((a) | mask(i))
#define turnoff(a, i)        ((a) & (~mask(i)))

#define ft                    first
#define sd                     second
#define pb                    push_back
#define mp                    make_pair

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define    rand()                rng()

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minqueue;
typedef priority_queue<pii> maxqueue;

const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
const int base = 26;
const double pi = 3.14159265359;

int counterr = 0;

#define start_debug    cerr << "Debug status: \n"
#define debug(...)     cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...)    cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug    cerr << "\n"

/** End of template **/
/** Nếu bạn mất niềm tin vào cuộc sống, hãy đọc code này **/

struct TWO_SAT {
    vector<vector<int>> adj;
    vector<int> num, low, scc;
    int cnt, k;
    stack<int> s;

    TWO_SAT(int sz) {
        adj.resize(sz * 2);
        num.resize(sz * 2), low.resize(sz * 2), scc.resize(sz * 2);
        cnt = 0, k = 0;
    }

    void add(int x, int statX, int y, int statY) {
        int nodeX = x << 1 ^ statX;
        int nodeY = y << 1 ^ statY;
        adj[nodeX ^ 1].pb(nodeY);
        adj[nodeY ^ 1].pb(nodeX);
    }

    void dfs(int u) {
        num[u] = low[u] = ++cnt;
        s.push(u);

        repa(v, adj[u]) {
            if(num[v] != 0) low[u] = min(low[u], num[v]);
            else {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }

        if(low[u] == num[u]) {
            ++k;
            int x = 0;
            do {
                x = s.top();
                s.pop();
                scc[x] = k;
                num[x] = low[x] = mod;
            } while(x != u);
        }
    }

    vector<int> solve() {
        rep(i, 0, int(adj.size()) - 1)
            if(num[i] == 0)
                dfs(i);

        int n = int(adj.size()) / 2;
        vector<int> ans(n);
        rep(i, 0, n - 1) {
            if(scc[i << 1 ^ false] == scc[i << 1 ^ true]) return vector<int>(0);
            ans[i] = (scc[i << 1 ^ false] > scc[i << 1 ^ true]);
        }
        return ans;
    }
} ;
int n, m;
main()
{
    start_debug;

    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    
//    fi(task".inp"), fo(task".out");
    
    cin >> n >> m;
    TWO_SAT G(2 * n);
    rep(i, 1, 2 * n) { /// x != y => x or y = 1 and not(x) or not(y) = 1
        G.add(i - 1, 1, i, 1);
        G.add(i - 1, 0, i, 0);
        i++;
    }

    rep(i, 1, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        /// (a, b) = (1, 0), (0, 1), (0, 0) => (nota, notb) = (0, 1), (1, 0), (1, 1)
        /// not(a) or not(b) = 1
        G.add(a, 0, b, 0);
    }

    vector<int> ans = G.solve(), id;

    if(ans.size() == 0) {
        cout << 0;
        return 0;
    }
    else {
        rep(i, 0, 2 * n - 1)
            if(ans[i] == 1)
                id.pb(i + 1);
        if(id.size() != n)
            cout << 0 << "\n";
        else {
            cout << 1 << "\n";
            repa(i, id)
                cout << i << " ";
        }
    }
    end_debug;
}
