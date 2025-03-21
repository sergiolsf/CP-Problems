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

const int MAXD = 1'000'010;

bool solve(int a, int b, int c, int &y, int n) {
    int l = 1;
    int r = sqrt(n)+1;
    while (r-l != 1) {
        int m = (r+l)/2;
        if (a*m*m+b*m+c <= 0) l = m;
        else r = m;
    }

    y = l;
    if (a*y*y + b*y + c == 0) return true;
    return false;
}

signed main() {
    fastio();
    int n; cin >> n;
    
    for (int d = 1; d < MAXD; d++) {
        if (n%d) continue;
        int a = 3, b = 3*d, c = d*d-n/d;
        int y;
        if (!solve(a, b, c, y, n)) continue;
        cout << y+d << " " << y << endl;
        return 0;
    }

    cout << -1 << endl;
  
    return 0;
}