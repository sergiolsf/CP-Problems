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

vi sum, sub, p, r;

int g(int a) {
    return (p[a] == a ? a : g(p[a]));
}

void join(int x, int y) {
    x = g(x);
    y = g(y);
    if (x == y) return;
    if (r[x] == r[y]) r[x]++;
    if (r[x] > r[y]) {
        sub[y] += sum[x];
        p[y] = x;
    } else {
        sub[x] += sum[y];
        p[x] = y;
    }
}

void add (int x, int v) {
    x = g(x);
    sum[x] += v;
}

int get (int a) {
    int S = sum[a], s = sub[a];
    while (p[a] != a) {
        a = p[a];
        S += sum[a];
        s += sub[a];
    }
    return S - s;
}

signed main() {
    fastio();
    int n, m;
    cin >> n >> m;

    p.resize(n+1);
    r.resize(n+1);
    sum.resize(n+1, 0);
    sub.resize(n+1, 0);

    for (int i = 1; i <= n; i++) p[i] = i;

    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        if (s == "add") {
            int x, v;
            cin >> x >> v;
            add(x, v);
        } else if (s == "join") {
            int x, y;
            cin >> x >> y;
            join(x, y);
        } else {
            int x;
            cin >> x;
            cout << get(x) << endl;
        }
    }
  
    return 0;
}