#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
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

int cross(pii a, pii b) {
    return a.first * b.second - a.second * b.first;
}

int cross(pii p, pii a, pii b) {
    auto [x1, y1] = p;
    auto [x2, y2] = a;
    auto [x3, y3] = b;
    return cross({x2-x1, y2-y1}, {x3-x1, y3-y1});
}

signed main() {
    fastio();
    int n; cin >> n;
    vector<pii> pontos(n);
    for (auto &[x, y]: pontos) cin >> x >> y;

    vector<pii> esq(n), dir(n);

    // esquerda para direita
    vector<pii> st1;
    st1.push_back(pontos[0]);
    for (int i = 1; i <= n-2; i++) {
        auto [x3, y3] = pontos[i];
        while (st1.size() > 1) {
            auto [x1, y1] = st1[st1.size()-2];
            auto [x2, y2] = st1[st1.size()-1];
            if (cross({x1, y1}, {x2, y2}, {x3, y3}) < 0) st1.pop_back();
            else break;
        }
        esq[i] = st1[st1.size()-1];
        st1.push_back({x3, y3});
    } 


    // direita para esquerda
    vector<pii> st;
    st.push_back(pontos[n-1]);
    for (int i = n-2; i >= 1; i--) {
        auto [x3, y3] = pontos[i];
        while (st.size() > 1) {
            auto [x1, y1] = st[st.size()-2];
            auto [x2, y2] = st[st.size()-1];
            if (cross({x1, y1}, {x2, y2}, {x3, y3}) > 0) st.pop_back();
            else break;
        }
        dir[i] = st[st.size()-1];
        st.push_back({x3, y3});
    } 

    /*ld ans = 0.0;
    for (int i = 1; i < n-1; i++) {
        auto [x1, y1] = pontos[i];
        auto [x2, y2] = esq[i];
        auto [x3, y3] = dir[i];
        cout << i << " {" << x2 << ", " << y2 << "} {" << x3 << ", " << y3 << "}" << endl;
        ld xd1 = (ld) x1, yd1 = (ld) y1, xd2 = (ld) x2, yd2 = (ld) y2, xd3 = (ld) x3, yd3 = (ld) y3;
        ld xe = xd1 - yd1 * (xd1-xd2)/(yd1-yd2);
        ld xd = xd1 - yd1 * (xd1-xd3)/(yd1-yd3);
        ld area = abs((xd2*(yd1 - yd3) + xd1*(yd3 - yd2) + xd3*(yd2 - yd1))) / 2.0;
        ans = max(ans, area);
    }*/

    ld ans = 0;
    for (int i = 1; i < n - 1; i++) {
        int y_i = pontos[i].second;
        pii left = esq[i];
        pii right = dir[i];

        left.first = pontos[i].first - left.first;
        left.second = pontos[i].second - left.second;

        right.first = pontos[i].first - right.first;
        right.second = pontos[i].second - right.second;

        ld xl = (ld)(y_i * left.first) / left.second;
        ld xr = (ld)(y_i * (-right.first)) / right.second;
        ld area = (y_i * (xl + xr)) / 2.0;

        if (area > ans) {
            ans = area;
        }
    }

    cout << fixed << setprecision(20) << ans << endl;
  
    return 0;
}