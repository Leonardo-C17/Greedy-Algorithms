# Greedy-Algorithms

Actividad 8: Algoritmos Voraces (Greedy). El repositorio contiene dos programas en C++ independientes, uno por problema:

| Archivo | Problema |
|---|---|
| `Fractional Bag.cpp` | Mochila fraccional |
| `Antenna Coverage.cpp` | Cobertura de antenas |

## Requisitos

- Un compilador de C++ con soporte para C++17 (por ejemplo, `g++` o `clang++`).
- Una terminal abierta en la carpeta del repositorio.

## Compilación y ejecución

Los nombres de los archivos contienen espacios, por eso deben escribirse entre comillas.

**Mochila fraccional**

```bash
g++ -std=c++17 -o fractional_bag "Fractional Bag.cpp"
```

**Cobertura de antenas**

```bash
g++ -std=c++17 -o antenna_coverage "Antenna Coverage.cpp"
```

En Windows, el ejecutable se llama con `fractional_bag.exe` y `antenna_coverage.exe`.

## Uso

Cada programa pide sus datos por consola y valida la entrada: si se ingresa un valor no numérico o fuera de rango, lo vuelve a solicitar.

### Mochila fraccional

Datos solicitados: capacidad máxima, cantidad de objetos y, por cada objeto, su nombre, valor y peso (mayor que 0).

Entrada de ejemplo:

```
Capacidad maxima: 50
Cantidad de objetos: 3
Objeto 1 - nombre: A
  Valor: 60
  Peso (> 0): 10
Objeto 2 - nombre: B
  Valor: 100
  Peso (> 0): 20
Objeto 3 - nombre: C
  Valor: 120
  Peso (> 0): 30
```

Salida:

```
Objetos seleccionados:
  A completo
  B completo
  20/30 Parte del objeto C
Valor total aproximado: 240
```

### Cobertura de antenas

Datos solicitados: cantidad de casas, sus posiciones (enteros separados por espacio) y el rango de cobertura R. Las posiciones pueden ingresarse en cualquier orden.

Entrada de ejemplo:

```
Cantidad de casas: 7
Posiciones de las casas (enteros separados por espacio): 1 2 7 11 20 21 30
Cobertura R: 5
```

Salida:

```
Antenas colocadas en:
  6
  25
Cantidad total: 2
```

## Estrategia greedy utilizada (también incluido en el documento de presentación)

### Mochila fraccional

Se ordenan los objetos de mayor a menor razón valor/peso y se recorren en ese orden. Cada objeto se toma completo mientras quepa en la capacidad restante; el primero que no cabe se toma solo en la fracción necesaria para llenar la mochila, y el algoritmo termina. Es óptimo porque, al poder fraccionar, siempre conviene llenar la capacidad con el mayor valor por unidad de peso disponible.

Complejidad: O(n log n) en tiempo (por el ordenamiento) y O(n) en espacio.

### Cobertura de antenas

Se ordenan las posiciones de las casas y se recorren de izquierda a derecha. Al encontrar la primera casa sin cobertura, en la posición `p`, se coloca una antena en `p + R`: es la posición más a la derecha que todavía cubre esa casa, por lo que alcanza el mayor número posible de casas siguientes (hasta `p + 2R`). Luego se omiten las casas ya cubiertas y se repite el proceso. Esto garantiza la menor cantidad de antenas.

Complejidad: O(n log n) en tiempo (O(n) si las casas ya están ordenadas) y O(n) en espacio.