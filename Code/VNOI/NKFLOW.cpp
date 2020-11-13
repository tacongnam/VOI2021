/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: FORD_FULKERSON **/

#include <bits/stdc++.h>

#define task				"NKFLOW"
#define fi(a)				freopen(a, "r", stdin)
#define fo(a)				freopen(a, "w", stdout)
#define rep(i, a, b)		for(int (i) = (a); (i) <= (b); ++(i))
#define repd(i, a, b)		for(int (i) = (a); (i) >= (b); --(i))
#define repa(a, u)			for(auto (a) : (u))

#define bit(a, i)			(((a) >> (i)) & 1)
#define mask(i)				(1LL << (i))
#define turnon(a, i)		((a) | mask(i))
#define turnoff(a, i)		((a) & (~mask(i)))

#define ft					first
#define sd 					second
#define pb					push_back
#define mp					make_pair

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define	rand()				rng()

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minqueue;
typedef priority_queue<pii> maxqueue;

const int maxn = 1e3 + 3;
const long long mod = 1e9 + 7;
const int base = 26;
const double pi = 3.14159265359;

int counterr = 0;

#define start_debug	cerr << "Debug status: \n"
#define debug(...) 	cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...)	cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug	cerr << "\n"

/** End of template **/
/** Nếu bạn mất niềm tin vào cuộc sống, hãy đọc code này **/

int c[maxn][maxn], f[maxn][maxn];
int p[maxn];
int n, m, s, t, maxf;
vector<int> adj[maxn];

void add(int u, int v, int w) {
	adj[u].pb(v);
	adj[v].pb(u);
	c[u][v] = w;
}

void bfs() {
    queue <int> qu;
    qu.push(s);
    p[s] = s;
    while(qu.empty() == false) {
        int u = qu.front();
        qu.pop();
        rep(i, 0, int(adj[u].size()) - 1) {
            int v = adj[u][i];
            if(p[v] == 0 && f[u][v] < c[u][v]) {
                p[v] = u;
                qu.push(v);
            }
        }
    }
    return ;
}

bool Find_Path() {
	rep(i, 1, n) p[i] = 0;
	p[s] = -1;
	bfs();
	return p[t];
}

void IncFlow() {
	int delta = mod;
	int u = t;
	while(u != s) {
		int v = p[u];
		delta = min(delta, c[v][u] - f[v][u]);
		u = v;
	}

	u = t;
	while(u != s) {
		int v = p[u];
		f[v][u] += delta;
		f[u][v] -= delta;
		u = v;
	}

	maxf += delta;
}

int solve() {
	maxf = 0;
	while(Find_Path() == true)
		IncFlow();
	return maxf;
}


main() {
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp");
//	fo(task".out");

	cin >> n >> m >> s >> t;
	
	rep(i, 1, m) {
		int u, v, c;
		cin >> u >> v >> c;
		add(u, v, c);
	}

	solve();

	cout << maxf << "\n";

	end_debug;
}
