#include <iostream>

void solve() {
	int a, b, c;
	std::cin >> a >> b >> c;
	if(a < b && b < c) std::cout << "STAIR"<< "\n";
	else if(a < b && b > c) std::cout << "PEAK"<< "\n";
	else std::cout << "NONE" << "\n";
}

int main() {
	int tt; std::cin >> tt;
	while(tt--) 
	    solve();
}