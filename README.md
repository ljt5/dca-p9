# dca-p9

El repositorio en GitHub está público [aquí](https://github.com/ljt5/dca-p9). Puede ser útil verlo para ver este documento formateado correctamente en markdown.
He creado dos alias locales, se pueden ver en `.git/config`. Uno para status y otro para hacer log personalizado de los commits:
```
st = status
log-bonito = log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold green)(%ar)%C(reset) %C(white)%s%C(reset) %C(dim white)-%an%C(reset)%C(bold yellow)%d%C(reset)' --all
```
El repositorio son una serie de ejercicios de programación, cada ejercicio es un commit. Para **git bisect** introduje un fallo en el ejercicio 2 en un commit intermedio. De forma que le proporciono como commit malo el último (ejercicio 8) y como bueno el commit del ejercicio 2 en el que sabíamos que aún funcionaba bien. Nos sugiere el ejercicio 5 que funciona mal, entonces nos sugiere el 4 y como funciona bien nos indica que el commit del ejercicio 5 fue el que introdujo el fallo. Aquí se puede ver como lo he usado:

```
ljt5@ljt5-VirtualBox:~/Documents/DCA/dca-p9$ git bisect start
ljt5@ljt5-VirtualBox:~/Documents/DCA/dca-p9$ git bisect bad d3f5786
ljt5@ljt5-VirtualBox:~/Documents/DCA/dca-p9$ git bisect good d7a1be9
Bisecting: 2 revisions left to test after this (roughly 2 steps)
[3dfd001f010e3c432295056f1779a33c85aa769d] ej5
ljt5@ljt5-VirtualBox:~/Documents/DCA/dca-p9$ g++ -g -Wall p0main.cc p0.cc -o p0
ljt5@ljt5-VirtualBox:~/Documents/DCA/dca-p9$ ./p0
1 - Ej 1
2 - Ej 2
3 - Ej 3
4 - Ej 4
5 - Ej 5
0 - Salir
Introduce el Ej: 2
Introduce el nº de elementos del vector:4
Introduce elemento nº0: 2
Introduce elemento nº1: 2
Introduce elemento nº2: 51
Introduce elemento nº3: 2
El vector:
[2 2 51 2 ]
nº pares: 3
1 - Ej 1
2 - Ej 2
3 - Ej 3
4 - Ej 4
5 - Ej 5
0 - Salir
Introduce el Ej: 0
ljt5@ljt5-VirtualBox:~/Documents/DCA/dca-p9$ git bisect bad
Bisecting: 0 revisions left to test after this (roughly 1 step)
[beab1e35211bf19ba5df6f8293e3dcc3d41e7206] ej4
ljt5@ljt5-VirtualBox:~/Documents/DCA/dca-p9$ g++ -g -Wall p0main.cc p0.cc -o p0
ljt5@ljt5-VirtualBox:~/Documents/DCA/dca-p9$ ./p0
1 - Ej 1
2 - Ej 2
3 - Ej 3
4 - Ej 4
0 - Salir
Introduce el Ej: 2
Introduce el nº de elementos del vector:4
Introduce elemento nº0: 2
Introduce elemento nº1: 2
Introduce elemento nº2: 51
Introduce elemento nº3: 2
El vector:
[2 2 51 2 ]
nº pares: 2
1 - Ej 1
2 - Ej 2
3 - Ej 3
4 - Ej 4
0 - Salir
Introduce el Ej: 0
ljt5@ljt5-VirtualBox:~/Documents/DCA/dca-p9$ 
ljt5@ljt5-VirtualBox:~/Documents/DCA/dca-p9$ git bisect good
3dfd001f010e3c432295056f1779a33c85aa769d is the first bad commit
commit 3dfd001f010e3c432295056f1779a33c85aa769d
Author: Luis Jiménez Tortosa <ljt5@alu.ua.es>
Date:   Wed Dec 29 21:09:34 2021 +0100

    ej5

 p0.cc     | 38 ++++++++++++++++++++++++++++++++++----
 p0.h      |  3 +++
 p0main.cc |  8 ++++++++
 3 files changed, 45 insertions(+), 4 deletions(-)
ljt5@ljt5-VirtualBox:~/Documents/DCA/dca-p9$ git bisect reset
Previous HEAD position was beab1e3 ej4
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
```
Por último para el **hook** he creado uno muy simple en `prepare-commit-msg` que muestra un mensaje al realizar un commit pidiendo que introduzcas un mensaje útil para el commit. 
