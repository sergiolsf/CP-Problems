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
    int ans = 0;
    int n; cin >> n;
    string s, t; cin >> s >> t;
    for (int i = 0; i < n; i++)  ans += (s[i] != t[i]);
    
    cout << ans << endl;
    return 0;
}