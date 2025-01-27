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

signed main() {
    fastio();
    int n;
    cin >> n;

    vi a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 2; i < n; i++) {
        if (a[i]*a[i] != a[i-1]*a[i+1]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    
    return 0;
}