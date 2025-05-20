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

signed main() {
    fastio();
    int n; cin >> n;
    vi A(n);
    for (auto &i: A) cin >> i;
    
    int k = 0;
    vi L(n, 0);
    
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
        L[pos] = A[i];
        if (pos == k) {
            k = pos+1;
        }
    }

    cout << k << endl;
  
    return 0;
}