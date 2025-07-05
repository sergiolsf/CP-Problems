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

const int MAX_N = 5'005;
const int INF = 1'000'000'000'000'000;
int a[MAX_N];
int n; 

int bb(int ini, int fim) {

    int lo = 0, hi = n+1;
    while (hi-lo > 1) {
        int m = (hi+lo)/2;
        if (a[m] < ini) lo = m;
        else hi = m;
    }

    if (hi >= fim) return 0;
    return fim-hi;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n+1] = INF;

    int ans = 0;
    for (int p = n; p >= 3; p--) {
        for (int q = p-1; q >= 2; q--) {
            int ini = max(a[p]-a[q], a[n]-a[p]-a[q]);
            ans += bb(ini+1, q);
        }
    }
    cout << ans << endl;
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