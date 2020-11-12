/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: TREE **/

#include <bits/stdc++.h>

#define task				"TREE"
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

const int maxn = 1e5 + 1;
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

int Leaf[maxn], n, k;
ll F[maxn][105];
vector<pii> adj[maxn];

void dfs(int u, int p) {
	Leaf[u] = (adj[u].size() == 1);

	if(Leaf[u] == 1) {
        rep(i, 0, 1)
            F[u][i] = 0;
	}

	repa(v, adj[u]) {
		if(v.ft == p) continue;
		dfs(v.ft, u);

		repd(i, min(Leaf[u], k), 0)
			rep(j, 0, min(Leaf[v.ft], k - i))
				F[u][i + j] = min(F[u][i + j], F[u][i] + F[v.ft][j] + v.sd * j * (k - j));

		Leaf[u] += Leaf[v.ft];
	}

	return ;
}

main() {
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	fi(task".inp");
	fo(task".out");

	cin >> n >> k;

	rep(i, 1, n)
        rep(j, 1, k)
            F[i][j] = 1e18;

	rep(i, 1, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}

	dfs(1, 1);

	cout << F[1][k] << "\n";

	end_debug;
}
