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
    set<int> st;
    while (n--) {
        int a; cin >> a;
        st.insert(a);
    }

    cout << st.size() << endl;
    bool fir = true;
    for (auto e: st) {
        if (!fir) cout << " ";
        cout << e;
        fir = false;
    }
  
    return 0;
}