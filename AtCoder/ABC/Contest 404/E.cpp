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

vi mqz;
vi c;
vi a;

const int INF = 1'000'000'000'000;

signed main() {
    fastio();
    int n; cin >> n;
    c.resize(n);
    a.resize(n);
    mqz.resize(n);
    for (int i = 1; i < n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) cin >> a[i];
    a[0] = 1;

    mqz[0] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i]) {
            mqz[i] = 0;
            continue;
        }
        int d = INF;
        for (int j = i-1; j >= 0 && j >= i-c[i]; j--) {
            d = min(d, mqz[j]);
        }
        mqz[i] = d+1;
    }

    int ans = 0;
    for (int i = n-1; i > 0; i--) {
        if (!a[i]) continue;
        bool flag = false;
        int d = INF;
        int J;
        for (int j = i-1; j >= 0 && j >= i-c[i]; j--) {
            if (mqz[j] == 0) {
                ans++;
                flag = true;
                break;
            }
            if (d > mqz[j]) {
                J = j;
                d = mqz[j];
            }
        }
        if (flag) continue;
        a[J]++;
        ans++;
    }

    cout << ans << endl;

  
    return 0;
}