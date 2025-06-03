#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX_N = 1'000'000;
const int MOD = 1e9+7; //998'244'353
const int INF = 0x3f3f3f3f3f3f3f3fll; //int: 0x3f3f3f3f
const double PI = acos(-1);

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    int n; cin >> n;  
    string S; cin >> S;
    string T; cin >> T;
    int A = 0, B = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] == '*') {
            A++;
            if (T[i] != '*') B++;
        }
    } 

    double ans = (double) B / (double) A;
    cout << fixed << setprecision(2) << ans << endl;
}

signed main() {
    fastio();
    int t = 1;
    //cin >> t;
    while (t--) solve();  
    return 0;
}