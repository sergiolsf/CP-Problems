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
    string a, b;
    cin >> a >> b;

    transform(all(a), a.begin(), ::toupper);
    transform(all(b), b.begin(), ::toupper);

    if (a == b) cout << 0 << endl;
    else if (a < b) cout << -1 << endl;
    else cout << 1 << endl;
  
    return 0;
}