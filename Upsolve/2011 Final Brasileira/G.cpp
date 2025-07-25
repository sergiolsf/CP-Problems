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

const int INF = 1'000'000'000'000'000'000;

int pos(int x1, int y1, int x2, int y2, int x3, int y3) {
    //cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
    x2 -= x1; y2 -= y1;
    x3 -= x1; y3 -= y1;
    if (x2*y3 - y2*x3 == 0) return 0;
    else if (x2*y3 - y2*x3 < 0) return 1;
    return -1;
}

signed main() {
    fastio();
    int p, l; cin >> p >> l;
    while (p != 0 || l != 0) {
        vector<tuple<int,int,int,int>> v;
        for (int i = 0; i < p; i++) {
            tuple<int,int,int,int> tp;
            auto &[x, y, k, t] = tp;
            cin >> x >> y >> k;
            t = 0;
            v.push_back(tp);
        }
        for (int i = 0; i < l; i++) {
            tuple<int,int,int,int> tp;
            auto &[x, y, k, t] = tp;
            cin >> x >> y >> k;
            t = 1;
            v.push_back(tp);
        }

        int ans = INF;
        for (int i = 0; i < p+l-1; i++) {
            tuple<int,int,int,int> tpi = v[i];
            auto [x1, y1, k1, t1] = tpi;
            for (int j = i + 1; j < p+l; j++) {
                tuple<int,int,int,int> tpj = v[j];
                auto [x2, y2, k2, t2] = tpj;

                int esqP = 0, esqL = 0, dirP = 0, dirL = 0;
                vector<pii> muro;
                for (int k = 0; k < p+l; k++) {
                    tuple<int,int,int,int> tpk = v[k];
                    auto [x3, y3, k3, t3] = tpk;
                    int lado = pos(x1, y1, x2, y2, x3, y3);
                    if (lado == 0) {
                        muro.push_back({k3,t3});
                    }
                    else if (lado == -1) {
                        if (t3) esqL += k3;
                        else esqP += k3;
                    } else {
                        if (t3) dirL += k3;
                        else dirP += k3;
                    }
                }

                if (!muro.empty()) {
                    vi sumP((int) muro.size(), 0);
                    vi sumL((int) muro.size(), 0);

                    for (int h = 0; h < muro.size(); h++) {
                        auto [k, t] = muro[h];
                        if (h > 0) {
                            sumP[h] = sumP[h-1];
                            sumL[h] = sumL[h-1];
                        }
                        if (t == 0) sumP[h] += k;
                        else sumL[h] += k;
                    }

                    ans = min({ans, esqL+dirP+sumP[muro.size()-1], esqP+dirL+sumL[muro.size()-1]});
                    ans = min({ans, esqL+dirP+sumL[muro.size()-1], esqP+dirL+sumP[muro.size()-1]});

                    for (int h = 0; h < muro.size()-1; h++) {
                        ans = min({ans, esqL+dirP+sumL[h]+(sumP[muro.size()-1] - sumP[h]), esqP+dirL+sumP[h]+(sumL[muro.size()-1] - sumL[h])});
                        ans = min({ans, esqL+dirP+sumP[h]+(sumL[muro.size()-1] - sumL[h]), esqP+dirL+sumL[h]+(sumP[muro.size()-1] - sumP[h])});
                    }
                } else {
                    cout << "a";
                    ans = min({ans, esqL+dirP, esqP+dirL});
                }
                
            }
        }

        cout << ans << endl;

        cin >> p >> l;
    }


  
    return 0;
}