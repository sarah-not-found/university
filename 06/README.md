# Aufgabe 1 (5 Punkte)

## Vorlesungsfolien

* Arrays (EidP-07-Arrays.pdf)

## Beschreibung

Implementieren Sie eine Funktion mit der Signatur `void reverse(int values[], size_t length)`, welche die Reihenfolge
der Elemente eines Arrays umkehrt.

Testen Sie Ihre `reverse`-Implementierung in der `main`-Funktion mit einigen Beispielaufrufen.

## Beispiele

|         `values` | `length` | `values` nach dem Aufruf von `reverse(values, length)` |
|-----------------:|---------:|-------------------------------------------------------:|
|        {1, 2, 3} |        3 |                                              {3, 2, 1} |
|   {4, 7, 10, -1} |        4 |                                         {-1, 10, 7, 4} |

# Aufgabe 2 (6 Punkte)

## Vorlesungsfolien

* Arrays (EidP-07-Arrays.pdf)

## Beschreibung

Implementieren Sie eine Funktion mit der Signatur `unsigned max_difference(int values[], size_t length)`, welche die
maximale Differenz zwischen zwei Werten des Arrays `max_difference` zurückgibt.

Erklären Sie mithilfe von Kommentaren, warum als Rückgabetyp der Funktion `unsigned` und nicht `int` verwendet wurde.

Testen Sie Ihre Funktion in der `main` -Funktion mit einigen Beispielaufrufen.

## Beispiele

|           values |  length | `max_difference(values, length)` |
|-----------------:|--------:|---------------------------------:|
|               {} |       0 |                                0 |
|              {1} |       1 |                                0 |
|       {1, 3, -5} |       3 |                                8 |
| {10, 2, -5, -60} |       4 |                               70 |

# Aufgabe 3 (5 Punkte)

## Vorlesungsfolien

* Arrays (EidP-07-Arrays.pdf)

## Beschreibung

Implementieren Sie eine Funktion mit der Signatur `size_t count_number_of_letters(char text[])`, welche die Anzahl der
(Klein- sowie Groß-)Buchstaben des [lateinischen Alphabets](https://en.wikipedia.org/wiki/Latin_alphabet), d. h. „a“,
„b“, …, „z“, „A“, „B“, …, „Z“, im übergebenen String `text` zählt und zurückgibt.

Testen Sie Ihre `count_number_of_letters`-Implementierung in der `main`-Funktion mit einigen Beispielaufrufen.

## Beispiele

| `text`       | `count_number_of_letters(text)` |
|--------------|--------------------------------:|
| ""           |                               0 |
| "0123456789" |                               0 |
| "abcABC"     |                               6 |
| "a!B?"       |                               2 |
| "1a 2b 3c"   |                               3 |

# Aufgabe 4 (7 Punkte)

## Vorlesungsfolien

* Arrays (EidP-07-Arrays.pdf)

## Beschreibung

Implementieren Sie eine Funktion mit der Signatur `void count_frequency(int frequency[], const int src[], size_t len)`.
Diese Funktion zählt für alle Werte aus dem Array `src` die Häufigkeit und speichert sie in das Array `frequency` ab.
Dabei wird jede Position `i` im Array `frequency` mit der Häufigkeit des Werts `src[i]` aus dem Array `src` befüllt.

## Beispiele

|                 src |  length | `frequency` nach dem Aufruf von `count_frequency(frequency, src, lenght)` |
|--------------------:|--------:|--------------------------------------------------------------------------:|
|           {1, 1, 1} |       3 |                                                                 {3, 3, 3} |
|           {1, 2, 3} |       3 |                                                                 {1, 1, 1} |
| {5, 2, 5, 7, -7, 3} |       4 |                                                        {2, 1, 2, 1, 1, 1} |

## Hinweise

- Der Datentyp `size_t` ist ein plattformabhängiger, vorzeichenloser Ganzzahltyp, welcher die maximale Größe eines Typs
  (Arrays inklusive) darstellt. Dieser Typ ist mindestens zwei Byte groß. `size_t` wird häufig als Datentyp für
  Schleifenindizes verwendet.
- Beide Arrays (`frequency` und `src`) haben die Länge `len`.
- Testen Sie Ihre `count_frequency`-Implementierung in der `main`-Funktion.

# Aufgabe 5 (7 Punkte)

## Vorlesungsfolien

* Arrays (EidP-07-Arrays.pdf)

## Beschreibung

Erstellen Sie ein Programm, welches die in einem ASCII-Text vorkommenden Buchstaben zählt und alle gefundenen Buchstaben
lexikografisch geordnet zusammen mit den dazugehörigen Häufigkeiten ausgibt. Alle anderen Zeichen werden in der
Kategorie `other` zusammengefasst und zusammen mit der Häufigkeit am Schluss ausgegeben. Die Groß- und Kleinschreibung
von Buchstaben wird nicht gesondert berücksichtigt. Der ASCII-Text wird über die Kommandozeile übergeben.

### Arbeitsschritte

Bearbeiten Sie die folgenden Funktionen (verwenden Sie den bereitgestellten Quellcode als Vorlage und ändern Sie die
Signaturen der Funktionen nicht):

- `count_letter_occurrence`: Zählt wie oft jeder Buchstabe
  des [lateinischen Alphabets](https://de.wikipedia.org/wiki/Lateinisches_Alphabet) im Parameter `text` vorkommt. Die
  vorkommende Anzahl an `'a'`s wird dabei an Position `0` im `letters` Array gezählt, die Anzahl der `'b'`s an
  Position `1`, usw.!
  Alle Zeichen, welche nicht Buchstaben sind, werden an Position `26` im `letters` Array gezählt. Die Zählung in dieser
  Funktion soll unabhängig von Groß- und Kleinschreibung sein.
- `print_letter_occurrence`: Gibt das Array `letters` mit der im Beispiel aufgezeigten Formatierung aus. Es werden nur
  jene Einträge ausgegeben, welche nicht `0` sind. Die Häufigkeiten sollen rechtsbündig mit einer Feldbreite von 4
  ausgegeben werden.
- `letters_to_lower`: Wandelt alle Buchstaben im Array `text` in Kleinbuchstaben um.
- `main`: Vervollständigen Sie die `main`-Funktion mithilfe der zuvor implementierten Funktionen, sodass das Programm
  die Spezifikation der Beschreibung erfüllt.

### Beispielaufrufe mit Ausgabe:

Beispiel 1: Beispielaufruf mit `"abcABC"` als Kommandozeilenparameter und Programmablauf

```text
./s06e05 "abcABC"
  'a':    2
  'b':    2
  'c':    2
```

Beispiel 2: Beispielaufruf mit `"A lOnG tEsT sTrInG"` als Kommandozeilenparameter und Programmablauf

```text
./s06e05 "A lOnG tEsT sTrInG"
  'a':    1
  'e':    1
  'g':    2
  'i':    1
  'l':    1
  'n':    2
  'o':    1
  'r':    1
  's':    2
  't':    3
other:    3
```

Beispiel 3: Beispielaufruf mit `"aaaaaBBBaaaaa"` als Kommandozeilenparameter und Programmablauf

```text
./s06e05 "aaaaaBBBaaaaa"
  'a':   10
  'b':    3
```

### Hinweise

- Der zu analysierende Text wird beim Programmaufruf als Parameter übergeben und nicht mit `scanf` eingelesen! Sie
  können den Code aus dem Programm `args_demo.c` als Grundlage für Ihre Implementierung heranziehen.
- Die Lösung für diese Aufgabe funktioniert möglicherweise nicht für Buchstaben, die nicht im lateinischen Alphabet vorkommen
  (beispielsweise ä, ö, ü). Solche Buchstaben müssen beim Testen nicht berücksichtigt werden.
- Vergessen Sie nicht, dass Zeichenketten nullterminiert.
- Stellen Sie sicher, dass die Funktion `count_letter_occurrence` für Texte mit Groß- und Kleinbuchstaben funktioniert.
- Der Datentyp `size_t` ist ein plattformabhängiger, vorzeichenloser Ganzzahltyp, welcher die maximale Größe eines Typs
  (Arrays inklusive) darstellt. Dieser Typ ist mindestens zwei Byte groß. `size_t` wird häufig als Datentyp für
  Schleifenindizes verwendet.
- Durch den Aufruf `./s06e05 "$(cat example_text1.txt)"` können Sie die Buchstaben einer Textdatei `example_text1.txt`
  zählen lassen. Dieser Aufruf kann für das Testen von langen Texten hilfreich sein.
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!
