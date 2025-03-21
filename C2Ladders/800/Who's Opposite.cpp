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
    int a, b, c;
    cin >> a >> b >> c;
    int d = abs(a-b);
    int n = 2*d;
    if (n < max({a,b,c})) {
        cout << -1 << endl;
        return;
    }
    cout << (c+d-1)%n+1 << endl;
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