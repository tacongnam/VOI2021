/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: PIANO **/

#include <bits/stdc++.h>

#define task				"PIANO"
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

int n, k, q;
ll a[maxn];

struct STree {
	vector<vector<ll>> st;
	vector<int> laz;

	STree(int sz) {
		st.resize(4 * sz);
		laz.resize(4 * sz);
		rep(i, 0, 4 * sz - 1)
			st[i].resize(31);
	}

	void Merge(int id) {
		rep(i, 0, 30)
			st[id][i] = st[id * 2][i] + st[id * 2 + 1][i];
	}

	void init(int id, int l, int r) {
		if(l == r) {
			st[id][0] = a[l];
			rep(i, 1, 30)
				st[id][i] = st[id][i - 1] / k;
			return ;
		}

		int mid = (l + r) / 2;
		init(id * 2, l, mid);
		init(id * 2 + 1, mid + 1, r);
		Merge(id);
	}

	void lazy(int id) {
		if(laz[id] == 0 || id > 4 * n)
			return;

		rep(i, 0, 30) {
			if(i + laz[id] > 30)
				st[id][i] = 0;
			else st[id][i] = st[id][i + laz[id]];
		}

		if(id * 2 + 1 <= 4 * n)
            laz[id * 2] += laz[id], laz[id * 2 + 1] += laz[id];
		laz[id] = 0;
	}

	void update(int id, int l, int r, int u, int v) {
		if(r < u || v < l)
			return ;
		if(u <= l && r <= v) {
			laz[id]++;
			lazy(id);
			return ;
		}

		int mid = (l + r) / 2;
        lazy(id * 2);
		update(id * 2, l, mid, u, v);
		lazy(id * 2 + 1);
		update(id * 2 + 1, mid + 1, r, u, v);
		Merge(id);
	}

	void change(int id, int l, int r, int pos, int val) {
		if(pos < l || r < pos) return ;
		if(l == r) {
			st[id][0] = val;
			rep(i, 1, 30)
				st[id][i] = st[id][i - 1] / k;
			return ;
		}

		int mid = (l + r) / 2;
		lazy(id * 2);
		change(id * 2, l, mid, pos, val);
		lazy(id * 2 + 1);
		change(id * 2 + 1, mid + 1, r, pos, val);
		Merge(id);
	}

	ll get(int id, int l, int r, int u, int v) {
		if(r < u || v < l) return 0;
		if(u <= l && r <= v)
			return st[id][0];
		int mid = (l + r) / 2;
		lazy(id * 2), lazy(id * 2 + 1);
		ll A = get(id * 2, l, mid, u, v);
		ll B = get(id * 2 + 1, mid + 1, r, u, v);
		return A + B;
	}
};

STree S(maxn);
main() {
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	fi(task".inp");
	fo(task".out");

	cin >> n >> q >> k;
	rep(i, 1, n)
		cin >> a[i];

	S.init(1, 1, n);

	while(q--) {
		int id, l, r;
		cin >> id >> l >> r;
		if(id == 1)
			S.change(1, 1, n, l, r);
		else if(id == 2) {
            if(k != 1)
                S.update(1, 1, n, l, r);
		}
		else
			cout << S.get(1, 1, n, l, r) << "\n";
	}

	end_debug;
}
