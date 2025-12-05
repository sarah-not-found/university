# Aufgabe 1 (5 Punkte)

## Vorlesungsfolien

* Funktionen (EidP-06-Funktionen.pdf)

## Beschreibung

Implementieren Sie eine Funktion mit der Signatur `unsigned square_pyramidal_number(unsigned height)`. Diese Funktion
berechnet wie viele Bausteine für eine quadratische Pyramide mit der Höhe `height` erforderlich sind. Als Bausteine für
die quadratische Pyramide werden Murmeln herangezogen.

Testen Sie Ihre Funktion in der `main`-Funktion mit einigen Beispielaufrufen.

## Beispiele

|  height | `square_pyramidal_number(height)` |
|--------:|----------------------------------:|
|       0 |                                 0 |
|       1 |                                 1 |
|       2 |                                 5 |
|       3 |                                14 |
|       8 |                               204 |

## Hinweise

- Überlegen Sie sich vor dem Implementieren wie diese Zahlen berechnet werden können. Eine Skizze der Beispiele könnte
  hilfreich sein.

# Aufgabe 2 (3 Punkte)

## Vorlesungsfolien

* Funktionen (EidP-06-Funktionen.pdf)

## Beschreibung

Das folgende Programm kompiliert nicht ohne Fehler. Erklären Sie, warum das Programm nicht kompiliert und beheben Sie
den Fehler ohne die Funktionsrümpfe zu verändern!

```c
#include <stdio.h>
#include <stdlib.h>

unsigned f1(unsigned a, unsigned b) {
    if (a < b) {
        return a + b;
    }
    return f2(a - b);
}

unsigned f2(unsigned a) { return f1(a >> 1, 5); }

int main(void) {
    printf("%u\t%u\n", f1(1, 2), f2(3));
    printf("%u\t%u\n", f1(4, 5), f2(6));
    return EXIT_SUCCESS;
}

```

# Aufgabe 3 (4 Punkte)

## Vorlesungsfolien

* Funktionen (EidP-06-Funktionen.pdf)

## Beschreibung

Betrachten Sie folgendes Programm. In welchen Zeilen werden lokale bzw. globale Variablen deklariert? Geben Sie für jede
Zuweisung die Zeile der Variablendeklaration und den Dezimalwert vor sowie nach der Verwendung an, indem Sie die Tabelle
in der Datei `s05e03_b.txt` ausfüllen.

Falls Sie das Programm ausführen möchten, verzichten Sie beim Kompilieren dieser Teilaufgabe auf die Flags `-Wall -Werror -Wextra -Wpedantic`!

```c
1  #include <stdlib.h>
2
3  int a;
4
5  int main(void) {
6     a = 1;
7     {
8         a = 2;
9         char a;
10        a = 3;
11        {
12            int a;
13            a = 4;
14        }
15        {
16            a = 5;
17        }
18        a = 6;
19     }
20     a = 7;
21     return EXIT_SUCCESS;
22 }
23
```

# Aufgabe 4 (6 Punkte)

## Vorlesungsfolien

* Funktionen (EidP-06-Funktionen.pdf)

## Beschreibung

Implementieren Sie eine Funktion mit der Signatur `unsigned different_bits(unsigned a, unsigned b)`, welche die Bits der
beiden Zahlen `a` und `b` vergleicht und zurückgibt, wie viele Bits unterschiedlich sind.

Testen Sie Ihre Funktion in der `main`-Funktion mit einigen Beispielaufrufen.

## Beispiele

|  a |  b | `different_bits(a, b)` |
|---:|---:|-----------------------:|
|  0 |  0 |                      0 |
|  0 |  3 |                      2 |
|  7 |  3 |                      1 |
| 15 |  0 |                      4 |
| 10 | 21 |                      5 |

# Aufgabe 5 (5 Punkte)

## Vorlesungsfolien

* Funktionen (EidP-06-Funktionen.pdf)

## Beschreibung

Implementieren Sie folgende Funktionen:

- `unsigned fibonacci_recursive(unsigned n)`: Diese Funktion berechnet rekursiv die `n`-te Fibonacci-Zahl.
- `unsigned fibonacci_iterative(unsigned n)`: Diese Funktion berechnet iterative die `n`-te Fibonacci-Zahl.

Testen Sie Ihre Funktion in der `main`-Funktion mit einigen Beispielaufrufen.

## Hinweise

- Die `n`-te Fibonacci-Zahl $`F_n`$ ist durch die lineare Differenzengleichung $`F_n = F_{n - 1} + F_{n - 2}`$ mit 
  $`F_0 = 1`$ und $`F_1 = 1`$ definiert.

## Beispiele

|  n | `fibonacci_recursive(value)` | `fibonacci_iterative(value)` |
|---:|-----------------------------:|-----------------------------:|
|  1 |                            1 |                            1 |
|  2 |                            2 |                            2 |
| 10 |                           55 |                           55 |

# Aufgabe 6 (7 Punkte)

## Vorlesungsfolien

* Funktionen (EidP-06-Funktionen.pdf)

## Beschreibung

In dieser Aufgabe wird die Binärdarstellung einer Zahl rekursiv ausgegeben.

### Arbeitsschritte

- Informieren Sie sich über [Integer mit fester Bitbreite](https://en.cppreference.com/w/c/types/integer) wie z.
  B. `uint32_t`!
- Implementieren Sie eine Funktion mit der Signatur `void print_binary(uint32_t value)`, welche ohne Schleifen und
  mithilfe von rekursiven Hilfsfunktionen die Binärdarstellung der positiven Ganzzahl `value` auf der Standardausgabe
  ausgibt. Die Formatierung der Ausgabe ist von den Beispielausgaben zu entnehmen.
- Lesen Sie in der `main`-Funktion mittels `scanf` eine positive Ganzzahl mit der festen Breite von $`32`$ Bit ein und
  rufen Sie mit dieser Zahl als Argument die von Ihnen implementierte Funktion `print_binary` auf.

## Beispiele

Beispiel 1: Möglicher Programmablauf bei der Eingabe der Zahl `5`. Die Zahl $`5`$ in der ersten Zeile der
Beispielausgabe wurde durch den\*die Benutzer\*in eingegeben und solle nicht von Ihrem Programm ausgegeben werden.

```text
value: 5

5 = 0b00000000000000000000000000000101
```

Beispiel 2: Möglicher Programmablauf bei der Eingabe der Zahl `16`. Die Zahl $`16`$ in der ersten Zeile der
Beispielausgabe wurde durch den\*die Benutzer\*in eingegeben und solle nicht von Ihrem Programm ausgegeben werden.

```text
value: 16

16 = 0b00000000000000000000000000010000
```

Beispiel 3: Möglicher Programmablauf bei der Eingabe der Zahl `4294967294`. Die Zahl $`4294967294`$ in der ersten Zeile
der Beispielausgabe wurde durch den\*die Benutzer\*in eingegeben und solle nicht von Ihrem Programm ausgegeben werden.

```text
value: 4294967294

4294967294 = 0b11111111111111111111111111111110
```

### Hinweise

- In dieser Aufgabe dürfen Sie keine Schleifen verwenden!
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!
- Die Binärdarstellung der Zahl muss nur auf der Standardausgabe ausgegeben werden. Ein Zwischenspeichern der Zahl ist
  nicht erforderlich.
- Mithilfe des folgenden Codefragments können Sie mit `scanf` bzw. `printf` die Variable `value` vom Typ `uint32_t`
  einlesen bzw. ausgeben. Beachten Sie, dass Sie für die Konstanten `SCNu32` und `PRIu32` den Header `inttypes.h`
  inkludieren müssen.

  ```c
  scanf("%" SCNu32, &value);
  printf("%" PRIu32, value);
  ```
