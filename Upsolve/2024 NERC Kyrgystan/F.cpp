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
    int s, f; cin >> s >> f;
    vector<pair<int, pii>> v;
    map<int, pii> mp;

    for (int i = 1; i <= n; i++) {
        int b, e; cin >> b >> e;
        if (mp.count(b)) mp[b].first++;
        else mp[b] = {1, 0};

        if (mp.count(e)) mp[e].second++;
        else mp[e] = {0, 1};
    }
    
    if (!mp.count(f)) mp[f] = {0, 0};

    for (auto e: mp) {
        v.push_back({e.first, {e.second.first, e.second.second}});
    }

    sort(all(v));

    vi t(n+1, 0);

    int ant = s;
    int qtd = 0;
    for (int i = 0; i < v.size(); i++) {
        int u = v[i].first, a = v[i].second.first, b = v[i].second.second;
        if (u > f) break;
        if (u < s) {qtd += (a-b); continue;}

        t[qtd+1] += u-ant;
        qtd += a-b;
        ant = u;
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
       cout << t[i] + sum << (i == n ? "\n" : " ");
        sum += t[i];
    }
  
    return 0;
}