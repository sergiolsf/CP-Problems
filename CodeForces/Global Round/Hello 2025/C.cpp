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
    cout.tie(NULL);
}

void solve() {
    int l, r;
    cin >> l >> r;

    int k;

    k = 31 - __builtin_clz(r^l);

    int a = l | ((1<<k)-1);
    int b = a+1;
    int c = (a == l) ? r : l;
    
    cout << a << " " << b << " " << c << endl;   
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