#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int maxN = 100;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> v(maxN);

void solve() {
    int n;
    cin >> n;
    for (int i = 1; ; i++) {
        if (v[i] >= n) {
            cout << i << endl;
            return;
        }
    }
}

signed main() {
    fastio();
    int t;
    cin >> t;
    int res = 1;
    int i;
    for (i = 1; res <= 100000; i++) {
        v[i] = res;
        res = (res+1)*2;
    }
    v[i] = res;

    while(t--) {
        solve();
    }    
    return 0;
}