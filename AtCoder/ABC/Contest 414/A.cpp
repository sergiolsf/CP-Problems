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
    int n, l, r; cin >> n >> l >> r;
    int ans = 0;
    while(n--) {
        int a, b; cin >> a >> b;
        if (l >= a && r <= b) ans++;
    }
    cout << ans << endl;
  
    return 0;
}