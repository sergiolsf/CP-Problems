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
    vi slopes(n+1, 0);
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        slopes[(a+b)%n]++;
    }

    int ans = m*(m-1)/2;
    for (int i = 0; i < n; i++) {
        int k = slopes[i];
        ans -= k*(k-1)/2;
    }

    cout << ans << endl;
  
    return 0;
}