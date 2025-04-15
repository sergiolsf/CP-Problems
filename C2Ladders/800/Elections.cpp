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
    int a[3]; cin >> a[0] >> a[1] >> a[2];
    for (int i = 0; i < 3; i++) {
        int b = a[i];
        int d = 0;
        for (int j = 0; j < 3; j++) {
            if (j == i) continue;
            if (b <= a[j]) {
                d += a[j]-b+1;
                b = a[j]+1;
            }
        }
        cout << d << (i == 2 ? "\n" : " ");
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