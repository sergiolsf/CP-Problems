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
    int n, k; cin >> n >> k;

    vi a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    map<int,int> mp;
    set<pii> st;
    int ult = 1, atual = 1, cont = 0, ans = 0;

    for (int i = 1; i <= n; i++) {
        if (mp.count(a[i])) {
            st.erase({mp[a[i]], a[i]});
        } else {
            if (cont == k) {
                int pri = st.begin()->second;
                int ind = st.begin()->first;

                st.erase({mp[pri], pri});
                mp.erase(pri);

                int m;
                m = atual-(ind+1)+1;
                ans -= (m*(m+1))/2;

                m = atual-ult+1;
                ans += (m*(m+1))/2;
                
                ult = ind+1;
            } else {
                cont++;
            }
        }
        atual = i;
        st.insert({i, a[i]});
        mp[a[i]] = i;
    }

    int m = atual-ult+1;
    ans += m*(m+1)/2;

    cout << ans << endl;
  
    return 0;
}