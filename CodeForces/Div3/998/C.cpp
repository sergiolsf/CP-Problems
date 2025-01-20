#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    int n, k;
    cin >> n >> k;

    vi numb;
    map<int,int> mp;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numb.push_back(x);
        if (mp.count(k-x)) {
            mp[k-x]++;
        } else {
            mp[k-x] = 1;
        }
    }

    int sp = 0;
    int p = 0;

    /// casp de k-x = x

    for (int i = 0; i < n; i++) {
        if(!mp.count(numb[i]) || mp[numb[i]] == 0) {
            sp++;
        } else {
            //cout << numb[i] << " " << k-numb[i] << endl;
            mp[numb[i]]--;
            p++;
        }
    }

    cout << p/2 << endl;

    
    
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