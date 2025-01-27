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

const int INF = 1e9+5;

signed main() {
    fastio();
    int n;
    cin >> n;

    int s = 0;
    vi x(n+1);

    int ans = -INF;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    int menor = 0;

    for (int i = 1; i <= n; i++) {
        s += x[i];
        ans = max(ans, s - menor);
        menor = min(menor, s);
    }

    cout << ans << endl;
    
    return 0;
}