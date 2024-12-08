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
    string s;
    cin >> s;
    int S = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < s.size(); i++) {
        int num = s[i]-'0';
        S += num;
        if (num == 2) cnt2++;
        else if (num == 3) cnt3++;
    }

    if (S%9 == 0) {
        cout << "YES" << endl;
        return;
    }

    int cont;
    for (int i = 0; i <= 3 && i <= cnt3; i++) {
        for (int j = 0; j <= 9 && j <= cnt2; j++) {
            cont = i*6 + j*2;
            if ((cont+S)%9 == 0) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
    return;
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