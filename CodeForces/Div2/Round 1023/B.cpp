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

void ganhou(int a) {
    if (a%2 == 0) {
        cout << "Tom\n";
    } else cout << "Jerry\n";
}

void solve() {
    int n, k; cin >> n >> k;
    map<int,int> mp;
    int cont = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (mp.count(a)) mp[a]++;
        else mp[a] = 1;
        cont += a;
    }

    int ma = (--mp.end())->first;
    int me = mp.begin()->first;

    int player = 0;
    if ((mp[ma] > 1 && ma-me > k) || (mp[ma] == 1 && ma-me-1 > k)) {
        ganhou(player+1);
        return;
    }

    player = (player+cont)%2;
    ganhou(player+1);
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