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
    int s = 0, maior = 0;
    while (n--) {
        int t; cin >> t;
        s += t;
        maior = max(maior, t);
    }

    s = max(2*maior, s);
    cout << s << endl;
  
    return 0;
}