# Aufgabe 1 (9 Punkte)

## Vorlesungsfolien

* Operatoren und Ausdrücke (EidP-04-OperatorenAusdruecke.pdf)

## Beschreibung

In dieser Aufgabe sollen das theoretische Verständnis für die Auswertung von C-Ausdrücken/-Anweisungen gefestigt werden.
Lösen Sie dafür die folgenden Unteraufgaben. Verwenden Sie zum Lösen dieser Aufgabe die bereitgestellte
Datei `s03e01.txt`.

### Teilaufgabe a)

Geben Sie den **C-Datentyp** des Ergebnisses der folgenden C-Ausdrücke an:

1. `0.2 == 0.2f`
2. `4U == (2U << 1U)`
3. `0xcad`
4. `(2 * 5) / 3.0`
5. `((float) 6.0) / 4`
6. `0XFULL + 'a'`
7. `'E' * 'i' + 'd' + 'P'`
8. `(8.0 * 0x10) * (((4U << 2U) + 10L) * 5.0f)`
9. `(UINT_MAX + 1) & 0xF`
10. `12U | ((6L ^ 4) & 13LL)`

### Teilaufgabe b)

Geben Sie das **Resultat** der folgenden C-Ausdrücke im Dezimalsystem an:

1. `0x10`
2. `'Z' - 'A'`
3. `(5U << 1U) == (13 ^ 7)`
4. `(UINT_MAX + 2U) + 1`
5. `3.0 + 1 - 4 / 2`

### Teilaufgabe c)

Geben Sie das **Resultat** der folgenden C-Ausdrücke im Dezimalsystem an. Erklären Sie jeweils, wie es zu diesem Ergebnis
kommt.

1. `0.1f + 0.1f == 0.2`
2. `0.1 - 0.1f == 0`

### Teilaufgabe d)

Setzen Sie für jeden Ausdruck Klammern, sodass die Auswertungsreihenfolge durch die gesetzten Klammern ersichtlich, jedoch nicht verändert wird.
Geben Sie an, welcher Operator bei der Auswertung zuletzt ausgeführt wird.

1. `5 * 2 + 1 == 4 && 2 + 1 > 3`
2. `x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z'`
3. `1 * 2 / 3 % 4 * 5 / 6`

### Hinweise

- Die Konstantem `INT_MAX` und `UINT_MAX` sind im Header `limits.h` definiert.
- Nehmen Sie an, dass die Ausdrücke auf einer Rechnerarchitektur ausgeführt werden, welche Ganzzahlen im
  Zweierkomplement darstellt, und ein zum ASCII-Code kompatibler Zeichensatz verwendet wird.

# Aufgabe 2 (5 Punkte)

## Vorlesungsfolien

* Vorschau (EidP-02-Vorschau.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches ermittelt, ob die Zahl `n`
eine [vollkommene Zahl](https://en.wikipedia.org/wiki/Perfect_number) ist. Die Zahl `n` wird von dem\*der Benutzer\*in
mittels `scanf` als nicht negative Ganzzahl (`unsigned int`) eingelesen.

## Ablauf

- Der\*die Benutzer\*in gibt eine Ganzzahl für `n` ein.
- Ausgabe eines Zeilenumbruchs.
- Das Programm ermittelt, ob `n` eine vollkommene Zahl ist. Abhängig vom Ergebnis folgt eine der folgenden Ausgaben auf
  der Standardausgabe. In beiden Fällen wird der Platzhalter `<n>` durch den gewählten Wert von `n` als Dezimalzahl
  ersetzt.
    - `n` ist eine vollkommene Zahl: `"The number <n> is a perfect number!"`
    - `n` ist keine vollkommene Zahl: `"The number <n> is not a perfect number!"`

Das Format der Ausgabe ist von den Beispielausgaben zu entnehmen.

### Beispiele

Beispiel 1: Programmablauf bei der Eingabe der Zahl `1`

```text
1

The number 1 is not a perfect number!
```

Beispiel 2: Programmablauf bei der Eingabe der Zahl `5`

```text
5

The number 5 is not a perfect number!
```

Beispiel 3: Programmablauf bei der Eingabe der Zahl `6`

```text
6

The number 6 is a perfect number!
```

### Hinweise

- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!

# Aufgabe 3 (6 Punkte)

## Vorlesungsfolien

* Vorschau (EidP-02-Vorschau.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches die ersten `n`-Zahlen der linearen Differenzengleichung $`x_{i+2} = x_{i} + 1`$ 
mit den Anfangswerten $`x_0 = 2`$ und $`x_1 = 4`$ mithilfe einer `while`-Schleife berechnet und hintereinander
ausgibt. Die Ganzzahl (`int`) `n` wird von dem\*der Benutzer\*in eingelesen.

## Ablauf

- Der\*die Benutzer\*in gibt einen Dezimalwert für `n` ein.
    - Sofern die eingegebene Zahl kleiner als 1 ist, wird keine Berechnung ausgeführt, sondern eine Fehlermeldung auf
      der Standardausgabe ausgegeben und das Programm nicht erfolgreich beendet (`EXIT_FAILURE`). Als Fehlermeldung wird
      der Text `"ERROR: The provided number <n> is smaller than 1!"` verwendet, wobei der Platzhalter `<n>` durch den
      eingegebenen Wert ersetzt wird.
- Ausgabe eines Zeilenumbruchs.
- Die ersten `n`-Zahlen werden nacheinander in einer Zeile ausgegeben. Als Trennzeichen zwischen den Zahlen wird ein
  Beistrich gefolgt von einem Leerzeichen (`", "`) verwendet.

## Beispiele

Beispiel 1: Programmablauf bei der Eingabe der Zahlen `10`. Die Zahl `10` in der Beispielausgabe wurde durch den\*die
Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
10

2, 4, 3, 5, 4, 6, 5, 7, 6, 8
```

Beispiel 2: Programmablauf bei der Eingabe der Zahlen `17`. Die Zahl `17` in der Beispielausgabe wurde durch den\*die
Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
17

2, 4, 3, 5, 4, 6, 5, 7, 6, 8, 7, 9, 8, 10, 9, 11, 10
```

Beispiel 3: Programmablauf bei der Eingabe der Zahlen `-2`. Die Zahl `-2` in der ersten Zeile der Beispielausgabe wurde
durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
-2

ERROR: The provided number -2 is smaller than 1!
```

## Hinweise

- Verwenden Sie `scanf` für das Einlesen von `n`.
- Was passiert, wenn Sie eine ungültige Zahl eingeben (z.B. `Z`)?
- Am Anfang und Ende der ausgegebenen Zahlen soll *kein* Beistrich stehen!
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!

# Aufgabe 4 (2 Punkte)

## Vorlesungsfolien

* Operatoren und Ausdrücke (EidP-04-OperatorenAusdruecke.pdf)

## Beschreibung

Geben Sie jeweils einen Ausdruck mit dem Bedingungsoperator an, der das geforderte Ergebnis ermittelt:

1. Maximum der Werte der `int`-Variablen `x` und `y`.
2. Minimum der Werte der `int`-Variablen `x` und `y`.
3. [Signum](https://en.wikipedia.org/wiki/Sign_function) des Werts der `int`-Variable `x`, d. h. $`\text{sgn}(\texttt{x})`$.
4. [Absolutbetrag](https://en.wikipedia.org/wiki/Absolute_value) des Werts der `int`-Variable `x`, d. h. $`|\texttt{x}|`$.

### Hinweise

- Möglicherweise wird für einzelne Ausdrücke mehr als ein Bedingungsoperator benötigt. 

# Aufgabe 5 (8 Punkte)

## Vorlesungsfolien

* Operatoren und Ausdrücke (EidP-04-OperatorenAusdruecke.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches die Anzahl der Nullen der [signifikanten Stellen](https://en.wikipedia.org/wiki/Significant_figures) der Binärrepräsentation der Dezimalzahl `value` ermittelt.
Die Zahl `value` wird von dem\*der Benutzer\*in mittels `scanf` als positive Ganzzahl mit genau 32 Bit
(`uint32_t`) eingelesen.

### Ablauf

- Das Programm gibt den Text `"value: "` auf der Standardausgabe aus.
- Der\*die Benutzer\*in gibt eine positive Ganzzahl im Dezimalsystem für `value` ein.
- Ausgabe eines Zeilenumbruchs.
- Die Anzahl der Nullen der signifikanten Stellen der Binärrepräsentation der Dezimalzahl `value` wird ermittelt.
- Abhängig von der Anzahl an Nullen der signifikanten Stellen wird einer der folgenden Texte auf der Standardausgabe ausgegeben. Bei
  den folgenden Texten wird der Platzhalter `<n>` mit dem gewählten Wert und der Platzhalter `<zeros>`
  mit der Anzahl der Nullen der signifikanten Stellen ersetzt.
    - die signifikanten Stellen der Binärrepräsentation der Dezimalzahl `value` beinhalten genau eine
      Null: `"The number <n> contains 1 zero in the significant digits of the binary representation!"`
    - die signifikanten Stellen der Binärrepräsentation der Dezimalzahl `value` beinhalten keine oder mehr als eine
      Null: `"The number <n> contains <zeros> zeros in the significant digits of the binary representation!"`
- Nach der Ausgabe wird das Programm erfolgreich mit dem Rückgabewert `EXIT_SUCCESS` beendet.

## Hinweise

- Es wird angenommen, dass die signifikanten Stellen der Binärrepräsentation der Dezimalzahl $`0`$ eine Null beinhalten.
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!
- Mithilfe des folgenden Codefragments können Sie mit `scanf` bzw. `printf` die Variable `value` vom Typ `uint32_t`
  einlesen bzw. ausgeben. Beachten Sie, dass Sie für die Konstanten `SCNu32` und `PRIu32` den Header `inttypes.h`
  inkludieren müssen.

  ```c
  scanf("%" SCNu32, &value);
  printf("%" PRIu32, value);
  ```

## Beispiele

Beispiel 1: Programmablauf bei der Eingabe von `5`. Die Zahl $`5`$ in der ersten Zeile der Beispielausgabe wurde durch
den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden. Die Dezimalzahl `5` entspricht der Binärzahl `101`.

```text
value: 5

The number 5 contains 1 zero in the significant digits of the binary representation!

```

Beispiel 2: Programmablauf bei der Eingabe von `3`. Die Zahl $`3`$ in der ersten Zeile der Beispielausgabe wurde durch
den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden. Die Dezimalzahl `3` entspricht der Binärzahl `11`. 


```text
value: 3

The number 3 contains 0 zeros in the significant digits of the binary representation!

```

Beispiel 3: Programmablauf bei der Eingabe von `64`. Die Zahl $`64`$ in der ersten Zeile der Beispielausgabe wurde durch
den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden. Die Dezimalzahl `64` entspricht der Binärzahl `1000000`.

```text
value: 64

The number 64 contains 6 zeros in the significant digits of the binary representation!

```

Beispiel 4: Programmablauf bei der Eingabe von `0`. Die Zahl $`0`$ in der ersten Zeile der Beispielausgabe wurde durch
den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
value: 0

The number 0 contains 1 zero in the significant digits of the binary representation!

```
