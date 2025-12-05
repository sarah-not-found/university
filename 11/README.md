# Aufgabe 1 (15 Punkte)

## Beschreibung

Ziel dieser Aufgabe ist es, ein Programm zu erstellen, welches u.a. das von der argentinischen Mathematikerin Lea Gorodisky veröffentlichte Rätsel (siehe [Hemmes mathematische Rätsel vom 15.1.2021](https://www.spektrum.de/raetsel/stellenteiler/1809020)) lösen kann:


 **"Ordnen Sie die Ziffern 1-9 so an, dass die Zahl, die von ihrer ersten Ziffer gebildet wird, durch 1 teilbar ist, die, die von ihren ersten beiden Ziffern gebildet wird, durch 2 teilbar ist, und so weiter, bis schließlich die, die von allen neun Ziffern gebildet wird, durch 9 teilbar ist."**

### Beispiel

Anordnung:  `123687945`

Überprüfung, ob die Anordnung einer Lösung des Rätsels entspricht:
- 1 ist ohne Rest durch 1 teilbar
- 12 ist ohne Rest durch 2 teilbar
- 123 ist ohne Rest durch 3 teilbar
- 1236 ist ohne Rest durch 4 teilbar
- **12368 ist nicht ohne Rest durch 5 teilbar**
- **123687 ist nicht ohne Rest durch 6 teilbar**
- 1236879 ist ohne Rest durch 7 teilbar
- **12368794 ist nicht ohne Rest durch 8 teilbar**
- 123687945 ist ohne Rest durch 9 teilbar

Somit ist diese Anordnung keine Lösung des Rätsels.

## Aufgabe

Implementieren Sie die im Template vorgegebene Funktion `my_list *compute_solutions(unsigned short max_digit)`, welche obiges Rätsel für die Ziffern 1 bis `max_digit` löst und alle Lösungen in einer Liste speichert und zurückgibt (`my_list` aus Aufgabenblatt 09).

Beispielsweise sollen für `max_digit = 6` die Ziffern 1-6 nach obiger Beschreibung angeordnet werden (eine mögliche Lösung wäre hier `"123654"`). Sie können davon ausgehen, dass für `max_digit` nur Werte von 1 bis 9 verwendet werden.

Verwenden Sie für die Anordnung der Zahlen einen String (`char *`). Wenn ein String der Lösung entspricht, fügen Sie diesen mithilfe der bestehenden Implementierung von `my_list` der Liste der Lösungen hinzu. Jedes Element der Liste ist somit ein String der Länge `max_digit`.

## Lösungshinweise

Prinzipiell sind Sie in Ihrer Implementierung völlig frei, d.h. außer `compute_solutions` sind keinerlei Funktionen zwingend notwendig.

Generell empfiehlt sich folgende Vorgehensweise:
- Starten Sie bei der Anordnung `"123..."` bis inklusive `max_digit`
- Ordnen Sie das Array auf alle möglichen Weisen um (berechnen Sie alle Permutationen)
- Überprüfen Sie für jede Anordnung (Permutation), ob diese eine Lösung des Rätsels ist.
- Wenn ein String eine Lösung ist, fügen Sie ihn zur Liste der Lösungen hinzu. Beachten Sie, dass Sie die aktuelle Anordnung an eine neue Speicherstelle kopieren müssen, da sie ansonsten mit der nächsten Permutation verloren geht (siehe Kapitel Zeiger). Suchen Sie sich hierfür eine geeignete Funktion aus der Bibliothek `string.h` (Achtung: in Artemis sind nur Funktionen zulässig, die im C-Standard definiert sind, d.h. z.B. die Verwendung von `strndup` ist nicht möglich)

### Erweiterte Lösungshinweise

In diesem Abschnitt wird ein möglicher Lösungsansatz genauer skizziert.

#### Mögliche Funktionen
- `long long compute_number_from_string(char *digits, unsigned short to_index)`: berechnet die Zahl, die sich aus den ersten `to_index` Ziffern des übergebenen Strings `digits` ergibt. Zum Beispiel ergibt `compute_number_from_string("123456789", 4)` die Zahl `1234`.
- `int is_solution(char *digits)`: überprüft, ob der übergebene String `digits` einer Lösung entspricht.
- `void swap(char *str, size_t index1, size_t index2)`: tauscht beim String `str` die Zeichen an den Indizes `index1` bzw. `index2`.

#### Algorithmus

Zum Testen aller möglichen Permutationen des Ziffernstrings kann ein einfacher rekursiver Ansatz verwendet werden. Folgender [Pseudocode](https://en.wikipedia.org/wiki/Pseudocode) skizziert den schlussendlichen Algorithmus:

```c
check_and_permute(digits, start, end)
  if start = end {
    Überprüfe, ob digits einer Lösung entspricht.      
    return
  }

  for (i = start; i <= end; i++) {
    swap digits[i] and digits[start]
    check_and_permute(digits, start + 1, end)
    swap digits[i] and digits[start]
  }
```

Der erste Aufruf von `check_and_permute` verwendet dabei `start = 0` und `end = max_digit-1`.
Beachten Sie, dass Sie der Funktion ggf. noch weitere Parameter mitgeben müssen. Diese ergeben sich aus der Verwendung der obigen Funktionen (falls verwendet).

## Hinweise

- Übertragen Sie Ihre `my_list` Implementierung in die Datei `my_list.c`.
- Die Reihenfolge der Lösungen in der Liste spielen keine Rolle.
  - Es gibt nicht für alle `max_digit`-Belegungen Lösungen. In diesem Fall bleibt die Liste leer.
