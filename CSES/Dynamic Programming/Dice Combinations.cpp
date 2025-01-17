#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MOD = 1e9+7;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

signed main() {
    fastio();
    int n;
    cin >> n;

    vi count(n+1, 0);

    count[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && i-j >= 0; j++) {
            count[i] = (count[i-j]+count[i])%MOD;
        }
    }

    cout << count[n]%MOD << endl;
    
    return 0;
}