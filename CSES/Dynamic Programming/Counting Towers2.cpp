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

const int MAX_N = 1'000'005;
const int MOD = 1'000'000'007;

int cont[MAX_N][2];

signed main() {
    fastio();
    cont[1][0] = 1;
    cont[1][1] = 1;

    for (int i = 2; i < MAX_N; i++) {
        cont[i][0] = (4*cont[i-1][0] + cont[i-1][1])%MOD;
        cont[i][1] = (cont[i-1][0] + 2*cont[i-1][1])%MOD;
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << (cont[n][0]+cont[n][1])%MOD << endl;
    }
    
  
    return 0;
}