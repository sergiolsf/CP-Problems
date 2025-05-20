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
    vvi g(n+1);
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        while (k--) {
            int L; cin >> L;
            g[i].push_back(L);
        }
    }

    if (n==2) {
        vi v;
        for (auto e: g[1]) v.push_back(e);
        for (int i = g[2].size()-1; i >= 0; i--) v.push_back(g[2][i]);
        int ult = v[0];
        bool virou = false;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] != ult && virou) {
                cout << "N\n";
                return 0;
            } 
            if (v[i] != ult) virou = true;
            ult = v[i];
        }
    }

    cout << "S\n";
  
    return 0;
}