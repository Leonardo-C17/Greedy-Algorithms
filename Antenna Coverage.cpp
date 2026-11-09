// Problema 2: Cobertura de antenas
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

// Lee un número de tipo T y vuelve a pedirlo hasta que sea válido y >= minimumValue.
template <typename T>
T readNumber(const string& prompt, T minimumValue) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minimumValue) {
            return value;
        }
        cout << "  Entrada invalida. Debe ser un numero >= " << minimumValue << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');   // limpia y descarta ante entradas inválidas
    }
}

vector<long long> placeAntennas(vector<long long> houses, long long range) {
    sort(houses.begin(), houses.end());  // las posiciones pueden llegar desordenadas

    vector<long long> antennas;
    size_t index = 0;
    while (index < houses.size()) {
        long long antennaPosition = houses[index] + range;  // cubre la primera casa descubierta
        long long coverageEnd = antennaPosition + range;    // límite derecho del intervalo

        antennas.push_back(antennaPosition);

        // Se saltan todas las casas dentro de [antennaPosition - range, coverageEnd].
        while (index < houses.size() && houses[index] <= coverageEnd) {
            ++index;
        }
    }
    return antennas;
}

int main() {
    int houseCount = readNumber<int>("Cantidad de casas: ", 1);
    vector<long long> houses(houseCount);

    cout << "Posiciones de las casas (enteros separados por espacio): ";
    for (long long& position : houses) {
        while (!(cin >> position)) {
            cout << "  Entrada invalida, reingrese ese valor: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    long long range = readNumber<long long>("Cobertura R: ", 0);

    vector<long long> antennas = placeAntennas(houses, range);

    cout << "\nAntenas colocadas en:\n";
    for (long long position : antennas) {
        cout << "  " << position << "\n";
    }
    cout << "Cantidad total: " << antennas.size() << "\n";
    return 0;
}