#include <bits/stdc++.h>

#define task                "SIGNAL"
#define fi                  freopen(task".inp", "r", stdin);
#define fo                  freopen(task".out", "w", stdout);
#define FIO                 ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define rep(i, a, b)        for(int (i) = (a); (i) <= (b); ++(i))
#define repd(i, a, b)       for(int (i) = (a); (i) >= (b); --(i))
#define repa(u, v)          for(auto u : v)

#define int     long long
#define bit(a, i)           (((a) >> (i)) & 1)
#define mask(i)             (1LL << (i))
#define turn(a, i)          ((a) ^ mask(i))

#define pb                  push_back
#define ft                  first
#define sd                  second
#define mp                  make_pair

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define rand()              rng()

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minqueue;
typedef priority_queue<pii> maxqueue;

const int maxn = 2e5 + 3;
const long long mod = 1e9 + 7;
const int base = 26;
const double pi = 3.14159265359;

int counterr = 0;

#define start_debug cerr << "Debug status: \n"
#define debug(...)  cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...) cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug   cerr << "\n"

struct SegTree {
    vector<int> st;

    SegTree (int sz) {
        st.resize(4 * sz, 0);
    }

    void init(int id, int l, int r) {
        if(l == r) {
            st[id] = 0;
            return ;
        }
        int mid = (l + r) / 2;
        init(id * 2, l, mid);
        init(id * 2 + 1, mid + 1, r);
        st[id] = 0;
    }

    void upd(int id, int l, int r, int pos, int val) {
        if(pos < l || r < pos)
            return ;
        if(l == r) {
            st[id] = val;
            return ;
        }
        int mid = (l + r) / 2;
        upd(id * 2, l, mid, pos, val);
        upd(id * 2 + 1, mid + 1, r, pos, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    int get(int id, int l, int r, int u, int v) {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (l + r) / 2;
        return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
    }
};

vector<pii> vt;
int n, k, a[maxn], s[maxn], T[maxn], maxsum = 0, minsum = 1e18;
int szz;

void Compress() {
    rep(i, 0, n)
        vt.pb(mp(s[i], i));
    sort(vt.begin(), vt.end());
}

int FindPos(pii val) {
    return lower_bound(vt.begin(), vt.end(), val) - vt.begin();
}

SegTree S(maxn);
int Count(int sum) {
    S.init(1, 0, n);

    int cnt = 0;

    int pos = FindPos(mp(s[n], n));
    S.upd(1, 0, n, pos, 1);
    T[n] = 0;
    repd(i, n - 1, 0) {
        pos = FindPos(mp(s[i] + sum, 0));
        if(pos <= n)
            T[i] = S.get(1, 0, n, pos, n);
        else T[i] = 0;

        cnt += T[i];
        pos = FindPos(mp(s[i], i));
        S.upd(1, 0, n, pos, 1);
    }

    return cnt;
}

int GetAns(int sum) {
    S.init(1, 0, n);

    int ans = 0;

     int pos = FindPos(mp(s[n], n));
    S.upd(1, 0, n, pos, s[n]);
    repd(i, n - 1, 0) {
        pos = FindPos(mp(s[i] + sum, 0));
        ans += S.get(1, 0, n, pos, n) - T[i] * s[i];
        int pos = FindPos(mp(s[i], i));
        S.upd(1, 0, n, pos, s[i]);
    }

    return ans;
}

int cmid(int L, int R) {
    if(L + R >= 0) return (L + R) / 2;
    else return (L + R) / 2 - 1;
}

main() {
    start_debug;

    FIO
    fi fo

    cin >> n >> k;
    rep(i, 1, n) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        maxsum = max(maxsum, s[i]);
        minsum = min(minsum, s[i]);
    }

    Compress();

    int L = minsum - maxsum, R = maxsum - minsum + 1;

    while(L < R) {
        int mid = cmid(L, R);
        int c = Count(mid);
        if(c >= k)
            L = mid + 1;
        else R = mid;
    }

    L--;
    cerr << L << '\n';
    cout << L * (k - Count(L + 1)) + GetAns(L + 1);

    end_debug;
}

