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

map<int,int> mp;
vi v;
vvi memo(2005, vi (2005, -1));

int dp (int i, int j) {
    int &ans = memo[i][j];
    if (ans != -1) return ans;

    if (i == j) {
        return ans = 0;
    }

    int a = dp(i+1, j) + mp[v[i]]*(v[j]-v[i]);
    int b = dp(i, j-1) + mp[v[j]]*(v[j]-v[i]);
    return ans = min(a, b);
}

signed main() {
    fastio();
    int n;
    cin >> n;
    int cont = 0;
    for (int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        if (mp.count(s)) mp[s]++;
        else {
            mp[s] = 1;
            v.pb(s);
            cont++;
        }
    }

    sort(all(v));

    cout << dp(0, cont-1) << endl;
  
    return 0;
}