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
    string s;
    cin >> s;
    int cont = 1;
    char ant = s[0];

    for (int i = 1; i < (int) s.size(); i++) {
        if (s[i] == ant) {
            cont++;
            if (cont >= 7) {
                cout << "YES\n";
                return 0;
            }
        } else cont = 1;
        ant = s[i];
    }

    cout << "NO\n";  
    return 0;
}