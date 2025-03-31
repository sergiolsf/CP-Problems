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
    vi b(n);
    for (auto &i: b) cin >> i;

    int s = 0, k = 0;
    int ant = 0;
    for (int i = 0; i < n; i++) {
        if ((ant|b[i]) == (ant^b[i])) ant |= b[i];
        else {
            k++;
            s += ant;
            ant = b[i];
        }
    }
    k++;
    s += ant;

    cout << s << " " << k << endl;
  
    return 0;
}