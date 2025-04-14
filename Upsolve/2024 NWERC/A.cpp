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
    string lixo; getline(cin, lixo);
    vector<pair<string, string>> vp;
    vector<string> vs;

    for (int i = 0; i < n; i++) {
        string s; getline(cin, s);
        vs.push_back(s);   
    }

    for (int i = 0; i < n; i++) {
        string s = vs[i];
        int sz = s.size();
        int k;
        for (int j = 0; j < sz; j++) {
            if (s[j]-'A' >= 0 && s[j]-'A' < 27) {
                k = j;
                break;
            }
        }
        string S;
        for (int j = k; j < sz; j++) {
            S.push_back(s[j]);
        }
        vp.push_back({S, s});
    }

    sort(all(vp));
    for (auto e: vp) {
        cout << e.second << endl;
    }
  
    return 0;
}