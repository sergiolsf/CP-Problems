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

void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto &i: a) cin >> i;

    int maior = 0, menor = 0;
    int contMa = 1, contMe = 1;
    for (int i = 0; i < n; i++) {
        map<int,int> mp;
        
        int x1 = maior+a[i];
        mp[x1] = contMa;
        x1 = abs(x1);
        if (mp.count(x1)) mp[x1] = (contMa+mp[x1])%MOD;
        else mp[x1] = contMa%MOD;

        if (maior != menor) {
            int x2 = menor+a[i];
            if (mp.count(x2)) mp[x2] = (contMe+mp[x2])%MOD;
            else mp[x2] = contMe%MOD;

            x2 = abs(x2);
            if (mp.count(x2)) mp[x2] = (contMe+mp[x2])%MOD;
            else mp[x2] = contMe%MOD;
        }    

        maior = (--mp.end())->first;
        menor = (mp.begin())->first;
        contMa = mp[maior];
        contMe = mp[menor];
    }

    cout << contMa << endl;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}