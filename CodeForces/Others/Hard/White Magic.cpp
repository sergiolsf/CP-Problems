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

const int MAX_N = 200'010;
const int INF = 1'000'000'000'000'000'000;

int a[MAX_N];

void solve() {
    int n; cin >> n;
    int ans = 0;
    vi v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 0) {
            ans++;
            v.push_back(a[i]);
        }
    }

    if (ans == 0 || a[1] == 0) {
        ans++;

    } else if (a[n] == 0) {
       sort(all(v));
       int mex = 1;
       bool f = true;
       for (int i = 0; i < v.size(); i++) {
            if (v[i] < mex) {
                f = false;
                break;
            }
            mex++;
       }
       if (f) ans++;      

    } else if (n != ans) {
        
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