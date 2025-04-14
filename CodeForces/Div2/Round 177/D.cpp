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

const int MOD = 998'244'353;
const int MAX_N = 500'010;

vi c(30);
vi fat(MAX_N);
vi inv(MAX_N);
int tot, val;
vi pd(MAX_N);

int mod(int a) {
    return (a%MOD);
}

void dp() {
    for(int i = 1; i <= tot; i++) pd[i] = 0;
    pd[0] = 1;

    for (int i = 0; i < 26; i++) {
        if (c[i] == 0) continue;
        for (int j = tot; j >= 0; j--) {
            if (j + c[i] > tot) continue;
            if (pd[j]) pd[j+c[i]] = mod(pd[j+c[i]]+pd[j]);
        }
    }
}

void findVal() {
    int sum = 0;
    for (int i = 0; i < 26; i++) {
        sum += c[i];
    }

    tot = (sum/2) + (sum%2);
    val = mod(fat[tot]*fat[sum-tot]);

    for (int i = 0; i < 26; i++) {
        if (c[i] != 0) val = mod(val*inv[c[i]]);
    }
}

void solve() {
    for (int i = 0; i < 26; i++) cin >> c[i];
    findVal();
    dp();
    cout << mod(pd[tot]*val) << endl;
}

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = mod(ans*ans);
    if (p&1) ans = mod(ans*b);
    return ans;
}

int INV(int a) {
    return modpow(a, MOD-2);
}

signed main() {
    fastio();
    
    fat[0] = 1;
    for (int i = 1; i < MAX_N; i++) fat[i] = mod(fat[i-1]*i);
    for (int i = 1; i < MAX_N; i++) inv[i] = INV(fat[i]);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}
