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

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    vector<cd> a0(n/2), a1(n/2);
    for (int i = 0; 2*i < n;  ++i) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2*PI/n * (invert ? -1:1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2*i < n; i++) {
        a[i] = a0[i] + w*a1[i];
        a[i+n/2] = a0[i] - w*a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(all(a)), fb(all(b));
    int n = 1;
    while (n < a.size()+b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for(int i = 0; i < n; i++) {
        result[i] = round(fa[i].real());
    }
    result.resize(a.size()+b.size()-1);
    return result;
}

signed main() {
    fastio();
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    bool menos = false;
    if (a[i] == '-') {
        menos = !menos;
        i++;
    }
    if (b[j] == '-') {
        menos = !menos;
        j++;
    }

    vi c, d;
    for (;i < a.size(); i++) {
        int num = a[i]-'0';
        c.push_back(num);
    }
    for (;j < b.size(); j++) {
        int num = b[j]-'0';
        d.push_back(num);
    }

    vi r = multiply(c, d);

    bool flag = false;
    for (auto e: r) if (e != 0) {
        flag = true;
        break;
    }

    if (!flag) {
        cout << 0 << endl;
        return 0;
    }

    if (menos) cout << "-";
    
    stack<int> ans;
    int sobra = 0;
    for (int k = r.size()-1; k >= 0; k--) {
        int t = r[k]+sobra;
        ans.push(t%10);
        sobra = t/10;
    }

    if (sobra) cout << sobra;

    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    
    cout << endl;
  
    return 0;
}