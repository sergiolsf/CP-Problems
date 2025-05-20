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

const int MAX_N = 4'005;
const int MOD = 998'244'353;

int n, k;
int cont[MAX_N];

signed main() {
    fastio();
    cin >> n >> k;

    cont[0] = 1;
    for (int i = n; i >= 1; i--) {
        if (i == k) continue;
        for (int j = 0; j < n; j++) {
            if (j+i > n) break;
            if (cont[j]) {
                cont[j+i] = (cont[j+i]+cont[j])%MOD;
            }
        }
    }

    cout << cont[n] << endl;
    return 0;
}