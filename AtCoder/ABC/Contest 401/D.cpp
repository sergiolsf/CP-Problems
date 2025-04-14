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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int m = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') {
            if (i-1 >= 0 && s[i-1] == '?') s[i-1] = '.';
            if (i+1 < n && s[i+1] == '?') s[i+1] = '.';
            m++;
        }
    }

    if (m == k) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') cout << '.';
            else cout << s[i];
        }
        cout << endl;
        return 0;
    } 

    int maior = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') {
            maior++;
            flag = true;
        } else if (s[i] == '?') {
            if (!flag) maior++;
            flag = !flag;
        } else {
            flag = false;
        }
    }

    if (maior > k) {
        cout << s << endl;
        return 0;
    }

    map<int,int> mp;
    int cont = 0;
    int ini;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (cont == 0) ini = i;
            cont++;
        } else {
            if (cont) {
                mp[ini] = cont;
            }
            cont = 0;
        }
    }
    if (cont) mp[ini] = cont;

    for (auto e: mp) {
        flag = true;
        if (e.second&1) {
            for (int i = e.first; i < e.first+e.second; i++) {
                if (flag) s[i] = 'o';
                else s[i] = '.';
                flag = !flag;
            }
        }
    } 


    cout << s << endl;
  
    return 0;
}