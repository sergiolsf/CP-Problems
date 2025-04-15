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

void solve() {
    int n, q; cin >> n >> q;

    while (q--) {
        string op; cin >> op;
        if (op == "->") {
            int x, y; cin >> x >> y;
            
            ///
            int m = 1LL<<n;
            int iniL = 1, fimL = m;
            int iniC = 1, fimC = m;
            int iniN = 1, fimN = 1LL<<(2*n);
            while (iniL != fimL && iniC != fimC) {
                int div = (fimN - iniN + 1)/4;
                m /= 2;
                if ((x <= iniL+m-1) && (y <= iniC+m-1)) {
                    fimL = iniL + m - 1;
                    fimC = iniC + m - 1;
                    fimN = iniN+div-1;
                } else if ((x > iniL+m-1) && (y > iniC+m-1)) {
                    iniL = fimL - (m-1);
                    iniC = fimC - (m-1);
                    fimN = iniN+2*div-1;
                    iniN = iniN+div;
                } else if ((x > iniL+m-1) && (y <= iniC+m-1)) {
                    iniL = fimL - (m-1);
                    fimC = iniC + m - 1;
                    
                    fimN = iniN+3*div-1;
                    iniN = iniN+2*div;
                } else {
                    fimL = iniL + m - 1;
                    iniC = fimC - (m-1);
                    
                    fimN = iniN+4*div-1;
                    iniN = iniN+3*div;
                }
            }
            cout << iniN << endl;


            ///


        } else {
            int d; cin >> d;
            int m = 1LL<<n;
            int iniL = 1, fimL = m;
            int iniC = 1, fimC = m;
            int iniN = 1, fimN = 1LL<<(2*n);
            while (iniL != fimL && iniC != fimC) {
                int div = (fimN - iniN + 1)/4;
                m /= 2;
                if (d <= iniN+div-1) {
                    fimL = iniL + m - 1;
                    fimC = iniC + m - 1;
                    fimN = iniN+div-1;
                } else if (d <= iniN+2*div-1) {
                    iniL = fimL - (m-1);
                    iniC = fimC - (m-1);
                    fimN = iniN+2*div-1;
                    iniN = iniN+div;
                } else if (d <= iniN+3*div-1) {
                    iniL = fimL - (m-1);
                    fimC = iniC + m - 1;
                    
                    fimN = iniN+3*div-1;
                    iniN = iniN+2*div;
                } else {
                    fimL = iniL + m - 1;
                    iniC = fimC - (m-1);
                    
                    fimN = iniN+4*div-1;
                    iniN = iniN+3*div;
                }
            }
            cout << iniL << " " << iniC << endl;
        }
    }
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