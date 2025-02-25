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
    int n;
    string s;
    cin >> n >> s;
    int contA = 0, contB = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') contA++;
        else contB++;
    }
    int c = contA/2;
    int d = c + (contA%2 == 1 ? 1 : 0);
    cout << c*d*contB << endl;
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