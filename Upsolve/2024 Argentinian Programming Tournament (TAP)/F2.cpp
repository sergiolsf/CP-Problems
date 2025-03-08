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
    int n; cin >> n;
    
    int ans = 0, st = 0;
    for (int i = 0; i < n; i++) {
        int r; cin >> r;
        if (r) {
            st++;
            ans++;
        } else {
            ans--;
            st = 0;
        }
        if (st >= 3) ans++;
    }
    cout << ans << endl;
  
    return 0;
}