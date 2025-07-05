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

int n;

bool pred(string a) {
    int zero = 0;
    for (int i = 0; i < 2*n; i++) if (a[i] == '0') zero++;
    return (zero >= n ? false : true);
}

void sol(string a, string b, bool caracter) {
    int i = 0, j = 0;
    char c;

    if (caracter) c = '1';
    else c = '0';

    while (i < 2*n && j < 2*n) {
        if (a[i] == b[j]) {
            if (a[i] == c) {
                cout << a[i];
                i++; j++;
            } else {
                cout << a[i];
                i++; j++;
            }
        } else {
            if (a[i] == c) {
                cout << b[j];
                j++;
            } else {
                cout << a[i];
                i++;
            }
        }
    }

    while (i < 2*n) {
        cout << a[i];
        i++;
    }

    while (j < 2*n) {
        cout << b[j];
        j++;
    }

    cout << endl;
}

void solve() {
    cin >> n;
    string a, b, c; cin >> a >> b >> c;
    bool predA = pred(a);
    bool predB = pred(b);
    bool predC = pred(c);

    if (predA == predB) sol(a, b, predA);
    else if (predA == predC) sol(a, c, predA);
    else if (predB == predC) sol(b, c, predB);
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