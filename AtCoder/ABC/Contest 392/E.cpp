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

vi p, r;

int get(int a) {
    return (p[a] == a ? a : get(p[a]));
}

void uniao (int a, int b) {
    a = get(a);
    b = get(b);
    if (r[a] == r[b]) r[a]++;
    if (r[a] > r[b]) {
        p[b] = a;
    } else {
        p[a] = b;
    }
}

signed main() {
    fastio();
    int n, m;
    cin >> n >> m;
    p.resize(n+1);
    r.resize(n+1, 0);
    vector<pii> cabos;
    for (int i = 1; i <= n; i++) p[i] = i;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        int a = get(u);
        int b = get(v);

        if (a == b) {
            cabos.pb({i, u});
        } else {
            uniao(a,b);
        }
    }
    int j = 0;
    int sz = cabos.size();
    vector<pair<int,pii>> ans;

    for (int i = 1; i <= n && j < sz; i++) {
        pii c = cabos[j];
        int u = c.second;
        int a = get(i);
        int b = get(u);

        if (a != b) {
            ans.pb({c.first,{u,i}});
            uniao(a,b);
            j++;
        }
    }

    cout << ans.size() << endl;
    for (auto e: ans) {
        cout << e.first << " " << e.second.first << " " << e.second.second << endl;
    }
  
    return 0;
}