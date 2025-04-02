Wartości na stosie podczas wywołania funkcji można sobie podejrzeć na przykład za pomocą debuggera gdb.
Jako przykład weźmy rekurencyjną funkcję z pliku `silnia.cpp`, liczącą silnię rekurencyjnie.

Na początek skompilujmy program instrukcją  `gcc main.c silnia.c -g -O1 -no-pie -fno-pie`. 
W skrócie opisując użyte flagi:

* `-g` jest flagą dla debuggera $-$ dzięki niej możemy w gdb podejrzeć dodatkowo kod w `C`, widzimy nazwy zmiennych itp. 
* `-O1` $-$ użycie lepszych optymalizacji skutkuje usunięciem rekurencji z naszej funkcji :).
* `-no-pie -fno-pie` $-$ te flagi wyłączają tzw. randomizację adresów, o której dowiemy się później. Z naszego punktu widzenia, wszystkie adresy w kodzie są ustalone i mają wartości rzędu `0x400000`.


Po kompilacji warto obejrzeć wygenerowany kod poleceniem `objdump -d a.out`.
Aby zobaczyć różnicę, polecam raz skompilować sobie kod bez powyższych flag i uruchomić gdb.

Możemy odpalać gdb: `gdb a.out`.

Na początku warto ustawić breakpoint na początku funkcji `fun` poleceniem `break fun`.
Później możemy uruchomić kod poleceniem `run`.

Na starcie program poprosi nas o podanie liczby, która jest argumentem naszej funkcji. 
Możemy podać dowolną dodatnią, na przykład `10`.
Następnie możemy poruszać się po kodzie i oglądać wykonanie kodu i wartości rejestrów instrukcjami `si` (wykonaj kolejną instrukcję assemblera) albo `c` (kontynuuj do kolejnego natrafienia na breakpoint).

Jednak kluczową dla nas instrukcją jest `x/20gx $rsp`, która podgląda pamięć, a dokładniej 20 elementów ze szczytu stosu.
Możemy na nim zobaczyć głównie elementy odłożone przez funkcję (argumenty wywołania funkcji) oraz adresy powrotu.

Warto dodać, że powyższa instrukcja `x` potrafi oglądać pamięć nie tylko na stosie, ale też w innych miejscach.
Przykładowo, wywołanie instrukcji `x/20gx $rsp-64` pozwoli nam podejrzeć 8 elementów, które znajdują się pod szczytem stosu (dzięki temu widzimy, że stos nie sprząta po sobie podczas zdejmowania elementów) oraz 12 elementów ze szczytu stosu.
Innym przykładem użycia instrukcji `x` jest `x/20gi $rip` lub `x/20gb $rip`, która pozwala nam podejrzeć fragment pamięci, w którym znajduje się aktualnie wykonywana przez nas instrukcja. 
Powyższymi instrukcjami możemy podejrzeć kod albo w czytelnym dla nas formacie, albo w formacie maszynowym, bajt po bajcie.

Aby lepiej poznać gdb, polecam ściągawkę znajdującą się na stronie wykładu.

