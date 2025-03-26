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

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int c = k/n;
    if (k%n) c++;
    int l = 0, r = c;
    while (r-l != 1) {
        int t = (r+l) / 2;
        int a = 0;
        if (c%t) a++;
        if (t*(c/t) + c%t + (c/t+a) - 1 <= m) r = t;
        else l = t;
    }
    cout << r << endl;
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