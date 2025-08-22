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

const int MAX_S = 1LL<<21;
const int MAX_N = 20;

pii memo[MAX_S];
int n, x;
int w[MAX_N];

pii dp(int S) {
    if (S == 0) return {1, 0};

    pii &ans = memo[S];
    if (ans.first != -1) return ans;

    int viagens = 21, peso = 0;
    for (int i = 0; i < n; i++) {
        if ((1<<i) & S) {
            auto [v, p] = dp(S^(1<<i));
            if (p+w[i] <= x) {
                p += w[i];
            } else {
                v++;
                p = w[i];
            }

            if (viagens > v) {
                viagens = v;
                peso = p;
            } else if(viagens == v) {
                peso = min(peso, p);
            }
        }
    }

    return ans = {viagens, peso};
}

void init() {
    for (int i = 0; i < MAX_S; i++) memo[i] = {-1, -1};
}

signed main() {
    fastio();
    init();

    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> w[i];

    cout << dp((1<<n) - 1).first << endl;
  
    return 0;
}