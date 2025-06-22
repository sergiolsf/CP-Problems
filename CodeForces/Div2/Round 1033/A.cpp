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
    int l1, b1, l2, b2, l3, b3; cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if (b1 == b2 && b1 == b3 && (l1+l2+l3 == b1)) cout << "YES\n"; 
    else if (l1 == l2 && l1 == l3 && (b1+b2+b3 == l1)) cout << "YES\n"; 
    else if (l1 == l2+l3 && b2 == b3 && b2+b1 == l1) cout << "YES\n"; 
    else if (b1 == b2+b3 && l2 == l3 && l1+l2 == b1) cout << "YES\n"; 
    else cout << "NO\n";
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