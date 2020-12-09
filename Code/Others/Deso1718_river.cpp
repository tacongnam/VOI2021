/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: RIVER **/

/** Đề bài: (Chèn link sau) **/

#include <bits/stdc++.h>

#define task                "RIVER"
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

int node_child[200 * maxn][2];
int st[200 * maxn], cnt = 1;

int child(int u, bool rigt) {
    if(node_child[u][rigt] == 0) {
        node_child[u][rigt] = ++cnt;
        st[cnt] = 0;
    }
    return node_child[u][rigt];
}

void upd(int id, int l, int r, int pos, int val) {
    if(pos < l || r < pos) return ;
    if(l == r) {
        st[id] = val;
        return ;
    }
    int mid = (l + r) / 2;
    upd(child(id, 0), l, mid, pos, val);
    upd(child(id, 1), mid + 1, r, pos, val);
    st[id] = st[child(id, 0)] + st[child(id, 1)];
    return ;
}

int get_pos(int id, int l, int r, int index) {
    if(index > st[1]) return r + 1;
    if(index == 0) return 0;
    if(l == r) return l;
    int mid = (l + r) / 2;
    if(st[child(id, 0)] < index)
        return get_pos(child(id, 1), mid + 1, r, index - st[child(id, 0)]);
    else return get_pos(child(id, 0), l, mid, index);
}

/** End of template **/
/** Con trâu là đầu cơ nghiệp **/

int n, p, a[maxn], s[maxn], cnt_n, k;
ll ans;

ll square(ll A) {
    return 1LL * A * A;
}

void type1(int x) {
    if(x == 1) {
        int pos = get_pos(1, 1, s[n], x);
        int nxtpos = get_pos(1, 1, s[n], x + 1);
        int nxtnxtpos = get_pos(1, 1, s[n], x + 2);

        ans = ans - square(nxtpos - pos) - square(nxtnxtpos - nxtpos);
        upd(1, 1, s[n], nxtpos, 0);
        ans = ans + square(nxtnxtpos - pos);
    }
    else if(x == cnt_n) {
        int pos = get_pos(1, 1, s[n], x);
        int prepos = get_pos(1, 1, s[n], x - 1);
        int nxtpos = get_pos(1, 1, s[n], x + 1);

        ans = ans - square(nxtpos - pos) - square(pos - prepos);
        upd(1, 1, s[n], pos, 0);
        ans = ans + square(nxtpos - prepos);
    }
    else {
        int pos = get_pos(1, 1, s[n], x);
        int nxtpos = get_pos(1, 1, s[n], x + 1);
        int nxtnxtpos = get_pos(1, 1, s[n], x + 2);
        int prepos = get_pos(1, 1, s[n], x - 1);

        int val = nxtpos - pos;

        ans = ans - square(pos - prepos) - square(nxtpos - pos) - square(nxtnxtpos - nxtpos);
        upd(1, 1, s[n], pos, 0);
        upd(1, 1, s[n], nxtpos, 0);
        upd(1, 1, s[n], pos + val / 2, 1);
        ans = ans + square(pos + val / 2 - prepos) + square(nxtnxtpos - pos - val / 2);
    }

    cnt_n--;
}

void type2(int x) {
    int pos = get_pos(1, 1, s[n], x);
    int nxtpos = get_pos(1, 1, s[n], x + 1);
    ans = ans - square(nxtpos - pos);
    int val = nxtpos - pos;
    upd(1, 1, s[n], pos + val / 2, 1);
    ans = ans + square(val / 2) + square(val - val / 2);
    cnt_n++;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    fi(task".inp");
    fo(task".out");

    cin >> n >> p;
    rep(i, 1, n) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    rep(i, 1, n)
        upd(1, 1, s[n], s[i - 1] + 1, 1);

    rep(i, 1, n) {
        int pos = get_pos(1, 1, s[n], i + 1);
        int prepos = get_pos(1, 1, s[n], i);
        ans = ans + square(pos - prepos);
    }

    cout << ans << "\n";

    cin >> k;
    cnt_n = n;
    while(k--) {
        int id, x;
        cin >> id >> x;

        if(id == 1)
            type1(x);
        else if(id == 2)
            type2(x);

        cout << ans << "\n";
    }
}
