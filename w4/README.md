Komendy kompilatora GCC użyte na wykładzie.

* `gcc main.c plik.c` - komenda kompilująca dwa pliki razem ze sobą. Powstanie nam wtedy plik wynikowy `a.out`, który można uruchomić.
* `./a.out` - uruchomienie pliku `a.out`.
* `gcc plik.c -S -O2` - flaga `-S` sprawia, że GCC wygeneruje nam kod assemblera pliku `plik.c`. Zostanie on umieszczony w pliku `plik.s`.
* `gcc plik.s main.c` - ciekawostką jest to, że pliki z rozszerzeniem `.s` i `.c` można normalnie razem kompilować.
* `gcc plik.s -c` - flaga `-c` pozwala nam wygenerować tak zwany plik *relokowalny* (o kótrych będzie mowa później). W takim pliku możemy podejrzeć kod maszynowy (czyli assembler już w postaci binarnej), ale nie da się go jeszcze uruchomić. Będzie on się nazywał `plik.o`.
* `objdump -d plik.o` - komenda `objdump` ma wiele własności podglądania danych w pliku relokowalnym, a jedną z nich jest podejrzenie kodu za pomocą flagi `-d`. 