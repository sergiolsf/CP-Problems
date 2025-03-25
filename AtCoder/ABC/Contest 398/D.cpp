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
    int N, R, C; cin >> N >> R >> C;
    string S; cin >> S;

    set<pii> st;

    int fx = 0, fy = 0;
    st.insert({0,0});
    for (auto e: S) {
        if (e == 'N') {
            fx++;
            R++;
        }
        else if (e == 'S') {
            fx--;
            R--;
        }
        else if (e == 'E') {
            fy--;
            C--;
        }
        else {
            fy++;
            C++;
        }
    
        if (st.count({R,C})) cout << 1;
        else cout << 0;

        st.insert({fx, fy});
    }
  
    return 0;
}