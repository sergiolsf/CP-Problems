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

const int NINF = -1'000'000'000'000'000;

void solve() {
    int n; cin >> n;
    vi v;

    v.push_back(NINF);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (v.back() != x) v.push_back(x);
    }
    v.push_back(NINF);

    int ans = 0;
    int sz = v.size()-2;
    for (int i = 1; i <= sz; i++) {
        if ((v[i-1] < v[i]) && (v[i] > v[i+1])) ans++;
    }

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