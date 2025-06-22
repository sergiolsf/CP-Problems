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

const int MOD = 998244353;
const int MAX_N = 100'005;

vvi dado (MAX_N, vi (7));

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = (ans*ans)%MOD;
    if (p&1) ans = (ans*b)%MOD;
    return ans;
}

int mod (int a) {
    return (a%MOD + MOD)%MOD;
}

signed main() {
    fastio();

    int n; cin >> n;
    set<int> st;
    vector<pii> vp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            cin >> dado[i][j];
            st.insert(dado[i][j]);
            vp.push_back({dado[i][j], i});
        }
    }

    vi S; S.push_back(0);
    for (auto e: st) {
        S.push_back(e);
    }

    sort(all(vp));

    int cont = 0;
    vi P;   
    P.push_back(0);
    int ans = 1;

    map<int,int> mp;

    for (int i = 0; i < vp.size();) {
        int j = i;
        while (j < vp.size() && vp[i].first == vp[j].first) {
            if (mp.count(vp[j].second)) {
                int md = mp[vp[j].second];
                ans = (ans*modpow(md, MOD-2))%MOD;
                md++;
                ans = (ans*md)%MOD;
                mp[vp[j].second] = md;
            } else {
                cont++;
                mp[vp[j].second] = 1;
            }
            j++;
        }

        if (cont == n) {
                P.push_back(mod(ans));
            } else {
                P.push_back(0);
            }
        i = j;
    }

    int E = 0;

    for (int i = 1; i < S.size(); i++) {
        //cout << S[i] << " " << P[i] << endl;
        E = mod(E+mod(S[i]*mod(P[i] - P[i-1])));
    }

    int m6 = modpow(6, n);
    int mult = modpow(m6, MOD-2);
    E = mod(E*mult);

    cout << E << endl;
  
    return 0;
}