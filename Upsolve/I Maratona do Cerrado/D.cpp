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

signed main() {
    fastio();
    vi r = {-1, 1, 2, 4, 7, 8, 11, 13};
    int p; cin >> p;
    int d = (p/8)*15 + r[p%8];
    cout << d << endl;

    return 0;
}