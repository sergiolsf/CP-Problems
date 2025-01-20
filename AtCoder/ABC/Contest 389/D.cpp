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

bool ok(int x, int L, int n, int cst) {
    if (((L+2+2*x)*(L+2+2*x) + (1+2*n)*(1+2*n)) <= cst) {
        return true;
    }
    return false;
}

int binary_search (int L, int n, int cst) {
    int x = -1;
    for (int b = L; b >= 1; b /= 2) {
        while (ok(x+b, L, n, cst)) x += b;
    }
    int k = x;
    return k;
}

signed main() {
    fastio();
    int R;
    cin >> R;

    int L;

    for (L = R; L*L <= 2*R*R; L++);
    L--;
    if (L%2 == 0) L--;

    int ans = L*L;

    /// Soma todos que ainda cabem
    int quad = (L+2)*(L+2);
    int cst = 4*R*R;
    int n = 0;
    while (true) {
        if ((quad + (1+2*n)*(1+2*n)) <= cst) { 
            if (n == 0) ans += 4;
            else ans += 8;

           int p = binary_search(L, n, cst);
           if (p > 0) {
            if (n == 0) ans += 4*p;
            else ans += 8*p;
           }

        }
        else break;
        n++;
    }

    cout << ans << endl;    
    return 0;
}