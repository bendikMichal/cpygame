
rm -r buildlib
clear
mkdir buildlib
cd buildlib

mkdir include
cd include
mkdir libs
cd ..

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
gcc -o buildlib/clock.o -c libs/clock.c -lSDL2
gcc -o buildlib/draw.o -c libs/draw.c -lSDL2
gcc -o buildlib/circle.o -c libs/circle.c -lSDL2
gcc -o buildlib/transform.o -c libs/transform.c -lSDL2
gcc -o buildlib/event.o -c libs/event.c -lSDL2
gcc -o buildlib/mixer.o -c libs/mixer.c -lSDL2

cp cpygame.h ./buildlib/include
cp ./libs/*.h ./buildlib/include/libs

cd buildlib
ar rcs libcpygame.a cpygame.o display.o image.o mouse.o surface.o window.o rect.o font.o key.o clock.o draw.o circle.o transform.o event.o mixer.o
mv libcpygame.a lib
rm ./*.o
cd ..

