# Aufgabe 1 (7 Punkte)

## Vorlesungsfolien

* Kontrollstrukturen (EidP-05-Kontrollstrukturen.pdf)

## Beschreibung

In dieser Aufgabe muss die Erreichbarkeit von bestimmten Positionen basierend auf der Initialisierung der Variablen `a`
und `b` ermittelt werden. Dafür ist der folgende Code gegeben.

```c
#include <stdlib.h>

int main(void) {
    int a, b;
    // initialize variables `a` and `b` to reach respective position
    if (a > 5 && a < 10) {
        if (a <= b) {
            // position 1
        }
        // position 2
    } else if (a > b) {
        // position 3
        if ((a = 8)) {
            // position 4
        } else {
            // position 5
        }
    } else {
        // position 6
        if (!a && a == 0) {
            // position 7
        } else {
            // position 8
        }
    }
    if (a == 8) {
        // position 9
    }
    // position 10
    return EXIT_SUCCESS;
}

```

Geben Sie die Bedingung an, welche die beiden Initialisierungen der Variablen `a` und `b` jeweils erfüllen müssen, um
die Positionen 2 bis 10 im Code zu erreichen, indem Sie die Tabelle in der Datei `s04e01.txt` – analog zum bereits
angeführten Beispiel für Position 1 – vervollständigen.

# Aufgabe 2 (4 Punkte)

## Vorlesungsfolien

* Kontrollstrukturen (EidP-05-Kontrollstrukturen.pdf)

## Teilaufgabe a)

Gegeben sei folgendes C-Programm. Dieses liefert nicht die von dem\*der Programmierer\*in erwartete Ausgabe:
Beispielsweise sollte für die Eingabe des Wertes `2048` die Ausgabe `count = 1890` auf der Standardausgabe erfolgen.
Erläutern Sie alle Ihnen auffallenden Probleme mithilfe von Kommentaren und beheben Sie die entsprechenden Fehler im
Programmcode. Begründen Sie außerdem Ihre Änderungen.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned short n;
    if (!scanf("%hu", &n)) {
        fprintf(stderr, "ERROR: The provided input could not be converted!\n");
        return EXIT_FAILURE;
    }
    unsigned count = 0;
    for (unsigned char i = 0; i < n; ++i) {
        if (i % 13) {
            ++count;
        }
    }
    printf("count = %u\n", count);
    return EXIT_SUCCESS;
}

```

## Teilaufgabe b)

Gegeben sei folgendes C-Programm. Dieses liefert nicht die von dem\*der Programmierer\*in erwartete Ausgabe:
Beispielsweise sollte für die Eingabe des Wertes `50` die Ausgabe `sum = 1275` auf der Standardausgabe erfolgen.
Erläutern Sie alle Ihnen auffallenden Probleme mithilfe von Kommentaren und beheben Sie die entsprechenden Fehler im
Programmcode **ohne den Datentyp der Variable `n` zu verändern!** Begründen Sie außerdem Ihre Änderungen.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned char n;
    if (!scanf("%hhu", &n)) {
        fprintf(stderr, "ERROR: The provided input could not be converted!\n");
        return EXIT_FAILURE;
    }
    unsigned sum = 0;
    for (unsigned char i = n; i >= 0; --i) {
        sum += i;
    }
    printf("sum = %u\n", sum);
    return EXIT_SUCCESS;
}

```

## Teilaufgabe c)

Verändern Sie das gegebene Programm, sodass eine `while`-Schleife anstelle der `do`-`while`-Schleife verwendet wird und
dennoch die identische Ausgabe auf der Standardausgabe erfolgt.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = 1;
    do {
        if (!(i % 2)) {
            continue;
        }
        printf("%d\n", i);
    } while (i++ < 20);
    return EXIT_SUCCESS;
}

```

## Teilaufgabe d)

Verändern Sie das gegebene Programm, sodass `for`-Schleifen anstelle von `while`-Schleifen verwendet werden und dennoch
die identische Ausgabe auf der Standardausgabe erfolgt.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	unsigned height = 10;
	unsigned i = 1;
	unsigned j = 1;
	while (i <= height) {
		while (j <= height) {
			printf(" %c", height - j++ >= i ? ' ' : '#');
		}
		printf("\n");
		i += 3;
		j = 1;
	}
	return EXIT_SUCCESS;
}

```

## Hinweise

- Vergessen Sie nicht alle von Ihnen durchgeführten Änderungen mithilfe von Kommentaren zu dokumentieren.

# Aufgabe 3 (4 Punkte)

## Vorlesungsfolien

* Kontrollstrukturen (EidP-05-Kontrollstrukturen.pdf)

## Beschreibung

Implementieren Sie ein C-Programm, welches einen eingegebenen Text, welcher ausschließlich aus ASCII-Zeichen besteht,
mithilfe der Atbasch-Verschlüsselung verschlüsselt. Die Atbasch-Verschlüsselung bildet jeden Klartextbuchstaben auf
einen Geheimbuchstaben ab, indem der erste Buchstabe mit dem letzten Buchstaben vertauscht wird, der zweite Buchstaben
mit dem vorletzten vertauscht wird usw.!
Wird dieses Prinzip auf das lateinische Alphabet angewendet, erhält man folgende Tabelle zur Ver- und Entschlüsselung
von Texten. In Ihrem Programm werden so lange Zeichen eingelesen bis das Zeichen `#` oder die Konstante `EOF` (aus
`stdio.h`) auftritt. Bei der Verschlüsselung sollen nur Zeichen aus dem lateinischen Alphabet verschlüsselt werden.
Alle anderen Zeichen (beispielsweise Ziffern und Leerzeichen) werden nicht verschlüsselt und unverändert ausgegeben. Des
Weiteren soll die Ausgabe – unabhängig von der Eingabe – nur aus Kleinbuchstaben bestehen.

| Klartextbuchstabe | Geheimtextbuchstabe |
|-------------------|---------------------|
| a                 | z                   |
| b                 | y                   |
| c                 | x                   |
| d                 | w                   |
| e                 | v                   |
| f                 | u                   |
| g                 | t                   |
| h                 | s                   |
| i                 | r                   |
| j                 | q                   |
| k                 | p                   |
| l                 | o                   |
| m                 | n                   |
| n                 | m                   |
| o                 | l                   |
| p                 | k                   |
| q                 | j                   |
| r                 | i                   |
| s                 | h                   |
| t                 | g                   |
| u                 | f                   |
| v                 | e                   |
| w                 | d                   |
| x                 | c                   |
| y                 | b                   |
| z                 | a                   |

Nachdem Sie das Programm zur Verschlüsselung von Texten implementiert haben, erhalten Sie den folgenden
Atbasch-verschlüsselten Geheimtext. Überlegen Sie wie der Text mithilfe des zuvor implementierten Programms zum
Entschlüsseln des Geheimtextes verwendet werden kann und entschlüsseln Sie den Text mit Ihrem Programm. Sofern
Änderungen notwendig sind, begründen Sie diese. Beschreiben mithilfe von Kommentaren in Ihrem Programm wie Sie den Text
mit Ihrem Programm entschlüsseln können. Fügen Sie den entschlüsselten Text in die Datei `decrypted.txt` ein.

```text
dvoo wlmv!
zgyzhs rh z nlmlzokszyvgrx hfyhgrgfgrlm xrksvi lirtrmzoob fhvw gl vmxibkg
gsv svyivd zokszyvg. rg xzm yv nlwrurvw uli fhv drgs zmb pmldm dirgrmt hbhgvn
drgs z hgzmwziw xloozgrmt liwvi [sggkh://vm.drprkvwrz.lit/drpr/zgyzhs]. mlgv
gszg gsv zgyzhs xrksvi gvcg xzm yv vmxibkgvw zmw wvxibkgvw fhrmt gsv hznv
zotlirgsn.
```

## Hinweise

- In dem Header `ctype.h` stehen Funktionen bereit, die für das Arbeiten mit dem Datentyp `char` hilfreich sein können.
- Das bereitgestellte Programm (`s04e03.c`) kann als Grundlage für die Implementierung herangezogen werden. Es liest
  die einzelnen Zeichen von `stdin` ein und gibt diese wieder über `stdout` aus, solange bis keiner der beiden
  Werte `'#'` oder `EOF` eingelesen wird. Nachdem dieses Programm `ex.c` erfolgreich als `ex` kompiliert wurde, kann mit
  dem Aufruf `cat sample_text.txt | ./ex` der Inhalt der Datei `sample_text.txt` ausgegeben werden.
- Geben Sie ausschließlich den entschlüsselten Text aus!

# Aufgabe 4 (7 Punkte)

## Vorlesungsfolien

* Variablen und Datentypen (EidP-03-VariablenDatentypen.pdf)
* Kontrollstrukturen (EidP-05-Kontrollstrukturen.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches eine Zifferntreppe mit der Höhe `height` auf der Standardausgabe ausgibt. Die
Ganzzahl (`int`) `height` wird von dem\*der Benutzer\*in eingelesen.

## Ablauf

- Das Programm gibt den Text `"height: "` auf der Standardausgabe aus.
- Der\*die Benutzer\*in gibt die Höhe als Ganzzahl ein.
    - Wird durch die Eingabe das Format nicht erfüllt, wird das Programm mit einem entsprechenden Fehler beendet. Sie
      können einen entsprechenden, sinnvollen Text für die Fehlermeldung frei wählen!
    - Sofern die Höhe negativ ist, wird eine Fehlermeldung ausgegeben und das Programm nicht erfolgreich beendet. Sie
      können einen entsprechenden, sinnvollen Text für die Fehlermeldung frei wählen!
- Ausgabe eines Zeilenumbruchs.
- Die Zifferntreppe wird entsprechend dem Format der Beispielausgaben auf der Standardausgabe ausgegeben. Beachten Sie,
  dass jede Zahl mit einer Mindestbreite von zwei Stellen ausgegeben wird. Sofern die ausgegebene Zahl weniger als diese
  zwei Stellen aufweist, wird von links ein Leerzeichen eingefügt. Innerhalb einer Zeile werden keine weiteren Abstände
  ausgegeben.

## Beispiele

Beispiel 1: Programmablauf bei der Eingabe `2`. Die Zahl $`2`$ in der ersten Zeile der Beispielausgabe wurde
durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
height: 2

 1
 1 2
```

Beispiel 2: Programmablauf bei der Eingabe `4`. Die Zahl $`4`$ in der ersten Zeile der Beispielausgabe wurde
durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
height: 4

 1
 1 2
 1 2 3
 1 2 3 4
```

Beispiel 3: Programmablauf bei der Eingabe `12`. Die Zahl $`12`$ in der ersten Zeile der Beispielausgabe wurde
durch den\*die Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
height: 12

 1
 1 2
 1 2 3
 1 2 3 4
 1 2 3 4 5
 1 2 3 4 5 6
 1 2 3 4 5 6 7
 1 2 3 4 5 6 7 8
 1 2 3 4 5 6 7 8 9
 1 2 3 4 5 6 7 8 910
 1 2 3 4 5 6 7 8 91011
 1 2 3 4 5 6 7 8 9101112

```

## Hinweise

- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!

# Aufgabe 5 (8 Punkte)

## Vorlesungsfolien

* Variablen und Datentypen (EidP-03-VariablenDatentypen.pdf)

## Beschreibung

Erstellen Sie ein C-Programm, welches den Umriss eines um 45 Grad gedrehten Quadrats (Raute) mit Seitenlänge `a`
ausgibt. Die Seitenlänge `a` wird als `unsigned char` eingelesen und gespeichert.

## Ablauf

- Das Programm gibt den Text `"a: "` auf der Standardausgabe aus.
- Der\*die Benutzer\*in gibt einen Dezimalwert für `a` ein.
- Sofern die Variable `a` nach dem Einlesen den Wert 0 aufweist, wird die
  Fehlermeldung `"ERROR: The side length is zero!"` auf der Standardfehlerausgabe ausgegeben und das Programm nicht
  erfolgreich beendet.
- Ausgabe eines Zeilenumbruchs.
- Ansonsten wird der Umriss der Raute entsprechend ausgegeben. Die Formatierung ist von den Beispielausgaben zu
  entnehmen.

## Hinweise

- Um einen Backslash auszugeben, müssen Sie diesen escapen, d.h. zum Beispiel gibt `printf("\\")` einen einzelnen Backslash aus.
- Durch die Verwendung von entsprechenden Formatstrings kann die Ausgabe der Raute mit nur zwei aufeinanderfolgenden
  Schleifen realisiert werden. Dazu benötigen Sie das von `printf` unterstützte `width`-Flag mit `*` und entsprechender berechneter Länge. Sie können die Aufgabe aber alternativ auch in mehreren Einzelschritten lösen.
- Halten Sie sich genau an das Format der Beispiele und geben Sie keine weiteren Texte aus!
- Geben Sie Fehlermeldungen auf der Standardfehlerausgabe (`stderr`) aus. Dies kann beispielsweise durch folgendes
  Codefragment erreicht werden:

```c
fprintf(stderr, "ERROR: The side length is zero!\n");
```

## Beispiele

Beispiel 1: Möglicher Programmablauf bei der Eingabe `a` = `2`. Die Zahl `2` in der Beispielausgabe wurde durch den\*die
Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
a: 2

 /\
/  \
\  /
 \/
```

Beispiel 2: Möglicher Programmablauf bei der Eingabe `a` = `4`. Die Zahl `4` in der Beispielausgabe wurde durch den\*die
Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
a: 4

   /\
  /  \
 /    \
/      \
\      /
 \    /
  \  /
   \/
```

Beispiel 3: Möglicher Programmablauf bei der Eingabe `a` = `6`. Die Zahl `6` in der Beispielausgabe wurde durch den\*die
Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
a: 6

     /\
    /  \
   /    \
  /      \
 /        \
/          \
\          /
 \        /
  \      /
   \    /
    \  /
     \/
```

Beispiel 4: Möglicher Programmablauf bei der Eingabe `a` = `0`. Die Zahl `0` in der Beispielausgabe wurde durch den\*die
Benutzer\*in eingegeben und soll nicht von Ihrem Programm ausgegeben werden.

```text
a: 0

ERROR: The side length is zero!
```
