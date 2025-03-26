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
const int MAXB = 63;
const int maximo = 1'000'000'000'000'000'000;

int cont(int x, int y) {
    int a = x&y;
    int ans = __builtin_popcountll(a);
    return ans;
}

void solve() {
    int x, y, k = 0; cin >> x >> y;
    if (cont(x, y) == 0) {
        cout << 0 << endl;
        return;
    }
    int i = 0;
    for (; i < MAXB && k < maximo; i++) {
        if (cont(x+(1LL<<i)+k, y+(1LL<<i)+k) <= cont(x+k, y+k)) k += (1LL<<i);
        if (cont(x+k, y+k) == 0 && k <= maximo) {
            cout << k << endl;
            return;
        }
    }
    if (k > maximo) k -= (1LL<<(i-1));
    if (cont(x+k, y+k) == 0) {
        cout << k << endl;
        return;
    }
    cout << -1 << endl;
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