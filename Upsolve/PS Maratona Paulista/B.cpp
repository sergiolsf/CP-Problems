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

signed main() {
    fastio();
    int n, x; cin >> n >> x;
    vi q(5, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int d = a%3;
        q[d]++;
    }

    bool flag;
    if ((q[1]+q[2])&1) flag = true;
    else if (q[0] > 0 && x > 0) flag = false;
    else if (q[0] == 0 && x > 0) {
        if ((x%2) == (q[1]%2)) flag = false;
        else flag = true;
    } else if (!x) {
        if (q[1]%2 == 0 && q[2]%2 == 0) flag = false;
        else flag = true;
    }

    cout << (flag ? "Julia\n" : "Giovana\n");
  
    return 0;
}