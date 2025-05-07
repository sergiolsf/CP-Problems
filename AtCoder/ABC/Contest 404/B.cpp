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
    vvi s(n+1, vi(n+1));
    vvi t(n+1, vi(n+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            if (c == '.') s[i][j] = 0;
            else s[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            if (c == '.') t[i][j] = 0;
            else t[i][j] = 1;
        }
    }

    int ans = 1'000'000'000'000'000;

    int cont = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cont += (s[i][j] != t[i][j]);
        }
    }
    ans = min(cont, ans);

    cont = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = n; i >= 1; i--) {
            cont += (s[i][j] != t[j][n+1-i]);
        }
    }
    ans = min(cont, ans);

    cont = 2;
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            cont += (s[i][j] != t[n+1-i][n+1-j]);
        }
    }
    ans = min(cont, ans);

    cont = 3;
    for (int j = n; j >= 1; j--) {
        for (int i = 1; i <= n; i++) {
            cont += (s[i][j] != t[n+1-j][i]);
        }
    }
    ans = min(cont, ans);

    cout << ans << endl;
  
    return 0;
}