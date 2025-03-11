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
    if (n == 1) {cout << a[0] << endl; return;}
    sort(a.rbegin(), a.rend());
    int maior = a[0];
    for (int i = 1; i < n; i++) {
        maior = max(maior, maior+a[i]-1);
    }
    cout << maior << endl;
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