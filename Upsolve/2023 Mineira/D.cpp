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
    vi ans(n, -1);
    int s = 0;
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        s += x;
    }

    s = s%n;

    for (int i = 0; i <= 20; i++) {
        if (ans[s] == -1) ans[s] = i;
        s = (s+1)%n;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
  
    return 0;
}