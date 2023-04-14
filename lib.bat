cls
mkdir buildlib
cd buildlib
mkdir include
mkdir lib
cd ..

gcc -o buildlib/cpygame.o -c cpygame.c -lSDL2 -lSDL2_image

gcc -o buildlib/display.o -c libs/display.c -lSDL2 -lSDL2_image
gcc -o buildlib/image.o -c libs/image.c -lSDL2 -lSDL2_image
gcc -o buildlib/mouse.o -c libs/mouse.c -lSDL2 -lSDL2_image
gcc -o buildlib/surface.o -c libs/surface.c -lSDL2 -lSDL2_image
gcc -o buildlib/window.o -c libs/window.c -lSDL2 -lSDL2_image
gcc -o buildlib/font.o -c libs/font.c -lSDL2 -lSDL2_ttf -lSDL2_image
gcc -o buildlib/rect.o -c libs/rect.c -lSDL2 -lSDL2_image
gcc -o buildlib/key.o -c libs/key.c -lSDL2

copy cpygame.h "buildlib/include"
robocopy libs buildlib/include/libs *.h /E

cd buildlib
:: gcc -shared -o libcpygame.so cpygame.o display.o image.o mouse.o surface.o window.o -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
ar rcs libcpygame.a cpygame.o display.o image.o mouse.o surface.o window.o rect.o font.o key.o
move libcpygame.a lib
del *.o
cd ..

