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
    int n, k; cin >> n >> k;
    vi a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vi pre, pos;
    int cont = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= k) cont++;
        if (cont >= (i+1)/2) {
            if (cont > 1 && pre.size() > 0) flag = true;
            pre.push_back(i); 
        }
    }
    if (flag) {
        cout << "YES\n";
        return;
    }
    cont = 0;
    flag = false;
    for (int i = n; i >= 1; i--) {
        if (a[i] <= k) cont++;
        if (cont >= ((n-i+1)+1)/2) {
            if (cont > 1 && pos.size() > 0) flag = true;
            pos.push_back(i);
        }
    }
    if (flag) {
        cout << "YES\n";
        return;
    }
    else if (pos.size() == 0 || pre.size() == 0) {
        cout << "NO\n";
        return;
    }

    for (auto e: pos) {
        for (auto g: pre) {
            if (g < e-1) {
                cout << "YES\n";
                return;
            }
        }
    }
    
    cout << "NO\n";
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