#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int MAXK = 102;
const int MAXM = 502;

vi baldeval[MAXK][MAXM];    
vector<pii> baldevalbac[MAXK][MAXM];
int dp[MAXK][MAXM];         
pii dpbac[MAXK][MAXM];       
vi x;                         
vector<pii> ans;    
int n, k, m;       

void init() {
    for(int i = 0; i <= 50; i++) {        
        if(i <= k) {
            for (int j = 1; j <= m; j++) {
                baldeval[i][j].pb(i);
                baldevalbac[i][j].pb({1, i});
            }
            continue;
        }
        
        for(int j = 1; j <= m; j++) {
            int maxVal = 0;
            vector<pii> vp;
            for(int l = 0; l < j; l++) {
                int a = i/2, r = j-l-1;
                int b = i-a;
                if(r < 0) continue;
                int valA, valB;

                if (a <= k && l > 0) {
                    valA = a;
                } else {
                    if (baldeval[a][l].empty()) valA = 0;
                    else valA = baldeval[a][l].back();
                }

                if (b <= k && r > 0) {
                    valB = b;
                } else {
                    if (baldeval[b][r].empty()) valB = 0;
                    else valB = baldeval[b][r].back();
                }

                if ((valA + valB) > maxVal) {
                    maxVal = valA + valB;
                    vp.clear();
                    vp.pb({2, i});                  
                    if(a <= k) {
                        if (l > 0) vp.pb({1, a});
                    } else {
                        for(auto e: baldevalbac[a][l]) vp.pb(e);
                    }

                    if(b <= k) {
                        if (r > 0) vp.pb({1, b});
                    } else {
                        for (auto e: baldevalbac[b][r]) vp.pb(e);
                    }
                }
            }
            if (maxVal > 0) {
                baldeval[i][j].pb(maxVal);
                baldevalbac[i][j] = vp;
            }
        }
    }
}

signed main() {
    fastio();
    
    cin >> n >> k >> m;
    x.resize(n);
    
    for (auto &i: x) cin >> i;
    
    init();
        
    for (int i = 0; i < n; i++) {
        int c = x[i];
        for (int j = 0; j <= m; j++) {
            dp[i+1][j] = dp[i][j];
            dpbac[i+1][j] = {0, 0};
            for (int l = 1; l <= j; l++) {
                if (baldeval[c][l].empty()) continue;
                int nv = dp[i][j-l] + baldeval[c][l].back();
                if(nv > dp[i+1][j]) {
                    dp[i+1][j] = nv;
                    dpbac[i+1][j] = {l, c};
                }
            }
        }
    }
    
    int bestj = m;
    for (int i = n; i > 0; i--) {
        int l = dpbac[i][bestj].first;
        int bk = dpbac[i][bestj].second;
        if(l && bk) {
            for(auto e: baldevalbac[bk][l]) {
                ans.pb(e);
            }
        }
        bestj -= l;
    }
    
    cout << dp[n][m] << " " << ans.size() << endl;

    for(auto e: ans) cout << e.first << " " << e.second << endl;
    
    return 0;
}