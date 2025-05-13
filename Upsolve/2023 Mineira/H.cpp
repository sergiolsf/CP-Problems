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

const int MAX_N = 1LL<<21;

signed main() {
    fastio();
    
    int num = 0;
    vi v(MAX_N, 0);
    v[0] = 1;

    int n; cin >> n; 
    string s; cin >> s;

    vi tira(6);
    tira[0] = 'a'-'a';
    tira[1] = 'e'-'a';
    tira[2] = 'i'-'a';
    tira[3] = 'o'-'a';
    tira[4] = 'u'-'a';
    tira[5] = 'y'-'a';

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int C = s[i]-'a';
        int c = C;
        for (int j = 0; j < 6; j++) {
            if (C > tira[j]) c--;
        }
        num ^= (1LL << c);

        ans += v[num];

        for (int j = 0; j < 20; j++) {
            num ^= (1LL << j);
            ans += v[num];
            num ^= (1LL << j);
        }

        v[num]++;
    }

    cout << ans << endl;
  
    return 0;
}