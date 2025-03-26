
gcc add.c -O0 -g

objdump -d a.out

gdb a.out
break 7
run
si
c


gcc main.c fun.c -no-pie -O2 -g

objdump -d a.out

gdb a.out
break fun
run
si
c

gcc main.c switch.c -no-pie -fno-pie -O2 -g
x/10gx 0x402010
