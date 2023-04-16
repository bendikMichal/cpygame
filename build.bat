cls
:: gcc -o test test.c cpygame.c libs/mouse.c libs/display.c libs/window.c libs/image.c libs/surface.c libs/font.c libs/rect.c libs/key.c libs/clock.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
gcc -o test test.c -L.\buildlib\lib -I.\buildlib\include -lmingw32 -lSDL2main -lcpygame -lSDL2 -lSDL2_image -lSDL2_ttf

MOVE test.exe ./dlls
cd dlls
test
cd ..

