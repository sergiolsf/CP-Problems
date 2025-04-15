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

bool primo (int a) {
    for (int i = 2; i*i <= a; i++) {
        if (a%i == 0) return false;
    }
    return true;
}

void solve() {
    int n, k; cin >> n >> k;

    if (n == 1 && k == 1) {
        cout << "NO\n";
        return;
    }
    
    int num = 0;
    if (k > 1) {
        if (n == 1) {
            int d = 1;
            for (int i = 1; i <= k; i++) {
                num += d;
                d *= 10;
            }
        } else {
            cout << "NO\n";
            return;
        }
    } else {
        num = n;
    }

    if (primo(num)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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