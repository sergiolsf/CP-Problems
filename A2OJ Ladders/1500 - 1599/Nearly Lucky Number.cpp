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

bool good (int x) {
    int p;
    do {
        p = x%10;
        if (p != 4 && p != 7) return false;
        x /= 10;    
    } while (x);
    return true;
}

signed main() {
    fastio();
    string n;
    cin >> n;
    int cont = 0;
    for (int i = 0; i < (int) n.size(); i++) {
        if (n[i] == '4' || n[i] == '7') cont++;
    }
    if (good(cont)) cout << "YES\n";
    else cout << "NO\n";
  
    return 0;
}