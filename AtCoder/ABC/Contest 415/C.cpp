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

const int MAX_N = 500'005;

int n;
string s; 
bool pode[MAX_N];
int memo[MAX_N];

bool dp(int pos) {
    //cout << pos << endl;
    if (pos == ((1<<n) - 1)) return true;

    int &ans = memo[pos];
    if (ans != -1) return ans;
    ans = 0;
    for (int i = 0; i < n; i++) {
        if (pos&(1<<i) || !pode[pos|(1<<i)]) continue;
        ans |= dp(pos|(1<<i));
    }

    return ans;
}

void init() {
    memo[0] = -1;
    for (int i = 0; i < (1<<n)-1; i++) {
        if (s[i] == '1') pode[i+1] = false;
        else pode[i+1] = true;
        memo[i+1] = -1;
    }
}

void solve() {
    cin >> n >> s;
    init();
    if (dp(0)) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    fastio();
    int t; cin >> t;
    while (t--) {
        solve();
    }
  
    return 0;
}