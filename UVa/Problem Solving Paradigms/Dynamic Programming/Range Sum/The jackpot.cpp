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

const int INF = 1e7;

signed main() {
    fastio();
    int n;
    cin >> n;
    while (n) {
        int s = 0;
        int ans = -INF;
        int menor = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s += x;
            ans = max(ans, s-menor);
            menor = min(menor, s);
        }

        if (ans <= 0) cout << "Losing streak." << endl;
        else cout << "The maximum winning streak is " << ans << ".\n";

        cin >> n;
    }    
    return 0;
}