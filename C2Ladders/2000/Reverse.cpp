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

int quant_um(int a) {
    return __builtin_popcountll(a);
}

vi zeros_entre(int a) {
    vi ans;
    while(a%2 == 0) a/=2;
    a/=2;
    while(a) {
        int p = __builtin_ctzll(a);
        //if (p) 
        ans.push_back(p);
        while(a%2 == 0) a/=2;
        a/=2;
    }

    vi bb;
    bool flag = false;
    for (int i = 0; i < ans.size(); i++) {
        if (flag || ans[i]) {
            flag = true;
            bb.push_back(ans[i]);
        }
    }

    reverse(all(bb));
    flag = false;
    vi aa;
    for (int i = 0; i < bb.size(); i++) {
        if (flag || bb[i]) {
            flag = true;
            aa.push_back(bb[i]);
        }
    }
    return bb;
}

int zeros_final(int a) {
    return __builtin_ctzll(a);
}

void printBinary(int x) {
    if (x == 0) {
        cout << 0;
        return;
    }

    string binary = "";
    while (x > 0) {
        binary = char('0' + (x % 2)) + binary;
        x /= 2;
    }

    cout << binary;
}

signed main() {
    fastio();
    int x, y; cin >> x >> y;

    //printBinary(x); cout << endl;
    //printBinary(y); cout << endl;

    int q1x = quant_um(x), q1y = quant_um(y);

    if (q1x > q1y) {
        cout << "NO\n";
        return 0;
    }

    vi zx = zeros_entre(x);
    vi zy = zeros_entre(y);

    int zfx = zeros_final(x);
    int zfy = zeros_final(y);


    /*for (auto e: zx) cout << e << " ";
    cout << endl;
    for (auto e: zy) cout << e << " ";
    cout << endl;*/

    if (zfy && zfy != zfx) {
        cout << "NO\n";
        return 0;
    }

    if (zfy && zfx == zfy) {
        if (q1x != q1y) {
            cout << "NO\n";
            return 0;
        }
    }

    if (abs((int)zx.size()+1LL-(int)zy.size()) >= 2) {
        cout << "NO\n";
        return 0;
    }

    if (zy.size()-zx.size() == 1) zx.push_back(zfx);

    if(zy.size() != zx.size()) {
        cout << "NO\n";
        return 0;
    }
    
    bool flag = true;
    for (int i = 0; i < zy.size(); i++) {
        if (zy[i] != zx[i]) flag = false;
    }

    if (flag) {
        cout << "YES\n";
        return 0;
    }

    reverse(all(zx));

    flag = true;
    for (int i = 0; i < zy.size(); i++) {
        if (zy[i] != zx[i]) flag = false;
    }

    if (flag) {
        cout << "YES\n";
        return 0;
    }
  
    cout << "NO\n";
    return 0;
}