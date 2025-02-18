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
    int n;
    cin >> n;
    vi coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    vector<bool> pos(1e5+2, false);
    pos[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 1e5; j >= 0; j--) {
            if (pos[j]) pos[j+coin[i]] = true;
        }
    }

    vi ans;
    for (int i = 1; i <= 1e5; i++) {
        if (pos[i]) {
            ans.pb(i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    if(ans.size()) cout << endl;

  
    return 0;
}