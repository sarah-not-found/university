# Einführung in die Programmierung 25W (EidP)

Dieses Repository beinhaltet die Materialien, welche für das Proseminar _Einführung in die
Programmierung_ ([703004](https://lfuonline.uibk.ac.at/public/lfuonline_lv.details?sem_id_in=25W&lvnr_id_in=703004)) im Wintersemester 2025 erforderlich sind.

**Lesen Sie dieses Dokument sorgfältig durch, da es wichtige Information über das Proseminar enthält.**

## Ziele

- Erwerben grundlegender Programmierkenntnisse und -fähigkeiten in C auf Basis des Stoffes aus
  der [Vorlesung](https://lfuonline.uibk.ac.at/public/lfuonline_lv.details?sem_id_in=25S&lvnr_id_in=703003)
    - Variablen und Datentypen
    - Operatoren und Ausdrücke
    - Kontrollstrukturen
    - Funktionen
    - Arrays
    - Zeiger
    - Zusammengesetzte Datentypen
    - Dynamische Speicherverwaltung
    - Präprozessor und modulare Programmierung
    - Ein-/Ausgabe
- Arbeiten mit Tools und Software für die C-Programmierung
    - [`gcc`](https://gcc.gnu.org/)
    - [GNU Make](https://www.gnu.org/software/make/)
    - [`valgrind`](https://valgrind.org/)
    - [Linux](https://en.wikipedia.org/wiki/Linux) (in Eigenregie)

## Der PS-Modus zusammengefasst
- Ausarbeitung von wöchentlichen Aufgaben + Präsentation
- Sie benötigen eine Mindestanzahl an gelösten Aufgaben
- wird diese Mindestanzahl nicht erreicht: Nicht Genügend
- andernfalls ergibt sich die Note ausschließlich über Midtermtests (Anzahl der gelösten Aufgaben fließt nicht in die Note ein)

## Termine

Im Proseminar *Einführung in die Programmierung* werden die Hausübungen, welche außerhalb des Proseminars in
**Einzelarbeit** gelöst werden müssen, besprochen. Dafür werden Studierende ausgewählt, die ihre Lösung präsentieren und
Fragen dazu beantworten müssen.

Sämtliche Aufgaben, die von Ihnen im Laufe des kommenden Semesters als Hausübungen bearbeitet werden müssen, werden
Ihnen über dieses Repository bereitgestellt. Die bereitgestellten Aufgaben werden – abgesehen von der Korrektur von Tippfehlern oder Ergänzung von Klarstellungen – nicht mehr verändert. Dementsprechend können Sie, wenn Sie möchten, vorarbeiten und die im Laufe dieses Semesters zu lösenden Aufgaben bereits früher bearbeiten. Zusätzlich werden die Aufgaben spätestens eine Woche vor Ende der jeweiligen Abgabefrist in
[Artemis](https://artemis.codeability.uibk.ac.at/) freigeschaltet.

| **PS-Termin** | **Blatt**          | **Teil** | **Veröffentlichung (Artemis)** | **Fälligkeit (Artemis)** | **Inhalt**                                                            |
|---------------|--------------------|----------|--------------------------------|--------------------------|-----------------------------------------------------------------------|
| 07.10.25      | 00                 |          |                                |                          | Einführung in Artemis                                                 |
| 14.10.25      | 01                 | 1        | 06.10.25                       | 13.10.25 16:00           | Vorschau                                                              |
| 21.10.25      | 02                 | 1        | 13.10.25                       | 20.10.25 16:00           | Variablen & Datentypen                                                |
| 28.10.25      | 03                 | 1        | 20.10.25                       | 27.10.25 16:00           | Operatoren & Ausdrücke                                                |
| 04.11.25      | 04                 | 1        | 27.10.25                       | 03.11.25 16:00           | Kontrollstrukturen                                                    |
| **11.11.25**  | **Test 1**         |          |                                |                          | **Themen der Blätter 01-04**                                          |
| 18.11.25      | 05                 | 2        | 03.11.25                       | 17.11.25 16:00           | Funktionen                                                            |
| 25.11.25      | 06                 | 2        | 17.11.25                       | 24.11.25 16:00           | Arrays                                                                |
| 02.12.25      | 07                 | 2        | 24.11.25                       | 01.12.25 16:00           | Zeiger                                                                |
| **09.12.25**  | **Test 2**         |          |                                |                          | **Themen der Blätter 01-07**                                          |
| 16.12.25      | 08                 | 3        | 01.12.25                       | 15.12.25 16:00           | Strukturen, Unions, Bitfelder                                         |
| _23.12.25_    | _Weihnachtsferien_ |          |                                |                          |
| _30.12.25_    | _Weihnachtsferien_ |          |                                |                          |
| _06.01.26_    | _Weihnachtsferien_ |          |                                |                          |
| 13.01.26      | 09                 | 3        | 15.12.25                       | 12.01.26 16:00           | Dynamische Speicherverwaltung, Modulare Programmierung & Präprozessor |
| 20.01.26      | 10, 11\*           | 3, 1-3\* | 12.01.26                       | 19.01.26 16:00           | Ein-/Ausgabe + Bonus                                                  |
| **27.01.26**  | **Test 3**         |          |                                |                          | **Themen der Blätter 01-10**                                          |

Blatt 11 ist optional und erhaltene Punkte können als Zusatzpunkte für alle Teile angerechnet werden (siehe Benotung). 

## Gruppen

| Gruppe | Zeit          | Raum  | Leiter                                                                                                   |
|-------:|---------------|-------|----------------------------------------------------------------------------------------------------------|
|      1 | 08:30 - 10:00 | rr 15 | [Peter Thoman](mailto:Peter.Thoman@uibk.ac.at?subject=[LV%20703004]%20%3CMein%20Anliegen%3E)             |
|      2 | 12:00 - 13:30 | rr 21 | [Michael Tschuggnall](mailto:Michael.Tschuggnall@uibk.ac.at?subject=[LV%20703004]%20%3CMein%20Anliegen%3E)                  |
|      3 | 13:45 - 15:15 | rr 15 | [Michael Tschuggnall](mailto:Michael.Tschuggnall@uibk.ac.at?subject=[LV%20703004]%20%3CMein%20Anliegen%3E)                  |
|      4 | 15:30 - 17:00 | rr 15 | [Harald Schweiger](mailto:Harald.Schweiger@uibk.ac.at?subject=[LV%20703004]%20%3CMein%20Anliegen%3E)     |
|      5 | 08:30 - 10:00 | rr 20 | [Michael Tschuggnall](mailto:Michael.Tschuggnall@uibk.ac.at?subject=[LV%20703004]%20%3CMein%20Anliegen%3E) |
|      6 | 12:00 - 13:30 | rr 20 | [Markus Walzthöni](mailto:Markus.Walzthoeni@uibk.ac.at?subject=[LV%20703004]%20%3CMein%20Anliegen%3E)                   |
|      7 | 13:45 - 15:15 | rr 20 | [Markus Walzthöni](mailto:Markus.Walzthoeni@uibk.ac.at?subject=[LV%20703004]%20%3CMein%20Anliegen%3E)    |



## Hausübung und Abgabe

In Summe gibt es 10 Aufgabenblätter, wobei jedes Aufgabenblatt 30 Punkte wert ist. Eine Aufgabe gilt als gelöst, sofern
Sie alle Anforderungen der Aufgabenstellung erfüllt und **in Artemis 100%** erreicht haben. Damit Sie die Punkte erhalten,
müssen Sie 
- die Lösungen eigenständig erarbeiten (keine Teamarbeit)
- die Lösungen vor der Deadline über Artemis abgeben, **und**
- **im entsprechenden Proseminar anwesend sein.**

Die Deadline für das Abgeben der Aufgaben ist jeweils **um 16:00 Uhr am Vortag des Proseminars**.

Bei der Korrektur oder während der Präsentation einer Aufgabe können durch die/den ProseminarleiterIn die erreichten Punkte
der Aufgabe angepasst werden. Die Punkte werden gegebenenfalls durch die Proseminarleiter in OLAT angepasst.

Generell kann es aufgrund folgender Kriterien zu Punktereduktionen kommen:
- Die Lösung kann nicht oder nur unzureichend erklärt werden (Folge: Verlust der **gesamten Punkte des aktuellen Aufgabenblattes**). _Beispiel: Sie lassen sich Ihre Lösung von einer KI generieren, kopieren deren Lösung nach Artemis und erhalten dort 100%. Im PS können Sie diese Lösung aber nur teilweise (durch "Vorlesen") erklären._
- Das Abgeben einer konstruierten, fehlerhaften Lösung für eine Programmieraufgabe, mit dem Ziel die automatisierte Überprüfung in Artemis zu umgehen (Folge: Verlust der **gesamten Punkte des aktuellen Aufgabenblattes**).
- Die gewählte Formatierung beeinträchtigt die Lesbarkeit der Lösung.
- Die Abgabe ist keine zufriedenstellende Lösung für die Aufgabe bzw. eine Lösung einer anderen Aufgabe.

Kommt es aufgrund der zwei ersten genannten Punkte zweimalig zu einem vollständigen Abzug der Punkte eines Blattes, wird das gesamte Proseminar mit *Nicht Genügend* bewertet. 

## Präsentation von Lösungen

Für jede Aufgabe wird von Ihrer/Ihrem ProseminarleiterIn aus allen anwesenden Studierenden, welche die Aufgabe abgegeben und in Artemis 100% erreicht haben, eine Person für die Präsentation ausgewählt. Sollte die Präsentation aufgrund der oben gelisteten Kriterien nicht zufriedenstellend sein, führt dies zum Punkteverlust der
**gesamten Punkte des Aufgabenblattes**.

Bitte achten Sie darauf, dass alle Kommiliton\*innen Ihrer Präsentation folgen können. Nach Vorstellung einer Aufgabe sollten alle Studierenden in der Lage sein, die Aufgabe eigenständig zu lösen. Erklären Sie bei Programmieraufgaben, bei denen die Aufgabenstellung keine konkrete Umsetzung vorschreibt, zuerst die Idee Ihrer Lösung, bevor Sie auf den Quellcode eingehen.
Die PS-LeiterInnen werden Ihnen diesbzgl. Hilfestellung geben.

Die Präsentationen haben (bis auf einen möglichen Punkteverlust) ansonsten **keinerlei Einfluss auf die Note**. Sie dienen lediglich dazu, stichprobenweise zu verifizieren, ob Sie die Aufgaben selbst gelöst haben sowie zur allgemeinen Diskussion der Lösungsansätze.

## Anwesenheit

Da Proseminare prüfungsimmanente Lehrveranstaltungen sind, gilt grundsätzlich Anwesenheitspflicht. Ihre Anwesenheit wird durch Ihre/n ProseminarleiterIn über Anwesenheitslisten sichergestellt.

Bitte beachten Sie für Abwesenheiten **jeglicher Art** folgende Aspekte:

- Sind Sie in einer Proseminareinheit nicht anwesend, erhalten Sie **grundsätzlich keine Punkte** für Ihre Bearbeitung **des gesamten besprochenen Aufgabenblattes**. Dies gilt unabhängig davon, ob Sie die Aufgaben vor der Deadline abgegeben haben oder nicht.
- Sofern Sie nicht rechtzeitig zum Proseminar kommen, kann dies als Abwesenheit gezählt werden. Folglich können Sie durch Verspätungen auch alle Punkte eines Übungsblatts verlieren.
- Ihr/e ProseminarleiterIn kann nach eigenem Ermessen Punkte für Aufgaben aberkennen, sollten Sie zu spät kommen und/oder während des Proseminars zwischenzeitlich abwesend sein (z.B. längere Toilettenaufenthalte, Telefonate etc.).
- Ihre Anwesenheit gilt ausschließlich, wenn Sie die Proseminargruppe besuchen, die Ihnen zugeordnet wurde! Ausnahmen von dieser Regel müssen vor dem entsprechenden Proseminartermin von Ihrem/r ProseminarleiterIn gewährt werden.

## Abmeldung

Wenn Sie sich vom Proseminar abmelden möchten, ist dies bis zum **Fr, 24.10.2025** möglich. In diesem Fall erhalten Sie keine Note. Nach dem 24.10.2025 ist eine Abmeldung nicht mehr möglich und es wird jedenfalls eine Note vergeben (Nicht Genügend). Für die Abmeldung senden Sie bitte Ihrer/Ihrem ProseminarleiterIn vor der Deadline eine formlose E-Mail. Sie müssen keinen Grund für die Abmeldung angeben.

Falls Sie beabsichtigen, das Proseminar nach dem 24.10.2025 abzubrechen, ist es für Ihre/n ProseminarleiterIn hilfreich, wenn Sie dieser/m diesbezüglich eine kurze Information per E-Mail zukommen lassen. Bitte beachten Sie, dass auch bei Abmeldung per E-Mail wie oben beschrieben eine Note vergeben wird.

## Benotung

### Midtermtests

Es finden im Laufe des Semesters 3 Tests statt. Dabei können Sie bis zu 100 Punkte pro Test erhalten. 
Die **zwei besten Ergebnisse** bei diesen Tests werden für die Bewertung herangezogen.
Fehlen Sie bei einem Test, wird dieser mit **0 Punkten** bewertet und **kann nicht nachgeholt werden**. 


| Datum    | Test Nummer | Themen                         |
|----------|:-----------:|--------------------------------|
| 11.11.25 |      1      | Alle Themen der Blätter 01-04  |
| 09.12.25 |      2      | Alle Themen der Blätter 01-07  |
| 27.01.26 |      3      | Alle Themen der Blätter 01-10 |

Die Termine sind in [LFU:online](https://lfuonline.uibk.ac.at/public/lfuonline_lv.details?sem_id_in=25W&lvnr_id_in=703004) vermerkt, eine Anmeldung ist aber **nicht nötig**.

Für die Bearbeitung der Midtermtests dürfen Sie sämtliche Unterlagen aus der Vorlesung sowie Ihre ausgearbeiteten Übungsaufgaben verwenden. **Nicht erlaubt** ist hingegen:
* Verwendung des Internets (weder für Suche noch für Kommunikation)
* Zusammenarbeit mit Sitznachbarn oder anderen Studierenden
* Verwendung von externen AI-Tools
* Verwendung von integrierten AI-Tools in Ihrer IDE bzw. Editor

Bei Verletzung einer oder mehrerer Regeln hat der/die ProseminarleiterIn die Möglichkeit, nach eigenem Ermessen eine oder mehrere Aufgaben sowie im Falle auch den ganzen Test mit 0 Punkten zu bewerten.

### Bewertung der Midtermtests

Von den insgesamt 3 Midtermtests werden die beiden Tests mit den meisten Punkten zur Benotung verwendet, d.h. zusammengezählt und gemittelt. Dies bedeutet, dass Sie auch noch 100% der Midtermtestpunkte erreichen können, wenn Sie bei einem Test (z.B. aus gesundheitlichen Gründen) nicht mitschreiben.

Folgende Formel berechnet die erreichte Prozentzahl aus den Midtermtests:  

```math
p=\frac{\text{Midterm 1} + \text{Midterm 2} + \text{Midterm 3} - min (\text{Midterm 1}, \text{Midterm 2}, \text{Midterm 3})}{2 \cdot 100} \cdot 100
```

### Voraussetzung für eine positive Endnote

Um sich für eine positive Endnote zu qualifizieren, müssen **alle folgenden Kriterien erfüllt** werden:

- **Mindestens 33%** der Punkte von **Teil 1** (Blatt 01 bis 04)
- **Mindestens 33%** der Punkte von **Teil 2** (Blatt 05 bis 07)
- **Mindestens 33%** der Punkte von **Teil 3** (Blatt 08 bis 10)
- **Mindestens 60% der insgesamt erreichbaren Punkte** (d.h. mindestens 180 von insgesamt 300 erreichbaren Punkten)
 
Punkte aus dem Bonusblatt 11 können zu allen Teilen addiert werden.


### Endnote

Sofern diese Anforderungen erfüllt werden, wird basierend auf der bei den Tests erreichten Prozentzahl die Endnote wie folgt ermittelt:


|        Prozent | Note               |
|---------------:|--------------------|
|      [90, 100] | 1 (Sehr gut)       |
|       [80, 90) | 2 (Gut)            |
|       [70, 80) | 3 (Befriedigend)   |
|       [60, 70) | 4 (Genügend)       |
|        [0, 60) | 5 (Nicht genügend) |

Eine besonders gute und aktive Mitarbeit kann die Note zusätzlich positiv beeinflussen.

## Programmierrichtlinien

Alle Programmieraufgaben müssen in der Programmiersprache C gelöst werden. Stellen Sie sicher, dass Ihr Programm
mit `gcc` und den Optionen `-Wall -Wextra -Werror -Wpedantic -std=c18` erfolgreich kompiliert.

Formatieren Sie Ihren Code einheitlich. Am besten durch die Unterstützung einer IDE, eines Texteditors oder mit einem
Tool (z. B. [clang-format](https://clang.llvm.org/docs/ClangFormat.html), ein Beispiel
einer [`.clang-format`](.clang-format)-Datei finden Sie in diesem Repository).

Versuchen Sie durch eine einheitliche Struktur und erklärende Namen "selbstdokumentierenden Code"
(engl. [self-documenting code](https://en.wikipedia.org/wiki/Self-documenting_code)) zu schreiben. Fügen Sie bei Bedarf
beschreibende Kommentare ein. Wenn Sie ein `TODO`, welches in einem bereitgestellten Template enthalten ist, erledigt
haben, löschen Sie diesen Kommentar!

Schreiben Sie in Quellcode-Dateien alles in Englisch (z. B. Kommentar, textuelle Ausgaben und Bezeichnungen von
Variablen, Funktionen und Strukturen).

## Artemis

Artemis ist eine Lernplattform, welche Ihnen schnelles und personalisiertes Feedback für Ihre Lösungen von
Programmieraufgaben bereitstellt. Derzeit werden in Artemis nur Programmieraufgaben automatisiert getestet. Alle anderen
Aufgaben werden nach der Abgabefrist von den Proseminarleitern überprüft.

Beachten Sie bitte beim Arbeiten mit Artemis die folgenden Punkte:

- **Bitte benennen Sie die in Artemis vorgegebenen Dateien nicht um!**
- Teilweise wird durch Artemis die Ausgabe von Ihrem Programm überprüft. Hierbei ist Artemis meist sehr strikt, um Ihnen
  ein möglichst genaues Feedback geben zu können. Deshalb ist es wichtig, dass Sie sich genau an das vorgegebene Format
  halten und keine anderen oder weiteren Texte ausgeben!
- Sofern Sie sicher sind, dass Ihre Lösung die Aufgabe vollständig erfüllt und Artemis Ihre Lösung nicht als korrekt
  bewertet, kontaktieren Sie bitte Ihre/n ProseminarleiterIn.

Weitere Informationen bezüglich Artemis – beispielsweise was ein Ein-/Ausgabetest ist – finden Sie in
den [Frequently Asked Questions (FAQ)](FAQ.md).

Artemis soll Sie bei der Endkontrolle und Qualitätssicherung Ihrer Lösung unterstützen. Ein inkrementelles Testen von
Teilaspekten der Lösung wird nur bedingt unterstützt. Aus diesem Grund wird Ihnen folgender Workflow für das Bearbeiten
von Programmieraufgaben mit Artemis empfohlen:

1. Lesen Sie die Aufgabenstellung genau durch.
2. Implementieren Sie die Lösung auf Ihrem Rechner.
3. Kompilieren und testen Sie Ihre Lösung auf Ihrem Rechner.
4. Testen Sie die Aufgabe in Artemis. Sofern die Aufgabe nicht $`100\,%`$ erreicht, lesen Sie das Feedback durch, passen
   Sie Ihre Lösung an und gehen Sie zurück zu Schritt 3.

## Kommunikation

Bei **allgemeinen Fragen zu Aufgabenstellungen oder Bewertung**, welche für andere Studierende möglicherweise
interessant sind, nutzen Sie bitte das [OLAT-Forum](https://lms.uibk.ac.at/url/RepositoryEntry/5697863708/CourseNode/110299517241721). Auf diese Weise können wir einen direkten Austausch ermöglichen.

Bei **etwaigen anderen Fragen** zögern Sie nicht, Ihre/n ProseminarleiterIn zu kontaktieren. Gerne
hilft Ihnen diese/r weiter. Für die Kontaktaufnahme stehen Ihnen der Studentenchat, E-Mail und gegebenenfalls
Sprechstunden zur Verfügung. Um sicherzustellen, dass Ihr Anliegen rasch bearbeitet
werden kann, beachten Sie bitte folgende Aspekte:

- Wenn Sie Ihre/n ProseminarleiterIn via E-Mail kontaktieren, verwenden Sie bitte ausschließlich den E-Mailaccount der Universität Innsbruck und einen entsprechenden Betreff.
- Bitte geben Sie im Text oder Betreff den **Kurs sowie Ihre Proseminargruppe** an.
- Stellen Sie Ihre Frage so präzise wie möglich bzw. beschreiben Sie Ihr Problem genau, sodass Ihr Anliegen
  nachvollzogen werden kann.
- Wenn Ihr Anliegen eine Aufgabe betrifft, geben Sie an, um welches Aufgabenblatt und welche Aufgabennummer es sich handelt.
- Fügen Sie Ihren Code als Anhang in einer extra Datei an. 

### Kommunikation außerhalb der Proseminareinheiten

Für die Kommunikation von Informationen wird außerhalb der Proseminareinheiten E-Mail verwendet. Bitte stellen Sie
sicher, dass Sie die E-Mails Ihres Accounts der Universität lesen. Falls Sie Ihren Uni-Mail-Account in ein Mail-Programm
auf einem Ihrer persönlichen Geräte integrieren möchten, finden Sie
dazu [hier](https://www.uibk.ac.at/zid/faq/einstellungen.html) weitere Informationen.

## Sonstiges

- Die Deadlines werden strikt eingehalten!
- Treten in Artemis Probleme auf, nehmen Sie sich bitte die Zeit und informieren Sie Ihre/n ProseminarleiterIn oder [Michael Tschuggnall](mailto:Michael.Tschuggnall@uibk.ac.at?subject=[LV%20703004]%20Artemis:%20%3CAnliegen%3E).
- Es werden nicht alle Aspekte aller Aufgaben von Artemis getestet. Sie sind dafür verantwortlich, dass Ihre Lösung die Anforderungen der Angabe erfüllt. Stellen Sie deshalb sicher, dass Sie die Angaben immer sorgfältig lesen und vollständig bearbeiten.
- Es ist nicht möglich, Punkte zu kompensieren, die beispielsweise aufgrund eines Plagiats, einer Korrektur oder dem Versäumen der Deadline verloren wurden.
- Ersatz- bzw. Zusatzaufgaben, durch welche zusätzliche Punkte erreicht werden können, gibt es nicht.
- Es werden keine Musterlösungen bereitgestellt. Nach Vorstellung einer Aufgabe sollen alle Studierenden in der Lage sein, die Aufgabe eigenständig zu lösen.

## Tutorium

Jeden Donnerstag nach der Vorlesung von 16.30-17.15 im HSB 5.
Erstes Tutorium: Do, 9.10.2025

Tutor: Adam Pescoller

Kontakt: [Adam.Pescoller@student.uibk.ac.at](mailto:Adam.Pescoller@student.uibk.ac.at)
