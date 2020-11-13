/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: MINCOST **/

#include <bits/stdc++.h>

#define task				"MINCOST"
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

const int maxn = 1e3 + 1;
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

queue<int> q;
int n, m, k, s, t;
int f[maxn][maxn], c[maxn][maxn], p[maxn], d[maxn], cost[maxn][maxn];
int maxflow, pay;
vector<int> adj[maxn];
bool inqueue[maxn];

void bfs() {
	q.push(s);
	inqueue[s] = true;
	while(q.size() > 0) {
		int u = q.front();
		q.pop();
		inqueue[u] = false;

		repa(v, adj[u]) {
			if(f[u][v] < c[u][v]) {
				int ncost = ((f[u][v] < 0) ? -1 : 1) * cost[u][v];
				if(d[v] > d[u] + ncost) {
					d[v] = d[u] + ncost;
					p[v] = u;
					if(inqueue[v] == false)
						q.push(v), inqueue[v] = true;
				}
			}
		}
	}
}

bool FindPath() {
	rep(i, 1, n)
		p[i] = -1, d[i] = 1e9;
	p[s] = 0, d[s] = 0;
	bfs();
	return (p[t] != -1);
}

void IncFlow() {
	int u = t, delta = 1e9;
	while(u != s) {
		int v = p[u];
		delta = min(delta, (f[v][u] >= 0) ? c[v][u] - f[v][u] : -f[v][u]);
		u = v;
	}
	if(maxflow + delta > k)
		delta = k - maxflow;
	u = t;
	while(u != s) {
		int v = p[u];
		f[v][u] += delta;
		f[u][v] -= delta;
		u = v;
	}
	pay += delta * d[t];
	maxflow += delta;
}

main() {
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp");
//	fo(task".out");

	cin >> n >> m >> k >> s >> t;
	rep(i, 1, m) {
		int u, v, ct, d;
		cin >> u >> v >> ct >> d;
		adj[u].pb(v), adj[v].pb(u);
		c[u][v] = c[v][u] = d;
		cost[u][v] = cost[v][u] = ct;
	}

	while(maxflow < k && FindPath() == true)
		IncFlow();

	if(maxflow < k)
		cout << "-1\n";
	else {
		cout << pay << "\n";
		rep(i, 1, n)
			rep(j, 1, n)
				if(f[i][j] > 0)
					cout << i << " " << j << " " << f[i][j] << "\n";
		cout << "0 0 0\n";
	}
	end_debug;
}
