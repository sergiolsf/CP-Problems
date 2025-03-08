#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct Line {
    long long m, b;
    long long val(long long x) {
        return m*x + b;
    }
};

struct LiChao {
    long long l, r;
    Line line;
    LiChao *lc, *rc;
    LiChao(long long L, long long R, Line ln) {
        l = L;
        r = R;
        line = ln;
        lc = rc = nullptr;
    }
};

void addLine(LiChao*& t, long long L, long long R, Line nw) {
    if (!t) {
        t = new LiChao(L, R, nw);
        return;
    }
    long long mid = (t->l + t->r) / 2;
    bool leftBetter = (nw.val(t->l) > t->line.val(t->l));
    bool midBetter  = (nw.val(mid)   > t->line.val(mid));
    if (midBetter) swap(nw, t->line);
    if (t->l == t->r) return;
    if (leftBetter != midBetter) addLine(t->lc, t->l, mid, nw);
    else addLine(t->rc, mid+1, t->r, nw);
}

long long getMax(LiChao* t, long long x) {
    if (!t) return -LLONG_MAX/4;
    long long ans = t->line.val(x);
    long long mid = (t->l + t->r) / 2;
    if (t->l == t->r) return ans;
    if (x <= mid && t->lc) ans = max(ans, getMax(t->lc, x));
    else if (x > mid && t->rc) ans = max(ans, getMax(t->rc, x));
    return ans;
}

const int MX = 400000;
LiChao* seg[MX];
void buildSeg(int idx, int s, int e) {
    seg[idx] = nullptr;
    if (s == e) return;
    int m = (s + e) / 2;
    buildSeg(idx*2, s, m);
    buildSeg(idx*2+1, m+1, e);
}

void addLineSeg(int idx, int s, int e, int l, int r, Line ln) {
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        addLine(seg[idx], -1000000000LL, 1000000000LL, ln);
        return;
    }
    int m = (s + e) / 2;
    addLineSeg(idx*2, s, m, l, r, ln);
    addLineSeg(idx*2+1, m+1, e, l, r, ln);
}

vector<int> X, Y, ans;

void queryToken(int idx, int s, int e, int t) {
    if (!seg[idx]) return;
    long long val = getMax(seg[idx], X[t]);
    if (val > Y[t]) {
        if (s == e) {
            ans[t] = s;
            return;
        }
        int m = (s + e) / 2;
        queryToken(idx*2, s, m, t);
        if (!ans[t]) queryToken(idx*2+1, m+1, e, t);
    }
}

signed main() {
    fastio();
    int T;
    cin >> T;
    X.resize(T);
    Y.resize(T);
    for (int i = 0; i < T; i++) cin >> X[i] >> Y[i];
    int P;
    cin >> P;
    vector<Line> lines(P + 1);
    for (int i = 1; i <= P; i++) {
        long long a, b;
        cin >> a >> b;
        lines[i] = {a, b};
    }
    buildSeg(1, 1, P);
    for (int i = 1; i <= P; i++) addLineSeg(1, 1, P, i, i, lines[i]);
    ans.assign(T, 0);
    for (int t = 0; t < T; t++) queryToken(1, 1, P, t);
    vector<vi> who(P + 1);
    for (int t = 0; t < T; t++) if (ans[t]) who[ans[t]].pb(t + 1);
    for (int i = 1; i <= P; i++) {
        sort(all(who[i]));
        cout << who[i].size();
        for (auto x : who[i]) cout << " " << x;
        cout << endl;
    }
    
    return 0;
}
