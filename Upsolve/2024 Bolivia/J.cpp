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

int solve(int n, int m) {
    if (n == 2 && m == 2) {
        return 2;
    }

    int a = n - 1;
    int b = m - 1;
    int d = __gcd(a, b);

    if (d == 1) {
        if ((n * m) % 2 == 0) {
            return (1LL * n * m) / 2;
        } else {
            return (1LL * n * m - 1) / 2;
        }
    } else {
        int x = a / d;
        int y = b / d;
        int visited = (x + y - 1) * d + 1;
        return 1LL * n * m - visited;
    }

}

signed main() {
    int n, m;
    while (cin >> n >> m) {
        cout << solve(n, m) << endl;
    }
    return 0;
}