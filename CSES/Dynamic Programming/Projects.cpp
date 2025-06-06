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
const int MAX_N = 200'005;
vector<tuple<int, int, int>> v;
int n;

int memo[MAX_N];

int dp(int i) {
    if (i == n) return 0;

    int &ans = memo[i];
    if (ans != -1) return ans;

    auto [a, b, p] = v[i];
    int d1 = dp(i+1);

    auto it = upper_bound(all(v), b, [](auto val, const auto& t) {
                return val < get<0>(t);
            });

    int k = it - v.begin();
    int d2 = dp(k)+p;
    return ans = max(d1, d2);
}

signed main() {
    fastio();

    for (int i = 0; i < MAX_N; i++) memo[i] = -1;

    cin >> n;
    v.resize(n+1);
    
    for (int i = 0; i < n; i++) {
        auto &[a, b, p] = v[i];
        cin >> a >> b >> p;
    } 

    v[n] = {INF, 0, 0};

    sort(all(v));

    cout << dp(0) << endl;

  
    return 0;
}