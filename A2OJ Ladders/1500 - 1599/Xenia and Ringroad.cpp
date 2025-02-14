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
    int n, m;
    cin >> n >> m;
    int house = 1;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        if (x >= house) ans += x-house;
        else if (x < house) ans += (n-house) + x;
        house = x;
    }

    cout << ans << endl;
  
    return 0;
}