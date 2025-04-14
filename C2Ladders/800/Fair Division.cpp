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
    int q1 = 0, q2 = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 1) q1++;
        else q2++;
    }
    if (q1%2 == 0 && q2%2 == 0) { 
        cout << "YES\n";
        return;
    } else if (q1%2 == 0 && q1 > 0) {
        cout << "YES\n";
        return;
    } else {
        cout << "NO\n";
        return;
    }

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