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
    int n; cin >> n;
    vi a(n);
    int sum = 0;
    for (auto &i: a) {
        cin >> i;
        sum += i;
    }
    if (sum % n) {
        cout << -1 << endl;
        return;
    }
    int k = 0;
    int media = sum/n;
    for (auto i: a) {
        if (i > media) k++;
    }
    cout << k << endl;
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