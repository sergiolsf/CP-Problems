#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


signed main() {
    fastio();
    int n; cin >> n;
    vi h(n);
    for (auto &i: h) cin >> i;

    int ans = h[n-1]+1;
    for (int i = n-2; i >= 0; i--) {
        ans++;
        ans = max(ans, h[i]+1);
    }

    cout << ans+1 << endl;

    return 0;
}