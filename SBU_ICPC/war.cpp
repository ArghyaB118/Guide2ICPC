#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    cout << "Enter n: ";
    scanf("%d", &n);
    vector<int> tom, katy;
    int tmp1, tmp2;
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &tmp1, &tmp2);
        tom.push_back(tmp1);
        katy.push_back(tmp2);
    }
    return 0;
}
