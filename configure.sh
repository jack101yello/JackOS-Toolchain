export PREFIX="$HOME/opt/cross"
export TARGET=i386-jackos
export PATH="$PREFIX/bin:$PATH"
export LOCAL=$(pwd)
export SYSROOT=$LOCAL/libc

echo "Configuring JackOS cross compiler. Please note that this will take a while."
read -p "Press [Enter] key to continue..."

# Set up gcc again
cd $LOCAL/src/build-gcc
$LOCAL/gcc-*/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --with-sysroot=$SYSROOT --disable-werror --with-newlib \
	&& make all-gcc all-target-libgcc \
	&& make install-gcc install-target-libgcc

# Set up libstdc++
cd $LOCAL/src/build-gcc
make all-target-libstdc++-v3 \
	&& make install-target-libstdc++-v3 \
	&& echo "JackOS cross compiler installed!"
