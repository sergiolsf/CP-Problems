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
    string s; cin >> s;
    int impar = 0, par = 1, sum = 0;
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            sum++;
            //cont++;
        }

        if (sum&1) {
            cont += par;
            impar++;
        } else {
            cont += impar;
            par++;
        }
    }

    cout << n*(n+1)/2 - cont << endl;
  
    return 0;
}