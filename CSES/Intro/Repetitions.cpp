#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
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
    char ant = 'Z';
    int cont = 0, maxi = 0;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ant) {
            cont++;
        } else {
            ant = s[i];
            cont = 1;
        }
        maxi = max(maxi, cont);
    }

    cout << maxi << endl;
    
    return 0;
}