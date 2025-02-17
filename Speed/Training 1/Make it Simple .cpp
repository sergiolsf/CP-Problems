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

vvi g;

signed main() {
    fastio();
    int N, M;
    cin >> N >> M;
    int ans = 0;
    set<pii> st;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) ans++;
        else {
            if (st.count({u,v})) ans++;
            else {
                st.insert({u,v});
                st.insert({v,u});
            }
        }
    }

    cout << ans << endl;
  
    return 0;
}