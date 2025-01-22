#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int INF = 1e17;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vi a(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vi ini, med, fim;
    int ans1 = INF, ans2 = 0, ans3 = INF;

    for (int i = 1; i < l; i++) {
        ini.push_back(a[i]);
    }

    for (int i = l; i <= r; i++) {
        med.push_back(a[i]);
        ans2 += a[i];
    }

    for (int i = r+1; i <= n; i++) {
        fim.push_back(a[i]);
    }

    sort(all(ini));
    sort(all(med));
    sort(all(fim));

    int tot = med.size();
    int quant;

    if (ini.size()) {
        int i = 0; 
        int j = 0;
        quant = 0;
        ans1 = 0;
        while (i < ini.size() && j < med.size() && quant < tot) {
            if (ini[i] < med[j]) {
                ans1 += ini[i];
                quant++;
                i++;
            } else {
                ans1 += med[j];
                quant++;
                j++;
            }
        }

        while(quant < tot) {
            ans1 += med[j];
            quant++;
            j++;
        }
    }

    if (fim.size()) {
        int i = 0; 
        int j = 0;
        quant = 0;
        ans3 = 0;
        while (i < fim.size() && j < med.size() && quant < tot) {
            if (fim[i] < med[j]) {
                ans3 += fim[i];
                quant++;
                i++;
            } else {
                ans3 += med[j];
                quant++;
                j++;
            }
        }

        while(quant < tot) {
            ans3 += med[j];
            quant++;
            j++;
        }
    }

    cout << min(ans1, min(ans2, ans3)) << endl;
    
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}