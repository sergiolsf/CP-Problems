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

const int MAX_N = 1'000'005;
int v[MAX_N];
int n, d; 
int memo[MAX_N][2];

int dp(int ind, int ultimo) {
    if (ind >= MAX_N) return 0;

    int &ans = memo[ind][ultimo];
    if (ans != -1) return ans;

    int f = dp(ind+d, 0) + v[ind];
    if (ultimo == 1) {
        return ans = f;
    }
    
    return ans = min(f, dp(ind+d, 1));
}

void init() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < 2; j++) {
            memo[i][j] = -1;
        }
    }
}

signed main() {
    fastio();
    init();
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v[a]++;
    }

    int ans = 0;

    if (d == 0) {
        for (int i = 0; i < MAX_N; i++) {
            if (v[i]) ans += v[i]-1;
        }
        cout << ans << endl;
        return 0;
    }

    
    for (int i = 0; i < d; i++) {
        ans += dp(i, 0);
    }

    cout << ans << endl;
  
    return 0;
}