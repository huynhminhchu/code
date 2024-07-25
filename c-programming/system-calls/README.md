## How to compile

- Download the tlpi source code

```bash
wget "http://man7.org/tlpi/code/download/tlpi-161214-dist.tar.gz"
```

- Unzip the source code, and compile
```bash
tar -zxvf tlpi-161214-dist.tar.gz
cd tlpi-dist/
make -j
```

- Copy the header files to the system include library:
```bash
cd lib/
sudo cp tlpi_hdr.h get_num.h error_functions.h ename.c.inc /usr/local/include/
```

- Create a static library and copy to default lib folder:
```bash
ar rcs libtlpi.a get_num.o error_functions.o
sudo cp libtlpi.a /usr/local/lib
```

- Compile the code:
```bash
gcc -o copy copy.c -ltlpi
```