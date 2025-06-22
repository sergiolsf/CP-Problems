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
    int w, h, a, b; cin >> w >> h >> a >> b;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int linBaixo1 = y1, linAlto1 = y1+b, colEsq1 = x1, colDir1 = x1+a;
    int linBaixo2 = y2, linAlto2 = y2+b, colEsq2 = x2, colDir2 = x2+a;

    //cout << linBaixo1 << " " << linAlto1 << " " << colDir1 << " " << colEsq1 << endl;
    //cout << linBaixo2 << " " << linAlto2 << " " << colDir2 << " " << colEsq2 << endl;

    if ((linAlto1 <= linBaixo2 || linAlto2 <= linBaixo1) && (colDir1 <= colEsq2 || colDir2 <= colEsq1)) {
        int AA = min(abs(colEsq1 - colDir2), abs(colEsq2 - colDir1));
        int BB = min(abs(linAlto1 - linBaixo2), abs(linAlto2 - linBaixo1));
        if (AA%a && BB%b) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        return;
    }
    if (colDir1 <= colEsq2 || colDir2 <= colEsq1) {
        int AA = min(abs(colEsq1 - colDir2), abs(colEsq2 - colDir1));
        if (AA%a) {
            cout << "NO\n";
            return;
        }
    }
    else {
        int AA = min(abs(linAlto1 - linBaixo2), abs(linAlto2 - linBaixo1));
        if (AA%b) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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