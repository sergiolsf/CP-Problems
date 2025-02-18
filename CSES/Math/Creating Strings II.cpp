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

const int MAXX = 1e6+5;
const int MOD = 1e9+7;

vi fat(MAXX);

int modpow(int b, int p) {
    if (p == 0) return 1;
    int ans = modpow(b, p/2);
    ans = (ans*ans)%MOD;
    if (p&1) ans = (ans*b)%MOD;
    return ans;
}

int inv (int a) {
    return modpow(a, MOD-2);
}

signed main() {
    fastio();
    fat[0] = 1;
    for (int i = 1; i < MAXX; i++) {
        fat[i] = (i*fat[i-1])%MOD;
    }

    string s;
    cin >> s;
    vi alf(30, 0);

    for (int i = 0; i < (int) s.size(); i++) {
        alf[s[i]-'a']++;
    }

    int ans = fat[(int) s.size()];

    for (int i = 0; i < 28; i++) {
        int u = alf[i];
        ans = (ans*inv(fat[u]))%MOD;
    }

    cout << ans << endl;
  
    return 0;
}