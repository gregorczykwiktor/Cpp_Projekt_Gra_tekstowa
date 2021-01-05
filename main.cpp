#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "chklr.cpp"
#include "conlib.h" //Biblioteka do operowania oknem terminalu.
#include "slwtxt.cpp"
#include "logo.cpp"

using namespace std;

	void menu(HANDLE kolor);
	void select(string function);
	void stage1(HANDLE kolor);
	void stage2(HANDLE kolor);
	void stage3(HANDLE kolor);
	void stage4(HANDLE kolor);
	void stage5(HANDLE kolor);
	void endgame(HANDLE kolor);
	void tutorial(HANDLE kolor);
	void animation(HANDLE kolor);
	bool isnum(string t);
	int conv(string a);
	int menu_variable();
	int i=0,choose,load,loading=500,textSpeed=20,speed=0,muzyczka=0;
	string skip,function;

int main(){
	srand(time(NULL));
	SetConsoleTitle("Adventure RPG Game"); //Nadanie nazwy dla terminalu.
	HWND console = GetConsoleWindow();	//Pobranie rozmiaru konsoli.
	RECT r;	// Definiowanie pozycji okna.
	MoveWindow(console, r.left, r.top, 1280, 720, TRUE);  //Zmiana rozmiaru oraz pozycji konsoli w windowsie.
	HANDLE kolor;
	kolor=GetStdHandle(STD_OUTPUT_HANDLE);
	setlocale (LC_ALL, "");
	animation(kolor);
	return 0;
}

void animation(HANDLE kolor){
	logo(kolor);
	menu(kolor);
}

void menu(HANDLE kolor){
	VOID WINAPI Sleep(DWORD dwMilliseconds);
		chklr(kolor,0);slwtxt("\n\nMENU",textSpeed);
		chklr(kolor,0);slwtxt("\n1.Nowa gra.",textSpeed);
		chklr(kolor,0);slwtxt("\n2.Zaladuj gre.",textSpeed);
		chklr(kolor,0);slwtxt("\n3.Zakoncz gre.",textSpeed);
		chklr(kolor,0);slwtxt("\n\nTw�j wyb�r to: ",textSpeed);
			switch(menu_variable()){
				case 1:{
					system("cls");
					
					string imie;
					ofstream pout;
					pout.open("imie.txt");
					chklr(kolor,0);slwtxt("Podaj swoje imi�: ",textSpeed);
					chklr(kolor,6);cin>>imie;
					pout<<imie;
					pout.close();
					
					chklr(kolor,0);slwtxt("\n\nCzy ma gra� muzyka?\n",textSpeed);
					chklr(kolor,1);slwtxt("1.",textSpeed);
					chklr(kolor,0);slwtxt("Tak.\n",textSpeed);
					chklr(kolor,1);slwtxt("2.",textSpeed);
					chklr(kolor,0);slwtxt("Nie.\n",textSpeed);
					chklr(kolor,0);slwtxt("\nTw�j wyb�r to: ",textSpeed);
					cin>>muzyczka;
					if(muzyczka==1){
						WinExec("muzyka.exe",1);
					}else if(muzyczka==2){
					
					}
					
					speedster:
					chklr(kolor,0);slwtxt("\n\nZ jak� pr�dko�ci� ma sie pojawia� tekst?\n",textSpeed);
					chklr(kolor,1);slwtxt("1.",textSpeed);
					chklr(kolor,0);slwtxt("B�yskawicznie. (Mo�e zepsu� klimat gry.)\n",textSpeed);
					chklr(kolor,1);slwtxt("2.",textSpeed);
					chklr(kolor,0);slwtxt("Powoli.\n",textSpeed);
					chklr(kolor,1);slwtxt("3.",textSpeed);
					chklr(kolor,0);slwtxt("Wolno.\n",textSpeed);
					chklr(kolor,0);slwtxt("\nTw�j wyb�r to: ",textSpeed);
					cin>>speed;
					
					if(speed==1){
						textSpeed=0;
					}else if(speed==2){
						textSpeed=10;
					}else if(speed==3){
						textSpeed=20;
					}else{
						chklr(kolor,0);slwtxt("B��dna warto��! Spr�buj od nowa.",textSpeed);
						goto speedster;
					}
					
					chklr(kolor,0);slwtxt("\n\nCzy chcesz pomin�� tutorial ?\n[",textSpeed);
					chklr(kolor,2);slwtxt("T",textSpeed);
					chklr(kolor,0);slwtxt("/",textSpeed);
					chklr(kolor,1);slwtxt("n",textSpeed);
					chklr(kolor,0);slwtxt("]\n\n",textSpeed);
					chklr(kolor,0);slwtxt("Tw�j wyb�r to: ",textSpeed);
					chklr(kolor,0);cin>>skip;
					if(skip=="T"){
						stage1(kolor);
					}else if(skip=="t"){
						stage1(kolor);
					}else if(skip=="N"){
						tutorial(kolor);
					}else if(skip=="n"){
						tutorial(kolor);
					}else{
						system("cls");
						chklr(kolor,1);slwtxt("Poda�e� z�y wyb�r. Zacznij od nowa :)\n\n",textSpeed);
						menu(kolor);
					}
				}break;
				case 2:{
					system("cls");
					logo(kolor);
					
					chklr(kolor,0);slwtxt("\n\nCzy ma gra� muzyka?\n",textSpeed);
					chklr(kolor,1);slwtxt("1.",textSpeed);
					chklr(kolor,0);slwtxt("Tak.\n",textSpeed);
					chklr(kolor,1);slwtxt("2.",textSpeed);
					chklr(kolor,0);slwtxt("Nie.\n",textSpeed);
					chklr(kolor,0);slwtxt("\nTw�j wyb�r to: ",textSpeed);
					cin>>muzyczka;
					if(muzyczka==1){
						WinExec("muzyka.exe",1);
					}else if(muzyczka==2){
					
					}
					
					speedster1:
					chklr(kolor,0);slwtxt("\n\nZ jak� pr�dko�ci� ma sie pojawia� tekst?\n",textSpeed);
					chklr(kolor,1);slwtxt("1.",textSpeed);
					chklr(kolor,0);slwtxt("B�yskawicznie. (Mo�e zepsu� klimat gry.)\n",textSpeed);
					chklr(kolor,1);slwtxt("2.",textSpeed);
					chklr(kolor,0);slwtxt("Powoli.\n",textSpeed);
					chklr(kolor,1);slwtxt("3.",textSpeed);
					chklr(kolor,0);slwtxt("Wolno.\n",textSpeed);
					chklr(kolor,0);slwtxt("\nTw�j wyb�r to: ",textSpeed);
					cin>>speed;
					
					if(speed==1){
						textSpeed=0;
					}else if(speed==2){
						textSpeed=10;
					}else if(speed==3){
						textSpeed=20;
					}else{
						chklr(kolor,0);slwtxt("B��dna warto��! Spr�buj od nowa.",textSpeed);
						goto speedster1;
					}
					
					loadstage:
					system("cls");
					chklr(kolor,0);slwtxt("\n\nPodaj has�o do poziomu.",textSpeed);
					chklr(kolor,0);slwtxt("\nTw�je has�o to: ",textSpeed);
					cin>>load;
				    while (cin.fail())
				    {
				        cin.clear(); // clear input buffer to restore cin to a usable state
				        cin.ignore(INT_MAX, '\n'); // ignore last input
				        chklr(kolor,1);slwtxt("\nHas�o nie posaida �adnych liter!\n",textSpeed);
				        chklr(kolor,0);slwtxt("Podaj poprawne has�o: ",textSpeed);
				        cin>>load;
				    }

					switch(load){
						case 1543:{
							stage1(kolor);
						}break;

						case 2842:{
							stage2(kolor);
						}break;

						case 3256:{
							stage3(kolor);
						}break;

						case 4987:{
							stage4(kolor);
						}break;
						
						default:{
							chklr(kolor,1);slwtxt("\nTw�je has�o jest z�e zacznij od nowa.",textSpeed);
							getch();
							goto loadstage;
							
						}break;
					};
				}break;
				case 3:{
					system("pause");
				}break;
				default:{
					system("cls");
					slwtxt("Poda�e� z�y wyb�r !!! \nZacznij od nowa.\n", textSpeed);Sleep(loading);
					animation(kolor);
				}break;
			};
			chklr(kolor, 0);
}

void tutorial(HANDLE kolor){
	system("cls");
	slwtxt("Witaj w grze pod tytu�em ",textSpeed);
	chklr(kolor,2);slwtxt("RPG The Game", textSpeed);
	chklr(kolor,0);slwtxt(" w kt�rej twoim zadaniem b�dzie uko�czenie fabu�y.\n\n Zasady oraz informacje: \n", textSpeed);
	chklr(kolor,2);slwtxt("1.",textSpeed);
	chklr(kolor,0);slwtxt("Baw si� ",textSpeed);
	chklr(kolor,1);slwtxt("dobrze",textSpeed);
	chklr(kolor,0);slwtxt(".\n",textSpeed);
	chklr(kolor,2);slwtxt("2.",textSpeed);
	chklr(kolor,0);slwtxt("Wykonuj polecenia podane przez ",textSpeed);
	chklr(kolor,1);slwtxt("gre",textSpeed);
	chklr(kolor,0);slwtxt(".\n",textSpeed);
	chklr(kolor,2);slwtxt("3.",textSpeed);
	chklr(kolor,0);slwtxt("Has�o poziomu pokazuje si� przy numerze rozdzia�u ",textSpeed);
	chklr(kolor,1);slwtxt("zapisz",textSpeed);
	chklr(kolor,0);slwtxt("sobie je.\n",textSpeed);
	chklr(kolor,2);slwtxt("4.",textSpeed);
	chklr(kolor,0);slwtxt("Kiedy pojawia si� tekst mo�esz go przewija� klawiszem ",textSpeed);
	chklr(kolor,1);slwtxt("Enter",textSpeed);
	chklr(kolor,0);slwtxt(".\n",textSpeed);
	chklr(kolor,2);slwtxt("5.",textSpeed);
	chklr(kolor,0);slwtxt("Tw�rc� gry jest ",textSpeed);
	chklr(kolor,1);slwtxt("Wiktor Gregorczyk",textSpeed);
	chklr(kolor,0);slwtxt(".\n\n",textSpeed);
	slwtxt("Aby zacza� rozgrywk� kliknij dowolny przycisk.\n",textSpeed);
	_getch();
	system("cls");
	stage1(kolor);
}

void stage1(HANDLE kolor){
	
	ifstream pin;
	string imie;
	pin.open("imie.txt");
	if (!pin){
      cout << "\nBLAD OTWARCIA!\n";
      system ("Pause");
      endgame(kolor);
    }
	pin>>imie;
	pin.close();
	
	system("cls");
	
	int wybor;

	chklr(kolor,2);slwtxt("\nCzas: ",textSpeed);
	chklr(kolor,0);slwtxt("17 grudnia 2018 ",textSpeed);
	chklr(kolor,2);slwtxt("Miejsce: ",textSpeed);
	chklr(kolor,0);slwtxt("Pozna�, Polska\n\n",textSpeed);
	chklr(kolor,2);slwtxt("*Budzisz si� jak co dzie� w swoim ��ku z my�l�, �e znowu musisz i�� do pracy.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Ahh... i po co mi to wszystko by�o, ca�e te studia �eby teraz robi� w jakim� korpo do staro�ci. Masakra...\n",textSpeed);
	chklr(kolor,2);slwtxt("*Po kilku wdechach wsta�e� i zacze�e� si� szykowa�. Zjda�e� �niadanie i wyszed�e� z domu.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Ciekawe czy dzisaj znowu szef b�dzie mnie m�czy� swoim monlogiem na temat mojej wydajno�ci i innych bzdetach...\n",textSpeed);
	chklr(kolor,2);slwtxt("*Nagle s�yszysz, �e kto� krzyczy twoje imi�. Spogl�dasz za ciebie a to tw�j znajomy z pracy ",textSpeed);
	chklr(kolor,4);slwtxt("Mariusz",textSpeed);
	chklr(kolor,0);slwtxt(".*\n",textSpeed);
	chklr(kolor,4);slwtxt("Mariusz: ",textSpeed);
	chklr(kolor,0);slwtxt("Heej ",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(" zaczekaaj na mnieee !!!\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": *my�li* Mariusz to jedyny wporz�dku w tej firmie wi�c nie mam nic przeciwko na niego zaczeka�.\n",textSpeed);
	chklr(kolor,4);slwtxt("Mariusz: ",textSpeed);
	chklr(kolor,0);slwtxt("Cze�� dzi�ki, �e zaczeka�e�. W ko�cu razem zawsze ra�niej nieprawda�?\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": No tak, tak zawsze razem lepiej.\n",textSpeed);
	chklr(kolor,4);slwtxt("Mariusz: ",textSpeed);
	chklr(kolor,0);slwtxt("Hmm... A co ty na to aby gdzie� wyskoczy� na przerwie? Mo�e sushi?\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Czemu nie.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Nagle s�ycha� pisk opon, a nast�pnie uderzenie.*\n",textSpeed);
	chklr(kolor,4);slwtxt("Mariusz: ",textSpeed);
	chklr(kolor,0);slwtxt("Ludzie !!! Dzwoncie po karetke !! Pomocy !\n",textSpeed);
	chklr(kolor,2);slwtxt("*Odczuwasz zimno, a jednoczesnie ciep�o. Jeste� zdezorientowany.*\n*Powoli dociera do ciebie co sie sta�o.*\n",textSpeed);
	chklr(kolor,5);slwtxt("Nieznana posta�: ",textSpeed);
	chklr(kolor,0);slwtxt("A wi�c tak si� ko�czy tw�j �ywot na twojej planecie. Hmm.. bardzo ciekawe.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Co jest, kto to m�wi???\n",textSpeed);
	chklr(kolor,5);slwtxt("Nieznana posta�: ",textSpeed);
	chklr(kolor,0);slwtxt("Mo�e na chwil� przeniose nas w inne miejsce, �eby �atwiej by�o ci wszystko wyt�umaczy�.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Nagle pojawiasz si� w twoim pokoju w dodatku przed tob� stoi kobieta w czarnej szacie. Jeste� nadal zdezorientowany.*\n", textSpeed);
	chklr(kolor,5);slwtxt("Nieznana posta�: ",textSpeed);
	chklr(kolor,0);slwtxt("Wi�c zacznijmy od �atwiejszych rzeczy. Ty ",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(" w�asnie umra�e�.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Coo? Jakim cudem skoro tutaj jeste�my? A pozatym kim jeste�?!\n",textSpeed);
	chklr(kolor,5);slwtxt("Nieznana posta�: ",textSpeed);
	chklr(kolor,0);slwtxt("Moje imi� jest nie wa�ne, ale skoro chcesz je zna� to jestem ",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra",textSpeed);
	chklr(kolor,0);slwtxt(", zwana czasami przez tw�j gatunek jako bogini �mierci.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Chyba zaraz zwarjuj�. A nie, to pewnie tylko z�y sen dlatego jestem u mnie w pokoju, a reszta to moja wyobra�nia.\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("Niestety obawiam si�, �e to nie jest twoja wyobra�nia. Pozw�l, �e ci poka��.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Raptownie pojawiasz si� w miejscu, gdzie le�� twoje zw�oki. Obok nich widzisz ",textSpeed);
	chklr(kolor,4);slwtxt("Mariusza",textSpeed);
	chklr(kolor,2);slwtxt(", kt�ry pr�buje ci pom�c.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Co jakim cudem?? Przecie� ja stoje tutaj, a moje cia�o jest na ziemi ?!?\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("Wiem, �e dla ciebie mo�e by� to trudne do zrozumienia, ale jak teraz sam widzisz umar�e� naprawd�.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": No dobrze, dobrze teraz mo�e i ci uwierz�, ale dlaczego tutaj jeste� i mi to wszystko pokazujesz?\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("No dobrze to teraz cie zabior� do siebie i skoro och�on��e� to wyt�umacze ci.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Pojawiasz si� wraz z ",textSpeed);
	chklr(kolor,5);slwtxt("Nyjr� ",textSpeed);
	chklr(kolor,2);slwtxt("w dziwnym kompletnie bia�ym pomiesczeniu.*\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("W takim razie jak ju� zd�rzy�e� przyj�� do rozumu, �e umra�e� to chc� ci powiedzie� co si� z tob� dalej stanie.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": W takim razie s�ucham...\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("Masz wyb�r co chcesz zrobi�. Twoj� pierwsz� opcj� jest odes�anie do pustki co oznacza, �e stracisz �wiadomo�� i b�dziesz b��ka� si� bez ko�ca w\nnico�ci. Natomiast drugim wyborem jest zaczni�cie �ycia od nowa.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Co do pierwszego to jest niedorzeczne! Kto by chcia� wybra� co� takiego... Jakby� mog�a droga ",textSpeed);
	chklr(kolor,5);slwtxt("Nyjro ",textSpeed);
	chklr(kolor,0);slwtxt("wyt�umaczy� bardziej o tym nowym �yciu.\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("Je�li wybierzesz drug� opcje to zachowasz wspomnienia, wiek i rzeczy kt�re mia�e� przy sobie kiedy umra�e�, lecz pojawisz si� w losowym\nmiejscu i czasie.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Czyli mog� w wyl�dowa� w przysz�o�ci i przesz�o�ci?\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("Tak, a ponadto nie koniecznie mo�esz wyl�dowac w tym samym wszech�wiecie.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Chyba nie do ko�ca rozumiem ale mniejsza z tym.\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("W takim razie jaki jest tw�j wyb�r?\n\n",textSpeed);
				
	chklr(kolor,1);slwtxt("1. ",textSpeed);
	chklr(kolor,0);slwtxt("Zapomnienie o swojej egzystencji oraz b��kanie si� po pustce.\n",textSpeed);
	chklr(kolor,2);slwtxt("2. ",textSpeed);
	chklr(kolor,0);slwtxt("Odrodzenie si� oraz zacz�cie �ycia od nowa.\n\n",textSpeed);
	
	chklr(kolor,0);slwtxt("Tw�j wyb�r to: ",textSpeed);
	cin>>wybor;
				
	if(wybor==1){
		endgame(kolor);
	}else if(wybor==2){
		chklr(kolor,2);slwtxt("\nKoniec rozdzialu 1\nHas�o do tego poziomu to: 1543.\nKliknij dowolny przycisk aby zacz�� rozdzia� drugi.",textSpeed);
		getch();
		stage2(kolor);
	}else{
		chklr(kolor,1);slwtxt("A wi�c nie wybierasz niczego ?! W takim razie pozw�l, �e wybior� za ciebie.",textSpeed);
		getch();
		chklr(kolor,2);slwtxt("\nKoniec rozdzialu 1\nHas�o do tego poziomu to: 1543.\nKliknij dowolny przycisk aby zacz�� rozdzia� drugi.",textSpeed);
		getch();
		stage2(kolor);
	};		
}

void stage2(HANDLE kolor){
	
	ifstream pin;
	string imie;
	pin.open("imie.txt");
	if (!pin){
      cout << "\nBLAD OTWARCIA!\n";
      system ("Pause");
      endgame(kolor);
    }
	pin>>imie;
	pin.close();
	
	int wybor,wybor1,wybordom,wyborwalka,wybora=0,wyborb=0,HP=100,HPwilk=100,HPtymcz=0,zmiennadom=0,domeka=0,domekb=0,domekc=0,wyborwioskaa=0,wyborwioskab=0;
	
	system("cls");
	chklr(kolor, 2);slwtxt("Rozdzaial 2\n",textSpeed);
	
	chklr(kolor,2);slwtxt("\nCzas: ",textSpeed);
	chklr(kolor,0);slwtxt("Nieznany ",textSpeed);
	chklr(kolor,2);slwtxt("Miejsce: ",textSpeed);
	chklr(kolor,0);slwtxt("Nieznany\n\n",textSpeed);
	chklr(kolor,2);slwtxt("*Wstajesz ze snu z my�l�, �e to by� sen, lecz budzisz si� nie w swoim pokoju. Rozgl�dasz si� do oko�a i widzisz przepi�kny krajobraz.*\n\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": A jednak to nie by� sen. Dziwne, ale czuje si� wypocz�ty jakbym spa� z tydzie�. Dobra czas sprawdzi� na czym stoj� i co mam przy sobie.\n",textSpeed);
	wybor1:
	chklr(kolor,0);slwtxt("Co chcesz teraz zrobi�?\n\n",textSpeed);
	chklr(kolor,2);slwtxt("1.",textSpeed);
	chklr(kolor,0);slwtxt("Zajrzyj do plecaka.\n",textSpeed);
	chklr(kolor,2);slwtxt("2.",textSpeed);
	chklr(kolor,0);slwtxt("Porozgl�daj si� do oko�a.\n",textSpeed);
	chklr(kolor,2);slwtxt("3.",textSpeed);
	chklr(kolor,0);slwtxt("Obmy�l plan dzia�ania.\n\n",textSpeed);
	chklr(kolor,0);slwtxt("Tw�j wyb�r to: ",textSpeed);
	cin>>wybor;

	if(wybor==1){
		system("cls");
		chklr(kolor,6);slwtxt(imie,textSpeed);
		chklr(kolor,0);slwtxt(": A wi�c tak, aktualnie posiadamz ze sob� telefon, portfel, �niadanie oraz scyzoryk.\n",textSpeed);
		wybora=1;
		getch();
		system("cls");
		goto wybor1;
	}else if(wybor==2){
		system("cls");
		chklr(kolor,6);slwtxt(imie,textSpeed);
		chklr(kolor,0);slwtxt(": Widze do oko�a przepi�kne g�ry, lecz co najdziwniejsze one unosz� si� nad ziemi�!!! Aktualnie chyba jestem w jakiego� rodzaju lesie, chyba\nmusz� uwarza� na tutejsz� zwierzyn�.\n",textSpeed);
		wyborb=1;
		getch();
		system("cls");
		goto wybor1;
	}else if(wybor==3){
		if(wybora==1 && wyborb==1){
			
		}else{
			system("cls");
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Hmm... Najpierw sprawdze co mam przy sobie i co jest dooko�a mnie.",textSpeed);
			getch();
			system("cls");
			goto wybor1;
		}
	}
	system("cls");
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Skoro ju� wiem co mam przy sobie i znam z lekka okolice to my�le, �e czas wyruszy� poszuka� jakiego� schronienia, a mo�e i ludzi.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Po kilku godzinach tu�aczki znajdujesz najprawdopodobniej opuszczony ob�z koczowniczy.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Wreszcie jakie� oznaki, �e nie jestem sam lecz troche niepokoi mnie fakt, �e nikogo tutaj nie ma. Dobra czas rozejrze� si� i poszuka� czego�\nprzydatnego. Lepiej wyci�gne scyzoryk na wszelki wypadek.\n\n",textSpeed);
	wioska:
	chklr(kolor,0);slwtxt("Co chcesz teraz zrobi�?\n\n",textSpeed);
	chklr(kolor,2);slwtxt("1.",textSpeed);
	chklr(kolor,0);slwtxt("Sprawd� czy mo�e kto� jescze jest tutaj.\n",textSpeed);
	chklr(kolor,2);slwtxt("2.",textSpeed);
	chklr(kolor,0);slwtxt("Spl�druj chaty w poszukiwaniu czego� przydatnego.\n",textSpeed);
	chklr(kolor,2);slwtxt("3.",textSpeed);
	chklr(kolor,0);slwtxt("Udaj si� dalej.\n\n",textSpeed);
	chklr(kolor,0);slwtxt("Tw�j wyb�r to: ",textSpeed);
	cin>>wybor1;
	
	if(wybor1==1){
		system("cls");
		chklr(kolor,6);slwtxt(imie,textSpeed);
		chklr(kolor,0);slwtxt(": Halooo, jest tu kto�?? Halo, przyszed�em w dobrych intencjach. Najprawdopodobniej nie ma tutaj nikogo.\n",textSpeed);
		getch();
		system("cls");
		wyborwioskaa=1;
		goto wioska;
	}else if(wybor1==2){
		domy:
		system("cls");
		if(domeka==1 && domekb==1 && domekc==1){
			chklr(kolor,2);slwtxt("*To ju� chyba wszystkie domki jakie s�. Teraz mo�e zrobi� co� innego.*",textSpeed);
			getch();
			system("cls");
			wyborwioskab=1;
			goto wioska;
		}
		chklr(kolor,6);slwtxt(imie,textSpeed);
		chklr(kolor,0);slwtxt(": Z tego co widze jest tutaj kilka domk�w. Jeden po lewej i prawej oraz jeden na �rodku.\n\n",textSpeed);
		chklr(kolor,0);slwtxt("Kt�ry dom chcesz spl�drowa�?\n\n",textSpeed);
		chklr(kolor,2);slwtxt("1.",textSpeed);
		chklr(kolor,0);slwtxt("Lewy.\n",textSpeed);
		chklr(kolor,2);slwtxt("2.",textSpeed);
		chklr(kolor,0);slwtxt("�rodkowy.\n",textSpeed);
		chklr(kolor,2);slwtxt("3.",textSpeed);
		chklr(kolor,0);slwtxt("Prawy.\n\n",textSpeed);
		chklr(kolor,0);slwtxt("Tw�j wyb�r to: ",textSpeed);
		cin>>wybordom;
		
			if(wybordom==1){
				system("cls");
				if(domeka==1){
					chklr(kolor,6);slwtxt(imie,textSpeed);
					chklr(kolor,0);slwtxt(": Ju� by�em w tym domuku, p�jd� lepiej do nast�pnego.\n",textSpeed);
					getch();
					goto domy;
				};
				chklr(kolor,6);slwtxt(imie,textSpeed);
				chklr(kolor,0);slwtxt(": Wi�c sprawd�my co kryje lewy domek.\n",textSpeed);
				chklr(kolor,2);slwtxt("*Otwierasz drzwi do domku.*\n",textSpeed);
				chklr(kolor,6);slwtxt(imie,textSpeed);
				chklr(kolor,0);slwtxt(": Praktycznie wszystko zosta�o ju� chyba tutaj spl�drowane. No c� udam sie do kolejnych domk�w.",textSpeed);
				domeka=1;
				getch();
				system("cls");
				goto domy;
			}else if(wybordom==2){
				system("cls");
				if(domekb==1){
					chklr(kolor,6);slwtxt(imie,textSpeed);
					chklr(kolor,0);slwtxt(": Ju� by�em w tym domuku, p�jd� lepiej do nast�pnego.\n",textSpeed);
					getch();
					goto domy;
				};
				chklr(kolor,2);slwtxt("*Po spl�drowaniu tego domku odnalaz�e� butlek� wody oraz troche jedzenia.*\n",textSpeed);
				getch();
				domekb=1;
				system("cls");
				goto domy;
			}else if(wybordom==3){
				if(zmiennadom==1){
					system("cls");
					chklr(kolor,2);slwtxt("*Ju� pokona�e� wilka i spl�drowa�e� ten domek.*\n",textSpeed);
					getch();
					system("cls");
					goto domy;
				};
				system("cls");
				chklr(kolor,6);slwtxt(imie,textSpeed);
				chklr(kolor,0);slwtxt(": Wi�c sprawd�my co kryje prawy domek.\n",textSpeed);
				chklr(kolor,2);slwtxt("*Otwierasz drzwi do domku. I nagle wyskakuje przed tob� jakie� zwierze z lekka podobne do wilka.*\n",textSpeed);
				chklr(kolor,2);slwtxt("*Zwierz� czeka na tw�j ruch. Najprowdopodobniej jest to jego terytorium.*\n\n",textSpeed);
				walka:
				if(HPwilk==0){
					system("cls");
					goto domy;
				}
				chklr(kolor,0);slwtxt("Ilo�c punkt�w twojego �ycia wynosi: ",textSpeed);
				chklr(kolor,1);cout<<HP;
				chklr(kolor,0);slwtxt(".\n",textSpeed);
				chklr(kolor,0);slwtxt("Ilo�c punkt�w �ycia przeciwnika wynosi: ",textSpeed);
				chklr(kolor,1);cout<<HPwilk;
				chklr(kolor,0);slwtxt(".",textSpeed);
				chklr(kolor,0);slwtxt("\n\nCo chcesz teraz zrobi�?\n\n",textSpeed);
				chklr(kolor,2);slwtxt("1.",textSpeed);
				chklr(kolor,0);slwtxt("ATAK | ",textSpeed);
				chklr(kolor,2);slwtxt("2.",textSpeed);
				chklr(kolor,0);slwtxt("OBRONA | ",textSpeed);
				chklr(kolor,2);slwtxt("3.",textSpeed);
				chklr(kolor,0);slwtxt("UCIECZKA\n\n",textSpeed);
				chklr(kolor,0);slwtxt("Tw�j wyb�r to: ",textSpeed);
				cin>>wyborwalka;
				
					if(wyborwalka==1){
						system("cls");
						chklr(kolor,0);slwtxt("Tw�j wyb�r to: ATAK.",textSpeed);
						for(int i=0;i<=1;i++){
      						int obrazenia=(rand()%2)+1;
      						HP=HP-obrazenia;
 					  	};
						for(int i=0;i<=1;i++){
      						int obrazenia=(rand()%20)+1;
      						HPwilk=HPwilk-obrazenia;	
 					  	};
 					  	if(HPwilk<0){
 					  			system("cls");
      							HPwilk=0; 
      							zmiennadom=1;
      							domekc=1;
      							chklr(kolor,2);slwtxt("*Gratulacje wygra�e� t� walk�. Po przeszukaniu domku znalaz�e� tylko kilka starych monet.*",textSpeed);
							  };
 					  	getch();
 					  	system("cls");
 					  	goto walka;
					}else if(wyborwalka==2){
						system("cls");
						chklr(kolor,0);slwtxt("Tw�j wyb�r to: OBRONA.\n",textSpeed);
						chklr(kolor,2);slwtxt("*Gratulacje uda�o ci si� zablokowa� atak przeciwnika!*\n",textSpeed);
						getch();
						system("cls");
						goto walka;
					}else if(wyborwalka==3){
						system("cls");
						chklr(kolor,0);slwtxt("Tw�j wyb�r to: UCIECZKA.\n",textSpeed);
						chklr(kolor,2);slwtxt("*Nie uda�o ci si� ucie� od przeciwnika!*\n",textSpeed);
						getch();
						system("cls");
						goto walka;
					}else{
						system("cls");
						goto walka;
					};
					
			}else{
				system("cls");
				goto domy;
			}
		
	}else if(wybor1==3){
		if(wyborwioskaa==0 && wyborwioskab==0){
			chklr(kolor,2);slwtxt("*Musisz jescze doko�czy� poprzednie zadania, �eby przej�� dalej.*\n\n",textSpeed);
			chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przej�� dalej.",textSpeed);
			getch();
			system("cls");
			goto wioska;
		};
		system("cls");
		chklr(kolor,6);slwtxt(imie,textSpeed);
		chklr(kolor,0);slwtxt(": Chyba ju� zrobi�em wszystko co mog�em w tej wiosce. Chyba czas na znalezienia jakiego� schronienia na noc.\n",textSpeed);
		chklr(kolor,2);slwtxt("*Po czasie znalaz�e� miejsce do przenocowania oraz zdo�a�e� rozpali� ogie�.*\n\n",textSpeed);
		chklr(kolor,6);slwtxt(imie,textSpeed);
		chklr(kolor,0);slwtxt(": Dobra czas teraz �eby troche odpocz��. Ognisko si� pali wi�c powinno to odstraszy� zwierzyn� i nie zmarzn� dzi�ki niemu.\n\n",textSpeed);
		chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przej�� dalej.",textSpeed);
		getch();
		system("cls");
		int p=0;
		spanko:
		if(p==3){
			stage3(kolor);
		};
		while(p<3){
			p++;
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": zzzZZZzzz\n",50);
			system("cls");
			goto spanko;
		}
		chklr(kolor,2);slwtxt("\n\nKoniec rozdzialu 2\nHas�o do tego poziomu to: 2842.\nKliknij dowolny przycisk aby zacz�� rozdzia� trzeci.",textSpeed);
		getch();	
	}else{
		system("cls");
		goto wioska;
	}
}

void stage3(HANDLE kolor){
	system("cls");
	
	ifstream pin;
	string imie;
	pin.open("imie.txt");
	if (!pin){
      cout << "\nBLAD OTWARCIA!\n";
      system ("Pause");
      endgame(kolor);
    }
	pin>>imie;
	pin.close();
	
	int	HP=100,wybor,sklep=0,karczma=0,gildia=0,wyborjeden=0;
	
	chklr(kolor,2);slwtxt("*Obudzi� ci� szelest li�ci. Wsta�e� wypocz�ty oraz twoje punkty HP si� odnowi�y.*\n",textSpeed);
	chklr(kolor,0);slwtxt("Ilo�c punkt�w twojego �ycia wynosi: ",textSpeed);
	chklr(kolor,1);cout<<HP;
	chklr(kolor,0);slwtxt(".\n\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Ahh.. Czas wyruszy� w drog�, dalej szuka� jakie� cywilizacji.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Zgasi�e� ognisko i wyruszy�e� w drog�. Po 2 godzinnej tu�aczce znalaz�e� szlak z znakiem na kt�rym by�o napisane: <--- Do miasta.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": �wietnie w ko�cu b�d� m�g� z kim� porozmawia�.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Nagle zauwa�y�e�, �e z daleka nadci�ga jaki� w�z, a na nim siedzi cz�owiek.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Haloo!! Czy m�g�by Pan si� zatrzyma�?.\n",textSpeed);
	chklr(kolor,4);slwtxt("Nieznajomy: ",textSpeed);
	chklr(kolor,0);slwtxt("Gdzi� si� wybierasz cz�owieku?\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Chc� si� dosta� do miasta.\n",textSpeed);
	chklr(kolor,4);slwtxt("Nieznajomy: ",textSpeed);
	chklr(kolor,0);slwtxt("w takim razie wskakuj na ty�y.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Jestem ",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(", a ty?\n",textSpeed);
	chklr(kolor,4);slwtxt("Nieznajomy: ",textSpeed);
	chklr(kolor,0);slwtxt("Mi�o pozna� ",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(" ja jestem ",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel.",textSpeed);
	chklr(kolor,0);slwtxt(" Co cie sprowadza w nasze strony bo po ubiorze widz�, �e nietutejszy.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Zacze�em podr�owa� od jakiego� czasu i znalaz�em si� tutaj.\n",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel: ",textSpeed);
	chklr(kolor,0);slwtxt("Skoro m�wisz, �e jeste� poszukiwaczem przyg�d to powinniene� odwiedzi� gildi� w mie�cie. My�l�, �e znale�li by zadanie dla ciebie.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": A wi�c jest tutaj zaw�d Poszukiwacza przyg�d? Da si� jako� na tym zarobi�?\n",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel: ",textSpeed);
	chklr(kolor,0);slwtxt("HAHA ch�opcze, z k�d si� ty urwa�e� przecie� ",textSpeed);
	chklr(kolor,1);slwtxt("Poszukiwacz przyg�d",textSpeed);
	chklr(kolor,0);slwtxt(" jest aktualnie najbardziej p�atn� robot�. Jakbym by� m�odszy to pewnie teraz\nbym biega� po jaskiniach szukaj�c potwor�w.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Mo�na powiedzie�, �e jestem z miejsca dalszego ni� dok�d ka�demu znane. A masz mo�e jakie� porady co do miasta?\n",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel: ",textSpeed);
	chklr(kolor,0);slwtxt("Hmm pomy�lmy, dobrym miejscem do zatrzymania si� na troche jest karczma",textSpeed);
	chklr(kolor,1);slwtxt(" Winogrody",textSpeed);
	chklr(kolor,0);slwtxt(", co do miejsca z jakim� ubiorem i ekwipunkiem to sklep\nu krasnoluda ",textSpeed);
	chklr(kolor,1);slwtxt("Mattarniego",textSpeed);
	chklr(kolor,0);slwtxt(". No i jak m�wi�em gildia ",textSpeed);
	chklr(kolor,1);slwtxt("Poszukiwaczy przyg�d",textSpeed);
	chklr(kolor,0);slwtxt(" aby� m�g� co� zarobi�.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": A propo miasta ju� prawie jeste�my.\n",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel: ",textSpeed);
	chklr(kolor,0);slwtxt("Wiesz co ch�opcze masz tutaj kilka monet id� zmie� ten ubi�r bo mo�esz miec k�opoty przez niego. A teraz zmykaj z powozu �eby nas razem nie\nzobaczyli.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Dzi�kuje, a powiedz mi gdzie mog� ciebie znale�� �eby sp�aci� m�j d�ug wobec ciebie.\n",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel: ",textSpeed);
	chklr(kolor,0);slwtxt("Cz�sto wieczorami przesiaduj� w",textSpeed);
	chklr(kolor,1);slwtxt(" Winogrodach",textSpeed);
	chklr(kolor,0);slwtxt(" wi�c my�l�, �e i tak si� spotkamy i napijemy razem.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Oczywi�cie za twoje zdrowie. Do zobaczenia i powodzenia.\n",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel: ",textSpeed);
	chklr(kolor,0);slwtxt("Nawzajem m�ody.\n\n",textSpeed);
	chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przej�� dalej.",textSpeed);
	getch();
	system("cls");
	chklr(kolor,2);slwtxt("*Po oddaleniu si� od wozu Nathaniela, wyruszy�e� do bram zamku samemu, aby nie stwarza� problem�w.*\n",textSpeed);
	chklr(kolor,5);slwtxt("Stra�nik bramy: ",textSpeed);
	chklr(kolor,0);slwtxt("Ej ty st�j!!\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Tak, w czym mog� pom�c?\n",textSpeed);
	chklr(kolor,5);slwtxt("Stra�nik bramy: ",textSpeed);
	chklr(kolor,0);slwtxt("Widz�, �e jeste� nie tutejszy. Wpuszcz� ci� na teren miasta, lecz dam zna� innym o twoim pobycie tutaj wi�c miej si� na baczno�ci.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Dobrze, b�d� si� zachowywa� najlepiej jak potrafi�. Mi�ego dnia.\n",textSpeed);
	chklr(kolor,5);slwtxt("Stra�nik bramy: ",textSpeed);
	chklr(kolor,2);slwtxt(": *Wymamrota� pod nosem* ",textSpeed);
	chklr(kolor,0);slwtxt("Dziwny ten cz�owiek jakby nie wiedzia� co tutaj si� dzieje...\n\n",textSpeed);
	chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przej�� dalej.",textSpeed);
	getch();
	system("cls");
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": A wi�c z informacji jakie zdoby�em od ",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniela",textSpeed);
	chklr(kolor,0);slwtxt(" istniej� tutaj inne rasy ni� ludzie. Bardzo ten �wiat przypomina mi swojego rodzaju gry z Ziemi.\nNo c� mniejsza z tym czas uda� si� w miejsca o kt�rych m�wi� mi m�j nowy znajomy.\n\n",textSpeed);
	miasto:
	chklr(kolor,0);slwtxt("Gdzie chcesz si� uda�?\n\n",textSpeed);
	chklr(kolor,2);slwtxt("1.",textSpeed);
	chklr(kolor,0);slwtxt("Sklep z ubraniami i ekwipunkiem.\n",textSpeed);
	chklr(kolor,2);slwtxt("2.",textSpeed);
	chklr(kolor,0);slwtxt("Karczma.\n",textSpeed);
	chklr(kolor,2);slwtxt("3.",textSpeed);
	chklr(kolor,0);slwtxt("Gildia Poszukiwaczy przyg�d.\n\n",textSpeed);
	chklr(kolor,0);slwtxt("Tw�j wyb�r to: ",textSpeed);
	cin>>wybor;
	
	
	
	if(wybor==1){
		if(wyborjeden==0){
			system("cls");
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dobra wie� trzeba wtopi� si� w t�um i zdoby� jak�� lepsz� bro� ni� ten scyzoryk.\n",textSpeed);
			chklr(kolor,2);slwtxt("*Dotar�e� do sklepu z ubraniami i ekwpinukiem.*\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dzie� dobry, chcia�bym dokona� zakupku.\n",textSpeed);
			chklr(kolor,5);slwtxt("Kassarina: ",textSpeed);
			chklr(kolor,0);slwtxt(": Witam z tej strony Kassarina, co pana dok�aniej interesuje.\n",textSpeed);
			chklr(kolor,2);slwtxt("*Spogl�dasz do kieszeni i sprawdzasz ile masz monet.*\n",textSpeed);
			chklr(kolor,2);slwtxt("Aktualnie posiadasz: ",textSpeed);
			chklr(kolor,1);slwtxt("2 z�ote oraz 34 srebrne ",textSpeed);
			chklr(kolor,2);slwtxt("monety.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Wi�c potrzebuje ekwipunku oraz ubioru dla pocz�tkuj�cego podr�nika przyg�d.\n",textSpeed);
			chklr(kolor,5);slwtxt("Kassarina: ",textSpeed);
			chklr(kolor,0);slwtxt(": Zobaczmy... Mam komplet zbroi oraz kr�tki miecz. Cena tego zestawu to 30 srebrnych monet. Lecz mam dla Pana lepsz� propozycj�, podoba\nmi si� pana ubi�r mo�e dokonamy wymiany? M�j zestaw za pana ubi�r.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Oczywi�cie, �e si� zgadzam.\n",textSpeed);
			chklr(kolor,5);slwtxt("Kassarina: ",textSpeed);
			chklr(kolor,0);slwtxt(": W takim razie zapraszam do przymierzalni.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": *w my�lach*",textSpeed);
			chklr(kolor,0);slwtxt(" Ale super mi si� uda�o nie do��, �e pozby�em si� tych szmat to ten ekwipunek lerzy na mnie jak ula�.\n",textSpeed);
			chklr(kolor,5);slwtxt("Kassarina: ",textSpeed);
			chklr(kolor,0);slwtxt(": Czy to wszystko? Czy mo�e pan jescze czego� potrzebuje?\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Aktualnie podzi�kuje, ale co� mi poddpowiada, �e zawitam tutaj napewno. Dowidzenia.\n",textSpeed);
			chklr(kolor,5);slwtxt("Kassarina: ",textSpeed);
			chklr(kolor,0);slwtxt(": To ja dzi�kuje. Dowidzenia.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dobra teraz czas si� uda� za�atwi� reszt�.\n\n",textSpeed);
			chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przej�� dalej.",textSpeed);
			getch();
			sklep=1;
			system("cls");
			wyborjeden=1;
			goto miasto;
		}else if(wyborjeden==1){
			system("cls");
			chklr(kolor,2);slwtxt("*Ju� kupi�e� ekwpiunek, udaj si� do karczmy.*",textSpeed);
			getch();
			system("cls");
			goto miasto;
		}
	}else if(wybor==2){
		system("cls");
		if(sklep==0){
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Powinnienem najpierw kupi� jaki� ekwipunek zanim udam si� do karczmy.\n\n",textSpeed);
			chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przej�� dalej.",textSpeed);
			getch();
			system("cls");
			goto miasto;
		}else if(sklep==1){
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dobra wi�c trzeba znale�� lokum na dzisiejsz� noc, lecz musz� uwa�a� bo jescze nie znam cen. My�l�, �e wybiore co� najta�szego.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dzie� Dobry, chcia�bym najta�szy pok�j jaki jest na jedn� noc.\n",textSpeed);
			chklr(kolor,4);slwtxt("Karczmarka",textSpeed);
			chklr(kolor,0);slwtxt(": Dzie� Dobry, dobrze w takim razie poprosz� 5 srebrnych monet.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Prosz� bardzo.\n",textSpeed);
			chklr(kolor,4);slwtxt("Karczmarka",textSpeed);
			chklr(kolor,0);slwtxt(": Pa�ski pok�j znajduj� si� na pi�trze pierwsze drzwi po prawej. Oto klucz do pa�skiego pokoju.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dzi�kuje, mi�ego dnia.\n",textSpeed);
			chklr(kolor,4);slwtxt("Karczmarka",textSpeed);
			chklr(kolor,0);slwtxt(": Mi�ego pobytu w naszej karczmie!\n\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dobra teraz trzeba dosta� si� do gildii i zapisa� do niej.\n\n",textSpeed);
			chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przej�� dalej.",textSpeed);
			karczma=1;
			getch();
			system("cls");
			goto miasto;
		}
		system("cls");
		goto miasto;
	}else if(wybor==3){
		system("cls");
		if(karczma==0){
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Najpierw p�jde do karczmy wykupi� pok�j na t� noc.\n\n",textSpeed);
			chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przej�� dalej.",textSpeed);
			getch();
			system("cls");
			goto miasto;
		}else if(karczma==1){
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": A wi�c czas zacz�� przygod�.\n\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Witam chcia�bym si� zapisa� do gildi..\n",textSpeed);
			chklr(kolor,4);slwtxt("Rekrutantka",textSpeed);
			chklr(kolor,0);slwtxt(": Dobrze w takim razie, przedstawie panu zasady gildii:\n\n",textSpeed);
			chklr(kolor,0);slwtxt("1. Co miesi�czna op�ata w wysoko�ci 30 srebnych monet.\n",textSpeed);
			chklr(kolor,0);slwtxt("2. Zakaz sprzedawania innych cz�onk�w gildii.\n",textSpeed);
			chklr(kolor,0);slwtxt("3. Godne chodzenie z tytu�em nadamym przez lidera gildii.\n\n",textSpeed);
			chklr(kolor,4);slwtxt("Rekrutantka",textSpeed);
			chklr(kolor,0);slwtxt(": Lecz najpierw musz� popro�i� Pana o imi� oraz o uiszczenie wp�aty do gildi, wtedy zotanie pan pe�noprawnym cz�onkiem jako m�odszy poszukiwacz przyg�d.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Moje imi� to: ",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(". Prosz� tutaj 30 srebrnych monet.\n",textSpeed);
			chklr(kolor,4);slwtxt("Rekrutantka",textSpeed);
			chklr(kolor,0);slwtxt(": Gratulujemy zosta�e� oficjalnie cz�onkiem gildi! Niestety, ale wszystkie zadania na dzi� zosta�y rozdane. Zapraszam jutro z rana po nowe.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": R�wnie� dzi�kuj� i do jutra!\n\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dobra za du�o wra�e� jak na dzi�, czas is� spa�.\n\n",textSpeed);
			chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przej�� dalej.",textSpeed);
			getch();
			system("cls");
		}
		chklr(kolor,2);slwtxt("\nKoniec rozdzialu 3\nHas�o do tego poziomu to: 3256.\nKliknij dowolny przycisk aby zacz�� rozdzia� czwarty.",textSpeed);
		getch();
		system("cls");
		stage4(kolor);
	}else{
		system("cls");
		goto miasto;
	}
	
	getch();
}

void stage4(HANDLE kolor){
	system("cls");
	ifstream pin;
	string imie;
	pin.open("imie.txt");
	if (!pin){
      cout << "\nBLAD OTWARCIA!\n";
      system ("Pause");
      endgame(kolor);
    }
	pin>>imie;
	pin.close();

	chklr(kolor,2);slwtxt("*Po nocy w karczmie budzisz si� i szykujesz, aby wyruszy� na pierwsz� misj� z gildii.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Dobra trzba zacz�� zarabia� na dostatnie �ycie w tym �wiecie. Czas i�� do budynku gildii.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Kiedy ju� dotar�e� do gildii odrazu podszed�e� do tablicy og�osze�.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": W takim razie musz� wybra� co� z czym dam rad� na pocz�tku.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Kiedy przegl�da�e� og�oszenia nagle jedno z nich przyku�o twoj� uwag�.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Co to misja za 3 z�ote monety, a dla grupy m�odych poszukiwaczy przyg�d. Brzmi nie�le tylko gdzie znajde osoby, kt�re zdecyduj� sie tam p�j��. Hmm chyba p�jd� popyta� po gildii.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Przy jednym ze sto��w gildyjnych siedzia�o kilka os�b z s�abym ekwipunkiem.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Cze�� jestem",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(" czy mo�e macie troszk� czasu?\n",textSpeed);
	chklr(kolor,1);slwtxt("Alezy",textSpeed);
	chklr(kolor,0);slwtxt(": Ahh to ty ten nowy o kt�rym wczoraj m�wili. Witam jestem ",textSpeed);
	chklr(kolor,1);slwtxt("Alezy",textSpeed);
	chklr(kolor,0);slwtxt(", a to moja dru�yna w kt�rej w sk�ad wchodzi:\n",textSpeed);
	chklr(kolor,5);slwtxt("Alkais - pot�ny wojownik",textSpeed);
	chklr(kolor,0);slwtxt(", ",textSpeed);
	chklr(kolor,3);slwtxt("Somatris - nasza druidka ",textSpeed);
	chklr(kolor,0);slwtxt("oraz ",textSpeed);
	chklr(kolor,4);slwtxt("Saiko - �owca",textSpeed);
	chklr(kolor,0);slwtxt(". W czym mo�emy ci pom�c?\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Znalaz�em w�a�nie og�oszenia na 3 z�ote monety, lecz potrzebuje dru�yny aby je wykona�. Czy mo�e checeie mi pom�c?\n",textSpeed);
	chklr(kolor,3);slwtxt("Somatris",textSpeed);
	chklr(kolor,0);slwtxt(": Pewnie, zawsze milej wykonuje si� zadania razem.\n",textSpeed);
	chklr(kolor,1);slwtxt("Alezy",textSpeed);
	chklr(kolor,0);slwtxt(": W takim razie wyruszajmy p�ki mo�emy.\n",textSpeed);
	chklr(kolor,2);slwtxt("*W raz z nowymi kompanami wyruszyli�cie na zadanie poiwerzone przez gildie.*\n\n",textSpeed);
	chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przej�� dalej.",textSpeed);
	getch();
	system("cls");
	chklr(kolor,2);slwtxt("*Mine�o 2 dni od k�d wyruszyli�cie z miasta do wioski w kt�rej by�o zadanie do wykonania. W tym czasie ty wraz z nowymi kompanami strasznie sie z�yli�cie.\nOpowiedzia�e� im o swojej �mierci i o �yciu na Ziemi co nie do ko�ca ich zdziwi�o.*\n\n",textSpeed);
	chklr(kolor,2);slwtxt("*Kiedy dotarli�cie do wioski natychmiast wybrali�cie si� do wodza, kt�ry wyda� te og�oszenie.*\n",textSpeed);
	chklr(kolor,1);slwtxt("Alezy",textSpeed);
	chklr(kolor,0);slwtxt(": Witamy wodzu jeste�my cz�onkami gildii. Przybyli�my, aby wykona� twoje zadanie.\n",textSpeed);
	chklr(kolor,1);slwtxt("W�dz",textSpeed);
	chklr(kolor,0);slwtxt(": O Bogowie dzi�ki, w ko�cu wybawiciele. Dzi�kuje, �e przybylis�ie �mia�kowie na nasze wezwanie bowiem posiadamy problem z nieznan� kreatur�, kt�ra\npl�druje nasze ��ki. Czy rozprawicie si� z ni�?\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Oczywi�cie, �e damy rad� w ko�cu po to przybyli�my tutaj.\n",textSpeed);
	chklr(kolor,1);slwtxt("W�dz",textSpeed);
	chklr(kolor,0);slwtxt(": W takim razie wyruszajcie czym pr�dzej, poniewa� czuj�, �e ju� d�ugo nasza osada nie da rady je�li ta kreatura b�dzie nam nisczy�a zbiory.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Po spotkaniu z wodzem, grupa �mia�ych poszukiwaczy przyg�d uda�a si� bezpo�rednio do jaskini.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Jak my�lisz ",textSpeed);
	chklr(kolor,4);slwtxt("Saiko",textSpeed);
	chklr(kolor,0);slwtxt(" co to mo�e by� za stworzenie ?\n",textSpeed);
	chklr(kolor,4);slwtxt("Saiko",textSpeed);
	chklr(kolor,0);slwtxt(": Hmm dziwnie to wszystko, ja jako wybitny pocz�tkuj�cy �owca nie mog� znale�� rzadnych �lad�w ani nie czuje zapachu tej kreatury i nie wiem czym\nto mo�e by�. Lecz w�tpie, aby by�o to cos pot�nego skoro pl�druje tylko plony a nikogo do tej pory nie zabi�o.\n",textSpeed);
	chklr(kolor,5);slwtxt("Alkais",textSpeed);
	chklr(kolor,0);slwtxt(": Skoro to pewnie jakie� s�abe zwierz�tko to zr�bmy to jak najszybciej aby mie� to ju� z g�owy i zgarn�� nasze wynagrodzenie.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Po tych s�owach nasza grupa wesz�a do jaskini co by�o ogromnym b��dem. Okaza�o si�, �e stworzenie to",textSpeed);
	chklr(kolor,5);slwtxt(" Assperghak ",textSpeed);
	chklr(kolor,2);slwtxt("jedno z legendarnych kreatur tego\n�wiata, kt�rejest bardzo niebezpieczne kiedy wejdzie sie na jego teren.*\n",textSpeed);
	chklr(kolor,1);slwtxt("Alezy",textSpeed);
	chklr(kolor,0);slwtxt(": Bogowie co to jest!!! To nas wszystkich zabije!\n",textSpeed);
	chklr(kolor,5);slwtxt("Alkais",textSpeed);
	chklr(kolor,0);slwtxt(": Je�li mam zostac zabity to tylko podczas walki!! Wy mo�ecie ucieka�!\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Nigdy w �yciu! Skoro przybyli�my tutaj razem to nie pozwole ci samemu umrze� ja zostaje z ",textSpeed);
	chklr(kolor,5);slwtxt("Alkais'em",textSpeed);
	chklr(kolor,0);slwtxt("!\n",textSpeed);
	chklr(kolor,2);slwtxt("*Po bohaterskich wyznaniach bohater�w nast�pi�a powa�na walka.*\n",textSpeed);
	chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przej�� dalej.",textSpeed);
	getch();
	system("cls");
	
	int HP=100,HPenemy=100,wyborwalka=0;
	
	walka:
	if(HP==0){
		system("cls");
		chklr(kolor,2);slwtxt("\nKoniec rozdzialu 4\nHas�o do tego poziomu to: 4987.\nKliknij dowolny przycisk aby zacz�� rozdzia� czwarty.",textSpeed);
		stage5(kolor);
		
	}else{
	chklr(kolor,0);slwtxt("Ilo�c punkt�w twojej dru�yny wynosi: ",textSpeed);
	chklr(kolor,1);cout<<HP;
	chklr(kolor,0);slwtxt(".\n",textSpeed);
	chklr(kolor,0);slwtxt("Ilo�c punkt�w �ycia przeciwnika wynosi: ",textSpeed);
	chklr(kolor,1);cout<<HPenemy;
	chklr(kolor,0);slwtxt(".",textSpeed);
	chklr(kolor,0);slwtxt("\n\nCo chcesz teraz zrobi�?\n\n",textSpeed);
	chklr(kolor,2);slwtxt("1.",textSpeed);
	chklr(kolor,0);slwtxt("ATAK | ",textSpeed);
	chklr(kolor,2);slwtxt("2.",textSpeed);
	chklr(kolor,0);slwtxt("OBRONA | ",textSpeed);
	chklr(kolor,0);slwtxt("\n\nTw�j wyb�r to: ",textSpeed);
	cin>>wyborwalka;
	
	if(wyborwalka==1){
		system("cls");
		chklr(kolor,0);slwtxt("Tw�j wyb�r to: ATAK.",textSpeed);
		for(int i=0;i<=1;i++){
			int obrazenia=(rand()%15)+1;
			HP=HP-obrazenia;
	  	};
		for(int i=0;i<=1;i++){
			int obrazenia=(rand()%2)+1;
			HPenemy=HPenemy-obrazenia;	
	  	};
	  	if(HP<0){
	  			system("cls");
				HP=0; 
				chklr(kolor,2);slwtxt("*Niestety twoja dru�yna wraz z tob� poleg�y.*",textSpeed);
			  };
	  	getch();
	  	system("cls");
	  	goto walka;
	}else if(wyborwalka==2){
		system("cls");
		chklr(kolor,0);slwtxt("Tw�j wyb�r to: OBRONA.\n",textSpeed);
		chklr(kolor,2);slwtxt("*Wasz obrona okaza�a si� by� nie skuteczna! Potw�r zada� wam obra�enia!*\n",textSpeed);
		HP=HP-5;
		getch();
		system("cls");
		goto walka;
	}else{
		system("cls");
		goto walka;
	};	
}
}
void stage5(HANDLE kolor){
	system("cls");

	ifstream pin;
	string imie;
	pin.open("imie.txt");
	if (!pin){
      cout << "\nBLAD OTWARCIA!\n";
      system ("Pause");
      endgame(kolor);
    }
	pin>>imie;
	pin.close();
	
	chklr(kolor,1);slwtxt("....GAMEOVER....\n\n\n",textSpeed);
	getch();
	chklr(kolor,2);slwtxt("\nCzas: ",textSpeed);
	chklr(kolor,0);slwtxt("17 grudnia 2018 ",textSpeed);
	chklr(kolor,2);slwtxt("Miejsce: ",textSpeed);
	chklr(kolor,0);slwtxt("Pozna�, Polska\n\n",textSpeed);
	chklr(kolor,2);slwtxt("*Budzisz si� jak co dzie� w swoim ��ku z my�l�, �e znowu musisz i�� do pracy*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Ahh... i po co mi to wszystko by�o, ca�e te studia �eby teraz robi� w jakim� korpo do staro�ci. Masakra...\n",textSpeed);
	int i=0;
	while(i<5){
		chklr(kolor,0);slwtxt("...",textSpeed);
		i++;
	};
	
	chklr(kolor,2);slwtxt("\n\n\nKliknij dowolny przycisk, aby zako�czy� gr�.",textSpeed);
	getch();
	exit(0);
};

void endgame(HANDLE kolor){
	system("cls");
	chklr(kolor,1);slwtxt("....GAMEOVER....",textSpeed);
	Sleep(5000);
}

int conv(string a){ //zamiana typu zmiennej z string do int
    int v=0;
    for(int b=0;b<a.length();b++)
        v=v*10+a[b]-48;

    return v;
}

bool isnum( string t ) { //funkcja sprawdza czy podana wartosc jest cyfr�
    for(int a=0;a<t.length();a++){ //sprawd� ka�d� 'kom�rk�' z tablicy zmiennej
        if(t[a]>'0'+9||t[a]<'0') return false; //je�eli kt�rakolwiek z 'kom�rek' nie jest cyfr�, cala funkcja zwraca false

    }
    return true; //jezeli zmienna byla cyfra- zwroci true 
}

int menu_variable(){
        int menu=0;
        string ab; //zmienna wprowadzana w wyborze w menu
        cin.clear(); //czyszczenie cin
        cin.sync();
        getline(cin, ab);	//pobieranie zmiennej ab z cin
        if(isnum(ab)){ //sprawdzanie czy zmienna ab jest cyfra
            menu= conv(ab); //jezeli ab jest liczba to przypisz jej wartosc do zmiennej menu 
        }
        return menu; //zwracanie zmiennej menu, jezeli podana wartosc byla cyfra to j� zwr�ci, jezeli inna warto��, zwr�ci 0
}
