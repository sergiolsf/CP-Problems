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

const int MAX_N = 200'005;
bool fora[MAX_N];
bool dentro[MAX_N];

struct intervalo {
    int i, st, en;
    bool entrada;

    bool operator < (intervalo other) const {
        if (entrada && other.entrada) return st < other.st;
        if (entrada) return true;
        if (other.entrada) return false;
        if (en != other.en) return en < other.en;
        return st > other.st;
    }
};

signed main() {
    fastio();
    int n; cin >> n;
    vector<intervalo> vp;
    for (int i = 1; i <= n; i++) {
        int st, en; cin >> st >> en;
        intervalo v1, v2;
        v1.en = en; v1.entrada = true; v1.i = i; v1.st = st;
        vp.push_back(v1);
        v2.en = en; v2.entrada = false; v2.i = i; v2.st = st;
        vp.push_back(v2);
    }

    sort(all(vp));

    int maiorSt = 0;
    multiset<int> inicios;
    for (int i = 0; i < (int) vp.size(); i++) {
        int st = vp[i].st;

        if (!vp[i].entrada) {

            // 1a parte
            auto it = inicios.find(st);
            inicios.erase(it);
            if (!inicios.empty() && (*inicios.begin() <= st)) fora[vp[i].i] = true;

            // 2a parte
            if (st <= maiorSt) dentro[vp[i].i] = true;
            maiorSt = max(maiorSt, st);

        } else {
            inicios.insert(st);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dentro[i]) cout << 1 << " ";
        else cout << 0 << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        if (fora[i]) cout << 1 << " ";
        else cout << 0 << " ";
    }
    cout << endl;
  
    return 0;
}