
clear

# gcc -o test test.c cpygame.c libs/mouse.c libs/display.c libs/window.c libs/image.c libs/surface.c libs/font.c libs/rect.c libs/key.c libs/clock.c libs/draw.c libs/circle.c -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lm
# gcc -o test test.c -L./buildlib/lib -I./buildlib/include -lSDL2main -lcpygame -lSDL2 -lSDL2_image -lSDL2_ttf -lm
gcc -g -o test test.c -L./buildlib/lib -I./buildlib/include -lSDL2main -lcpygame -lSDL2 -lSDL2_image -lSDL2_ttf -lm

mv test ./dlls
cd dlls
chmod +x ./test
./test
cd ..
