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
    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        vi v;
        for (int i = 0; i < k; i++) {
            int a; cin >> a;
            v.push_back(a);
        }
        sort(v.rbegin(), v.rend());
        int lo = 0;
        for (int i = 0; i < k; i++) {
            int a = v[i];
            lo = lo + (1LL << (a-1));
        }
        cout << lo << endl;
    }
  
    return 0;
}