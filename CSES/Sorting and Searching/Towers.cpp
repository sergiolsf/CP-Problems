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
    vector<pii> v;

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        v.push_back({k, i});
    }

    sort(all(v));

    int ans = 0;
    int ult = 0;
    int ant = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].second > ult) {
            ans++;
            ult = v[i].second;
        } else if (ant == v[i].first) {
            ans++;
            ult = v[i].second;
        }
        ant = v[i].first;
    }

    cout << ans << endl;
  
    return 0;
}