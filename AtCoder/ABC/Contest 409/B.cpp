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

signed main() {
    fastio();
    int ans = 0;
    int n; cin >> n;
    vi a(n);
    for (auto &i: a) cin >> i;
    for (int i = 1; i <= 100; i++) {
        int cont = 0;
        for (auto e: a) {
            if (e >= i) cont++;
        }
        if (cont >= i) ans = i;
    }
    cout << ans << endl;
  
    return 0;
}