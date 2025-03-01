#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

signed main() 
{
    fastio();
    int n;
    cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.pb({x, i});
    }

    sort(all(v));

    int pri = 0;
    int ant = 0;
    int ans = 1e18;
    

    for (int i = 0; i < n; i++) {
        int x = v[i].first;
        int ind = v[i].second;
        if (x == ant) {
            ans = min(ans, ind-pri+1);
        } else {
            ant = x;
        }
        pri = ind;
    }

    if (ans == 0 || ans == 1 || ans > 1e7) cout << -1 << endl;
    else cout << ans << endl;
  
    return 0;
}