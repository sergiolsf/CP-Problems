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

const int MAX_N = 200'010;
vi v(MAX_N);

void solve() {
    int n; cin >> n;
    vi a(2*n+1);
    for (int i = 1; i <= 2*n; i++) {
        cin >> a[i];
        v[a[i]] = i;
    }

    int ans = 0;

    for (int i = 1; i <= 2*n; i++) {
        if (v[a[i]] == i) continue;
        if(a[i] == a[i+1] || a[i] == a[i-1]) continue;
        if ((a[v[a[i]]-1] == a[i+1]) && abs(v[a[i]]-1 - i-1) > 1) ans++;
        if (v[a[i]]+1 <= 2*n && a[v[a[i]]+1] == a[i+1]) ans++;
    }

    cout << ans << endl;
}

signed main() {
    fastio();
    int t; cin >> t;
    while (t--) solve();  
    return 0;
}