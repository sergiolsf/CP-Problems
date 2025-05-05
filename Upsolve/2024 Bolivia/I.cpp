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

const int MOD = 1'000'000'007;

vi r, p, cont;

int get (int a) {
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void uniao (int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return;
    if (r[a] == r[b]) r[a]++;
    if (r[a] > r[b]) {
        p[b] = a;
        cont[a] = (cont[a] + cont[b])%MOD;
    } else {
        p[a] = b;
        cont[b] = (cont[a] + cont[b])%MOD;
    }
}

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    r.resize(n+1, 0);
    cont.resize(n+1, 1);
    p.resize(n+1);
    for (int i = 1; i <= n; i++) p[i] = i;

    while (m--) {
        int a, b; cin >> a >> b;
        uniao(a, b);
    }

    set<int> st;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int a = get(i);
        if (!st.count(a)) {
            ans = (ans*cont[a])%MOD;
            st.insert(a);
        }
    }

    cout << ans << endl;
  
    return 0;
}