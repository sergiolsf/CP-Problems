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
    int n, k; cin >> n >> k;
    vector<pii> gloves(n);
    for (int i = 0; i < n; i++) {
        cin >> gloves[i].first;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> gloves[i].second;
        if (gloves[i].second < gloves[i].first) {
            swap(gloves[i].second, gloves[i].first);
        }
        ans += gloves[i].second;
    }

    sort(all(gloves));
    for (int i = n-1; i >= 0 && k > 1; i--) {
        k--;
        ans += gloves[i].first;
    }
    ans ++;
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