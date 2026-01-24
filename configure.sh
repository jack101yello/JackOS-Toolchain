export PREFIX="$HOME/opt/cross"
export TARGET=i386-jackos
export PATH="$PREFIX/bin:$PATH"
export LOCAL=$(pwd)
export SYSROOT=$LOCAL/libc

echo "Configuring JackOS cross compiler. Please note that this will take a while."
read -p "Press [Enter] key to continue..."

# Compile crtn.o
cd $SYSROOT/usr
$PREFIX/bin/$TARGET-as crti.s -o $SYSROOT/usr/lib/crti.o || exit
$PREFIX/bin/$TARGET-as crtn.s -o $SYSROOT/usr/lib/crtn.o || exit
$PREFIX/bin/$TARGET-as crt0.s -o $SYSROOT/usr/lib/crt0.o || exit

# Compile libc
cd $SYSROOT/usr
mkdir -p build
cd build
$PREFIX/bin/$TARGET-gcc -ffreestanding -fno-builtin -nostdlib -I$SYSROOT/usr/include -c $SYSROOT/usr/src/*.c \
	&& $PREFIX/bin/$TARGET-ar rcs libc.a *.o \
	&& cp libc.a $SYSROOT/usr/lib \
	&& cp libc.a $SYSROOT/lib

# Set up gcc again
cd $LOCAL/src/build-gcc
$LOCAL/gcc-*/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --with-sysroot=$SYSROOT --disable-werror --with-newlib \
	&& make all-gcc all-target-libgcc \
	&& make install-gcc install-target-libgcc

# Set up libstdc++
cd $LOCAL/src/build-gcc
make all-target-libstdc++-v3 \
	&& make install-target-libstdc++-v3
cp $SYSROOT/usr/lib/crtn.o $PREFIX/lib/gcc/$TARGET/13.3.0/
cp $SYSROOT/usr/lib/crti.o $PREFIX/lib/gcc/$TARGET/13.3.0/
cp $SYSROOT/usr/lib/crt0.o $PREFIX/lib/gcc/$TARGET/13.3.0/
