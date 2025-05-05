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
    int maior = 0, ind;
    string s; cin >> s;
    int cont  = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            cont++;
        } else cont--;
        if (cont > maior) {
            maior = cont;
            ind = i+1;
        }
    }

    cout << ind << endl;

  
    return 0;
}
