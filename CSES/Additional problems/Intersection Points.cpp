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

const int MAXN = 200'010;
int seg[4*MAXN];

void update (int pos, int ini, int fim, int id, int val) {
    if (id < ini || id > fim) return;
    if (ini == fim) {
        seg[pos] += val;
        return;
    }

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    update(e, ini, m, id, val);
    update(d, m+1, fim, id, val);
    seg[pos] = seg[e]+seg[d];    
}

int query (int pos, int ini, int fim, int p, int q) {
    if (q < ini || p > fim) return 0;
    if (p <= ini && fim <= q) return seg[pos];

    int m = (ini + fim)/2;
    int e = 2*pos, d = 2*pos+1;
    return query(e, ini, m, p, q) + query(d, m+1, fim, p, q);
}

signed main() {
    fastio();
    int n; cin >> n;
    set<int> st;
    vector<pair<pii, int>> h;
    vector<pair<int, pii>> v;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        st.insert(y1);
        st.insert(y2);
        if(y1 == y2) {
            h.push_back({{x1, y1}, 1});
            h.push_back({{x2, y2}, -1});
        } else {
            v.push_back({x1, {y1, y2}});
        }
    }

    // Compressao
    int i = 1, ult = 1'000'000'000;
    map<int,int> ny;
    for(auto e: st) {
        if (e != ult) {
            ny[e] = i;
            i++;
        }
        ult = e;
    }
    //

    sort(all(h));
    sort(all(v));
    int szh = h.size(), szv = v.size();

    int ih = 0, iv = 0;
    int ans = 0;
    while (ih < szh && iv < szv) {
        if (h[ih].first.first < v[iv].first) {
            int y = ny[h[ih].first.second];
            int m = h[ih].second;
            // soma m na seg em y
            update(1, 1, i, y, m);
            ih++;
        } else {
            int y1 = ny[v[iv].second.first];
            int y2 = ny[v[iv].second.second];
            // soma seg de y1 até y2 em ans
            ans += query(1, 1, i, y1, y2);
            iv++;
        }
    }

    cout << ans << endl;
  
    return 0;
}