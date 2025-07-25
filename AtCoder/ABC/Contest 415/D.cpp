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
    int n, m; cin >> n >> m;
    vector<pii> v(m);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[i] = {a-b, a};
    }
    sort(all(v));

    int ans = 0;
    for (int i = 0; i < m; i++) {
        auto [c, a] = v[i];
        int b = a-c;
        if (n < a) continue;
        int k = (n-a)/c;
        ans += k;
        if (n - k*c >= a) {
            ans++;
            k++;
        }
        n = n - k*c;
    }  

    cout << ans << endl;
    return 0;
}