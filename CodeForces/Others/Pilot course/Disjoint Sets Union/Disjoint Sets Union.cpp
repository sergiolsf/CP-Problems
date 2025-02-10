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

vi p;
vi r;

int get (int a) {
    if(p[a] != a)
        return get(p[a]);
    return p[a];
}

void uniao(int a, int b) {
    a = get(a);
    b = get(b);
    if (r[a] == r[b]) r[a]++;
    if (r[a] > r[b]) {
        p[b] = a;
    }
    else {
        p[a] = b;
    }
}

signed main() {
    fastio();
    int n, m;
    cin >> n >> m;
    p.resize(n+1);
    r.resize(n+1,0);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        string s;
        int u,v;
        cin >> s >> u >> v;
        if (s == "union") {
            uniao(u,v);
        } else {
            u = get(u);
            v = get(v);
            if (u == v) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}