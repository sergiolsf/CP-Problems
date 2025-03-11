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

const int MAXX = 100'000;

void solve() {
    int x; cin >> x;
    
    for (int y = x-1; y >= max(1LL, x-MAXX); y--) {
        int xy = x^y;
        if (max(xy, x) < y+min(xy,x)) {
            cout << y << endl;
            return;
        }
    }
    cout << -1 << endl;
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