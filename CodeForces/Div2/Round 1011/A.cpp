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
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        int j = n-i-1;
        if (s[i] < s[j]) {
            cout << "YES\n";
            return;
        } else if (s[i] > s[j]) {
            if (k > 0) {
                cout << "YES\n";
                return;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    // confere se tem duas letras diferentes
    if (k > 0) {
        sort(all(s));
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                cout << "YES\n";
                return;
            }
        }
    }
    //
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