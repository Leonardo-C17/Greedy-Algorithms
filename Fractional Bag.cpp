// Problema 1: Mochila fraccional
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

struct Item { //estructura para englobar las características de cada ítem
    string name;
    double value;
    double weight;

    double ratio() const { return value / weight; }
};

void solveFractionalKnapsack(vector<Item> items, double capacity) {
    // Se ordena de mayor a menor razón: O(n log n). El vector es una copia
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio() > b.ratio();
    });

    double remainingCapacity = capacity;
    double totalValue = 0.0;

    cout << "\nObjetos seleccionados:\n";
    for (const Item& item : items) {
        if (remainingCapacity <= 0) break;  // mochila llena, ya no cabe nada más

        if (item.weight <= remainingCapacity) {
            // El objeto cabe completo: se toma entero.
            cout << "  " << item.name << " completo\n";
            remainingCapacity -= item.weight;
            totalValue += item.value;
        } else {
            // Solo cabe una fracción: se toma lo que queda y se termina.
            double fraction = remainingCapacity / item.weight;
            cout << "  " << remainingCapacity << "/" << item.weight
                 << " Parte del objeto " << item.name << "\n";
            totalValue += item.value * fraction;
            remainingCapacity = 0;
        }
    }
    cout << "Valor total aproximado: " << totalValue << "\n";
}

int main() {
    double capacity = readNumber<double>("Capacidad maxima: ", 0.0);
    int itemCount = readNumber<int>("Cantidad de objetos: ", 1);

    vector<Item> items;
    for (int i = 0; i < itemCount; ++i) {
        Item item;
        cout << "Objeto " << (i + 1) << " - nombre: ";
        cin >> item.name;
        item.value = readNumber<double>("  Valor: ", 0.0);
        // El peso debe ser estrictamente positivo para no dividir entre cero en ratio().
        do {
            item.weight = readNumber<double>("  Peso (> 0): ", 0.0);
        } while (item.weight <= 0);
        items.push_back(item);
    }

    solveFractionalKnapsack(items, capacity);
    return 0;
}