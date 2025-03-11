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

const int INF = 1e18;
const int MAXN = 100'010;

int n;
vector<int> c;
vector<string> vs;
vvi memo(MAXN, vi (2, -1));

string palavra(int i, int inv) {
    string s;
    if (inv) {
        for (int j = vs[i].size()-1; j >= 0; j--) {
            s.push_back(vs[i][j]);
        }
    } else {
        for (int j = 0; j < vs[i].size(); j++) {
            s.push_back(vs[i][j]);
        }
    }
    return s;
}

int dp(int i, int inv) {

    if (i == n+1) return 0;

    string sAnt = palavra(i-1, inv);
    string sAtual = palavra(i, false);
    string sInv = palavra(i, true);

    int &ans = memo[i][inv];
    if (ans != -1) return ans;

    int res = INF;
    if (sAnt <= sAtual) res = min(res, dp(i+1, false));
    if (sAnt <= sInv) res = min(res, dp(i+1, true) + c[i]);
    return ans = res;
}

signed main() {
    fastio();
    cin >> n;
    c.resize(n+1);
    vs.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> vs[i];
    
    int d = min(dp(2, true)+c[1], dp(2, false));
    if (d > INF-100) d = -1;
    cout << d << endl;
    return 0;
}