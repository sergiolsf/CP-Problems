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
const int MAXA = 505;
const int INF = 1e18;

vvi memo(MAXA, vi (MAXA, -1));

int dp (int a, int b) {
    int &ans = memo[a][b];
    if (ans != -1) return ans;
    if (a == b) return ans = 0;
    int minA = INF, minB = INF;
    for (int i = 1; i < a; i++) {
        minA = min(minA, dp(i,b) + dp(a-i,b) + 1);
    }
    for (int i = 1; i < b; i++) {
        minB = min(minB, dp(a,i) + dp(a,b-i) + 1);
    }
    return ans = min(minA, minB);
}

signed main() {
    fastio();
    int a, b;
    cin >> a >> b;
    cout << dp(a, b) << endl;  
    return 0;
}