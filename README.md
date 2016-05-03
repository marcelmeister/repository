Coding-Style
------------------------------------------------------------------------------

* Klassen groß, z.B. Matrix oder Quaternion
* Funktionen und Methoden _klein_, z.B. Quaternion.toAxisAngle()
* Bei Benennungen möglichst CamelCase
* Einrücken mit 4 Spaces (keine Tabs)
* Pro Zeile möglichst weniger als 80 Zeichen


Hinweis für Mac-User
------------------------------------------------------------------------------

* qmake auf Pro-File ausführen (falls nicht im Pfad, z.B. wie folgt):
  ~/Qt5.6.0/5.6/clang_64/bin/qmake -spec macx-xcode Sinus.pro


Hinweis für Windows-User
------------------------------------------------------------------------------

* Project-Files alternativ auf Kommandozeile im Ordner mit Pro-File erzeugbar:
  qmake -spec win32-msvc2015 -tp vc
