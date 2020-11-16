/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: BONGDA **/

#include <bits/stdc++.h>

#define task				"BONGDA"
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

const int maxn = 30 + 2;
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

int n, a[maxn][maxn];

void input() {
	cin >> n;
	rep(i, 1, n)
		rep(j, 1, n)
			cin >> a[i][j];
	return ;
}

queue<int> q;
const int flow_node = maxn * maxn + maxn;
int p[flow_node], s, t;
int f[flow_node][flow_node], c[flow_node][flow_node];
bool inqueue[flow_node];
vector<int> adj[flow_node];

bool bfs() {
	rep(i, s, t) p[i] = -1;
	p[s] = 0;
	q.push(s);
	while(q.size() > 0) {
		int u = q.front();
		q.pop();
		inqueue[u] = false;
		repa(v, adj[u]) {
			if(p[v] == -1 && c[u][v] > f[u][v]) {
				p[v] = u;
				if(inqueue[v] == false) {
					inqueue[v] = true;
					q.push(v);
				}
			}
		}
	}

	return (p[t] != -1);
}

int maxflow;
void IncFlow() {
	int u = t, delta = 1e9;
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

	maxflow += delta;
	return ;
}

int score[maxn];
bool solve(int id) {
	rep(i, 1, n)
		score[i] = 0;
	rep(i, s, t) {
        adj[i].clear();
        rep(j, s, t)
            c[i][j] = f[i][j] = 0;
	}


	rep(i, 1, n)
		rep(j, i + 1, n) {
			if(a[i][j] == 0)
				score[j] += 3;
			else if(a[i][j] == 1)
				score[i] += 3;
		}

	rep(i, 1, n)
		if(a[id][i] == 2)
			score[id] += 3;

	#define match(i)	(i)
	#define team(i)		(i + n * n)

	int cnt = 0;

	rep(i, 1, n)
		rep(j, i + 1, n) {
			if(i == id || j == id) continue;
			if(a[i][j] == 2) {
				adj[match(++cnt)].pb(team(i));
				adj[match(cnt)].pb(team(j));
				adj[team(i)].pb(match(cnt));
				adj[team(j)].pb(match(cnt));

				c[match(cnt)][team(i)] = 1;
				c[match(cnt)][team(j)] = 1;
			}
		}

	rep(i, 1, cnt) {
		adj[s].pb(match(i));
		adj[match(i)].pb(s);
		c[s][match(i)] = 1;
	}

	rep(i, 1, n) {
		adj[team(i)].pb(t);
		adj[t].pb(team(i));
		if(score[id] < score[i])
            return false;
		c[team(i)][t] = (score[id] - score[i]) / 3;
	}

	maxflow = 0;
	while(bfs() == true)
		IncFlow();

	return (maxflow == cnt);
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	input();
	s = 0, t = n * n + n + 1;
	rep(i, 1, n)
		cout << ((solve(i) == true) ? 1 : 0);

	end_debug;
}
