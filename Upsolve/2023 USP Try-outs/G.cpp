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
    int n, f;
    cin >> n >> f;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        int ma = max(a,b);
        int mi = min(a,b);
        if (ma <= f) f += ma;
        else if (mi <= f) f += mi;
        else {
            cout << "N\n";
            return 0;
        }
    }
    cout << "S\n";  
    return 0;
}