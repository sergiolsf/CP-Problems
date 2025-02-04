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
    int N, Q;
    cin >> N >> Q;

    vi nests(N+1, 1);
    vi pigeons(N+1);
    for (int i = 1; i <= N; i++) {
        pigeons[i] = i;
    }

    int ans = 0;

    for (int i = 1; i <= Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int P, H;
            cin >> P >> H;
            int u = pigeons[P];
            nests[u]--;
            if (nests[u] == 1) {
                ans--;
            }
            nests[H]++;
            if (nests[H] == 2) {
                ans++;
            }
            pigeons[P] = H;
        } else {
            cout << ans << endl;
        }
    }
  
    return 0;
}