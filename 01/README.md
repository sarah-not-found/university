# Aufgabe 1 (4 Punkte)

## Vorlesungsfolien

* Einführung (EidP-01-Einfuehrung.pdf)

## Beschreibung

In dieser Aufgabe sollen Sie sich mit einigen Grundlagen vertraut machen. Verwenden Sie dafür einen Rechner mit einer
Linux Distribution Ihrer Wahl. Stellen Sie sicher, dass `gcc` installiert ist. Testen Sie erneut, ob das im Proseminar
besprochene *Hello World*-Programm `s01e01.c` kompiliert.

### Arbeitsschritte

Beantworten Sie die folgenden Fragen in der Textdatei `s01e01.txt`.

1. Was ist `gcc`? Wozu wird es gebraucht? Gibt es Alternativen?
2. Welche `gcc` Version ist auf Ihrem System installiert? Wie haben Sie diese Information ermittelt?
3. Welche ist die neueste `gcc` Version?
4. Erklären Sie die einzelnen Befehle Ihres *Hello World*-Programmcodes `s01e01.c` mithilfe von Kommentaren im
   Quellcode.
5. Was ist der Unterschied zwischen C-Quellcode und einem Executable, d. h. einer ausführbaren Datei? Ist `s01e01.c` ein
   Executable oder Quellcode?
6. Was passiert beim Kompilieren und warum ist dieser Schritt vor dem Ausführen notwendig?
7. Was bewirken die Optionen (`-Wall`, `-Wextra`, `-Werror`, `-Wpedantic`, `-std=c18`, `-o s01e01`) beim
   `gcc`-Aufruf `gcc -Wall -Wextra -Werror -Wpedantic -std=c18 s01e01.c -o s01e01`?
8. Wie kann das beim Kompilieren generierte Executable `s01e01` ausgeführt werden?

### Hinweise

- Während des gesamten Proseminars wird eine funktionierende Linux-Distribution vorausgesetzt. Sie ersparen sich jede
  Menge Arbeit, wenn Sie bereits jetzt eine Version installieren. Sie Können alle Aufgaben auch in *Artemis* lösen. Es
  wird jedoch vorausgesetzt, dass Sie Programme auch selbst in der Kommandozeile kompilieren können.
- Sollten Sie keinen eigenen PC besitzen, gibt es die Möglichkeit, die Linux-Rechner in den Rechnerräumen der
  Universität zu nutzen.
- Der Befehl `man gcc` könnte hilfreich sein.
- Sie können das *Hello-World*-Programm mittels des
  Befehls `gcc -Wall -Wextra -Werror -Wpedantic -std=c18 s01e01.c -o s01e01` kompilieren.

# Aufgabe 2 (4 Punkte)

## Vorlesungsfolien

* Vorschau (EidP-02-Vorschau.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches überprüft, ob die Variable `value` vom Datentyp `int` durch die Zahl dreizehn
teilbar ist.

### Arbeitsschritte

Verwenden Sie das bereitgestellte Codefragment und führen Sie folgende Schritte durch:

- Weisen Sie der Variable `value` eine beliebige, von Ihnen gewählten Ganzzahl zu.
- Verwenden Sie eine `if`-Anweisung, um zu entscheiden, ob der Wert der Variable `value` durch dreizehn teilbar ist.
- Sofern der von Ihnen gewählte Wert von `value` durch dreizehn teilbar ist, geben Sie mittels `printf` den
  Text `The given value <value> is divisible by thirteen!` aus.
- Sollte der Wert nicht durch dreizehn teilbar sein, muss `The given value <value> is not divisible by thirteen!`
  ausgegeben werden.
- Beachten Sie, dass anstelle von `<value>` der Wert der Variable `value` ausgegeben wird!
- Nach der Ausgabe wird das Programm erfolgreich (`EXIT_SUCCESS`) beendet.

### Beispielausgaben

Beispiel 1: `value = 39`

```text
The given value 39 is divisible by thirteen!
```

Beispiel 2: `value = 74`

```text
The given value 74 is not divisible by thirteen!
```

### Hinweise

- Verwenden Sie für das Ausgeben von Zahlen den entsprechenden Platzhalter in den Formatstrings.
- Mithilfe des Rest-Operators (`%`) kann der Rest einer Division bestimmt werden. Beispielsweise ist das Ergebnis der
  Berechnung `5 % 2` Eins. Ob eine Variable `a` ohne Rest durch zwei teilbar ist, kann beispielsweise mit der
  Bedingung `(a % 2) == 0` überprüft werden.
- Testen Sie die Ausgabe Ihres Programms mit einigen verschiedenen Werten für die Variable `value`. Achten Sie dabei
  darauf, dass Sie beide Fälle abdecken (Zahl ist teilbar bzw. nicht teilbar).
- Verwenden Sie `if` und `printf`.
- Bei den Ein-/Ausgabetests wird beim Testen der Wert der Variable `value` in Ihrem Programm verändert!
- Artemis setzt beim Testen für die Variable `value` nur Werte zwischen -32767 und 32767, d. h. 
  $` -32767 \le \mathtt{value} \le 32767`$, ein.
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!

# Aufgabe 3 (5 Punkte)

## Vorlesungsfolien

* Vorschau (EidP-02-Vorschau.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches das Ergebnis des Terms $`x^2 + 5 \cdot y - 4`$ berechnet und als Dezimalwert auf
der Standardausgabe ausgibt. Verwenden Sie für die Variablen `x` und `y` den Datentyp `int` und wählen Sie für beide
Variablen einen beliebigen Wert!

## Beispielausgaben

Beispiel 1: `x = 3` und `y = 5`

```text
30
```

Beispiel 2: `x = -3` und `y = 5`

```text
30
```

Beispiel 3: `x = 5` und `y = -10`

```text
-29
```

## Hinweise

- Bei den Ein-/Ausgabetests werden beim Testen die Werte der Variablen `x` und `y` in Ihrem Programm verändert!
- Artemis setzt beim Testen für die Variablen `x` und `y` nur Werte zwischen -100 und 100, d. h.
  $`-100 \le \mathtt{x} \le 100`$ und $`-100 \le \mathtt{y} \le 100`$, ein.
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!

# Aufgabe 4 (5 Punkte)

## Vorlesungsfolien

- Vorschau (EidP-02-Vorschau.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches den Wert von zwei `int`-Variablen `x` und `y` vertauscht. Der Dezimalwert der
Variablen `x` und `y` soll mit einer entsprechenden Statusmeldung vor und nach dem Tauschen mit der Funktion `printf`
ausgegeben werden. Die Formatierung der Ausgabe ist bei den Beispielausgaben ersichtlich. Den Variablen `x` und `y`
können Sie beliebige Werte zuweisen.

## Beispielausgaben

```text
initial state
x = 10
y = 20
swapped
x = 20
y = 10
```

## Hinweise

- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!
- Bei den Ein-Ausgabetests werden beim Testen die Werte der Variablen `x` und `y` in Ihrem Programm verändert. Bei der
  Ausgabe der Dezimalwerte müssen daher die Variablen verwendet werden!

# Aufgabe 5 (5 Punkte)

## Vorlesungsfolien

* Vorschau (EidP-02-Vorschau.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches mithilfe einer `while`-Schleife den Text `Hello World!`  `n` mal untereinander auf
der Standardausgabe ausgibt.

### Arbeitsschritte

Verwenden Sie das bereitgestellte Codefragment und führen Sie folgende Schritte durch:

- Initialisieren Sie die Variable `n` mit dem Datentyp `int` mit einer beliebigen, von Ihnen gewählten Ganzzahl.
- Implementieren Sie die erforderliche Programmlogik mit einer `while`-Schleife.
- Bitte beachten Sie, dass aufgrund von Einschränkungen beim Testen in Artemis, die Variable `n` in diesem Programm nur
  einmal initialisiert und anschließend nicht mehr verändert werden darf!

### Beispielausgaben

Beispiel 1: `n = 3`

```text
Hello World!
Hello World!
Hello World!

```

Beispiel 2: `n = 5`

```text
Hello World!
Hello World!
Hello World!
Hello World!
Hello World!

```

Beispiel 3: `n = 0`

```text

```

## Hinweise

- Bei den Ein-/Ausgabetests wird beim Testen der Wert der Variable `n` in Ihrem Programm verändert!
- Artemis setzt beim Testen für die Variable `n` nur Werte zwischen $`0`$ und $`32767`$ – d. h.
  $`0 \leq \mathtt{value} \leq 32767`$ – ein.
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!

# Aufgabe 6 (7 Punkte)

## Beschreibung

Erstellen Sie ein C-Programm, welches mithilfe einer `while`-Schleife alle durch elf teilbaren Ganzzahlen zwischen $`0`$
und $`\mathtt{n} \leq 32767`$ (jeweils inklusive), d. h. $`\{t\in\{0, ..., \mathtt{n}\}\;:\;11|t\}`$, in absteigender Reihenfolge
untereinander ausgibt.

### Arbeitsschritte

Führen Sie folgende Arbeitsschritte aus:

- Initialisieren Sie eine Variable vom Datentyp `int` namens `n` mit einem beliebigen, von Ihnen gewählten Wert zwischen
  $`0`$ und $`32767`$, d. h. $`0 \leq \mathtt{n} \leq 32767`$.
- Implementieren Sie die erforderliche Programmlogik.
- Bitte beachten Sie, dass aufgrund von Einschränkungen beim Testen in Artemis, die Variable `n` in diesem Programm nur
  einmal initialisiert und anschließend nicht mehr verändert werden darf!

### Beispielausgabe für `n = 100`

```
99
88
77
66
55
44
33
22
11
0
```

### Hinweise

- Die angegebenen Grenzen für die Variable `n` sind als "weiche Grenzen" zu verstehen. Das heißt alle Werte im
  angegebenen Bereich müssen funktionieren, Werte außerhalb können funktionieren.
- Bei den Ein-/Ausgabetests wird beim Testen der Wert der Variable `n` in Ihrem Programm verändert!
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!
