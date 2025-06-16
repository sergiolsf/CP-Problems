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

int jos(int k, int n) {
    //cout << k << " " << n << endl;
    if (n == 1) return 1;
    if (k <= ((n+1)/2)) {
        if (2*k>n) return (2*k)%n;
        return 2*k;
    }
    int prox = jos(k-((n+1)/2), (n)/2);
    if (n%2) return 2*prox+1;
    return 2*prox-1;
}

signed main() {
    fastio();
    int q; cin >> q;
    while (q--) {
        int k, n; cin >> n >> k;
        cout << jos(k, n) << endl;
    }
  
    return 0;
}