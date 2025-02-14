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
    string a, b, c;
    cin >> a >> b >> c;
    vi cont(30, 0);
    for (int i = 0; i < (int)a.size(); i++) {
        int d = (a[i]-'A');
        cont[d]++;
    }
    for (int i = 0; i < (int) b.size(); i++) {
        int d = (b[i]-'A');
        cont[d]++;
    }

    for (int i = 0; i < (int) c.size(); i++) {
        int d = (c[i]-'A');
        cont[d]--;
    }

    for (int i = 0; i <= 27; i++) {
        if (cont[i] != 0) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}