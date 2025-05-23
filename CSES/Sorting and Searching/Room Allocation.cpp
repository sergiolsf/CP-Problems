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
    vi room(n+1);
    vector<tuple<int,int,int>> p;
    set<int> st;

    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        p.push_back({a, 1, i});
        p.push_back({b, 2, i});
        st.insert(i);
    }

    sort(all(p));

    int ans = 0;
    for (auto &[a, c, i]: p) {
        if (c == 1) {
            int s = *st.begin();
            st.erase(s);
            ans = max(ans, s);
            room[i] = s;
        } else {
            int s = room[i];
            st.insert(s);
        }
    }

    cout << ans << endl;
    for (int i = 1; i <= n; i++) cout << room[i] << " ";
    cout << endl;
  
    return 0;
}