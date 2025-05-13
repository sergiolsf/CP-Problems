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
    vi v(5);
    for (int i = 1; i <= 4; i++) cin >> v[i];
    for (int i = 1; i <= 4; i++) {
        int cont = 0;
        for (int j = 1; j <= 4; j++) {
            if (v[j] != abs(i-j) && i!=j) cont++;
        }
        if (cont == 0) {
            cout << i << endl;
            return 0;
        }
    }
}