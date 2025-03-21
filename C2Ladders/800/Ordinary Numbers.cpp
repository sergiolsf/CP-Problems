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

int sol(int n) {
    int ans = 0;
    for (int d = 1; d <= 9; d++) {
        int p = 1;
        int s = 1;
        for (int k = 0; k <= 9; k++) {
            if (s*d <= n) ans++;
            else break;
            p*= 10;
            s += p;
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    cout << sol(n) << endl;
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