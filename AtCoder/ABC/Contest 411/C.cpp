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
    int n, q; cin >> n >> q;
    vector<bool> paint(n+2, false);
    int ans = 0;
    while (q--) {
        int a; cin >> a;
        if (paint[a]) {
            if (paint[a-1] && paint[a+1]) ans++;
            else if (paint[a-1] || paint[a+1]) ;
            else ans--;
        } else {
            if (paint[a-1] && paint[a+1]) ans--;
            else if (paint[a-1] || paint[a+1]) ;
            else ans++;
        }
        paint[a] = !paint[a];
        cout << ans << endl;
    }
  
    return 0;
}