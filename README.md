README

This is the toolchain for the JackOS operating system.
If you're interested in the source code for the compiler, you're in the right place!
If you're interested in writing programs for JackOS, you can download the tarball for the compiler on GitHub without needing to build it from here.
Use the following directions to get the toolchain set up, or to use it to compile code.

Setting up the toolchain:
1. Change the first line in configure.sh to reflect where you'd like to put your cross-compiler.
The default is $HOME/opt/cross.
2. Change the second line in configure.sh to reflect where you'd like to put the source files.
The default is $HOME/src.
3. Run "./configure.sh". You may need to mark is as executable first with "chmod +x configure.sh".

Using the toolchain:
The compiler now lives at, for instance, $HOME/opt/cross/bin. Therefore, to compile a C program for instance, you'd run "$HOME/opt/cross/bin/$TARGET-gcc program.c".
