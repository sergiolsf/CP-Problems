#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MOD = 998244353;

int modexp(int a, int b){
    int r=1;
    while (b > 0) {
        if (b&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return r;
}

int invSmall[18];
 
void Inv(){
    for (int i=1; i<=17; i++) {
        invSmall[i] = modexp (i,MOD-2);
    }
}

int comb (int n,  int r) {
    if (r < 0 || r > n) return 0;
    int ans = 1;
    for (int i=0; i<r; i++) {
        ans = (ans*((n-i)%MOD))%MOD;
        ans= (ans*invSmall[i+1])%MOD;//
    }
    return ans;
}

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    int k, n;
    cin >> k >> n;

    if (k == 1){
        cout << (n%MOD) << endl;
        return;
    }

    vvi t(18, vi(k+1,0));
    t[0][1] = 1;
    for (int x = 2; x <= k; x++){
        t[1][x] = 1;
    }
    for (int s = 2;s <= 17; s++){
        fill(all(t[s]), 0);
        for (int d = 1; d <= k; d++){
            int w = t[s-1][d];
            if (!w) continue;
            for (int x = 2; d*x <= k; x++){
                int m = d*x;
                int tmp = t[s][m] + w;
                if (tmp >= MOD) tmp -= MOD;
                t[s][m] = tmp;
            }
        }
    }
    vector<int> Cvals(18,0);
    for(int r=1;r<=17;r++){
        Cvals[r]=comb(n+1,r);
    }
    for(int x=1; x<=k; x++){
        if(x == 1){
            cout << (n%MOD);
        } else {
            int ans = 0;
            for (int s = 1; s <= 17; s++) {
                int cnt = t[s][x];
                if (!cnt) continue;
                int c = (s+1 <= 17 ? Cvals[s+1]: comb(n+1, s+1));
                ans = (ans + cnt*c)%MOD;
            }
            cout << ans;
        }
        if (x < k) cout << " ";
    }
    cout << endl;
}

signed main(){
    fastio();
    Inv();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
