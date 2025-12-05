# Aufgabe 1 (5 Punkte)

## Vorlesungsfolien

* Arrays (EidP-07-Arrays.pdf)

## Beschreibung

Implementieren Sie eine Funktion mit der Signatur `size_t copy_distinct(int dst[], const int src[], size_t len)`, welche
die Werte aus dem Array `src` in das Array `dst` kopiert. Bei diesem Kopieren werden keine Duplikate in das Array `dst`
übertragen. Dadurch ist jeder Wert aus dem Array `src` im Array `dst` vorhanden. Allerdings kommen im Array `dst` nur
einzigartige Werte vor. Die Ordnung der Werte im Array `dst` kann beliebig sein und ist nur von Ihrer Implementierung
abhängig. Die Anzahl an kopierten bzw. eindeutigen Werten im Array `dst` wird durch die Funktion zurückgegeben.

## Hinweise

- Der Datentyp `size_t` ist ein plattformabhängiger, vorzeichenloser Ganzzahltyp, welcher die maximale Größe eines Typs
  (Arrays inklusive) darstellt. Dieser Typ ist mindestens zwei Byte groß. `size_t` wird häufig als Datentyp für
  Schleifenindizes verwendet.
- Beide Arrays (`dst` und `src`) haben die Länge `len`. Wobei im Array `dst` möglicherweise nicht die ganze Länge
  verwendet werden muss.
- Testen Sie Ihre `copy_distinct`-Implementierung in der `main`-Funktion.
- Für das Array `{5, 2, 4, 5, 2}` gibt die Funktion den Wert `3` zurück und die ersten drei Werte im `dst`-Array müssen
  einem der folgenden Beispiele entsprechen:
    - `{2, 4, 5}`
    - `{2, 5, 4}`
    - `{4, 2, 5}`
    - `{4, 5, 2}`
    - `{5, 2, 4}`
    - `{5, 4, 2}`

# Aufgabe 2 (6 Punkte)

## Vorlesungsfolien

* Strukturen, Unions, Bitfelder (EidP-09-StrukturenUnionsBitfelder.pdf)

## Teilaufgabe a)

Definieren Sie die folgenden Strukturen.

1. Definieren Sie eine Struktur, welche eine Komponente vom Datentyp `unsigned short` und eine Komponente vom
   Datentyp `float` enthält.
2. Definieren Sie eine Struktur, welche eine Komponente vom Datentyp `unsigned` und eine Komponente vom Datentyp `int`
   enthält. Der `unsigned` Wert soll dabei 4 Bits und der `int` 2 Bits breit sein.
3. Definieren Sie eine Struktur, welche eine Komponente vom Datentyp `double` und eine anonyme `union`, die eine
   Komponente vom Datentyp `int`, eine Komponente vom Datentyp `float` und eine Komponente vom Datentyp `double`
   beinhaltet.
4. Definieren Sie eine mögliche Repräsentation einer [verketteten Liste](https://en.wikipedia.org/wiki/Linked_list),
   welche zur dynamischen Speicherung von Gleitkommazahlen mit doppelter Genauigkeit (`double`) verwendet werden kann.
   Erstellen Sie dafür eine Struktur `list`, welche eine Komponente namens `size` vom Datentyp `int` und eine
   Komponente `head` als Zeiger auf eine Struktur `node` enthält. Die Struktur `node` enthält eine Komponente `value`
   vom Datentyp `double` und eine Komponente `next` als Zeiger auf die Struktur `node`.

## Teilaufgabe b)

Gegeben sei folgendes Programm. Welchen Speicherbedarf erwarten Sie sich für die Strukturen `my_struct1`, `my_struct2`
und `my_struct3` basierend auf den verwendeten Datentypen der Elemente? Führen Sie anschließend das Programm aus.
Dokumentieren Sie Ihre Beobachtungen.

```c
#include <stdio.h>
#include <stdlib.h>

struct my_struct1 {
    float x;
    double y;
};

struct my_struct2 {
    float x;
    float y;
    double z;
};

struct my_struct3 {
    float x;
    double y;
    float z;
};

int main(void) {
    printf("size of my_struct1: %lu\n", sizeof(struct my_struct1));
    printf("size of my_struct2: %lu\n", sizeof(struct my_struct2));
    printf("size of my_struct3: %lu\n", sizeof(struct my_struct3));
    return EXIT_SUCCESS;
}

```

## Teilaufgabe c)

1. Was ist der minimale Speicherbedarf (in Byte) der Strukturen `my_struct1`, `my_struct2` und `my_struct3` basierend
   auf den verwendeten Datentypen?

   ```c
   struct my_struct1 {
       float a[4];
       char b[8];
       double c;
   };
   
   struct my_struct2 {
       int32_t a;
       double b;
       float c;
   };
   
   struct my_struct3 {
       int32_t a;
       struct my_struct4 {
           int64_t x;
           uint16_t y;
       };
       struct my_struct2 b;
   };
   ```

2. Was ist der minimale Speicherbedarf (in Byte) der Unions `my_union1`, `my_union2` und `my_union3` basierend auf den
   verwendeten Datentypen?

   ```c
   union my_union1 {
       float a[4];
       char b[8];
       double c;
   };
   
   union my_union2 {
       int32_t a;
       double b;
       float c;
   };
   
   union my_union3 {
       int32_t a;
       struct my_struct4 {
           int64_t x;
           uint16_t y;
       };
       struct my_struct2 b;
   };
   ```

3. Gegeben sei folgender Code.

   ```c
   #include <stdlib.h>
   
   struct tree_node {
       int value;
       struct tree_node *left;
       struct tree_node *right;
   };
   
   int main(void) {
       struct tree_node node1 = {5, NULL, NULL};
       struct tree_node node2 = {16, NULL, NULL};
       struct tree_node node3 = {10, &node1, &node2};
       struct tree_node *ptr = node3.left;
   
       // TODO: access member value of node1 via node1
   
       // TODO: access member value of node1 via node3
   
       // TODO: access member value of node1 via ptr
       // TODO: alternative syntax?
   
       return EXIT_SUCCESS;
   }
   
   ```

    - Wie kann auf den Wert `value` von `node1` über die Variable `node1` und `node3` zugegriffen werden?
    - Wie kann auf die Komponente `value` der Struktur `struct tree_node`  über den Zeiger `ptr` zugegriffen werden?
    - Gibt es für diese drei Zugriffe Alternativen?

# Aufgabe 3 (6 Punkte)

## Vorlesungsfolien

* Strukturen, Unions, Bitfelder (EidP-09-StrukturenUnionsBitfelder.pdf)

## Beschreibung

In dieser Aufgabe wird Funktionalität zum Sortieren und Ausgeben von Hörsälen implementiert. Führen Sie folgende
Arbeitsschritte aus.

### Arbeitsschritte

- Machen Sie sich mit der Struktur `lecture_hall_t` vertraut, welche mittels `typedef` deklariert wurde, um
  Eigenschaften von Hörsälen zu speichern. Ein Hörsaal hat einen Namen `name`, eine Größe `size` und Anzahl an
  Sitzplätzen `num_seats`. Es wird angenommen, dass der Hörsalname maximal $`64`$ Zeichen lang ist. Beachten Sie,
  dass die Struktur `lecture_hall_t` nicht verändert werden darf!
- Implementieren Sie eine Funktion `print_lecture_hall`, welche einen Zeiger auf einen Hörsaal als Parameter übergeben
  bekommt und den Hörsaal in einer Zeile auf der Standardausgabe ausgibt.
- Lesen Sie die [Manpage](https://en.wikipedia.org/wiki/Man_page) zu `qsort` und machen Sie sich mit der Funktion vertraut.
  Stellen Sie sicher, dass Sie jeden Parameter der Funktion `qsort` erklären können. Implementieren Sie anschließend
  folgende Vergleichsfunktionen, um ein Array von Hörsälen sortieren zu können:
    - `name_comparator`: Vergleicht den Namen von zwei Hörsälen lexikografisch.
    - `size_comparator`: Vergleicht die Größe von zwei Hörsälen numerisch.
    - `num_seats_comparator`: Vergleicht die Anzahl an Sitzplätzen in zwei Hörsälen numerisch.
    - `lecture_hall_comparator`: Vergleicht Hörsaaldaten numerisch nach der Anzahl an Sitzplätzen sowie Größe. Haben
      zwei Hörsäle die gleiche Anzahl an Sitzplätzen, wird zusätzlich die Größe herangezogen.
- Implementieren Sie mithilfe von `qsort` die Funktion mit der Signatur
  `void sort_lecture_halls(lecture_hall_t *lecture_halls, const size_t num_lecture_halls, int (*comparator)(const void *, const void *))`,
  welche ein Array `lecture_halls` mit der Länge `num_lecture_halls` unter Rückgriff auf dei Vergleichsfunktion `comparator` sortiert.
- Erstellen Sie in der `main`-Funktion ein Array mit den Daten von mindestens 4 Hörsälen und testen Sie Ihre
  `sort_lecture_halls`-Implementierung mit den vier unterschiedlichen Vergleichsfunktionen.

# Aufgabe 4 (5 Punkte)

## Vorlesungsfolien

* Strukturen, Unions, Bitfelder (EidP-09-StrukturenUnionsBitfelder.pdf)

## Beschreibung

Erstellen Sie ein Programm, welches für eine übergebene Gleitkommazahl
die [IEEE 754 double-precision](https://en.wikipedia.org/wiki/Double-precision_floating-point_format) Binärdarstellung
ausgibt. Die Gleitkommazahl wird als Kommandozeilenparameter übergeben, wobei eine gültige Gleitkommazahl folgende Teile
aufweist:

1. Optionales Plus- oder Minuszeichen
2. Eine nichtleere Folge von Dezimalziffern, welche optional einen Dezimalpunkt enthält
3. Optional ein `e` oder `E` mit einem optionalen Plus- oder Minuszeichen und einer nichtleeren Folge von Dezimalziffern

### Ablauf

- Der\*die Benutzer\*in übergibt als Kommandozeilenparameter eine Gleitkommazahl.
    - Wird kein Parameter übergeben, gibt das Programm den Text `"usage: ./s08e04 <double>"` auf der
      Standardfehlerausgabe `stderr` aus und terminiert mit dem Rückgabewert `EXIT_FAILURE`.
    - Sofern beim Konvertieren des Strings in eine Gleitkommazahl mit doppelter Genauigkeit (`double`) ein Fehler
      auftritt oder nicht der ganze Parameter in eine Zahl transformiert werden kann, wird die
      Fehlermeldung `"ERROR: <input> is not a valid double!\nExtracted double component: <extracted>\nRemaining: <remaining>"`
      auf der Standardfehlerausgabe `stderr` ausgegeben und das Programm terminiert mit dem Rückgabewert `EXIT_FAILURE`.
      Der Platzhalter `<input>` wird durch den Kommandozeilenparameter, `<extracted>` wird als Dezimalzahl mit sechs
      Nachkommastellen durch den Teil des Kommandozeilenparameters, der erfolgreich in eine Gleitkommazahl umgewandelt
      werden konnte, und `<remaining>` wird durch den restlichen Teil, welcher nicht mehr in eine Gleitkommazahl
      umgewandelt werden konnte, ersetzt.
- Der Text `"Number: <number>\nBinary representation:\n"` wird auf der Standardausgabe ausgegeben, wobei der
  Platzhalter `<number>` durch die Gleitkommazahl als Dezimalzahl in Exponentialdarstellung mit sechs Nachkommastellen,
  welche als Kommandozeilenparameter übergeben wurde, ersetzt wird.
- Die Komponenten Vorzeichen (`sign`), Exponent (`exponent`) und Mantisse (`mantissa`) der Gleitkommazahl werden
  berechnet und im Format `"   <sign> <exponent> <mantissa>\n"` mit drei Leerzeichen vor `sign` und jeweils einem
  Leerzeichen vor `exponent` und `mantissa` auf der Standardausgabe ausgegeben.
- Der Text `"sign    exponent                                             mantissa\n"` wird auf der Standardausgabe
  ausgegeben.
- Das Programm wird mit `EXIT_SUCCESS` beendet.

## Beispiele

Beispiel 1: Beispielaufruf mit `4.1` als Parameter und Programmablauf

```text
./s08e04 4.1
Number: 4.100000e+00
Binary representation:
   0 10000000001 0000011001100110011001100110011001100110011001100110
sign    exponent                                             mantissa

```

Beispiel 2: Beispielaufruf mit `-3.5` als Parameter und Programmablauf

```text
./s08e04 -3.5
Number: -3.500000e+00
Binary representation:
   1 10000000000 1100000000000000000000000000000000000000000000000000
sign    exponent                                             mantissa

```

Beispiel 3: Beispielaufruf mit `5a` als Parameter und Programmablauf

```text
./s08e04 5a
ERROR: 5a is not a valid double!
Extracted double component: 5.000000
Remaining: a

```

Beispiel 4: Beispielaufruf ohne Parameter und Programmablauf

```text
./s08e04 
usage: ./s08e04 <double>

```

Beispiel 5: Beispielaufruf mit `54e4` als Parameter und Programmablauf

```text
./s08e04 54e4
Number: 5.400000e+05
Binary representation:
   0 10000010010 0000011110101100000000000000000000000000000000000000
sign    exponent                                             mantissa

```

## Hinweise

- Sie können mithilfe von einer `union`, bestehend aus einer `double`- und einer `uint64_t`-Komponente, die
  Bitrepräsentation einer Gleitkommazahl mit doppelter Genauigkeit (`double`) ermitteln.
- Die Funktion [`strtod`](https://en.cppreference.com/w/c/string/byte/strtof) kann beim Umwandeln des übergebenen
  Parameters hilfreich sein.
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!

# Aufgabe 5 (8 Punkte)

## Vorlesungsfolien

* Arrays (EidP-07-Arrays.pdf)
* Zeiger (EidP-08-Zeiger.pdf)

## Beschreibung

Implementieren Sie eine Funktion mit der Signatur `int find_path(char grid[ROWS][COLS])`, welche für ein
Labyrinth `grid` einen Pfad von einem Start- zu einem Endpunkt sucht und markiert.

Testen Sie Ihre `find_path`-Implementierung in der `main` -Funktion mit einigen Beispielaufrufen.

### Details

Der Startpunkt wird im Labyrinth `grid` mit `'S'` und der Endpunkt mit `'E'` markiert. Freie Positionen sind durch
Leerzeichen (`' '`) gekennzeichnet. Alle anderen Zeichen stellen Wände bzw. Hindernisse dar. Ein Schritt von einem Feld
zu einem anderen kann nur zu einem der vier direkt benachbarten Felder nördlich, östlich, südlich oder westlich
erfolgen. Dementsprechend kann ausgehend vom Feld `grid[r][c]` entweder `grid[r + 1][c]`, `grid[r][c + 1]`
, `grid[r - 1][c]` oder `grid[r][c - 1]` besucht werden, sofern die Labyrinthgrenzen – d. h.
$`0 \le \mathtt{r} < \mathtt{ROWS}`$ und $`0 \le \mathtt{c} < \mathtt{COLS}-1`$ – nicht über- oder unterschritten werden
und die entsprechende Position frei ist. Jedes freie Feld darf maximal einmal besucht werden.

Sofern ein Weg gefunden wird, markiert die Funktion alle Schritte zwischen `'S'` und `'E'` mit dem Zeichen `'O'` im
Labyrinth `grid` und gibt den Wert `1` zurück. Wird kein Pfad vom Start- zum Endpunkt gefunden, retourniert die Funktion
lediglich den Wert `0` ohne einen Pfad einzuzeichnen.

Für das Suchen eines Pfades bietet sich die Problemlösungsmethode
namens [Backtracking](https://en.wikipedia.org/wiki/Backtracking) an, wobei ausgehend vom Startpunkt versucht wird
rekursiv einen gültigen Pfad aufzubauen, indem eine Folge von Schritten durchgeführt wird, bis entweder der Endpunkt
erreicht wurde oder alle möglichen Pfade überprüft wurden. Basierend auf dieser Idee kann folgender Algorithmus als
Grundlage verwendet werden:

> 1. Ist die Position außerhalb der Labyrinthgrenzen – d. h. $`\mathtt{r} \notin \{0, 1, \dots, \mathtt{ROWS}-1\}`$ oder
     $`\mathtt{c} \notin \{0, 1, \dots, \mathtt{COLS}-2\}`$ –, ist der Pfad nicht gültig.
> 2. Wird der Endpunkt erreicht, kann die Rekursion erfolgreich beendet werden.
> 3. Ist die aktuelle Position nicht frei, ist der Pfad nicht gültig.
> 4. Die aktuelle Position wird als besucht, markiert.
> 5. Wenn der Pfad in einer Sackgasse ist, da alle vier direkt benachbarten Felder - wie mithilfe von rekursiven Aufrufen
     festgestellt - zu keinem gültigen Pfad führen, wird diese Position wieder als frei markiert und es muss bis zu
     der Stelle zurückgekehrt werden, bei welcher eine alternative Auswahl getroffen werden kann (backtracking). Wurden
     alle möglichen Pfade überprüft und es konnte kein gültiger Pfad gefunden werden, gibt es keine Lösung.

### Hinweise

- Es ist immer genau ein Start- und ein Endpunkt vorhanden!
- Die Makros `ROWS` und `COLS` sind in der Datei `s08e05.c` bereits definiert und dürfen nicht verändert werden!
- Die folgende Funktion, die auch bei den nachfolgenden Beispielen genutzt wurde, kann für die Ausgabe des Labyrinths
  verwendet werden:
  ```c
  void print_grid(char grid[ROWS][COLS]) {
      for (int r = 0; r < ROWS; r++) {
          for (int c = 0; c < COLS - 1; c++) {
              printf("%c ", grid[r][c]);
          }
          putchar('\n');
      }
  }
  ```

### Beispiele

Beispiel 1: Gegeben sei das folgende Array `grid1`.

```c
char grid1[ROWS][COLS] = {
        "+++++++++++++++++++++++++++++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++",
        "|                                       |",
        "|                +-----+                |",
        "++++++++++++++   |    S|   ++++++++++++++",
        "++++++++++++++   |     |   ++++++++++++++",
        "++++++++++++++   |E    |   ++++++++++++++",
        "++++++++++++++   +-----+   ++++++++++++++",
        "++++++++++++++             ++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++"
};
```

Wird die Funktion `find_path` mit dem Array `grid1` aufgerufen, gibt die Funktion den Wert `1` zurück und markiert den
Pfad in `grid1` entsprechend.

```c
print_grid(grid1);
printf("\nsolution found: %s\n", find_path(grid1) ? "yes" : "no");
print_grid(grid1);
```

Folgende Ausgabe zeigt einen möglichen Pfad, welcher durch das vorherige Codefragment markiert wurde.

```text
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
|                                                                               | 
|                                 + - - - - - +                                 | 
+ + + + + + + + + + + + + +       |         S |       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +       |           |       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +       | E         |       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +       + - - - - - +       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +                           + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 

solution found: yes
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
|                                                                               | 
|                                 + - - - - - +                                 | 
+ + + + + + + + + + + + + +       | O O O O S |       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +       | O         |       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +       | E         |       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +       + - - - - - +       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +                           + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
```

Nachfolgende Ausgabe zeigt eine weitere Alternative.

```text
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
|                                                                               | 
|                                 + - - - - - +                                 | 
+ + + + + + + + + + + + + +       |         S |       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +       |           |       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +       | E         |       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +       + - - - - - +       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +                           + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 

solution found: yes
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
|                                                                               | 
|                                 + - - - - - +                                 | 
+ + + + + + + + + + + + + +       | O O O O S |       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +       | O O O O O |       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +       | E O O O O |       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +       + - - - - - +       + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + +                           + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 
```

Beispiel 2: Gegeben sei das folgende Array `grid2`.

```c
char grid2[ROWS][COLS] = {
      "+-------------+-+---+-------------+-----+",
      "|             | |S  |             |     |",
      "| +-----+---+ | + + | +-----+ +-+ +-+ +-+",
      "|       |   | |   | | |     | | |   |   |",
      "| +---+ | + | | +-+ + + +---+ | +-+ +-+ |",
      "| |   | | | | |   |     |     |   |     |",
      "+-+ + | | | | +---+-----+ +---+-+ +-+-+ |",
      "|   | | | | |     |       |       | |   |",
      "| +-+ + | | +---+ + +-----+-+ +-+ + | +-+",
      "|   |   | | |   |   |         | |   |   |",
      "+-+ +---+ +-+ + +-+-+ + +-+---+ +-+ +-+ |",
      "| | | |       |   |   |   |         |   |",
      "| + | | +-----+ + | +-+-+ | +---+---+ +-+",
      "|   | | |     | | | |     |     |   |   |",
      "+-+-+ | +---+ | | +-+ +---+---+ | + +-+ |",
      "| |   |       | |     |         | |   | |",
      "| + + +-----+ | | +---+-------+-+ | + | |",
      "|   |       | | | |           |   | | | |",
      "| +-+ +-----+ | +-+ +-------+ + +-+ +-+ |",
      "|   |         |     E       |     |     |",
      "+---+---------+-------------+-----+-----+"
};
```

Wird die Funktion `find_path` mit dem Array `grid2` aufgerufen, gibt die Funktion den Wert `1` zurück und markiert den
Pfad in `grid2` entsprechend.

```c
print_grid(grid2);
printf("\nsolution found: %s\n", find_path(grid2) ? "yes" : "no");
print_grid(grid2);
```

Folgende Ausgabe zeigt einen möglichen Pfad, welcher durch das vorherige Codefragment markiert wurde.

```text
+ - - - - - - - - - - - - - + - + - - - + - - - - - - - - - - - - - + - - - - - + 
|                           |   | S     |                           |           | 
|   + - - - - - + - - - +   |   +   +   |   + - - - - - +   + - +   + - +   + - + 
|               |       |   |       |   |   |           |   |   |       |       | 
|   + - - - +   |   +   |   |   + - +   +   +   + - - - +   |   + - +   + - +   | 
|   |       |   |   |   |   |       |           |           |       |           | 
+ - +   +   |   |   |   |   + - - - + - - - - - +   + - - - + - +   + - + - +   | 
|       |   |   |   |   |           |               |               |   |       | 
|   + - +   +   |   |   + - - - +   +   + - - - - - + - +   + - +   +   |   + - + 
|       |       |   |   |       |       |                   |   |       |       | 
+ - +   + - - - +   + - +   +   + - + - +   +   + - + - - - +   + - +   + - +   | 
|   |   |   |               |       |       |       |                   |       | 
|   +   |   |   + - - - - - +   +   |   + - + - +   |   + - - - + - - - +   + - + 
|       |   |   |           |   |   |   |           |           |       |       | 
+ - + - +   |   + - - - +   |   |   + - +   + - - - + - - - +   |   +   + - +   | 
|   |       |               |   |           |                   |   |       |   | 
|   +   +   + - - - - - +   |   |   + - - - + - - - - - - - + - +   |   +   |   | 
|       |               |   |   |   |                       |       |   |   |   | 
|   + - +   + - - - - - +   |   + - +   + - - - - - - - +   +   + - +   + - +   | 
|       |                   |           E               |           |           | 
+ - - - + - - - - - - - - - + - - - - - - - - - - - - - + - - - - - + - - - - - + 

solution found: yes
+ - - - - - - - - - - - - - + - + - - - + - - - - - - - - - - - - - + - - - - - + 
|                           |   | S O O | O O O O O O O O O O O O O |           | 
|   + - - - - - + - - - +   |   +   + O | O + - - - - - +   + - + O + - +   + - + 
|               |       |   |       | O | O |           |   |   | O O O |       | 
|   + - - - +   |   +   |   |   + - + O + O +   + - - - +   |   + - + O + - +   | 
|   |       |   |   |   |   |       | O O O     |           |       | O O O O O | 
+ - +   +   |   |   |   |   + - - - + - - - - - +   + - - - + - +   + - + - + O | 
|       |   |   |   |   |           |               |               |   | O O O | 
|   + - +   +   |   |   + - - - +   +   + - - - - - + - +   + - +   +   | O + - + 
|       |       |   |   |       |       |                   |   |       | O O O | 
+ - +   + - - - +   + - +   +   + - + - +   +   + - + - - - +   + - +   + - + O | 
|   |   |   |               |       |       |       |                   | O O O | 
|   +   |   |   + - - - - - +   +   |   + - + - +   |   + - - - + - - - + O + - + 
|       |   |   |           |   |   |   |           |           | O O O | O O O | 
+ - + - +   |   + - - - +   |   |   + - +   + - - - + - - - +   | O + O + - + O | 
|   |       |               |   |           |                   | O | O     | O | 
|   +   +   + - - - - - +   |   |   + - - - + - - - - - - - + - + O | O +   | O | 
|       |               |   |   |   | O O O O O O O O O O O | O O O | O |   | O | 
|   + - +   + - - - - - +   |   + - + O + - - - - - - - + O + O + - + O + - + O | 
|       |                   |         O E               | O O O     | O O O O O | 
+ - - - + - - - - - - - - - + - - - - - - - - - - - - - + - - - - - + - - - - - + 
```

Beispiel 3: Gegeben sei das folgende Array `grid3`.

```c
char grid3[ROWS][COLS] = {
        "+-+-----------------+-------------------+",
        "|S|                 |                   |",
        "+-+                 |                   |",
        "|                   |                   |",
        "|                   |                   |",
        "|                   |                   |",
        "|                   |                   |",
        "|                   |                   |",
        "|                   |                   |",
        "|                   |                   |",
        "+-------------------+-------------------+",
        "|                   |                   |",
        "|                   |                   |",
        "|                   |                   |",
        "|                   |                   |",
        "|                   |                   |",
        "|                   |                   |",
        "|                   |                   |",
        "|                   |                 +-+",
        "|                   |                 |E|",
        "+-------------------+-----------------+-+",
};
```

Wird die Funktion `find_path` mit dem Array `grid3` aufgerufen, gibt die Funktion den Wert `0`.

```c
print_grid(grid3);
printf("\nsolution found: %s\n", find_path(grid3) ? "yes" : "no");
print_grid(grid3);
```

Der Text in der folgenden Box zeigt die Ausgabe, welcher durch das vorherige Codefragment erzeugt wird.

```text
+ - + - - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - - - - + 
| S |                                   |                                       | 
+ - +                                   |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
+ - - - - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - - - - + 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                   + - + 
|                                       |                                   | E | 
+ - - - - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - - + - + 

solution found: no
+ - + - - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - - - - + 
| S |                                   |                                       | 
+ - +                                   |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
+ - - - - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - - - - + 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                       | 
|                                       |                                   + - + 
|                                       |                                   | E | 
+ - - - - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - - + - + 
```
