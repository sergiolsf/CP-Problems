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

signed main() {
    fastio();
    int n, m;
    cin >> n >> m;

    multiset<int> h;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto ans = h.lower_bound(x);

        if (*ans != x) { 
            if (ans == h.begin()) {
                cout << -1 << endl;
                continue;
            }
            ans--;
        }

        h.erase(ans);
        cout << *ans << endl;
    }


    
    return 0;
}