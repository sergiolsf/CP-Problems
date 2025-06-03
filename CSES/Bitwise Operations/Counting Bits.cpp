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

const int MAX_K = 60;

signed main() {
    fastio();
    int n; cin >> n;
    int ans = 0;

    for (int k = 1; k < MAX_K; k++) {
        int d1 = ((n+1)/(1LL << k)) * (1LL << (k-1));
        int d2 = max(0LL, (n+1)%(1LL<<k) - (1LL<<(k-1)));
        //cout << k << " " << d1 << " " << d2 << endl;
        ans += d1+d2;
    }

    cout << ans << endl;
  
    return 0;
}