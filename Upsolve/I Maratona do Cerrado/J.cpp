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

const int INF = 1e18;

vi a;
int n; 

vi func() {
    map<int,int> mp; // {gcd, qtd}
    vi ans(n, 0);

    ans[0] = a[0];
    mp[a[0]] = 1;

    for (int i = 1; i < n; i++) {
        ans[i] = ans[i-1] + a[i];
        map<int,int> aux;
        aux[a[i]] = 1;

        for (auto e: mp) {
            int mdc = e.first, qtd = e.second;
            int g = __gcd(a[i], mdc);
            ans[i] += g*qtd;
            if (aux.count(g)) {
                aux[g] += qtd;
            } else {
                aux[g] = qtd;
            }
        }
        mp = aux;
    }
    
    return ans;
}

signed main() {
    fastio();
    cin >> n;
    a.resize(n);
    
    for (auto &i: a) cin >> i;

    vi s = func();
    reverse(all(a));
    vi p = func();
    reverse(all(p));

    int menor = INF;

    for (int i = 0; i < n; i++) {
        int d = (i+1)*(n-i);
        if (i > 0) d += s[i-1];
        if (i < n-1) d += p[i+1];
        menor = min(menor, d);
    }
    cout << menor << endl;
  
    return 0;
}