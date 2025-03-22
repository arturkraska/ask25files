Komendy kompilatora GCC użyte na wykładzie.

* `gcc main.c plik.c` - komenda kompilująca dwa pliki razem ze sobą.

```
gcc plik.c -S -O2
```
```
gcc plik.s plik.c
```
```
gcc plik.s main.c -c
```
```
objdump -d plik.o
```