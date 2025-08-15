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

const int MAX_N = 1'000'001;

int sum[MAX_N];
int cont[MAX_N];

signed main() {
    fastio();
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        sum[a] += a;
        cont[a]++;
    }

    for (int i = 1; i < MAX_N; i++) {
        sum[i] += sum[i-1];
        cont[i] += cont[i-1];
    }

    while (q--) {
        int b; cin >> b;

        if (cont[MAX_N-1]-cont[b-1] == 0) {
            cout << -1 << endl;
            continue;
        }

        int ans = 0;
        ans += (b-1)*(cont[MAX_N-1]-cont[b-1]);
        ans += sum[b-1];
        cout << ans+1 << endl;
    }
  
    return 0;
}