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

const int MAX_N = 150;

int n, k;
string s;
int iNext[MAX_N];
int memo[MAX_N][MAX_N];

int dp(int i, int L) {
    if (L == 0) return 1;
    if (i == n) return 0;

    int &ans = memo[i][L];
    if (ans != -1) return ans;

    int d = dp(i+1, L-1) + dp(i+1, L);
    if (iNext[i] != -1) d -= dp(iNext[i]+1, L-1);

    return ans = d;
}

void achaiNext() {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (s[i] == s[j]) {
                iNext[i] = j;
                break;
            }
        }
    }
}

void init() {
    for (int i = 0; i < MAX_N; i++) {
        iNext[i] = -1;
        for (int j = 0; j < MAX_N; j++) {
            memo[i][j] = -1;
        }
    }
}

signed main() {
    fastio();
    init();
    cin >> n >> k;
    cin >> s;

    achaiNext();

    int ans = 0;
    for (int L = n; L >= 0; L--) {
        int d = dp(0, L);
        //cout << L << " " << d << endl;
        if (d < k) {
            ans += d*(n-L);
            k -= d;
        } else {
            ans += k*(n-L);
            k = 0;
            break;
        }
    }

    if (k == 0) cout << ans << endl;
    else cout << -1 << endl;
  
    return 0;
}