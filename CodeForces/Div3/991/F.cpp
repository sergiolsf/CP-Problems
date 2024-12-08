#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int maxN = 1000000;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int sqrt_n;

int A[maxN], B[maxN];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

void update_internal(int X) {
    int idx = (X/sqrt_n) * sqrt_n;
    B[idx] = A[idx];
    for (int i = idx; i < idx+sqrt_n; i++)
        B[idx] = gcd(B[idx], A[i]);
}

void update_value(int X, int K) {
    A[X] = K;
    update_internal(X);
}

int gcd_range(int L, int R) {
    int ans = 0;
    for (int i = L; i <= R; ) {
        if ((i%sqrt_n == 0) && (i+sqrt_n-1 <= R))
            ans = gcd(ans, B[i]), i += sqrt_n;
        else
            ans = gcd(ans, A[i]), ++i;
    }
    return ans;
}

void solve() {
    int n, q;
    cin >> n >> q;
    sqrt_n = sqrt(n)+1;

    //for (int i = 0; i <= n; i++) {
      //  A[i] = B[i] = 0;
    //}

    int ult = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (ult != 0) {
            update_value(i-1, llabs(x-ult));
        }
        ult = x;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << 0 << " ";
        } else {
            cout << gcd_range(l-1, r-2) << " ";
        }
    }

    cout << endl;
    
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