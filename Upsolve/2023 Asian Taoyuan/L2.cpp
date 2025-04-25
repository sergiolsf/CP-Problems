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

const int MOD = 1'000'000'007;

int ans = 0;

bool hasSubset9(vi &groups) {
    vector<bool> possible (11, false);
    possible[0] = true;
    for (auto g: groups) {
        if (g > 9) continue;
        for (int i = 8; i >= 0; i--) {
            if (possible[i] && i+g <= 9) {
                possible[i+g] = true;
            }
        }
    }
    return possible[9];
}

void backtracking (int n, vi& groups, int ini) {
    if (n == 0) {
        if (!hasSubset9(groups)) {
            ans = max(ans, (int) groups.size());
        }
        return;
    }
    for (int i = ini; i <= n; i++) {
        if (i == 9) continue;
        groups.push_back(i);
        backtracking(n-i, groups, i);
        groups.pop_back();
    }
}


signed main() {
    fastio();
    int n; cin >> n;
    if (n < 9) cout << n << endl;
    else if (n%2 == 0) cout << (n/2)%MOD << endl;
    else if (n > 29) {
        int maior = (n/2)-4;
        maior = (maior%MOD + MOD)%MOD;
        cout << maior << endl;
    } else {
        vi groups;
        backtracking(n, groups, 1);
        cout << ans << endl;
    }
  
    return 0;
}