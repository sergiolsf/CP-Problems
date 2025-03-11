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

const int MAXN = 110;

int n; 
vi a;
vector<vvi> memo (MAXN, vvi (2, vi (2, -1)));

int dp(int dia, int cont, int gym) {
    if (dia == n+1) return 0;

    int &ans = memo[dia][cont][gym];
    if (ans != -1) return ans;

    int d = dp(dia+1, 0, 0)+1;
    if (a[dia] == 0) return ans = d;
    if (a[dia] == 1 || a[dia] == 3) d = min(d, dp(dia+1, !cont, false) + (cont ? 1 : 0));
    if (a[dia] == 2 || a[dia] == 3) d = min(d, dp(dia+1, false, !gym) + (gym ? 1 : 0));
    if (a[dia] == 3) d = min(d, dp(dia+1, !cont, !gym) + (cont&&gym ? 1 : 0));
    return ans = d;
}

signed main() {
    fastio();
    cin >> n;
    a.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    cout << dp(1, false, false) << endl;

  
    return 0;
}