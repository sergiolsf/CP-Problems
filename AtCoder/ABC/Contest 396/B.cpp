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
    string s; cin >> s;
    int sz = s.size();
    int add = 0;
    for(int i = 0; i < sz; i++) {
        if ((add+i+1)&1 && s[i] == 'o') add++;
        if ((add+i+1)%2 == 0 && s[i] == 'i') add++;
    }

    cout << (((sz+add)&1) ? add+1 : add) << endl;
  
    return 0;
}