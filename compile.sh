#compile main.cpp
g++ -c main.cpp

#compile the drawhelper.cpp
g++ -c drawhelp.cpp

#compile the pong.cpp
g++ -c pong.cpp

#link
g++ main.o drawhelp.o pong.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

#run
./sfml-app
