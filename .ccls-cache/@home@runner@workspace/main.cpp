#include <iostream>
#include <string>

using namespace std;

// hash(s) = (s[0]*p^(n-1) + s[1]*p^(n-2) + ... + s[n-1]*p^0) % m

long long hash_string(string s, int p, long m ){

    for (int i = 0; i < s.length(); i++) {
        char caracter = s[i];
        
        cout << caracter << endl;
    }
    return 0;
}

int main() { 
    cout << hash_string("hola", 3, 10000000009) << endl;;
}