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

int gcd (int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    int c = n;
    while (c > 0) {
        sum += c%10;
        c/=10;
    }
    while (gcd(n, sum) == 1) {
        n++;
        c = n;
        sum = 0;
        while (c > 0) {
            sum += c%10;
            c/=10;
        }
    }
    
    cout << n << endl;
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