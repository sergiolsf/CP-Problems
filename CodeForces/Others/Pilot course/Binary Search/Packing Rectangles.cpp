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

int w, h, n;

bool f(int x) {
    return (x/h)*(x/w) >= n;
}

signed main() {
    fastio();
    cin >> w >> h >> n;

    int r = 1;
    int l = 0;
    while (!f(r)) {
        r*=2;
    }

    while (r-l != 1) {
        int m = (r+l)/2;
        if (f(m)) {
            r = m;
        } else l = m;
    }

    cout << r << endl;
  
    return 0;
}