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

struct seg {
    bool existe;
    bool perpendicular;
    int k, sinalX, sinalY, ini, fim;
    set<pii> pontos;
};

vector<pair<pii, int>> tower;
vector<seg> ans;

vector<seg> formaSegmentos (int i) {
    vector<seg> res(5);
    int xu = tower[i].first.first, yu = tower[i].first.second;
    int d = tower[i].second;

    res[1].perpendicular = false;
    res[2].perpendicular = false;
    res[3].perpendicular = false;
    res[4].perpendicular = false;

    res[1].existe = true; res[1].sinalX = 1; res[1].sinalY = -1; res[1].k = d+xu-yu;
    res[1].ini = xu; res[1].fim = xu+d;
    
    res[3].existe = true; res[3].sinalX = 1; res[3].sinalY = 1; res[3].k = d+xu+yu;
    res[3].ini = xu; res[3].fim = xu+d;

    res[2].existe = true; res[2].sinalX = -1; res[2].sinalY = 1; res[2].k = d-xu+yu;
    res[2].ini = xu-d; res[2].fim = xu;

    res[4].existe = true; res[4].sinalX = -1; res[4].sinalY = -1; res[4].k = d-xu-yu;
    res[4].ini = xu-d; res[4].fim = xu;

    return res;
}

bool paralelo(int i, seg s) {
    int k1 = ans[i].k, xini = ans[i].ini, xfim = ans[i].fim;
    int k2 = s.k, uini = s.ini, ufim = s.fim;
    vector<pii> v = {{xini, 1}, {xfim, 2}, {uini, 3}, {ufim, 4}};

    if (k1 != k2) return false;

    sort(all(v));

    if((v[0].second == 1 && v[1].second == 2) || (v[2].second == 1 && v[3].second == 2)) return false;

    ans[i].ini = v[1].first;
    ans[i].fim = v[2].first;

    return true;
}

bool perpendicular(int i, seg sa, seg sb) {
    int k1 = ans[i].k, s1 = ans[i].sinalX;
    int sy = ans[i].sinalY;
    int k2 = sa.k, s2 = sa.sinalX;
    int k3 = sb.k, s3 = sb.sinalX;
    int x1, x2;

    if (s1 == s2) {
        x1 = ((k1+k2)/2)*s1;
    } else {
        x1 = ((k1-k2)/2)*s1;
    }

    if (s1 == s3) {
        x2 = ((k1+k3)/2)*s1;
    } else {
        x2 = ((k1-k3)/2)*s1;
    }

    bool flag = false;
    if (ans[i].perpendicular) {
        set<pii> st;
        for (auto e: ans[i].pontos) {
            if (e.first == x1 || e.first == x2) {
                st.insert(e);
                flag = true;
            }
        }
        ans[i].pontos = st;
        return flag;
    }

    set<pii> st;
    if (ans[i].ini <= x1 && x1 <= ans[i].fim) {
        int y1 = (k1-s1*x1)*sy;
        st.insert({x1, y1});
        ans[i].perpendicular = true;
        flag = true;
    }

    if (ans[i].ini <= x2 && x2 <= ans[i].fim) {
        int y2 = (k1-s1*x2)*sy;
        st.insert({x2, y2});
        ans[i].perpendicular = true;
        flag = true;
    }

    if (flag) ans[i].pontos = st;

    return flag;
}


signed main() {
    fastio();
    int n; cin >> n;
    tower.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tower[i].first.first >> tower[i].first.second >> tower[i].second;
    }
    ans = formaSegmentos(0);

    for (int i = 1; i < n; i++) {
        vector<bool> used(5, false);
        vector<seg> segmento = formaSegmentos(1);
        for (int j = 1; j <= 2; j++) {
            if (!ans[j].existe) continue;
            for (int k = 1; k <= 2 && !used[j]; k++) {
                used[j] = paralelo(j, segmento[k]);
            }
            if (used[j]) continue;
            used[j] = perpendicular(j, segmento[3], segmento[4]);
        }

        for (int j = 3; j <= 4; j++) {
            if (!ans[j].existe) continue;
            for (int k = 3; k <= 4 && !used[j]; k++) {
                used[j] = paralelo(j, segmento[k]);
            }
            if (used[j]) continue;
            used[j] = perpendicular(j, segmento[1], segmento[2]);
        }

        for (int j = 1; j <= 4; j++) {
            if (!used[j]) ans[j].existe = false;
        }
    }

    set<pii> st;
    for (int i = 1; i <= 4; i++) {
        if (!ans[i].existe) continue;
        if (ans[i].perpendicular) {
            for (auto e : ans[i].pontos) st.insert(e);
        } else {
            int xini = ans[i].ini, xfim = ans[i].fim;
            int sx = ans[i].sinalX, sy = ans[i].sinalY;
            int k = ans[i].k;
            for (int x = xini; x <= xfim; x++) {
                int y = (k-sx*x)*sy;
                st.insert({x, y});
            }
        }
    }

    vector<pii> vp;
    for (auto e: st) {
        vp.push_back({e.first, -e.second});
    }
    sort(all(vp));

    for (auto e: vp) {
        cout << e.first << " " << -e.second << endl;
    }

    return 0;
}