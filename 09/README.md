# Aufgabe 1 (4 Punkte)

## Vorlesungsfolien

* Präprozessor (EidP-12-Praeprozessor.pdf)

## Beschreibung

Es sind folgende Makros gegeben.

```c
#define ARRAY_SIZE BUFFER_SIZE
#define BUFFER_SIZE DIMENSION * DIMENSION
#define DIMENSION 4

#define MIN(x, y) ((x) <= (y) ? (x) : (y))

#define POW2(x) x * x

#define MY_PRINT(n) printf("var" #n " = %d\n", var##n)

#define DEBUG 1

#define DEBUG_PRINT(...) printf("DEBUG: " __VA_ARGS__)
```

Geben Sie an, wie die folgenden Codeausschnitte nach dem Präprozessordurchlauf aussehen und beantworten Sie
zusätzlich die gestellten Fragen.

### Codeausschnitt 1

```c
char *array = malloc(ARRAY_SIZE * sizeof(*array));
```

### Codeausschnitt 2

```c
short a = 3;
printf("%d\n", MIN(MIN(a, '2'), 5));
printf("%f\n", MIN(4.0, 1.0));
```

- Was wird durch diesen Codeausschnitt auf der Standardausgabe ausgegeben?
- Kann das Makro `MIN` mit einer Funktion `min` mit Signatur `float min(float x, float y)` ersetzt werden, ohne
  sonstige Änderungen im Codeausschnitt durchzuführen?

### Codeausschnitt 3

```c
printf("%d\n", POW2(2 + 2));
```

- Was wird durch diesen Codeausschnitt auf der Standardausgabe ausgegeben?

### Codeausschnitt 4

```c
int var60 = 50;
int var50 = 60;
MY_PRINT(60);
```

- Was bewirken die Präprozessor-Operatoren `#` und `##`?
- Was wird durch diesen Codeausschnitt auf der Standardausgabe ausgegeben?

### Codeausschnitt 5

```c
#ifdef DEBUG
    printf("My debug messages\n");
#endif
```

- Was wird durch diesen Codeausschnitt auf der Standardausgabe ausgegeben, wenn `DEBUG` definiert ist?
- Was wird durch diesen Codeausschnitt auf der Standardausgabe ausgegeben, wenn `DEBUG` nicht definiert ist?

### Codeausschnitt 6

```c
int x = 12;
int y = 61;
DEBUG_PRINT("x = %d, y = %d\n", x, y);
```

- Was ist ein variadisches Makro?

# Aufgabe 2 (4 Punkte)

## Vorlesungsfolien

* Präprozessor (EidP-12-Praeprozessor.pdf)

## Beschreibung

Im Programmcode `s09e02.c` werden verschiedene symbolische Konstanten und Makros vorausgesetzt. Implementieren Sie diese
mithilfe von Präprozessor-Direktiven entsprechend den folgenden Vorgaben.

- Die Konstante `MY_VALUE` steht für den Wert `1`, sofern `DEBUG` definiert ist, ansonsten ist ihr Wert `10`.
- Die Konstante `MY_TRUE` steht für den Wert `1`.
- Die Konstante `MY_FALSE` steht für den Wert `0`.
- Das Makro `MY_ASSERT` erwartet einen booleschen Ausdruck und einen Text. Im Makro wird der boolesche Ausdruck
  überprüft. Sofern dieser wahr ist, wird der Text ausgegeben und das Programm mit `EXIT_FAILURE` beendet.
- Das Makro `COND_TO_STR` erwartet einen booleschen Ausdruck. Sofern dieser nicht wahr ist, evaluiert das
  Makro zu `"false"`. Ansonsten evaluiert es zu `"true"`.
- Das Makro `PRINT_COND` erwartet einen booleschen Ausdruck und gibt den booleschen Ausdruck sowie das Ergebnis des
  Ausdrucks mithilfe von `COND_TO_STR` aus. Für `COND_TO_STR(MY_TRUE)` wird beispielsweise
  `'MY_TRUE' evaluates to 'true'` auf der Standardausgabe ausgegeben.
- Das Makro `PRINT_DEBUG` soll nur Text ausgeben, wenn die Konstante `DEBUG` definiert ist.
- Das Makro `PRINT_STATUS` gibt die aktuelle Datei, Zeilennummer, Funktion sowie eine Nachricht aus. Für die Datei,
  Zeilennummer und Funktion sollen vordefinierte Makros herangezogen werden. Das Makro soll nur Text ausgeben, wenn die
  Konstante `DEBUG` gesetzt ist und den Wert `3` hat.


## Beispiele

Verwenden Sie zum Testen verschiedene Kompileraufrufe, um den Wert der Konstante `DEBUG` beim Kompilieren zu setzten:
- `s09e02`: Kompiliert `s09e02.c` mit den Flags `-Wall -Werror -Wextra -Wpedantic -std=c18`
- `s09e02_D`: Kompiliert `s09e02.c` mit den Flags `-Wall -Werror -Wextra -Wpedantic -std=c18` und definiert bei
  Compileraufruf zusätzlich das Flag `DEBUG`
- `s09e02_D3`: Kompiliert `s09e02.c` mit den Flags `-Wall -Werror -Wextra -Wpedantic -std=c18` und definiert bei
  Compileraufruf zusätzlich das Flag `DEBUG=3`

### Kompilieren & Ausgabe von `s09e02`

Kompileraufruf:

```shell
gcc -Wall -Werror -Wextra -Wpedantic -std=c18 s09e02.c -o s09e02
```

Erwartete Ausgabe:

```text
'MY_TRUE' evaluates to 'true'
'MY_FALSE' evaluates to 'false'
'y < x' evaluates to 'true'
'12 + 34 / 12 > 0' evaluates to 'true'
stop program, y < x.
```

### Kompilieren & Ausgabe von `s09e02_D`

Kompileraufruf:

```shell
gcc -Wall -Werror -Wextra -Wpedantic -std=c18 -D DEBUG s09e02.c -o s09e02_D
```

Erwartete Ausgabe:

```text
x: 1
y: 5
'MY_TRUE' evaluates to 'true'
'MY_FALSE' evaluates to 'false'
'y < x' evaluates to 'false'
'12 + 34 / 12 > 0' evaluates to 'true'
```

### Kompilieren & Ausgabe von `s09e02_D3`

Kompileraufruf:

```shell
gcc -Wall -Werror -Wextra -Wpedantic -std=c18 -D DEBUG=3 s09e02.c -o s09e02_D3
```

Erwartete Ausgabe:

```text
s09e02.c:42 | function: main | message: program start!
x: 1
y: 5
s09e02.c:47 | function: main | message: before first assertion
'MY_TRUE' evaluates to 'true'
'MY_FALSE' evaluates to 'false'
'y < x' evaluates to 'false'
'12 + 34 / 12 > 0' evaluates to 'true'
s09e02.c:55 | function: main | message: before second assertion
s09e02.c:58 | function: main | message: program end
```

## Hinweise

- Die Zeilennummern in Ihrer Abgabe können abweichen.

# Aufgabe 3 (6 Punkte)

## Vorlesungsfolien

* Strukturen, Unions, Bitfelder (EidP-09-StrukturenUnionsBitfelder.pdf)
* Dynamische Speicherverwaltung (EidP-11-DynamischeSpeicherverwaltung.pdf)

## Beschreibung

In dieser Aufgabe sollen Funktionen für das Generieren, Ausgeben und Freigeben des Speichers für einen Teil des
[Pascalschen Dreiecks](https://en.wikipedia.org/wiki/Pascal%27s_triangle) implementiert werden. Das Pascalsche Dreieck
ist eine grafische Darstellung der Binomialkoeffizienten $`n\choose k`$ mit $`n\in\mathbb{N}_{\ge0}`$ als Zeilenindex
und $`k\in\mathbb{N}_{\ge0}`$ als Spaltenindex: Jeder Eintrag entsteht durch die Summe der zwei darüberstehenden
Einträge, wobei Randeinträge, welche nicht zwei direkt darüberstehende Einträge haben, gleich $`1`$ gesetzt werden.

Die folgende Veranschaulichung zeigt ein Pascalsches Dreieck mit $`5`$ Zeilen.

```text
        1
      1   1
    1   2   1
  1   3   3   1
1   4   6   4   1 
```

Die Struktur `struct pascals_triangle` wird verwendet, um ein Pascalsches Dreieck einer bestimmten Zeilenanzahl
abzubilden, sodass die Einträge des Pascalschen Dreiecks im dynamisch allozierten, nicht-rechteckigen, zweidimensionalen
Array `values` der Struktur `struct pascals_triangle` gespeichert werden können. Der Pointer `values` zeigt auf einen
Speicher, welcher Zeiger für jede einzelne Zeile des Pascalschen Dreiecks beinhaltetet. Jeder Zeiger einer Zeile zeigt
auf einen Speicherbereich, welcher genau die Anzahl der Werte von dieser Zeile speichern kann.

Implementieren Sie folgende Funktionen:

- `init_pascals_triangle`: Reserviert Speicher für die Struktur `struct pascals_triangle` und für die Werte des
  Pascalschen Dreiecks entsprechend der übergebenen Zeilenanzahl `rows`. Anschließend wird das Element `rows` der
  Struktur auf den übergebenen Wert gesetzt und die Werte des Pascalschen Dreiecks berechnet.
- `get_element`: Retourniert den Wert des Eintrags in der Zeile `row` und Spalte `column` des zweidimensionalen Arrays
  `values`, d. h. des Pascalschen Dreiecks. Sofern der Wert für `row` oder `column` die Grenzen überschreitet, wird der
  Wert $`0`$ zurückgegeben.
- `free_pascals_triangle`: Gibt den reservierten Speicher für die Struktur `struct pascals_triangle` und damit die
  Einträge des Pascalschen Dreiecks frei.
- `print_pascals_triangle`: Gibt die Einträge des Pascalschen Dreiecks auf der Standardausgabe aus. Das Format der
  Ausgabe ist nicht vorgegeben.
- `main`: Vervollständigen Sie die `main`-Funktion mithilfe der zuvor implementierten Funktionen, sodass das Programm
  Speicher für ein Pascalsches Dreieck mit Zeilenanzahl `rows` reserviert, die Einträge berechnet, diese auf der
  Standardausgabe ausgibt und anschließend den Speicher für das Pascalsche Dreieck wieder freigibt. Die
  Zeilenanzahl `rows` wird als Kommandozeilenparameter übergeben.

### Beispielaufrufe mit Ausgabe:

Beispiel 1: Beispielaufruf mit Zeilenanzahl `4` als Kommandozeilenparameter und Programmablauf.

```text
./s09e03 4
    1
   1 1
  1 2 1
 1 3 3 1
```

Beispiel 2: Beispielaufruf mit Zeilenanzahl `9` als Kommandozeilenparameter und Programmablauf.

```text
./s09e03 9
                   1
                 1   1
               1   2   1
             1   3   3   1
           1   4   6   4   1
         1   5  10  10   5   1
       1   6  15  20  15   6   1
     1   7  21  35  35  21   7   1
   1   8  28  56  70  56  28   8   1
```

Beispiel 3: Beispielaufruf mit Zeilenanzahl `10` als Kommandozeilenparameter und Programmablauf.

```text
./s09e03 10
                     1
                   1   1
                 1   2   1
               1   3   3   1
             1   4   6   4   1
           1   5  10  10   5   1
         1   6  15  20  15   6   1
       1   7  21  35  35  21   7   1
     1   8  28  56  70  56  28   8   1
   1   9  36  84 126 126  84  36   9   1
```

## Hinweise

- Sie können für die Ausgabe des Pascalsches Dreiecks mit einer bestimmten Zeilenanzahl ein Format frei wählen. Die
  Beispiele zeigen eine gängige, mögliche Darstellung.

# Aufgabe 4 (8 Punkte)

## Vorlesungsfolien

* Strukturen, Unions, Bitfelder (EidP-09-StrukturenUnionsBitfelder.pdf)
* Dynamische Speicherverwaltung (EidP-11-DynamischeSpeicherverwaltung.pdf)

## Beschreibung

Implementieren Sie eine auf Arrays basierte generische Liste. Der für die Liste reservierte Speicher soll je nach Bedarf
dynamisch vergrößert bzw. verkleinert werden.

In der Datei `s09e04.c` ist die Struktur `my_list`, welche als Datentyp für die generische Liste verwendet wird, wie
folgt deklariert:

```c
typedef struct list {
    void **items;    // array of pointers to list items
    size_t capacity; // maximum possible size for currently allocated memory
    size_t size;     // current size of the list
} my_list;
```

Die Komponenten der Struktur `my_list` werden wie folgt verwendet:

- Die Komponente `items` zeigt auf einen Speicherbereich in welchem die Listenelemente gespeichert werden.
- Die aktuelle Kapazität der Liste, d. h. wie viele Listenelemente momentan maximal in der Liste gespeichert werden
  können, wird durch die Komponente `capacity` festgehalten.
- Die Anzahl der Elemente in der Liste wird durch die Komponente `size` gespeichert.

### Arbeitsschritte

Implementieren Sie die folgenden Funktionen:

- `my_list_init`: Reserviert Speicher für eine neue Liste vom Datentyp `my_list` mit ausreichend Speicherplatz für
  `ARRAY_INIT_CAPACITY` Elemente und gibt einen Zeiger auf diese Liste zurück.
- `my_list_size`: Gibt die Anzahl der Elemente in der übergebenen `my_list`-Liste zurück.
- `my_list_insert`: Fügt das Element `item` an Position `idx` der übergebenen `my_list`-Liste ein und verschiebt alle
  nachfolgenden Elemente um eine Position nach hinten, sofern die Position `idx` gültig ist. Eine Position ist
  für `my_list_insert` gültig, wenn sie zwischen $`0`$ und $`\mathtt{size}`$ (jeweils inklusive), d. h.
  $`0 \le \mathtt{idx} \le \mathtt{size}`$, liegt. Wurde das Element eingefügt retourniert die Funktion `0`, in jedem
  anderen Fall `-1`. Sollte der momentan für die Listenelemente reservierte Speicher nicht ausreichen, um das neue
  Element einzufügen, wird der für die Listenelemente reservierte Speicher verdoppelt und das Element anschließend an
  der übergebenen Position `idx`
  eingefügt.
- `my_list_append`: Fügt das neue Element `item` hinter dem aktuell letzten Element, d. h. dem Element mit größtem
  Index, in die Liste ein. Wurde das Element eingefügt retourniert die Funktion `0`, in jedem anderen Fall `-1`. Sollte
  der momentan für die Listenelemente reservierte Speicher nicht ausreichen, um das neue Element einzufügen, wird der
  für die Listenelemente reservierte Speicher verdoppelt und das Element anschließend an der übergebenen Position `idx`
  eingefügt.
- `my_list_get`: Gibt das Element an der Position `idx` zurück, sofern die Position gültig, d. h.
  $`0 \le \mathtt{idx} < \mathtt{size}`$, ist. In jedem anderen Fall – d. h. bei Zugriff auf eine ungültige
  Position `idx` – retourniert die Funktion `NULL`.
- `my_list_delete`: Löscht das Element an Position `idx` aus der übergebenen Liste, gibt das Element, welches an der
  gelöschten Position stand zurück und verschiebt alle nachfolgenden Elemente um eine Position nach vorne. Sofern der
  nach dem Löschen von Listenelementen belegte Speicher ein Viertel der maximalen Listengröße unterschreitet, wird der
  für die Listenelemente reservierte Speicher halbiert. Unabhängig von der Größe des durch die Elemente der Liste vom
  Datentyp
  `my_list` belegten Speichers darf die minimale Kapazität `ARRAY_INIT_CAPACITY` nicht unterschritten werden.
- `my_list_free`: Gibt den gesamten Speicher, welcher für die verkettete Liste reserviert wurde, wieder frei.

Testen Sie die Funktionalität der von Ihnen implementierten Funktionen in der `main` Funktion mit einigen
Beispielaufrufen.

### Hinweise

- Überlegen Sie wie sich die Funktionen verhalten sollen, wenn `NULL`-Pointer als Parameter übergeben werden oder andere
  Spezialfälle auftreten.
- Die Datenstrukturen sollten unter keinen Umständen Debug-Information ausgeben.
- Testen Sie mit `valgrind` ob jeglicher von den von Ihnen implementierten Funktionen allozierter Speicher wieder
  freigegeben wird.
- Bitte verwenden Sie den bereitgestellten Quellcode als Vorlage und ändern Sie die darin enthaltenen
  Funktionssignaturen sowie die Typdefinitionen nicht.

# Aufgabe 5 (8 Punkte)

## Vorlesungsfolien

* Strukturen, Unions, Bitfelder (EidP-09-StrukturenUnionsBitfelder.pdf)
* Dynamische Speicherverwaltung (EidP-11-DynamischeSpeicherverwaltung.pdf)
* Modulare Programmierung in C (EidP-13-ModulareProgrammierung.pdf)

## Beschreibung

In dieser Aufgabe werden vorzeichenlose Ganzzahlen in verlinkte Listen umgewandelt, wobei die einzelnen Knoten der Liste den Ziffern der Zahlen von rechts nach links gelesen entsprechen. Dazu wird Ihnen das Modul `uint_list` mit den folgenden Funktionen zur Verfügung gestellt:

- `uint_to_linked_list` speichert wie oben beschrieben die einzelnen Ziffern einer übergebenen positiven Ganzzahl (inklusive 0) in
einer verketteten Liste. Ausgehend vom Startknoten der List weisen die Werte der Knoten die Ziffern der Zahl von rechts nach links gelesen auf.
- `print_uint_list` gibt die Liste als Zahl auf der Konsole aus, normal von links nach rechts gelesen
- `free_uint_list` gibt den Speicher, welcher für die verkettete Liste reserviert wurde wieder frei.

Implementieren Sie nun im Modul `uint_list_util` folgende Funktionen:

- `size_t number_of_digits(uint_list_t *list)`: Gibt die Anzahl der Ziffern der Zahl, welche durch die verkettete Liste `list` repräsentiert wird, zurück.
- `unsigned long long digit_sum(uint_list_t *list)`: Gibt die Ziffernsumme der Zahl, welche durch die verkettete Liste `list`
  repräsentiert wird, zurück.
- `unsigned char highest_digit(uint_list_t *list)`: Gibt die größte Ziffer der Zahl, welche durch die verkettete
  Liste `list` repräsentiert wird, zurück.
- `uint_list_t *add(uint_list_t *list_a, uint_list_t *list_b)`: Addiert die zwei Zahlen, welche durch die zwei verketteten Listen `list_a` und `list_b` repräsentiert werden und gibt das Ergebnis als neue verkettete
  Liste zurück. Beachten Sie, dass die Wertebereiche der dargestellten Zahlen desjenigen von `unsigned long long` übersteigen können und somit keine reguläre Addition zur Berechnung möglich ist. Implementieren Sie stattdessen einen Algorithmus, der der schriftlichen Addition, wie sie in der Volksschule gelehrt wird, entspricht. Die Reihenfolge der Knoten (Ziffern rechts nach links) sollte Ihnen dabei zugutekommen.

Vervollständigen Sie schlussendlich zum Testen Ihrer Implementierung die Funktion `void test_list(unsigned long long a, unsigned long long b)` in der Datei `s09e05.c`. Die Funktion führt folgende Schritte durch:
1. Erzeugen einer Liste der Zahl `a`
2. Ausgabe von `number of digits: <Anzahl der Ziffern von a>`
3. Ausgabe von `digit sum: <Ziffernsumme der Zahl a>`
4. Ausgabe von `highest digit: <höchste Ziffer von a>`
5. Erzeugen einer Liste der Zahl `b`
6. Berechnung von `a+b` mit der Funktion `add`
7. Ausgabe von `a+b = <Summe von a und b>`

Die Ausgabe wird in Artemis nicht überprüft, d.h. Sie können diese gerne entsprechend anpassen, solange die gewünschte Funktionalität erhalten bleibt.

Stellen Sie sicher, dass Sie allen Dateien benötigte Header-Dateien entsprechend inkludieren.

## Beispiele `number_of_digits`, `digit_sum`, `highest_digit`

<table>
<thead>
  <tr>
    <th rowspan="2">Zahl repräsentiert durch die verkettete Liste <code>list_a</code></th>
    <th colspan="3">Rückgabewert</th>
  </tr>
  <tr>
    <th><code>number_of_digits(list_a)</code></th>
    <th><code>digit_sum(list_a)</code></th>
    <th><code>highest_digit(list_a)</code></th>
  </tr>
</thead>
<tbody>
  <tr>
    <td align="right">10</td>
    <td align="right">2</td>
    <td align="right">1</td>
    <td align="right">1</td>
  </tr>
  <tr>
    <td align="right">12345</td>
    <td align="right">5</td>
    <td align="right">15</td>
    <td align="right">5</td>
  </tr>
</tbody>
</table>

## Beispiele `add`

| Zahl repräsentiert durch `list_a` | Zahl repräsentiert durch `list_b` | Zahl repräsentiert durch die resultierende verkettet Liste |
|----------------------------------:|----------------------------------:|-----------------------------------------------------------:|
|                                 0 |                                11 |                                                         11 |
|                               999 |                                 1 |                                                       1000 |

## Beispiele `test_list`

Ausgabe durch `test_list(25, 17)`:
```
number of digits: 2
digit sum: 7
highest digit: 5
25 + 17 = 42
```

Ausgabe durch `test_list(987, 14)`:
```
number of digits: 3
digit sum: 24
highest digit: 9
987 + 14 = 1001
```

## Hinweise

- Die übergebenen verketteten Listen dürfen nicht verändert werden.
- Zum Arbeiten mit Modulen / Header-Dateien bieten alle gängigen IDE's wie Visual Studio Code oder CLion entsprechende Unterstützung an. Informieren Sie sich darüber und versuchen Sie, das Projekt in Ihrer Umgebung laufen zu lassen.
- Sie sollten zusätzlich auch in der Lage sein, das Programm auf der Konsole mittels `gcc` zu kompilieren und anschließend auszuführen.
