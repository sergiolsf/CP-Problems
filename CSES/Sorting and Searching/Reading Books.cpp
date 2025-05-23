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
    vi a(n); 
    for (auto &i: a) cin >> i;

    sort (all(a));

    int l = -1, r = n;
    int suml = 0, sumr = 0;
    while (l < r) {
        if (suml <= sumr) {
            l++;
            if (l != r) suml += a[l];
        } else {
            r--;
            if (l != r) sumr += a[r];
        }
    }

    cout << 2*max(suml, sumr) << endl;
  
    return 0;
}