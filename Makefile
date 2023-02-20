# all: compile link

# compile: 
# 	g++ -c main.cpp -I"C:\msys64\mingw64\include" -DSFML_STATIC

# link:
# 	g++ main.o -o main =L"C:\msys64\mingw64\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lsfml-main-s

# clean:
# 	rm -f main *.o

all: compile link
compile:
	g++ -I C:\msys64\mingw64\include -c main.cpp
link: 
	g++ main.o -o main -L C:\msys64\mingw64\lib -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio -l sfml-network -l opengl32 -l glu32