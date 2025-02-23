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

char dif(char a) {
    if (a == '1') return '0';
    return '1';
}

signed main() {
    fastio();

    int k;
    string s;
    cin >> k >> s;

    if (k == 2) {
        string a, b;
        int contA = 0, contB = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            if (i%2) {
                a.pb('1');
                b.pb('0');
            } else {
                b.pb('1');
                a.pb('0');
            }
        }
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] != a[i]) contA++;
            if (s[i] != b[i]) contB++;
        }

        if (contA < contB) cout << contA << " " << a << endl;
        else cout << contB << " " << b << endl;

        return 0;
    }

    int cont = 1;
    char ant = s[0];
    vi tam;
    for (int i = 1; i < (int) s.size(); i++) {
        if (ant == s[i]) cont++;
        else {
            tam.pb(cont);
            cont = 1;
        }
        ant = s[i];
    }
    tam.pb(cont);
    int j = 0;
    int ans = 0;
    for (int i = 0; i < (int) s.size(); ) {
        char oposto = dif(s[i]);
        if (tam[j]%k) {
            for (int p = i; p-i < tam[j]; p++) {
                if ((p-i+1)%k == 0) {
                    s[p] = oposto;
                    ans++;
                }
            }
        } else {
            for (int p = i; p-i < tam[j]-1; p++) {
                if ((p-i+1)%k == 0) {
                    s[p] = oposto;
                    ans++;
                }
            }
            s[i+tam[j]-2] = oposto;
            ans++;
        }
        i += tam[j];
        j++;
    }

    cout << ans << " " << s << endl;

    return 0;
}