/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: Klasika **/

#include <bits/stdc++.h>

#define task                "Klasika"
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

const int maxn = 2e5 + 5;
const long long mod = 1e9 + 7;
const int base = 26;
const double pi = 3.14159265359;

int counterr = 0;

#define start_debug cerr << "Debug status: \n"
#define debug(...)  cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...) cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug   cerr << "\n"

struct Trie {
    Trie *child[2];
    set<int> id;

    Trie() {
        child[0] = child[1] = nullptr;
        id.clear();
    }
} *root;

void add(int x, int visit_order) {
    Trie *u = root;
    repd(i, 31, 0) {
        int digit = bit(x, i);
        if(u->child[digit] == nullptr)
            u->child[digit] = new Trie();
        u = u->child[digit];
        u->id.insert(visit_order);
    }
}

int get_max(int val, int start_order, int finish_order) {
    Trie *u = root;
    int ans = 0;

    repd(i, 31, 0) {
        int digit = bit(val, i);

        bool turn1 = true;

        if(u->child[1 - digit] != nullptr) {
            auto v = u->child[1 - digit];
            auto it = v->id.lower_bound(start_order);
            if(it != v->id.end() && *it <= finish_order) {
                ans += mask(i);
                u = u->child[1 - digit];
            }
            else turn1 = false;
        }
        else turn1 = false;

        if(turn1 == false) {
            if(u->child[digit] != nullptr) {
                auto v = u->child[digit];
                auto it = v->id.lower_bound(start_order);
                if(it != v->id.end() && *it <= finish_order)
                    u = u->child[digit];
                else
                    return ans;
            }
            else return ans;
        }
    }

    return ans;
}

/** End of template **/

int start[maxn], finish[maxn], len[maxn];
int n, m, cnt;
vector<pii> adj[maxn];

void dfs(int u, int p) {
    start[u] = ++cnt;
    for(pii v : adj[u]) {
        if(v.ft == p) continue;
        len[v.ft] = len[u] ^ v.sd;
        dfs(v.ft, u);
    }
    finish[u] = cnt;
}

struct query {
    bool id; /// 0 - add, 1 - query
    int x, y; /// x,y : add, a,b: query
} q[maxn];

void input_query() {
    cin >> m;
    rep(i, 1, m) {
        string c; int x, y;
        cin >> c >> x >> y;
        if(c == "Add") {
            q[i].id = false;
            q[i].x = x, q[i].y = y;
        }
        else {
            q[i].id = true;
            q[i].x = x, q[i].y = y;
        }
    }
}

void make_graph() {
    cnt = 1;
    rep(i, 1, m) {
        if(q[i].id == false)
            adj[q[i].x].pb(mp(++cnt, q[i].y));
    }
    cnt = 0;
}

void solve() {
    cnt = 1;
    add(0, 1);
    rep(i, 1, m) {
        if(q[i].id == false) {
            cnt++;
            add(len[cnt], start[cnt]);
        }
        else
            cout << get_max(len[q[i].x], start[q[i].y], finish[q[i].y]) << "\n";
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

//    fi(task".inp");

    root = new Trie();
    input_query();
    make_graph();
    dfs(1, 1);
    solve();
}
