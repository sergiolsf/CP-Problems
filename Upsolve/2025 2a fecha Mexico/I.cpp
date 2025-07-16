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
    int q; cin >> q;
    while (q--) {
        int x, k; cin >> x >> k;
        int a = x, b = x;
        int ans = 1;
        while (b < k) {
            swap(a, b);
            b = a+b;
            ans++;
        }
        cout << ans << endl;
    }
  
    return 0;
}