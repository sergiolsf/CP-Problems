#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    int n = a.size();
    int m = b.size();
    int p = c.size();

    int min_changes = INT_MAX;

    // Simular começando com 'a'
    {
        int changes = 0, i = 0, j = 0;
        for (int k = 0; k < p; k++) {
            if (i < n && (j >= m || k % 2 == 0)) {
                if (c[k] != a[i]) changes++;
                i++;
            } else if (j < m) {
                if (c[k] != b[j]) changes++;
                j++;
            }
        }
        min_changes = min(min_changes, changes);
    }

    // Simular começando com 'b'
    {
        int changes = 0, i = 0, j = 0;
        for (int k = 0; k < p; k++) {
            if (j < m && (i >= n || k % 2 == 0)) {
                if (c[k] != b[j]) changes++;
                j++;
            } else if (i < n) {
                if (c[k] != a[i]) changes++;
                i++;
            }
        }
        min_changes = min(min_changes, changes);
    }

    cout << min_changes << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
