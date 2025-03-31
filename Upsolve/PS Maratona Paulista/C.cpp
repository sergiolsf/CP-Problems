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

const int MAXN = 30;

bool marc[MAXN][MAXN];

signed main() {
    fastio();
    string s; cin >> s;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char u, v; cin >> u >> v;
        int ud = u-'a';
        int vd = v-'a';
        marc[ud][vd] = true;
    }

    int sz = s.size();
    for (int i = 0; i < sz-1; i++) {
        int ud = s[i]-'a';
        int vd = s[i+1]-'a';
        if (!marc[ud][vd]) {
            cout << "NAO\n";
            return 0;
        }
    }

    cout << "SIM\n";
  
    return 0;
}