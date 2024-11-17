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
}

void solve() {
    int n;
    cin >> n;
    if (n <= 4) {
        cout << "-1" << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (i&1 && i != 5) cout << i << " ";
    }

    cout << "5 4";

    for (int i = 2; i <= n; i++) {
        if(i%2==0 && i != 4) cout << " " << i; 
    }

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