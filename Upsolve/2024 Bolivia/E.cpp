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
    vi primes;
    for (int i = 2; i <= n; i++) {
        while (n%i == 0) {
            primes.push_back(i);
            n /= i;
        }
    }

    for (int i = 0; i < primes.size(); i++) {
        if (i != 0) cout << "x";
        cout << primes[i];
    }
    cout << endl;
  
    return 0;
}