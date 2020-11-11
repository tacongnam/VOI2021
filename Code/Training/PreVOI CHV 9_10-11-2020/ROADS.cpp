#include <bits/stdc++.h>

#define task				"ROADS"
#define fi					freopen(task".inp", "r", stdin);
#define fo 					freopen(task".out", "w", stdout);
#define FIO					ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define rep(i, a, b)		for(int (i) = (a); (i) <= (b); ++(i))
#define repd(i, a, b)		for(int (i) = (a); (i) >= (b); --(i))
#define repa(u, v)			for(auto u : v)

#define bit(a, i)			(((a) >> (i)) & 1)
#define mask(i)				(1LL << (i))
#define turn(a, i)			((a) ^ mask(i))

#define pb 					push_back
#define ft 					first
#define sd 					second
#define mp 					make_pair

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define	rand()				rng()

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minqueue;
typedef priority_queue<pii> maxqueue;

const int maxn = 2e5 + 5;
const long long mod = 1e9 + 7;
const int base = 26;
const double pi = 3.14159265359;

int counterr = 0;

#define start_debug	cerr << "Debug status: \n"
#define debug(...) 	cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...)	cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug	cerr << "\n"

/** End of template **/
/** Just enjoy my code **/

typedef pair<long long, int> pli;
priority_queue<pli, vector<pli>, greater<pli>> pq;

int n, m;
ll d[3][maxn], u[maxn], v[maxn], w[maxn], b[3][maxn];
vector<pii> adj[maxn], rev[maxn];
bool vs[maxn];

ll Dijkstra(vector<pii> adj[], int id) {
	rep(i, 1, n) {
		d[id][i] = 1e18;
		vs[i] = false;
	}

	d[id][id] = 0;
	b[id][id] = 1;
	pq.push(mp(0, id));

	while(pq.size() > 0) {
		int u = pq.top().sd;
		int dst = pq.top().ft;
		pq.pop();
		if(vs[u] == true)
            continue;
        vs[u] = true;

		repa(it, adj[u]) {
			int v = it.ft, w = it.sd;
			if(d[id][v] > dst + w) {
				d[id][v] = dst + w;
				b[id][v] = b[id][u];
                pq.push(mp(d[id][v], v));
			}
			else if(d[id][v] == dst + w) {
				b[id][v] += b[id][u];
                pq.push(mp(d[id][v], v));
			}
		}
	}

	return d[id][2];
}

main() {
	start_debug;

	FIO
    fi fo

	cin >> n >> m;
	rep(i, 1, m) {
		cin >> u[i] >> v[i] >> w[i];
		adj[u[i]].pb(mp(v[i], w[i]));
		rev[v[i]].pb(mp(u[i], w[i]));
	}

	ll ft = Dijkstra(adj, 1);
	ll sd = Dijkstra(rev, 2);

	rep(i, 1, m) {
		int ini = d[1][u[i]] + d[2][v[i]] + w[i];
		int aft = d[1][v[i]] + d[2][u[i]] + w[i];

    	if(aft < ft) {
			cout << "HAPPY\n";
		}
		else if(ini == ft) {
			if(b[1][u[i]] * b[2][v[i]] == b[1][2])
				cout << "SAD\n";
			else
				cout << "SOSO\n";
		}
		else
			cout << "SOSO\n";
	}

	end_debug;
}
