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
    int C; cin >> C;
    char c; cin >> c;
    string s1; getline(cin, s1);
    s1 = c+s1;
    string s2; getline(cin, s2);
    vi v, w;
    int atual = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == ' ') {
            v.push_back(atual);
            atual = 0;
        } else {
            atual *= 10;
            atual += (int) (s1[i]-'0');
        }
    }
    v.push_back(atual);

    atual = 0;
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == ' ') {
            w.push_back(atual);
            atual = 0;
        } else {
            atual *= 10;
            atual += (int) (s2[i]-'0');
        }
    }
    w.push_back(atual);

    int n = v.size();
    //for (int i = 0; i < n; i++) cout << v[i] << " ";
    //cout << endl;
    //for (int i = 0; i < n; i++) cout << w[i] << " ";

    vi ans(C+1, -1);
    ans[0] = 0;
    for (int j = 0; j < n; j++) {
        for (int i = C; i >= 0; i--) {
            if (ans[i] != -1 && i+w[j] <= C) {
                ans[i+w[j]] = max(ans[i+w[j]], ans[i]+v[j]);
            }
        }
    }

    int maior = 0;
    for (int i = 0; i <= C; i++) {
        maior = max(maior, ans[i]);
    }
    cout << maior << endl;
  
    return 0;
}