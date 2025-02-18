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
    int n;
    cin >> n;
    if (n <= 20) {
        for (int i = 0; i < n; i++) {
            char c = 'a'+i;
            cout << c;
        }
    }
    else {
        if (n&1) {
            cout << "a";
            for (int i = 1; i <= (n-1)/2; i++) cout << "b";
            cout << "c";
            for (int i = 1; i < (n-1)/2; i++) cout << "b";
        }
        else {
            for (int i = 1; i <= (n)/2; i++) cout << "b";
            cout << "c";
            for (int i = 1; i < (n)/2; i++) cout << "b";
        }
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