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
    int c, g; cin >> c >> g;
    if (c == 1) cout << "vivo e morto\n";
    else if (g == 1) cout << "vivo\n";
    else cout << "morto\n";
  
    return 0;
}