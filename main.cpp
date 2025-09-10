#include <iostream>
#include <string>

using namespace std;

// hash(s) = (s[0]*p^(n-1) + s[1]*p^(n-2) + ... + s[n-1]*p^0) % m

long long hash_string(string s, int p, long m) {
    long long hash = 0;
    long long power = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        hash = (hash + s[i] * power) % m;
        power = (power * p) % m;
    }
    return hash;
}

int main() { 
    cout << hash_string("hola", 3, 10000000009) << endl;
}