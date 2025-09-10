#include <iostream>
#include <string>
#include <fstream>

using namespace std;

long long hash_string(string s, int p, long m) {
    // Calculates the hash of a string using the formula:
    // hash(s) = (s[0]*p^(n-1) + s[1]*p^(n-2) + ... + s[n-1]*p^0) % m
    // We iterate the string from right to left to avoid using modular inverses.

    long long hash = 0; // Accumulates the final hash result
    long long power = 1; // Represents the power of p at each step, starts at p^0
    // In each iteration, power = p^(n-1-i) for character s[i]
    for (int i = s.length() - 1; i >= 0; i--) {
        // s[i] * power corresponds to s[i] * p^(n-1-i)
        hash = (hash + s[i] * power) % m; // Adds the term for the current character
        power = (power * p) % m; // Updates the power for the next character to the left
    }
    // At the end, hash contains the value calculated according to the formula
    return hash;
}

int main() { 

    ifstream archivo("input_strings.txt");
    ofstream salida("output_hashes.txt");

    if (!archivo.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }
    if (!salida.is_open()){
        cout << "Error al crear el archivo de salida" << endl;
        return 1;
    }

    string linea;
    while (getline(archivo, linea)){
        salida << hash_string(linea, 31, 10000000009) << endl;
    }
    archivo.close();
    salida.close();
}