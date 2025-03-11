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

void solve() {
    int n; cin >> n;
    vi b(2*n); 
    for (auto &i: b) cin >> i;

    sort(all(b));
    int sumPar = 0, sumImpar = 0;
    for (int i = 0; i < 2*n; i+=2) sumPar += b[i];
    for (int i = 1; i < 2*n-1; i+=2) sumImpar += b[i];
    sumPar += b[2*n-1];

    for (int i = 0; i < 2*n-1; i++) cout << b[i] << " ";
    cout << sumPar-sumImpar << " " << b[2*n-1] << endl;
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