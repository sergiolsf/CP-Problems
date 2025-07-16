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

int a,b,c,x,y;
const int MAX_N = 55;
bool v[MAX_N];

void solve() {
    int ans = 0;
    //
    int p = 0;
    if (a < x) p++;
    if (b < y) p++;
    if (p == 2) {
        for (int i = 1; i < MAX_N; i++) {
            if (!v[i]) {
                ans = max(ans, i);
                break;
            }
        }
    } else if (p == 1) {
        for (int i = c+1; i < MAX_N; i++) {
            if (!v[i]) {
                if (i > 52) {
                    cout << -1 << endl;
                    return;
                }
                ans = max(ans, i);
                break;
            }
        }
    } else {
        cout << -1 << endl;
        return;
    }
    //
    p = 0;
    if (b < x) p++;
    if (a < y) p++;
    if (p == 2) {
        for (int i = 1; i < MAX_N; i++) {
            if (!v[i]) {
                ans = max(ans, i);
                break;
            }
        }
    } else if (p == 1) {
        for (int i = c+1; i < MAX_N; i++) {
            if (!v[i]) {
                if (i > 52) {
                    cout << -1 << endl;
                    return;
                }
                ans = max(ans, i);
                break;
            }
        }
    } else {
        cout << -1 << endl;
        return;
    }
    //
    p = 0;
    if (c < x) p++;
    if (b < y) p++;
    if (p == 2) {
        for (int i = 1; i < MAX_N; i++) {
            if (!v[i]) {
                ans = max(ans, i);
                break;
            }
        }
    } else if (p == 1) {
        for (int i = a+1; i < MAX_N; i++) {
            if (!v[i]) {
                if (i > 52) {
                    cout << -1 << endl;
                    return;
                }
                ans = max(ans, i);
                break;
            }
        }
    } else {
        cout << -1 << endl;
        return;
    }
    //
    p = 0;
    if (b < x) p++;
    if (c < y) p++;
    if (p == 2) {
        for (int i = 1; i < MAX_N; i++) {
            if (!v[i]) {
                ans = max(ans, i);
                break;
            }
        }
    } else if (p == 1) {
        for (int i = a+1; i < MAX_N; i++) {
            if (!v[i]) {
                if (i > 52) {
                    cout << -1 << endl;
                    return;
                }
                ans = max(ans, i);
                break;
            }
        }
    } else {
        cout << -1 << endl;
        return;
    }
    //
    p = 0;
    if (a < x) p++;
    if (c < y) p++;
    if (p == 2) {
        for (int i = 1; i < MAX_N; i++) {
            if (!v[i]) {
                ans = max(ans, i);
                break;
            }
        }
    } else if (p == 1) {
        for (int i = b+1; i < MAX_N; i++) {
            if (!v[i]) {
                if (i > 52) {
                    cout << -1 << endl;
                    return;
                }
                ans = max(ans, i);
                break;
            }
        }
    } else {
        cout << -1 << endl;
        return;
    }
    //
    p = 0;
    if (c < x) p++;
    if (a < y) p++;
    if (p == 2) {
        for (int i = 1; i < MAX_N; i++) {
            if (!v[i]) {
                ans = max(ans, i);
                break;
            }
        }
    } else if (p == 1) {
        for (int i = b+1; i < MAX_N; i++) {
            if (!v[i]) {
                if (i > 52) {
                    cout << -1 << endl;
                    return;
                }
                ans = max(ans, i);
                break;
            }
        }
    } else {
        cout << -1 << endl;
        return;
    }

    cout << ans << endl;
}

void init() {
    for (int i = 1; i < MAX_N; i++) v[i] = false;
}

signed main() {
    fastio();
    cin >> a >> b >> c >> x >> y;
    while (a != 0) {
        init();
        v[a] = v[b] = v[c] = v[x] = v[y] = true;
        solve();
        cin >> a >> b >> c >> x >> y;
    }
  
    return 0;
}