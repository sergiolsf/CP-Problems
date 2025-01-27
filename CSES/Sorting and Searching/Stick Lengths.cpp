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

signed main() {
    fastio();
    int n;

    cin >> n;
    vi a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));

    int x;

    if (n&1) {
        x = a[n/2];
    } else {
        x = (a[n/2] + a[n/2 - 1])/2;
    }

    int ans = 0;
    
    for (auto e: a) {
        ans += abs(x-e);
    }

    cout << ans << endl;
    
    return 0;
}