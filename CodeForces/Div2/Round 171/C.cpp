#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    int ans = 0;
    int menor = 1;

    int i = n-1;
    while (i >= 0) {
        if (i > 0 && s[i-1] == '0') {

            if (i < menor) {
                ans += i+1;
                break;
            }

            i--;
            while (i >= 0 && s[i] == '0') {
                if (i+1 >= menor) ans += i+1;
                i--;
            }

        } else {
            if (menor <= i) {
                ans += menor;
                menor++;
            }
            i--;
        }
    }

    cout << ans << endl;
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