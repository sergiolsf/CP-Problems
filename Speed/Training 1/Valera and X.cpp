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
    int n;
    cin >> n;
    vector<string> vs(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> vs[i];
    }
    char c = vs[1][0];
    char s = vs[1][1];
    if (c == s) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (i-j == 1 || i+j == n) {
                if (vs[i][j] != c) {
                    cout << "NO\n";
                    return 0;
                }
            }
            else if (vs[i][j] != s) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
  
    return 0;
}