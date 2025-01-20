#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vi card(2001);

void solve() {
    int n, m;
    cin >> n >> m;

    vi perm(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k;
            cin >> k;
            card[k] = i+1;
        }
    }

    for (int i = 0; i < n*m; i++) {
        if (i < n) perm[i] = card[i];
        else {
            if (perm[i%n] != card[i]) {
                cout << -1 << endl;
                return;
            }
        }
    }

    vi v;

    for (int i = 0; i < n; i++) {
        v.push_back(perm[i]);
    }

    sort(all(v));

    for (int i = 1; i < n; i++) {
        if (v[i] == v[i-1]) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0;i < n; i++) {
        cout << perm[i] << " ";
    }

    cout << endl;    
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