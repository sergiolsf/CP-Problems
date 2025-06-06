#include <bits/stdc++.h>
using namespace std;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    int n; cin >> n;
    vi basis;
    while (n--) {
        int x; cin >> x;
        for (auto e: basis) x = min(x, x^e);
        if (x) basis.push_back(x);
    }

    int ans = 1LL << (basis.size());
    cout << ans << endl;
  
    return 0;
}