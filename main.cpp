#include <iostream>
#include <string>

using namespace std;

// hash(s) = (s[0]*p^(n-1) + s[1]*p^(n-2) + ... + s[n-1]*p^0) % m

long long hash_string(string s, int p, long m ){

    long long hash = 0;
    long long power = 1;
    int n = s.length();
    // Calcula p^(n-1) para el primer caracter
    for (int i = 0; i < n - 1; i++) {
        power = (power * p) % m;
    }
    for (int i = 0; i < n; i++) {
        hash = (hash + (s[i] * power) % m) % m;
        if (power > 1) {
            power = (power * modInverse(p, m)) % m;
        } else {
            power = 1;
        }
    }
    return hash;
}

int main() { 
    cout << hash_string("hola", 3, 10000000009) << endl;
}