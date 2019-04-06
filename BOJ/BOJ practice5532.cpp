#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;

    float result1 = (float) a / c, result2 = (float) b / d;
    if (result1 < result2)
        result1 = result2;
    cout << l - ceil(result1);
}