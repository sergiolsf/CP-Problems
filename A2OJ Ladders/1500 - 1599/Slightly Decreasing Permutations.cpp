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
    int n, k;
    cin >> n >> k;

    int p = n;
    for (int i = 1; i <= k; i++) {
        cout << p << " ";
        p--;
    }

    for (int i = 1; i <= n-k; i++) {
        cout << i << " ";
    }
    
    cout << endl;
  
    return 0;
}