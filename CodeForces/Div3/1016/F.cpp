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

void solve() {
    int k = 0;
    map<string, int> mp;
    int n, m; cin >> n >> m;
    vector<int> a;
    vector<bool> todos(n, false);
    for (int i = 0; i < n; i++) {
        string g; cin >> g;
        if (mp.count(g)) {
            a.push_back(mp[g]);
        } else {
            k++;
            mp[g] = k;
            a.push_back(k);
        }
    }

    int maior = 0;
    while (m--) {
        int cont = 0;
        for (int i = 0; i < n; i++) {
            string g; cin >> g;
            if (mp.count(g)) {
                int p = mp[g];
                if (p == a[i]) {
                    cont++;
                    todos[i] = true;
                }
            }
        }
        maior = max(maior, cont);
    }

    for (int i = 0; i < n; i++) {
        if (!todos[i]) {
            cout << -1 << endl;
            return;
        }
    }

    int ans = n + (n-maior)*2;
    cout << ans << endl;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}