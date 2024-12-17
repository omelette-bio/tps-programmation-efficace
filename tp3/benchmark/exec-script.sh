for i in {1..50} ; do /usr/bin/time -f %e -o toto ./matrix-gcc ; cat toto >> bench-gcc.data ; done
for i in {1..50} ; do /usr/bin/time -f %e -o toto ./matrix-icx ; cat toto >> bench-icx.data ; done
