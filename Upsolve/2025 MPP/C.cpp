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
    int n; cin >> n;
    while (n--) {
        int x, y; cin >> x >> y;
        
        if (-200 <= x && x <= -100 && y >= 0 && y <= x+200) cout << "S\n";
        else if (-100 <= x && x <= 0 && y >= 0 && y <= 100) cout << "S\n";
        else if (0 <= x && x <= 100 && y <= 0 && y >= -100) cout << "S\n";
        else if (100 <= x && x <= 200 && y <= 0 && y >= x-200) cout << "S\n";
        else if (-100 <= x && x <= 0 && y <= 0 && y >= -x-100) cout << "S\n";
        else if (0 <= x && x <= 100 && y >= 0 && y <= -x+100) cout << "S\n";
        else cout << "N\n";
    }
  
    return 0;
}