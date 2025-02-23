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

const int MAXK = 1005;
vi ans(MAXK);

bool dislike (int p) {
    if (p%3 == 0 || p%10 == 3) return true;
    return false;
}

void solve() {
    int k;
    cin >> k;
    cout << ans[k] << endl;
}

signed main() {
    fastio();

    int i = 1, j = 1;

    while (i <= 1000) {
        if (!dislike(j)) {
            ans[i] = j;
            i++;
        }
        j++;
    }

    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}