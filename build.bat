cls
:: gcc -o test test.c cpygame.c libs/mouse.c libs/display.c libs/window.c libs/image.c libs/surface.c libs/font.c libs/rect.c libs/key.c libs/clock.c libs/draw.c libs/circle.c libs/transform.c libs/event.c libs/mixer.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
:: gcc -o test test.c -L.\buildlib\lib -I.\buildlib\include -lmingw32 -lSDL2main -lcpygame -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
gcc -g -o test test.c -L.\buildlib\lib -I.\buildlib\include -lmingw32 -lSDL2main -lcpygame -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

MOVE test.exe ./dlls
cd dlls
test
cd ..

