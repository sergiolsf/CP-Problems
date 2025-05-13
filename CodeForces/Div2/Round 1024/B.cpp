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
    bool f = true;
    int p;
    for (int i = 0;i < n; i++) {
        int x; cin >> x;
        a[i] = abs(x);
        if (f) p = abs(x);
        f = false;
    }
    int ant = 0, dep = 0;
    bool zero = false;

    sort(all(a));

    f = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == p) {
            f = true;
            continue;
        }
        if (a[i] == 0) zero = true;
        if (f) {
            dep++;
        } else {
            ant++;
        }
    }

    

    if (ant == dep || ant == dep+1) {
        cout << "YES\n";
        return;
    }

    if (dep > ant) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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