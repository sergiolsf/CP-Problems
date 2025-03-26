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

const int MAXN = 10'000'010;

vector<bool> prime(MAXN, true);

void solve() {
    int n; cin >> n; 
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (prime[i]) ans += n/i;
    }
    cout << ans << endl;
}

void init() {
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (prime[i]) {
            for (int j = i*i; j < MAXN; j+=i) {
                prime[j] = false;
            }
        }
    }
}

signed main() {
    fastio();
    init();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}