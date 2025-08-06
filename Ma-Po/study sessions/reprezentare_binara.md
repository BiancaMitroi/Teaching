## De ce este utila baza de numeratie 2?

Sistemele de calcul au la dispozitie doar "trece curent" (1) sau "nu trece curent" (0) ca si "simboluri" de reprezentare a numerelor.

Pentru un sistem de calcul, bitul este cea mai mica unitate de informatie care poate avea 2 stari: 0 sau 1.

Tot ceea ce exista in calculator este stocat pe biti (fisiere text, poze, filmulete, cod, etc.)

Toata informatia stocata in calculator ocupa o cantitate finita de memorie. De exemplu un fisier poate ocupa/avea dimensiunea de 10 KB (kilobytes). 

### Unitati de masura a dimensiunii in memorie

1 B (byte) = 8 biti (un octet)

1 KB = 1024 B ($2^{10}$)

1 MB (megabyte) = 1024 KB

1 GB (gigabyte) = 1024 MB

1 TB (terrabyte) = 1024 GB

Numerele intregi se pot reprezenta pe 1, 2 sau 4 octeti.

Numarul 5 in baza 10 este 101 in baza 5

In memorie, pe un octet se reprezinta `00000101`

## Baza de numeratie 16

Este foarte utila deoarece cu ea poti reprezenta ASCII si se incadreaza pe dimensiunile cu care un calculator poate lucra. Pentru a converti din baza 2 in baza 16, iei grupuri de cate 4 din numarul in baza 2 si le convertesti pe rand in baza 16. Dupa le alaturi and that's all.
In baza 16 ai 16 simboluri: cifrele de la 0 la 9 si literele de la A la F.

De exemplu numarul 30 in baza 10 (0001 1110 in baza 2) este 1E in baza 16. (0001 -> 1, 1110 -> E in baza 16, 14 in baza 10)

P.S. reprezentarea ASCII este un mod de a reprezenta si alte simboluri (litere sau caractere speciale) pe biti.

De exemplu litera `a` se reprezinta `01100001` care poate fi si nr 97. Diferenta o face programul sau utilizatorul care gestioneaza informatia asta (pentru ca da, ii poti spune calculatorului sa-ti interpreteze acelasi lucru in moduri diferite in functie de ce ai nevoie). De exemplu poti gasi intr-un fisier scris un numar in baza 16 (hexazecimal) care sa fie `72 75 6E` si de fapt sa insemne `run` :))