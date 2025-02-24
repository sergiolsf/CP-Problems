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

pii func(int m, bool centro) {
    int qA = 0, qB = 0;
    if (centro) m--;
    qA = (m/4)*2 + min(m%4, 2LL);
    qB = (m/4)*2 + max(m%4 - 2, 0LL);
    if (centro) {
        swap(qA, qB);
        qA++;
    }

    return {qA, qB};
}

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    int quant0 = 0;
    for (int i = 0; i < n; i++) if (s[i] == '0') quant0++;
    int l = 0, r = n-1, x = 0;
    while (l < r) {
        if (s[l] != s[r]) x++;
        l++; r--;
    }
    int A = 0, B = x;
    pii p = func(quant0-x, (n%2) && (s[n/2] == '0'));
    A += p.first;
    B += p.second;

    if (x == 1 && quant0 > 1 && !((n%2) && (s[n/2] == '0'))) {

    }
    

    cout << A << " " << B << endl;
    if (A < B) cout << "ALICE\n";
    else if (A > B) cout << "BOB\n";
    else cout << "DRAW\n";
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