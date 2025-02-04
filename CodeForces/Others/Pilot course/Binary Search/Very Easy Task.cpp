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

int n, x, y;

bool good  (int t) {
    return 1 + (t-min(x,y))/x + (t-min(x,y))/y >= n; 
}

signed main() {
    fastio();
    
    cin >> n >> x >> y;

    if (n == 1) {
        cout << min(x,y) << endl;
        return 0;
    }

    int l = 0; // l é ruim
    int r = 1; // r é bom

    while (!good(r)) r*=2;

    while (r-l != 1) {
        int m = (r+l)/2;
        if (good(m)) r = m;
        else l = m;
    }

    cout << r << endl;
  
    return 0;
}