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
    int n; cin >> n;
    vi ans(5);
    ans[1] = 1, ans[2] = 2, ans[3] = 3;
    while (n--) {
        int a, b; cin >> a >> b;
        swap(ans[a], ans[b]);
    }

    for (int i = 1; i <= 3; i++) {
        if (ans[i] == 2) cout << i << endl;
    }
  
    return 0;
}