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

int cobre(int x1, int x2, int y1, int y2){
    if (x1 >= x2 || y1 >= y2) return 0;

    int w = x2-x1, h = y2-y1;
    int ans = 0;

    while (true) {
        if (w == 0 || h == 0) return 0;
        int lado = 1LL<<(63-__builtin_clzll(min(w,h)));
        bool flag = false;

        while (lado > 0) {
            int xIni = ((x1+lado-1)/lado)*lado;
            int xFim   = ((x2-lado)/lado)*lado;

            if (xFim >= xIni) {
                int cntX = (xFim-xIni)/lado + 1;
                int yIni = ((y1+lado-1)/lado)*lado;
                int yFim = ((y2-lado)/lado)*lado;

                if (yFim >= yIni) {
                    int cntY = (yFim-yIni)/lado + 1;
                    int quad = cntX*cntY;

                    if (quad > 0) {
                        flag = true;
                        ans += quad;
                        ans += cobre(xIni, min(xFim+lado, x2), y1, min(yIni, y2));
                        ans += cobre(xIni, min(xFim+lado, x2), yFim+lado, y2);
                        ans += cobre(x1, min(xIni, x2), y1, y2);
                        ans += cobre(min(xFim + lado, x2), x2, y1, y2);
                        return ans;
                    }
                }
            }
            lado >>= 1;
        }
        if(!flag) return 0;
    }
}

void solve() {
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;

    cout << cobre(l1, r1, l2, r2) << endl;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}