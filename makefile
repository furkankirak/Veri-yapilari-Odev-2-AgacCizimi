Tum: derleme baglama calistirma
derleme:
	g++ -c -I ./include ./src/main.cpp -o ./lib/main.o 
	g++ -c -I ./include ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I ./include ./src/BagliListe.cpp -o ./lib/BagliListe.o
	g++ -c -I ./include ./src/ADugum.cpp -o ./lib/ADugum.o
	g++ -c -I ./include ./src/Agac.cpp -o ./lib/Agac.o
	g++ -c -I ./include ./src/Kuyruk.cpp -o ./lib/Kuyruk.o
	g++ -c -I ./include ./src/KDugum.cpp -o ./lib/KDugum.o
	
baglama:
	g++ ./lib/main.o ./lib/Dugum.o ./lib/BagliListe.o ./lib/ADugum.o ./lib/Agac.o ./lib/Kuyruk.o ./lib/KDugum.o -o ./bin/program 
calistirma:
	./bin/program