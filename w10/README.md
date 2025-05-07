Generowanie plików:

* `gcc main.c sum.c  -fno-pie -no-pie -S`
* `gcc main.c sum.c  -fno-pie -no-pie -c`
* `gcc main.c sum.c  -fno-pie -no-pie`
* `gcc dynamic.c -O2 -Wall -no-pie -fno-pie -g`

Podglądanie zawartości plików ELF:

* `objdump -dr a.out`
* `readelf -s a.out`
* `readelf -a a.out`
* `readelf -p 4 main.o`
* `readelf -x 5 main.o`
* `objdump -x main.o`
* `objdump -s main.o`

GDB:

* `gdb a.out`
* `break fun`
* `run`
* `c`
* `si`
