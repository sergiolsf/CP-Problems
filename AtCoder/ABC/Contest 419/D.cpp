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

const int MAX_N = 500'005;

int v[MAX_N];


signed main() {
    fastio();
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        v[l]++;
        v[r+1]--;
    }

    for (int i = 1; i <= n; i++) {
        v[i] += v[i-1];
        if (v[i]&1) cout << t[i-1];
        else cout << s[i-1];
    }
    cout << endl;
  
    return 0;
}