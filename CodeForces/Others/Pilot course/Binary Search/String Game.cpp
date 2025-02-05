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

string t, p;
int st, sp;
vi v;

// verifica se após x deletações há a string p dentro de t
bool good (int x) {
    int i = 0; // ponteiro na string t
    int j = 0; // ponteiro na string p
    while (i < st && j < sp) {
        if (v[i+1] > x && t[i] == p[j]) {
            j++;
        }
        i++;
    }
    if (j == sp) return true;
    return false;
}

signed main() {
    fastio();
    
    cin >> t >> p;
    st = t.size();
    sp = p.size();
    v.resize(st+1);

    for (int i = 1; i <= st; i++) {
        int x;
        cin >> x;
        v[x] = i;
    }

    int l = 0; // l tem a string p embutida
    int r = st; // r não tem a string p embutida

    while (r-l != 1) {
        int m = (r+l)/2;
        if (good(m)) l = m;
        else r = m;
    }

    cout << l << endl;
  
    return 0;
}