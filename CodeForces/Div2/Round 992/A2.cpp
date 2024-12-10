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
    int n, k;
    cin >> n >> k;
    vi resto(k, 0);
    vi ind(k,0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int r = x%k;
        resto[r]++;
        ind[r] = i;
    }

    for (int i = 0; i < k; i++) {
        if (resto[i] == 1) {
            cout << "YES" << endl;
            cout << ind[i] << endl;
            return;
        }
    }
    cout << "NO" << endl;
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