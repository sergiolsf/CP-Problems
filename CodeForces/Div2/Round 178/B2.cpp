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
    int n; cin >> n;
    vi a(n);
    for (auto &i: a) cin >> i;
    vi maior(n), sum(n+1, 0);
    maior[0] = a[0];
    sum[n-1] = a[n-1];
    for (int i = 1; i < n; i++) {
        maior[i] = max(maior[i-1], a[i]);
    }
    for (int i = n-2; i >= 0; i--) {
        sum[i] = sum[i+1]+a[i];
    }
    for (int i = n; i > 0; i--) {
        cout << sum[i]+maior[i-1] << (i == 1 ? "\n" : " ");
    }
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