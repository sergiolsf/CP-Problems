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

const int MAX = 200'005;
const int MOD = 1'000'000'007;

void solve() {
    int n, m, r, c;
	cin >> n >> m >> r >> c;
	r--; c--;
	char a[n + 7][m + 7];
	bool hasB = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			hasB |= (a[i][j] == 'B');
		}
	}
	if (!hasB) {cout << -1 << '\n'; return;}
	if (a[r][c] == 'B') {cout << 0 << '\n'; return;}
	bool oneMove = false;
	for (int i = 0; i < n; i++) {
		oneMove |= (a[i][c] == 'B');
	}
	for (int j = 0; j < m; j++) {
		oneMove |= (a[r][j] == 'B');
	}
	if (oneMove) {cout << 1 << '\n';}
	else {cout << 2 << '\n';}
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