#include <iostream>
#include <string>
#include <fstream>

using namespace std;

long long hash_string(string s, int p, long m) {
    // Calcula el hash de una cadena usando la fórmula:
    // hash(s) = (s[0]*p^(n-1) + s[1]*p^(n-2) + ... + s[n-1]*p^0) % m
    // Recorremos la cadena de derecha a izquierda para evitar el uso de inversos modulares.

    long long hash = 0; // Acumula el resultado final del hash
    long long power = 1; // Representa la potencia de p en cada paso, inicia en p^0
    // En cada iteración, power = p^(n-1-i) para el caracter s[i]
    for (int i = s.length() - 1; i >= 0; i--) {
        // s[i] * power corresponde a s[i] * p^(n-1-i)
        hash = (hash + s[i] * power) % m; // Suma el término correspondiente al caracter actual
        power = (power * p) % m; // Actualiza la potencia para el siguiente caracter a la izquierda
    }
    // Al final, hash contiene el valor calculado según la fórmula
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