#include <iostream>
#include <string>
#include <fstream>

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

    ifstream archivo("input_strings.txt");

    if (!archivo.is_open()){
        cout << "Error al abrir el archivo" << endl;
    }

    string linea;
    while (getline(archivo, linea)){
        cout << linea << ": ";
        cout << hash_string(linea, 31, 10000000009) << endl;
    }
}