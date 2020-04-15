# URA-Homework-2
Fakultet elektrotehnike Tuzla - Uvod u racunarske algoritme 


## Napomena

U svim problemima koji slijede nije dozvoljena upotreba komandi i funkcija koje dosad nisu
korištene na predavanjima ili vježbama. Dozvoljena je upotreba kontejnera iz standardne
biblioteke (std::vector i std::list), kao i C nizova.

## Zadatak 1:

Program sa standardnog ulaza čita duge sekvence brojeva koje dolaze neodređenim i
slučajnim redoslijedom i, nakon prihvatanja svih vrijednosti u odgovarajući kontejner, u
daljem izvođenju vrši velik broj pretraživanja unutar te sekvence. Potrebno je implementirati
osnovne funkcije programa (čitanje, upisivanje i pretraživanje) tako da vremenska složenost
izvođenja programa bude minimalna. Obrazložiti implementirano rješenje i uporediti ga sa
drugim, neoptimalnim, rješenjima koja omogućavaju iste funkcionalnosti.

## Zadatak 2:

Ilustrirati izvršavanje ​ _bubble sort_ ​ algoritma na sljedećem nizu cijelih brojeva:
**A = {7, 18, 52, 20, 22, 46, 51, 17, 88};**
Za svaku iteraciju izvršenja algoritma napisati sadržaj niza u tom trenutku.

## Zadatak 3:

Ilustrirati izvršavanje ​ _sheell sort_ ​ algoritma na sljedećem nizu cijelih brojeva:
**A = {9, 13, 58, 23, 19, 57, 88, 21, 7};**
Za svaku iteraciju izvršenja algoritma napisati sadržaj niza u tom trenutku.


## Zadatak 4:

Neka je data klasa ​Tim​ definisana na sljedeći način:
**class** ​ Tim{
**public** ​:
**string** ​ naziv;
**int** ​ bodovi;
**int** ​ primljeniGolovi;
**int** ​ postignutiGolovi;
};
Napisati funkciju koja sortira niz objekata klase Tim proizvoljne dužine tako da budu
zadovoljeni sljedeći kriteriji:

- timovi na kraju treba da budu sortirani po broju bodova u rastućem redoslijedu
- ukoliko postoji više timova sa istim brojem bodova, bolje pozicionirani tim je tim sa boljom
gol-razlikom (razlikompostignutih i primljenih golova)
- ukoliko postoji više timova sa istomgol-razlikom, bolje pozicioniran je tim sa većim
brojem postignutih golova
- ukoliko postoji dva ili više timova sa istim brojem postignutih i primljenih golova te
istim brojem bodova, u konačnom poretku treba da budu međusobno poredani po
rastućem abecednom redoslijedu
Implementirani algoritam treba biti in-place i imati minimalnu moguću složenost.
Objasniti implementirano rješenje.

