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

const int MAX_N = 100'005;

int n, k;

vector<vi> stMin (MAX_N, vi(25, 0));
vector<vi> stMax (MAX_N, vi(25, 0));
vi sub(MAX_N);

signed main() {
    fastio();
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> sub[i];

    k = log2(n) + 1;

    for (int i = 1; i <= n; i++) {
        stMin[i][0] = sub[i];
        stMax[i][0] = sub[i];
    }

    for (int j = 1; j < k; j++) {
        for (int i = 1; i + (1<<j) - 1 <= n; i++) {
            stMin[i][j] = min(stMin[i][j-1], stMin[i + (1<<(j-1))][j-1]);
            stMax[i][j] = max(stMax[i][j-1], stMax[i + (1<<(j-1))][j-1]);
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;
        if (l == r) {
            if (sub[l] == 1) cout << "TAK\n";
            else cout << "NIE\n";
        } else {
            int k2 = log2(r-l+1);
            int ansMin = stMin[l][k2];
            int ansMax = stMax[l][k2];
            int dif = r - (l + (1LL<<k2) - 1);

            if (dif > 0) {
                ansMin = min(ansMin, stMin[l+dif][k2]);
                ansMax = max(ansMax, stMax[l+dif][k2]);
            }

            if (ansMin == 1 && ansMax == r-l+1) cout << "TAK\n";
            else cout << "NIE\n";

            //cout << ansMin << " " << ansMax << endl;
        }
    }

  
    return 0;
}