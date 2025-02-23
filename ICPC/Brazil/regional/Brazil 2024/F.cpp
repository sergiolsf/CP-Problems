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

bool solve (int k, int n) {
    for (int m = n-2; m <= n; m++) {
        int n1 = 3*k-m-2;
        int n2 = m-2*k+1;
        if (n1 >= 0 && n2 >= 0) {
            if (m != n) cout << "-";
            cout << "X";
            for (int i = 1; i <= n1; i++) cout << "-X";
            for (int i = 1; i <= n2; i++) cout << "--X";
            if (m == n-2) cout << "-";
            cout << endl;
            return true;
        }
    }
    return false;
}

signed main() {
    fastio();
    int k, n;
    cin >> k >> n;

    
    if (!solve(k, n)) {
        cout << "*\n";
    }
  
    return 0;
}