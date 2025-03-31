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

const int MAXN = 300'000;
int N, k, X; 

int s[MAXN], e[MAXN];
vi memo(MAXN);
vector<bool> marc(MAXN, false);

int dp(int pos) {
    if (pos > N) {
        return 0;
    }

    int &ans = memo[pos];
    if (marc[pos]) return ans;

    marc[pos] = true;

    int d1 = dp(pos+k)-X;
    int d2 = dp(pos+1)+e[pos]-s[pos];
    return ans = max(d1, d2);
}

signed main() {
    fastio();
    cin >> N >> k >> X;
    for (int i = 1; i <= N; i++) {
        cin >> s[i] >> e[i];
    }

    cout << max(0LL, dp(1)) << endl;
  
    return 0;
}