
Komenda `gcc add.c -O0 -g` pozwala nam na kompilację pliku `add.c`. Flaga `-O0` oznacza, że kompilator nie ma wykonywać żadnych optymalizacji, a flaga `-g` sprawia, że w wersji skompilowanej będą się również zawierać informacje dla debuggera odnośnie pierwotnego kodu w języku C.

Za pomocą komendy `objdump -d a.out` możemy obejrzeć wynikowy kod maszynowy po kompilacji. 
Dzięki temu, że nie daliśmy żadnych optymalizacji, dodawanie wykona się za pomocą instrukcji `add`, a nie na przykład `lea`. 

Przed użyciem debuggera *GDB* zalecam instalację nakładki *GDB Dashboard*, do której link znajduje się na SKOSie. Pozwoli ona na duużo wygodniejsze korzystanie z debuggera.

Aby uruchomić debugger, wystarczy użyć komendy `gdb a.out`.
Na starcie proponuję dodać w kodze breakpointa komendą `break 7`, wtedy kod się zatrzyma w momencie, gdy dojdzie do  fragmentu kodu przetłumaczonego z linijki $7$ w pierwotnym kodzie C, czyli na dodawaniu. 
Następnie komendą `run` możemy uruchomić program.

W momencie, gdy kod dojdzie do wczytania danych, musimy mu podać dwie liczby, które są żądane na wejściu.
Po wprowadzeniu liczb program zatrzyma się w wyznaczonym breakpoint'cie.
Wtedy, na przykład komendą `si` możemy przesuwać się po jednej instrukcji assemblera do przodu i obserwować wywołanie. 
Najciekawszym momentem jest sytuacja, gdy wykonamy linijkę z instrukcją `add`. 
Wtedy możemy podejrzeć które spośród  flag `OF`, `CF`, `SF` i `ZF` są ustawione.

Komenda `c` bądź `continue` pozwala na kontynuację kodu do kolejnego breakpointa (w naszym przypadku do końca kodu).




Komenda `gcc main.c switch.c -no-pie -fno-pie -O2 -g` pozwala nam na kompilację kodu z instrukcją `switch`.
Tutaj dodaliśmy dodatkowo flagi `-no-pie -fno-pie`, które (pomijając szczegóły) sprawiają, że skompilowany kod będzie miał z góry ustawione wszystkie adresy (będą one rzędu `0x400000`), a dodatkowo podczas tłumaczenia na assembler użyta będzie tablica skoków.

Podejrzenie kodu instrukcją `objdump -d a.out` pozwala zauważyć, że (w moim przypadku) zawiera on instrukcję `jmp *0x402010(,%rdi,8)`, co oznacza, że tablica skoków znajduje się pod adresem `0x402010`.

Po uruchomieniu kodu debuggerem (`gdb a.out`), dodaniu breakpointa (np. `break fun` zatrzyma się po dojściu do etykiety/funkcji `fun`), uruchomieniu `run` i podaniu dowolnego argumentu, możemy podejrzeć pamięć na przykład za pomocą komendy `x/10gx 0x402010`.
Pozwoli nam to zauważyć w jakie miejsca kodu może skoczyć funkcja dla wartości argumentu od $0$ do $6$.


Aby uzyskać troszkę czytelniejszy format kodu, można przekleić kod z pliku `switch.c` do godbolta.
