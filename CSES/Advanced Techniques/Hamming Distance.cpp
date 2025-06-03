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

const int INF = 1e18;

int N(char c) {
    if (c == '0') return 0;
    return 1;
}

signed main() {
    fastio();
    int n, k; cin >> n >> k;
    vi num(n+1);
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        int p = 0;
        for (int j = 0; j < k; j++) {
            p += (int) N(s[j])*(1LL<<(k-1-j));
        }
        num[i] = p;
    }

    int ans = INF;

    for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            int a = __builtin_popcountll(num[i]^num[j]);
            ans = min(ans, a);
        }
    }

    cout << ans << endl;

  
    return 0;
}