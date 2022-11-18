

all: build run


build:
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp -g
	g++ -I ./include/ -o ./lib/SatirListesiNode.o -c ./src/SatirListesiNode.cpp -g
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp -g
	g++ -I ./include/ -o ./lib/YoneticiListesiNode.o -c ./src/YoneticiListesiNode.cpp -g
	g++ -I ./include/ -o ./lib/utils.o -c ./src/utils.cpp -g
	g++ -I ./include/ -o ./lib/navUtils.o -c ./src/navUtils.cpp -g

	g++ -I ./include/ -o ./bin/main ./lib/SatirListesi.o ./lib/SatirListesiNode.o ./lib/YoneticiListesi.o  ./lib/YoneticiListesiNode.o ./lib/navUtils.o ./lib/utils.o   ./src/main.cpp -g

run:
	./bin/main