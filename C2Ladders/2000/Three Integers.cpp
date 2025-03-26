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

const int INF = 1e18;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int AA, BB, CC;
    int ans = INF;
    for (int A = 1; A <= 2*a; A++) {
        for (int B = A; B <= 2*b; B += A) {
            int C;
            if (B >= c) C = B;
            else {
                int C1 = (c/B)*B;
                int C2 = C1 + B;
                if (abs(C1-c) < abs(C2-c)) C = C1;
                else C = C2;
            }
            /// ve se é o melhor até agora
            int delta = abs(A-a)+abs(B-b)+abs(C-c);
            if (delta < ans) {
                ans = delta;
                AA = A;
                BB = B;
                CC = C;
            }
        }
    }

    cout << ans << endl;
    cout << AA << " " << BB << " " << CC << endl;
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