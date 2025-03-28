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

void solve() {
    int n, d;
    cin >> n >> d;
    cout << 1 << " ";

    if (d == 3 || d == 6 || d == 9 || n >= 3) cout << 3 << " ";
    if (d == 5) cout << 5 << " ";
    if (d == 7 || n >= 3) cout << 7 << " ";
    if (d == 9 || n >= 6) cout << 9 << " ";
    else if (d == 3 && n >= 3 || d == 6 && n >= 3) cout << 9 << " ";

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