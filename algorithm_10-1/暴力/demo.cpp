#include <iostream>
using namespace std;
#define ll long long
int main() {
    ll a, ans = 0;
    cin >> a;
	ll h = a / 3600;
	ll m = (a % 3600) / 60;
	ll s = (a % 60);
	printf("%lld:%lld:%lld", h, m, s);
    return 0;
}
