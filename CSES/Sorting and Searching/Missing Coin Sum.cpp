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
    vi a(n);
    for (auto &i: a) cin >> i;

    sort(all(a));
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] - sum > 1) {
            cout << sum+1 << endl;
            return 0;
        }
        sum += a[i];
    }
    cout << sum+1 << endl;  
    return 0;
}