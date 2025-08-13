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

char inv (char c) {
    if (c == 'A') return 'B';
    return 'A';
}

signed main() {
    fastio();
    int n; cin >> n;
    string s; cin >> s;

    int cont = 0;

    char ant = s[0];
    bool troca = false;
    for (int i = 1; i < n; i++) {
        if (s[i] == ant) {
            if (!troca) continue;
            ant = inv(ant);
            cont++;
        } else {
            troca = true;
            cont++;
        }
    }

    ant = s[n-1];
    troca = false;
    for (int i = n-2; i >= 0; i--) {
        if (s[i] == ant) {
            if (!troca) continue;
            ant = inv(ant);
            cont++;
        } else {
            troca = true;
            cont++;
        }
    }

    for (int i = 0; i < n-1; i++) {
        if (s[i] != s[i+1]) cont--;
    }

    //cout << cont << endl;

    int ans = n*(n+1)/2 - n - cont;

    cout << ans << endl;
  
    return 0;
}