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

int n;
vi h, s;

signed main() {
    fastio();
    int x;
    cin >> n >> x;

    h.resize(n);
    s.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vi pages(x+1, -1);

    pages[0] = 0;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 1; j--) {
            if (j - h[i] >= 0) {
                if (pages[j-h[i]] >= 0) {
                    pages[j] = max(pages[j], pages[j-h[i]] + s[i]);
                    ans = max(ans, pages[j]);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}