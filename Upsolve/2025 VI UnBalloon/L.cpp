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

int A, B, C; 
vi f(205);

int func(int x) {
    int val = (A+C)*x*x*x;
    val += (1-B)*x*x;
    val += (B*C - A + C)*x;
    val -= A*C;
    return abs(val);
}

signed main() {
    fastio();
    cin >> A >> B >> C;
    for (int i = 0; i <= 200; i++) {
        f[i] = func(i-100);
    }

    int ans = 0;

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        ans ^= f[x+100];
    }

    cout << ans << endl;
  
    return 0;
}