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
    vi sum(n);
    for (int i = 0; i < n-1; i++) {
        cin >> sum[i];
    }
    for (int i = 1; i < n; i++) {
        sum[i] += sum[i-1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j+i < n; j++) {
            if (i > 0) cout << sum[i+j-1]-sum[i-1];
            else cout << sum[i+j-1];
            cout << (j+i == n-1 ? "\n" : " ");
        }
    }
  
    return 0;
}