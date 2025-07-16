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
    vector<string> vs;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        vs.push_back(s);
    }

    set<string> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            string a; a = vs[i]+vs[j];
            ans.insert(a);
        }
    }

    cout << ans.size() << endl;
  
    return 0;
}