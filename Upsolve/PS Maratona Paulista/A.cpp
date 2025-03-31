#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


signed main() {
    fastio();
    int n, x; cin >> n >> x;
    vi ans;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (x%a == 0) ans.push_back(i);
    }

    int sz = ans.size();
    cout << sz << endl;
    for (int i = 0; i < sz; i++) cout << ans[i] << (i == sz-1 ? "\n" : " ");

    return 0;
}