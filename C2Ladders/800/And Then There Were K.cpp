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

int pot(int n) {
    int ans = 0;
    while (n > 0) {
        n /= 2;
        ans++;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    int b = pot(n)-1;
    cout << ((1<<b) - 1) << endl;
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