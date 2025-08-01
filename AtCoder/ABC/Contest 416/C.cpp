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

int n, k, x; 
vector<string> vs;
vector<string> v;

void solve(int q, string s) {
    if (q == 0) {
        vs.push_back(s);
        return;
    }
    for (int i = 0; i < n; i++) {
        solve(q-1, s+v[i]);
    }
}

signed main() {
    fastio();
    cin >> n >> k >> x;
    
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        v.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        solve (k-1, v[i]);
    }

    sort(all(vs));
    cout << vs[x-1] << endl;
  
    return 0;
}