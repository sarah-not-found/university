# Aufgabe 1 (4 Punkte)

## Vorlesungsfolien

* Variablen und Datentypen (EidP-03-VariablenDatentypen.pdf)

## Beschreibung

Geben Sie den C-Datentyp und den Dezimalwert der folgenden C-Literale an:

1. `0xCull`
2. `'c'`
3. `.2f`
4. `1.3e-2f`
5. `30`
6. `0xB1LL`
7. `011`
8. `1e4L`
9. `4.`
10. `5u`
11. `2.l`
12. `0x1e5f`
13. `.7`
14. `5e2`
15. `0Xcaul`
16. `'\t'`
17. `80000`
18. `2f`
19. `0x1e5l`
20. `8l`
21. `0x1e5lf`

*Achtung:* Es haben sich ungültige Literale eingeschlichen! Markieren Sie diese mit "ungültig".

### Hinweise

- Nehmen Sie für Zeichen an, dass ein ASCII-Code kompatibler Zeichensatz verwendet wird!

# Aufgabe 2 (5 Punkte)

## Vorlesungsfolien

* Variablen und Datentypen (EidP-03-VariablenDatentypen.pdf)

## Teilaufgabe a)

### Beschreibung

In dieser Aufgabe sollen diverse Ausgaben mit `printf` durch entsprechende Formatstrings ausgegeben werden. Verwenden
Sie das vorgegebene C-Programm als Grundlage für die Ausarbeitung der Arbeitsschritte. Beachten Sie, dass jede der
Variablen in einer eigenen Zeile ausgegeben wird. Nach jedem Arbeitsschritt wird zusätzlich eine Leerzeile erwartet.

### Arbeitsschritte

1. Geben Sie den Inhalt der Variablen `a`, `b`, `c`, `d` und `e` auf der Standardausgabe aus, sodass die Ausgabe genau
   dem bei der Variablendeklaration angegebenen Wert und Format entspricht. Vor jeder Zahl soll `<var_name> = ` als
   Präfix ausgegeben werden, wobei `<var_name>` mit dem entsprechenden Variablennamen substituiert werden soll (z.B.
   wird für die Variable `c` die Zeichenkette `c = Z` ausgegeben).
2. Geben Sie `b` mit 10 Nachkommastellen aus und verwenden Sie `b_10 = ` als Präfix. Was beobachten Sie bei dieser
   Ausgabe? Dokumentieren Sie Ihre Erkenntnisse mithilfe von Kommentaren im Code!
3. Geben Sie `c` als Hexadezimalzahl mit Präfix `0x` und Kleinbuchstaben für `a` - `f` aus und verwenden Sie `c_hex = `
   als Präfix.
4. Geben Sie `c` als Ganzzahl (`int`) mit einer Mindestbreite von `pad` Stellen aus. Sofern die Zahl `c` weniger als
   diese in der Variable `pad` angegebenen Stellen aufweist, werden von links Nullen eingefügt (engl. `zero padding`).
   Verwenden Sie das Präfix `c_pad = `.
5. Geben Sie `a`, `b`, `c`, `d` und `e` als Dezimalzahlen rechtsbündig aus, sodass die Dezimalstellen (z.B. Einer-,
   Zehner-, Hunderterstelle, usw.) der Zahlen untereinanderstehen. Für die rechtsbündige Ausgabe sollen 15
   Vorkommastellen angenommen werden. Für alle Gleitkommazahlen sollen 4 Nachkommastellen ausgegeben werden. Verwenden
   Sie wieder das Präfix `<var_name> = `.

### Hinweise

- Die Handbuchseite `man 3 printf` kann zum Identifizieren der notwendigen Formatspecifier behilflich sein.
- Verwenden Sie für alle Transformationen nur `printf` und keine eigens implementierte Logik.
- Verwenden Sie in den `printf`-Aufrufen ausschließlich die bereits deklarierten Variablen ohne jegliche Veränderung von
  den Werten dieser Variablen.
- Stellen Sie sicher, dass vor dem Zeilenumbruch kein Leerzeichen ausgegeben wird.
- Um die Korrektheit Ihres Programms zu überprüfen, werden bei Ein-/Ausgabetests mit Substitution teilweise die Werte
  von Variablen in Ihrem Programm verändert! Sofern in diesem Test Fehler auftreten, stellen Sie bitte sicher, dass Sie
  die entsprechenden Formatspecifier verwenden!

### Tests


## Teilaufgabe b)

Folgender Code ist gegeben.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int zero;
    printf("zero = %hd\n", zero);
    return EXIT_SUCCESS;
}

```

Sehen Sie sich den Code an und analysieren Sie, ob bei diesem Programm Probleme auftreten können. Sie können das Programm
beispielsweise mehrfach ausführen. Dokumentieren Sie Ihre Erkenntnisse mithilfe von Kommentaren im Code!

### Hinweise

- Damit Sie den gegebenen Code kompilieren können muss auf das Flag `-Werror` verzichtet werden!

# Aufgabe 3 (4 Punkte)

## Vorlesungsfolien

* Vorschau (EidP-02-Vorschau.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches mithilfe einer `while`-Schleife die Summe aller Ganzzahlen von 1 bis `n`
berechnet ($`\sum_{i=1}^{n} i`$).

### Arbeitsschritte

Führen Sie folgende Arbeitsschritte aus:
- Lesen Sie vom Benutzer eine Ganzzahl (`n`) ein
- Berechnen Sie mithilfe einer `while`-Schleife die Summe der Zahlen von `1` bis `n`.
- Geben Sie den Text `"sum from 1 to <n> = <sum>"` aus, wobei anstelle von `<n>` bzw. `<sum>` der Wert der Variable `n`
  bzw. `sum` ausgegeben wird!
- Nach der Ausgabe wird das Programm erfolgreich (`EXIT_SUCCESS`) beendet.

### Hinweise

- Artemis gibt beim Testen für die Variable `n` nur Werte zwischen $`0`$ und $`1000`$, d. h.
  $`0 \le \mathtt{n} \le 1000`$, ein.
- Verwenden Sie `scanf` für das Einlesen von `n`.

### Beispielausgaben

Beispiel 1: Programmablauf bei der Eingabe der Zahlen `5`. Die Zahl `5` in ersten Zeile der Beispielausgabe wurde durch
den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```
5
sum from 1 to 5 = 15
```

Beispiel 2: Programmablauf bei der Eingabe der Zahlen `100`. Die Zahl `100` in ersten Zeile der Beispielausgabe wurde
durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```
100
sum from 1 to 100 = 5050
```

# Aufgabe 4 (5 Punkte)

## Vorlesungsfolien

* Vorschau (EidP-02-Vorschau.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches berechnet wie viele Stunden, Minuten und Sekunden einem eingelesenen
Wert `chosen_seconds` in Sekunden entsprechen. Die Ganzzahl (`int`) `chosen_seconds` wird von dem\*der Benutzer\*in
eingelesen.

### Ablauf

- Der\*die Benutzer\*in gibt eine Ganzzahl für `chosen_seconds` ein.
    - Bei negativen Werten wird ein Fehler ausgegeben und das Programm nicht erfolgreich beendet. Für diese
      Fehlerausgabe gibt es keine Vorgaben bezüglich des Inhaltes und der Formatierung.
- Ausgabe eines Zeilenumbruchs.
- Berechnen der Werte für Stunden, Minuten und Sekunden und Ausgabe des
  Texts `"<chosen_seconds>s -> <hours>h <minutes>m <seconds>s"` auf der Standardausgabe, wobei der
  Platzhalter `<chosen_seconds>` mit der gewählten Zahl und die Platzhalter `<hours>`, `<minutes>` bzw. `<seconds>` mit
  den entsprechenden Werten für Stunden, Minuten bzw. Sekunden ersetzt werden.
- Nach der Ausgabe wird das Programm erfolgreich (`EXIT_SUCCESS`) beendet.

### Beispiele

Beispiel 1: Programmablauf bei der Eingabe der Zahl `60`. Die Zahl `60` in der ersten Zeile der Beispielausgabe wurde
durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```
60

60s -> 0h 1m 0s
```

Beispiel 2: Programmablauf bei der Eingabe der Zahl `3601`. Die Zahl `3601` in der ersten Zeile der Beispielausgabe
wurde durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```
3601

3601s -> 1h 0m 1s
```

Beispiel 3: Programmablauf bei der Eingabe der Zahl `93200`. Die Zahl `93200` in der ersten Zeile der Beispielausgabe
wurde durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```
93200

93200s -> 25h 53m 20s
```

### Hinweise

- Sie können das Programm `s02e04.c` als Grundlage für Ihre Implementierung heranziehen. Dieses Programm liest eine
  Ganzzahl `seconds` vom Typ `int` ein und gibt den Wert von `seconds` anschließend auf der Standardausgabe aus (sofern
  beim Einlesen kein Fehler auftrat).
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!

# Aufgabe 5 (5 Punkte)

## Vorlesungsfolien

* Vorschau (EidP-02-Vorschau.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches mithilfe einer `while`-Schleife die Ziffern einer eingelesenen nicht negativen
Ganzzahl `number`, d. h. $`0 \leq \texttt{number} \leq \texttt{INT\_MAX}`$, in umgekehrter Reihenfolge auf der
Standardausgabe ausgibt. Die Ganzzahl (`int`) `number` wird von dem\*der Benutzer\*in eingelesen.

### Ablauf

- Der\*die Benutzer\*in gibt einen Wert für `number` ein.
    - Wird ein negativer Wert eingegeben, gibt das Programm eine Fehlermeldung auf der Standardausgabe aus. Anschließend
      wird das Programm nicht erfolgreich mit dem Rückgabewert `EXIT_FAILURE` beendet. Sie können einen entsprechenden,
      sinnvollen Text für die Fehlermeldung frei wählen!
- Ausgabe eines Zeilenumbruchs.
- Der Text `"input:  <number>\noutput: "` wird auf der Standardausgabe ausgegeben, wobei der Platzhalter `<number>`
  durch den gewählten Wert von `number` ersetzt wird.
- Schrittweise werden die Ziffern der Zahl `number` in umgekehrter Reihenfolge auf der Standardausgabe ausgegeben.

### Beispielausgaben

Beispiel 1: Programmablauf bei der Eingabe der Zahl `1234`. Die Zahl `1234` in der ersten Zeile der Beispielausgabe
wurde durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
1234

input:  1234
output: 4321
```

Beispiel 2: Programmablauf bei der Eingabe der Zahl `510`. Die Zahl `510` in der ersten Zeile der Beispielausgabe wurde
durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
510

input:  510
output: 015
```

Beispiel 3: Programmablauf bei der Eingabe der Zahl `0001`. Die Zahl `0001` in der ersten Zeile der Beispielausgabe
wurde durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
0001

input:  1
output: 1
```

Beispiel 4: Programmablauf bei der Eingabe der Zahl `1000`. Die Zahl `1000` in der ersten Zeile der Beispielausgabe
wurde durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
1000

input:  1000
output: 0001
```

### Hinweise

- Die Konstante `INT_MAX` ($`\texttt{INT\_MAX} \geq 32767`$) stellt den plattformabhängigen Maximalwert des
  Datentyps `int` dar.
- Sie können das Programm `s02e05.c` als Grundlage für Ihre Implementierung heranziehen. Dieses Programm liest eine
  Ganzzahl `number` vom Typ `int` ein und gibt den Wert von `number` anschließend auf der Standardausgabe aus (sofern
  beim Einlesen kein Fehler auftrat).
- Die letzte Ziffer der Dezimalzahl `number` können Sie mithilfe des Ausdrucks `n % 10` berechnen (Restwert).
- Die letzte Ziffer der Dezimalzahl `number` können Sie mithilfe des Ausdrucks `n / 10` "abschneiden" (Ganzzahldivision)
  .
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!

# Aufgabe 6 (7 Punkte)

## Vorlesungsfolien

* Variablen und Datentypen (EidP-03-VariablenDatentypen.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches alle Buchstaben zwischen zwei Buchstaben (inklusive der Grenzen) in entsprechender
Reihenfolge untereinander auf der Standardausgabe ausgibt. Die zwei Buchstaben werden als Zeichen von dem\*der Benutzer\*in
eingelesen.

## Ablauf

- Der\*die Benutzer\*in gibt den Start- und Endwert im Format `<start>-<end>` ein.
    - Bei dieser Eingabe werden nur Kleinbuchstaben akzeptiert. Wird ein anderes Zeichen eingegeben, gibt das Programm
      nach der Eingabe die Fehlermeldung `"ERROR: At least one input was not a lowercase letter!"` auf der
      Standardausgabe aus und beendet nicht erfolgreich (`EXIT_FAILURE`).
- Ausgabe eines Zeilenumbruchs.
- Ausgehend vom zuerst eingegebenen Buchstaben werden alle Buchstaben bis zum zweiten Buchstaben in entsprechender
  Reihenfolge untereinander auf der Standardausgabe ausgegeben.

## Beispielausgaben

Beispiel 1: Programmablauf bei der Eingabe der Zeichen `a` und `d`. Der Text `a-d` in der ersten Zeile der
Beispielausgabe wurde durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
a-d

a
b
c
d
```

Beispiel 2: Programmablauf bei der Eingabe der Zeichen `d` und `a`. Der Text `d-a` in der ersten Zeile der
Beispielausgabe wurde durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
d-a

d
c
b
a
```

Beispiel 3: Programmablauf bei der Eingabe der Zeichen `u` und `u`. Der Text `u-u` in der ersten Zeile der
Beispielausgabe wurde durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
u-u

u
```

Beispiel 4: Programmablauf bei der Eingabe der Zeichen `A` und `d`. Der Text `A-d` in der ersten Zeile der
Beispielausgabe wurde durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
A-d

ERROR: At least one input was not a lowercase letter!
```

## Hinweise

- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!
