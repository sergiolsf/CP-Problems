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

void solve() {
    string a, b; cin >> a >> b;
    vector<int> a1;
    char ant = a[0];
    int sum = 0;
    if (ant == 'R') sum = -1;
    else sum = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == 'R') {
            if (ant == a[i]) {
                sum--;
            } else {
                a1.push_back(sum);
                sum = -1;
            }
        } else {
            if (ant == a[i]) {
                sum++;
            } else {
                a1.push_back(sum);
                sum = 1;
            }
        }
        ant = a[i];
    }
    a1.push_back(sum);

    vector<int> b1;
    ant = b[0];
    if (ant == 'R') sum = -1;
    else sum = 1;
    for (int i = 1; i < b.size(); i++) {
        if (b[i] == 'R') {
            if (ant == b[i]) {
                sum--;
            } else {
                b1.push_back(sum);
                sum = -1;
            }
        } else {
            if (ant == b[i]) {
                sum++;
            } else {
                b1.push_back(sum);
                sum = 1;
            }
        }
        ant = b[i];
    }
    b1.push_back(sum);

    if (a1.size() != b1.size()) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < a1.size(); i++) {
        if (a1[i]*b1[i] < 0) {
            cout << "NO\n";
            return;
        }
        if (!(abs(b1[i]) >= abs(a1[i]) && abs(b1[i]) <= 2*abs(a1[i]))) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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