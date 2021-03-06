#include <iostream>
using namespace std;

int NWD(int a, int b) {
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main(){
    int n;
    cin >> n;
    int t[n];
    for (int i=0; i<n; i++)
        cin >> t[i];
    int w = NWD(t[0],t[1]); // NWD dla pierwszych dwoch liczb!
    for (int i=2; i<n; i++)
        w = NWD(w,t[i]);
    cout << w << endl;
}



