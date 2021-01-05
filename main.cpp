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
		chklr(kolor,0);slwtxt("\n\nTwój wybór to: ",textSpeed);
			switch(menu_variable()){
				case 1:{
					system("cls");
					
					string imie;
					ofstream pout;
					pout.open("imie.txt");
					chklr(kolor,0);slwtxt("Podaj swoje imiê: ",textSpeed);
					chklr(kolor,6);cin>>imie;
					pout<<imie;
					pout.close();
					
					chklr(kolor,0);slwtxt("\n\nCzy ma graæ muzyka?\n",textSpeed);
					chklr(kolor,1);slwtxt("1.",textSpeed);
					chklr(kolor,0);slwtxt("Tak.\n",textSpeed);
					chklr(kolor,1);slwtxt("2.",textSpeed);
					chklr(kolor,0);slwtxt("Nie.\n",textSpeed);
					chklr(kolor,0);slwtxt("\nTwój wybór to: ",textSpeed);
					cin>>muzyczka;
					if(muzyczka==1){
						WinExec("muzyka.exe",1);
					}else if(muzyczka==2){
					
					}
					
					speedster:
					chklr(kolor,0);slwtxt("\n\nZ jak¹ prêdkoœci¹ ma sie pojawiaæ tekst?\n",textSpeed);
					chklr(kolor,1);slwtxt("1.",textSpeed);
					chklr(kolor,0);slwtxt("B³yskawicznie. (Mo¿e zepsuæ klimat gry.)\n",textSpeed);
					chklr(kolor,1);slwtxt("2.",textSpeed);
					chklr(kolor,0);slwtxt("Powoli.\n",textSpeed);
					chklr(kolor,1);slwtxt("3.",textSpeed);
					chklr(kolor,0);slwtxt("Wolno.\n",textSpeed);
					chklr(kolor,0);slwtxt("\nTwój wybór to: ",textSpeed);
					cin>>speed;
					
					if(speed==1){
						textSpeed=0;
					}else if(speed==2){
						textSpeed=10;
					}else if(speed==3){
						textSpeed=20;
					}else{
						chklr(kolor,0);slwtxt("B³êdna wartoœæ! Spróbuj od nowa.",textSpeed);
						goto speedster;
					}
					
					chklr(kolor,0);slwtxt("\n\nCzy chcesz pomin¹æ tutorial ?\n[",textSpeed);
					chklr(kolor,2);slwtxt("T",textSpeed);
					chklr(kolor,0);slwtxt("/",textSpeed);
					chklr(kolor,1);slwtxt("n",textSpeed);
					chklr(kolor,0);slwtxt("]\n\n",textSpeed);
					chklr(kolor,0);slwtxt("Twój wybór to: ",textSpeed);
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
						chklr(kolor,1);slwtxt("Poda³eœ z³y wybór. Zacznij od nowa :)\n\n",textSpeed);
						menu(kolor);
					}
				}break;
				case 2:{
					system("cls");
					logo(kolor);
					
					chklr(kolor,0);slwtxt("\n\nCzy ma graæ muzyka?\n",textSpeed);
					chklr(kolor,1);slwtxt("1.",textSpeed);
					chklr(kolor,0);slwtxt("Tak.\n",textSpeed);
					chklr(kolor,1);slwtxt("2.",textSpeed);
					chklr(kolor,0);slwtxt("Nie.\n",textSpeed);
					chklr(kolor,0);slwtxt("\nTwój wybór to: ",textSpeed);
					cin>>muzyczka;
					if(muzyczka==1){
						WinExec("muzyka.exe",1);
					}else if(muzyczka==2){
					
					}
					
					speedster1:
					chklr(kolor,0);slwtxt("\n\nZ jak¹ prêdkoœci¹ ma sie pojawiaæ tekst?\n",textSpeed);
					chklr(kolor,1);slwtxt("1.",textSpeed);
					chklr(kolor,0);slwtxt("B³yskawicznie. (Mo¿e zepsuæ klimat gry.)\n",textSpeed);
					chklr(kolor,1);slwtxt("2.",textSpeed);
					chklr(kolor,0);slwtxt("Powoli.\n",textSpeed);
					chklr(kolor,1);slwtxt("3.",textSpeed);
					chklr(kolor,0);slwtxt("Wolno.\n",textSpeed);
					chklr(kolor,0);slwtxt("\nTwój wybór to: ",textSpeed);
					cin>>speed;
					
					if(speed==1){
						textSpeed=0;
					}else if(speed==2){
						textSpeed=10;
					}else if(speed==3){
						textSpeed=20;
					}else{
						chklr(kolor,0);slwtxt("B³êdna wartoœæ! Spróbuj od nowa.",textSpeed);
						goto speedster1;
					}
					
					loadstage:
					system("cls");
					chklr(kolor,0);slwtxt("\n\nPodaj has³o do poziomu.",textSpeed);
					chklr(kolor,0);slwtxt("\nTwóje has³o to: ",textSpeed);
					cin>>load;
				    while (cin.fail())
				    {
				        cin.clear(); // clear input buffer to restore cin to a usable state
				        cin.ignore(INT_MAX, '\n'); // ignore last input
				        chklr(kolor,1);slwtxt("\nHas³o nie posaida ¿adnych liter!\n",textSpeed);
				        chklr(kolor,0);slwtxt("Podaj poprawne has³o: ",textSpeed);
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
							chklr(kolor,1);slwtxt("\nTwóje has³o jest z³e zacznij od nowa.",textSpeed);
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
					slwtxt("Poda³eœ z³y wybór !!! \nZacznij od nowa.\n", textSpeed);Sleep(loading);
					animation(kolor);
				}break;
			};
			chklr(kolor, 0);
}

void tutorial(HANDLE kolor){
	system("cls");
	slwtxt("Witaj w grze pod tytu³em ",textSpeed);
	chklr(kolor,2);slwtxt("RPG The Game", textSpeed);
	chklr(kolor,0);slwtxt(" w której twoim zadaniem bêdzie ukoñczenie fabu³y.\n\n Zasady oraz informacje: \n", textSpeed);
	chklr(kolor,2);slwtxt("1.",textSpeed);
	chklr(kolor,0);slwtxt("Baw siê ",textSpeed);
	chklr(kolor,1);slwtxt("dobrze",textSpeed);
	chklr(kolor,0);slwtxt(".\n",textSpeed);
	chklr(kolor,2);slwtxt("2.",textSpeed);
	chklr(kolor,0);slwtxt("Wykonuj polecenia podane przez ",textSpeed);
	chklr(kolor,1);slwtxt("gre",textSpeed);
	chklr(kolor,0);slwtxt(".\n",textSpeed);
	chklr(kolor,2);slwtxt("3.",textSpeed);
	chklr(kolor,0);slwtxt("Has³o poziomu pokazuje siê przy numerze rozdzia³u ",textSpeed);
	chklr(kolor,1);slwtxt("zapisz",textSpeed);
	chklr(kolor,0);slwtxt("sobie je.\n",textSpeed);
	chklr(kolor,2);slwtxt("4.",textSpeed);
	chklr(kolor,0);slwtxt("Kiedy pojawia siê tekst mo¿esz go przewijaæ klawiszem ",textSpeed);
	chklr(kolor,1);slwtxt("Enter",textSpeed);
	chklr(kolor,0);slwtxt(".\n",textSpeed);
	chklr(kolor,2);slwtxt("5.",textSpeed);
	chklr(kolor,0);slwtxt("Twórc¹ gry jest ",textSpeed);
	chklr(kolor,1);slwtxt("Wiktor Gregorczyk",textSpeed);
	chklr(kolor,0);slwtxt(".\n\n",textSpeed);
	slwtxt("Aby zaczaæ rozgrywkê kliknij dowolny przycisk.\n",textSpeed);
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
	chklr(kolor,0);slwtxt("Poznañ, Polska\n\n",textSpeed);
	chklr(kolor,2);slwtxt("*Budzisz siê jak co dzieñ w swoim ³ó¿ku z myœl¹, ¿e znowu musisz iœæ do pracy.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Ahh... i po co mi to wszystko by³o, ca³e te studia ¿eby teraz robiæ w jakimœ korpo do staroœci. Masakra...\n",textSpeed);
	chklr(kolor,2);slwtxt("*Po kilku wdechach wsta³eœ i zacze³eœ siê szykowaæ. Zjda³eœ œniadanie i wyszed³eœ z domu.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Ciekawe czy dzisaj znowu szef bêdzie mnie mêczy³ swoim monlogiem na temat mojej wydajnoœci i innych bzdetach...\n",textSpeed);
	chklr(kolor,2);slwtxt("*Nagle s³yszysz, ¿e ktoœ krzyczy twoje imiê. Spogl¹dasz za ciebie a to twój znajomy z pracy ",textSpeed);
	chklr(kolor,4);slwtxt("Mariusz",textSpeed);
	chklr(kolor,0);slwtxt(".*\n",textSpeed);
	chklr(kolor,4);slwtxt("Mariusz: ",textSpeed);
	chklr(kolor,0);slwtxt("Heej ",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(" zaczekaaj na mnieee !!!\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": *myœli* Mariusz to jedyny wporz¹dku w tej firmie wiêc nie mam nic przeciwko na niego zaczekaæ.\n",textSpeed);
	chklr(kolor,4);slwtxt("Mariusz: ",textSpeed);
	chklr(kolor,0);slwtxt("Czeœæ dziêki, ¿e zaczeka³eœ. W koñcu razem zawsze raŸniej nieprawda¿?\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": No tak, tak zawsze razem lepiej.\n",textSpeed);
	chklr(kolor,4);slwtxt("Mariusz: ",textSpeed);
	chklr(kolor,0);slwtxt("Hmm... A co ty na to aby gdzieœ wyskoczyæ na przerwie? Mo¿e sushi?\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Czemu nie.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Nagle s³ychaæ pisk opon, a nastêpnie uderzenie.*\n",textSpeed);
	chklr(kolor,4);slwtxt("Mariusz: ",textSpeed);
	chklr(kolor,0);slwtxt("Ludzie !!! Dzwoncie po karetke !! Pomocy !\n",textSpeed);
	chklr(kolor,2);slwtxt("*Odczuwasz zimno, a jednoczesnie ciep³o. Jesteœ zdezorientowany.*\n*Powoli dociera do ciebie co sie sta³o.*\n",textSpeed);
	chklr(kolor,5);slwtxt("Nieznana postaæ: ",textSpeed);
	chklr(kolor,0);slwtxt("A wiêc tak siê koñczy twój ¿ywot na twojej planecie. Hmm.. bardzo ciekawe.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Co jest, kto to mówi???\n",textSpeed);
	chklr(kolor,5);slwtxt("Nieznana postaæ: ",textSpeed);
	chklr(kolor,0);slwtxt("Mo¿e na chwilê przeniose nas w inne miejsce, ¿eby ³atwiej by³o ci wszystko wyt³umaczyæ.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Nagle pojawiasz siê w twoim pokoju w dodatku przed tob¹ stoi kobieta w czarnej szacie. Jesteœ nadal zdezorientowany.*\n", textSpeed);
	chklr(kolor,5);slwtxt("Nieznana postaæ: ",textSpeed);
	chklr(kolor,0);slwtxt("Wiêc zacznijmy od ³atwiejszych rzeczy. Ty ",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(" w³asnie umra³eœ.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Coo? Jakim cudem skoro tutaj jesteœmy? A pozatym kim jesteœ?!\n",textSpeed);
	chklr(kolor,5);slwtxt("Nieznana postaæ: ",textSpeed);
	chklr(kolor,0);slwtxt("Moje imiê jest nie wa¿ne, ale skoro chcesz je znaæ to jestem ",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra",textSpeed);
	chklr(kolor,0);slwtxt(", zwana czasami przez twój gatunek jako bogini œmierci.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Chyba zaraz zwarjujê. A nie, to pewnie tylko z³y sen dlatego jestem u mnie w pokoju, a reszta to moja wyobraŸnia.\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("Niestety obawiam siê, ¿e to nie jest twoja wyobraŸnia. Pozwól, ¿e ci poka¿ê.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Raptownie pojawiasz siê w miejscu, gdzie le¿¹ twoje zw³oki. Obok nich widzisz ",textSpeed);
	chklr(kolor,4);slwtxt("Mariusza",textSpeed);
	chklr(kolor,2);slwtxt(", który próbuje ci pomóc.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Co jakim cudem?? Przecie¿ ja stoje tutaj, a moje cia³o jest na ziemi ?!?\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("Wiem, ¿e dla ciebie mo¿e byæ to trudne do zrozumienia, ale jak teraz sam widzisz umar³eœ naprawdê.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": No dobrze, dobrze teraz mo¿e i ci uwierzê, ale dlaczego tutaj jesteœ i mi to wszystko pokazujesz?\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("No dobrze to teraz cie zabiorê do siebie i skoro och³on¹³eœ to wyt³umacze ci.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Pojawiasz siê wraz z ",textSpeed);
	chklr(kolor,5);slwtxt("Nyjr¹ ",textSpeed);
	chklr(kolor,2);slwtxt("w dziwnym kompletnie bia³ym pomiesczeniu.*\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("W takim razie jak ju¿ zd¹rzy³eœ przyj¹æ do rozumu, ¿e umra³eœ to chcê ci powiedzieæ co siê z tob¹ dalej stanie.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": W takim razie s³ucham...\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("Masz wybór co chcesz zrobiæ. Twoj¹ pierwsz¹ opcj¹ jest odes³anie do pustki co oznacza, ¿e stracisz œwiadomoœæ i bêdziesz b³¹ka³ siê bez koñca w\nnicoœci. Natomiast drugim wyborem jest zaczniêcie ¿ycia od nowa.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Co do pierwszego to jest niedorzeczne! Kto by chcia³ wybraæ coœ takiego... Jakbyœ mog³a droga ",textSpeed);
	chklr(kolor,5);slwtxt("Nyjro ",textSpeed);
	chklr(kolor,0);slwtxt("wyt³umaczyæ bardziej o tym nowym ¿yciu.\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("Jeœli wybierzesz drug¹ opcje to zachowasz wspomnienia, wiek i rzeczy które mia³eœ przy sobie kiedy umra³eœ, lecz pojawisz siê w losowym\nmiejscu i czasie.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Czyli mogê w wyl¹dowaæ w przysz³oœci i przesz³oœci?\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("Tak, a ponadto nie koniecznie mo¿esz wyl¹dowac w tym samym wszechœwiecie.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Chyba nie do koñca rozumiem ale mniejsza z tym.\n",textSpeed);
	chklr(kolor,5);slwtxt("Nyjra: ",textSpeed);
	chklr(kolor,0);slwtxt("W takim razie jaki jest twój wybór?\n\n",textSpeed);
				
	chklr(kolor,1);slwtxt("1. ",textSpeed);
	chklr(kolor,0);slwtxt("Zapomnienie o swojej egzystencji oraz b³¹kanie siê po pustce.\n",textSpeed);
	chklr(kolor,2);slwtxt("2. ",textSpeed);
	chklr(kolor,0);slwtxt("Odrodzenie siê oraz zaczêcie ¿ycia od nowa.\n\n",textSpeed);
	
	chklr(kolor,0);slwtxt("Twój wybór to: ",textSpeed);
	cin>>wybor;
				
	if(wybor==1){
		endgame(kolor);
	}else if(wybor==2){
		chklr(kolor,2);slwtxt("\nKoniec rozdzialu 1\nHas³o do tego poziomu to: 1543.\nKliknij dowolny przycisk aby zacz¹æ rozdzia³ drugi.",textSpeed);
		getch();
		stage2(kolor);
	}else{
		chklr(kolor,1);slwtxt("A wiêc nie wybierasz niczego ?! W takim razie pozwól, ¿e wybiorê za ciebie.",textSpeed);
		getch();
		chklr(kolor,2);slwtxt("\nKoniec rozdzialu 1\nHas³o do tego poziomu to: 1543.\nKliknij dowolny przycisk aby zacz¹æ rozdzia³ drugi.",textSpeed);
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
	chklr(kolor,2);slwtxt("*Wstajesz ze snu z myœl¹, ¿e to by³ sen, lecz budzisz siê nie w swoim pokoju. Rozgl¹dasz siê do oko³a i widzisz przepiêkny krajobraz.*\n\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": A jednak to nie by³ sen. Dziwne, ale czuje siê wypoczêty jakbym spa³ z tydzieñ. Dobra czas sprawdziæ na czym stojê i co mam przy sobie.\n",textSpeed);
	wybor1:
	chklr(kolor,0);slwtxt("Co chcesz teraz zrobiæ?\n\n",textSpeed);
	chklr(kolor,2);slwtxt("1.",textSpeed);
	chklr(kolor,0);slwtxt("Zajrzyj do plecaka.\n",textSpeed);
	chklr(kolor,2);slwtxt("2.",textSpeed);
	chklr(kolor,0);slwtxt("Porozgl¹daj siê do oko³a.\n",textSpeed);
	chklr(kolor,2);slwtxt("3.",textSpeed);
	chklr(kolor,0);slwtxt("Obmyœl plan dzia³ania.\n\n",textSpeed);
	chklr(kolor,0);slwtxt("Twój wybór to: ",textSpeed);
	cin>>wybor;

	if(wybor==1){
		system("cls");
		chklr(kolor,6);slwtxt(imie,textSpeed);
		chklr(kolor,0);slwtxt(": A wiêc tak, aktualnie posiadamz ze sob¹ telefon, portfel, œniadanie oraz scyzoryk.\n",textSpeed);
		wybora=1;
		getch();
		system("cls");
		goto wybor1;
	}else if(wybor==2){
		system("cls");
		chklr(kolor,6);slwtxt(imie,textSpeed);
		chklr(kolor,0);slwtxt(": Widze do oko³a przepiêkne góry, lecz co najdziwniejsze one unosz¹ siê nad ziemi¹!!! Aktualnie chyba jestem w jakiegoœ rodzaju lesie, chyba\nmuszê uwarzaæ na tutejsz¹ zwierzynê.\n",textSpeed);
		wyborb=1;
		getch();
		system("cls");
		goto wybor1;
	}else if(wybor==3){
		if(wybora==1 && wyborb==1){
			
		}else{
			system("cls");
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Hmm... Najpierw sprawdze co mam przy sobie i co jest dooko³a mnie.",textSpeed);
			getch();
			system("cls");
			goto wybor1;
		}
	}
	system("cls");
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Skoro ju¿ wiem co mam przy sobie i znam z lekka okolice to myœle, ¿e czas wyruszyæ poszukaæ jakiegoœ schronienia, a mo¿e i ludzi.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Po kilku godzinach tu³aczki znajdujesz najprawdopodobniej opuszczony obóz koczowniczy.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Wreszcie jakieœ oznaki, ¿e nie jestem sam lecz troche niepokoi mnie fakt, ¿e nikogo tutaj nie ma. Dobra czas rozejrzeæ siê i poszukaæ czegoœ\nprzydatnego. Lepiej wyci¹gne scyzoryk na wszelki wypadek.\n\n",textSpeed);
	wioska:
	chklr(kolor,0);slwtxt("Co chcesz teraz zrobiæ?\n\n",textSpeed);
	chklr(kolor,2);slwtxt("1.",textSpeed);
	chklr(kolor,0);slwtxt("SprawdŸ czy mo¿e ktoœ jescze jest tutaj.\n",textSpeed);
	chklr(kolor,2);slwtxt("2.",textSpeed);
	chklr(kolor,0);slwtxt("Spl¹druj chaty w poszukiwaniu czegoœ przydatnego.\n",textSpeed);
	chklr(kolor,2);slwtxt("3.",textSpeed);
	chklr(kolor,0);slwtxt("Udaj siê dalej.\n\n",textSpeed);
	chklr(kolor,0);slwtxt("Twój wybór to: ",textSpeed);
	cin>>wybor1;
	
	if(wybor1==1){
		system("cls");
		chklr(kolor,6);slwtxt(imie,textSpeed);
		chklr(kolor,0);slwtxt(": Halooo, jest tu ktoœ?? Halo, przyszed³em w dobrych intencjach. Najprawdopodobniej nie ma tutaj nikogo.\n",textSpeed);
		getch();
		system("cls");
		wyborwioskaa=1;
		goto wioska;
	}else if(wybor1==2){
		domy:
		system("cls");
		if(domeka==1 && domekb==1 && domekc==1){
			chklr(kolor,2);slwtxt("*To ju¿ chyba wszystkie domki jakie s¹. Teraz mo¿e zrobiê coœ innego.*",textSpeed);
			getch();
			system("cls");
			wyborwioskab=1;
			goto wioska;
		}
		chklr(kolor,6);slwtxt(imie,textSpeed);
		chklr(kolor,0);slwtxt(": Z tego co widze jest tutaj kilka domków. Jeden po lewej i prawej oraz jeden na œrodku.\n\n",textSpeed);
		chklr(kolor,0);slwtxt("Który dom chcesz spl¹drowaæ?\n\n",textSpeed);
		chklr(kolor,2);slwtxt("1.",textSpeed);
		chklr(kolor,0);slwtxt("Lewy.\n",textSpeed);
		chklr(kolor,2);slwtxt("2.",textSpeed);
		chklr(kolor,0);slwtxt("Œrodkowy.\n",textSpeed);
		chklr(kolor,2);slwtxt("3.",textSpeed);
		chklr(kolor,0);slwtxt("Prawy.\n\n",textSpeed);
		chklr(kolor,0);slwtxt("Twój wybór to: ",textSpeed);
		cin>>wybordom;
		
			if(wybordom==1){
				system("cls");
				if(domeka==1){
					chklr(kolor,6);slwtxt(imie,textSpeed);
					chklr(kolor,0);slwtxt(": Ju¿ by³em w tym domuku, pójdê lepiej do nastêpnego.\n",textSpeed);
					getch();
					goto domy;
				};
				chklr(kolor,6);slwtxt(imie,textSpeed);
				chklr(kolor,0);slwtxt(": Wiêc sprawdŸmy co kryje lewy domek.\n",textSpeed);
				chklr(kolor,2);slwtxt("*Otwierasz drzwi do domku.*\n",textSpeed);
				chklr(kolor,6);slwtxt(imie,textSpeed);
				chklr(kolor,0);slwtxt(": Praktycznie wszystko zosta³o ju¿ chyba tutaj spl¹drowane. No có¿ udam sie do kolejnych domków.",textSpeed);
				domeka=1;
				getch();
				system("cls");
				goto domy;
			}else if(wybordom==2){
				system("cls");
				if(domekb==1){
					chklr(kolor,6);slwtxt(imie,textSpeed);
					chklr(kolor,0);slwtxt(": Ju¿ by³em w tym domuku, pójdê lepiej do nastêpnego.\n",textSpeed);
					getch();
					goto domy;
				};
				chklr(kolor,2);slwtxt("*Po spl¹drowaniu tego domku odnalaz³eœ butlekê wody oraz troche jedzenia.*\n",textSpeed);
				getch();
				domekb=1;
				system("cls");
				goto domy;
			}else if(wybordom==3){
				if(zmiennadom==1){
					system("cls");
					chklr(kolor,2);slwtxt("*Ju¿ pokona³eœ wilka i spl¹drowa³eœ ten domek.*\n",textSpeed);
					getch();
					system("cls");
					goto domy;
				};
				system("cls");
				chklr(kolor,6);slwtxt(imie,textSpeed);
				chklr(kolor,0);slwtxt(": Wiêc sprawdŸmy co kryje prawy domek.\n",textSpeed);
				chklr(kolor,2);slwtxt("*Otwierasz drzwi do domku. I nagle wyskakuje przed tob¹ jakieœ zwierze z lekka podobne do wilka.*\n",textSpeed);
				chklr(kolor,2);slwtxt("*Zwierzê czeka na twój ruch. Najprowdopodobniej jest to jego terytorium.*\n\n",textSpeed);
				walka:
				if(HPwilk==0){
					system("cls");
					goto domy;
				}
				chklr(kolor,0);slwtxt("Iloœc punktów twojego ¿ycia wynosi: ",textSpeed);
				chklr(kolor,1);cout<<HP;
				chklr(kolor,0);slwtxt(".\n",textSpeed);
				chklr(kolor,0);slwtxt("Iloœc punktów ¿ycia przeciwnika wynosi: ",textSpeed);
				chklr(kolor,1);cout<<HPwilk;
				chklr(kolor,0);slwtxt(".",textSpeed);
				chklr(kolor,0);slwtxt("\n\nCo chcesz teraz zrobiæ?\n\n",textSpeed);
				chklr(kolor,2);slwtxt("1.",textSpeed);
				chklr(kolor,0);slwtxt("ATAK | ",textSpeed);
				chklr(kolor,2);slwtxt("2.",textSpeed);
				chklr(kolor,0);slwtxt("OBRONA | ",textSpeed);
				chklr(kolor,2);slwtxt("3.",textSpeed);
				chklr(kolor,0);slwtxt("UCIECZKA\n\n",textSpeed);
				chklr(kolor,0);slwtxt("Twój wybór to: ",textSpeed);
				cin>>wyborwalka;
				
					if(wyborwalka==1){
						system("cls");
						chklr(kolor,0);slwtxt("Twój wybór to: ATAK.",textSpeed);
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
      							chklr(kolor,2);slwtxt("*Gratulacje wygra³eœ tê walkê. Po przeszukaniu domku znalaz³eœ tylko kilka starych monet.*",textSpeed);
							  };
 					  	getch();
 					  	system("cls");
 					  	goto walka;
					}else if(wyborwalka==2){
						system("cls");
						chklr(kolor,0);slwtxt("Twój wybór to: OBRONA.\n",textSpeed);
						chklr(kolor,2);slwtxt("*Gratulacje uda³o ci siê zablokowaæ atak przeciwnika!*\n",textSpeed);
						getch();
						system("cls");
						goto walka;
					}else if(wyborwalka==3){
						system("cls");
						chklr(kolor,0);slwtxt("Twój wybór to: UCIECZKA.\n",textSpeed);
						chklr(kolor,2);slwtxt("*Nie uda³o ci siê ucieæ od przeciwnika!*\n",textSpeed);
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
			chklr(kolor,2);slwtxt("*Musisz jescze dokoñczyæ poprzednie zadania, ¿eby przejœæ dalej.*\n\n",textSpeed);
			chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przejœæ dalej.",textSpeed);
			getch();
			system("cls");
			goto wioska;
		};
		system("cls");
		chklr(kolor,6);slwtxt(imie,textSpeed);
		chklr(kolor,0);slwtxt(": Chyba ju¿ zrobi³em wszystko co mog³em w tej wiosce. Chyba czas na znalezienia jakiegoœ schronienia na noc.\n",textSpeed);
		chklr(kolor,2);slwtxt("*Po czasie znalaz³eœ miejsce do przenocowania oraz zdo³a³eœ rozpaliæ ogieñ.*\n\n",textSpeed);
		chklr(kolor,6);slwtxt(imie,textSpeed);
		chklr(kolor,0);slwtxt(": Dobra czas teraz ¿eby troche odpocz¹æ. Ognisko siê pali wiêc powinno to odstraszyæ zwierzynê i nie zmarznê dziêki niemu.\n\n",textSpeed);
		chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przejœæ dalej.",textSpeed);
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
		chklr(kolor,2);slwtxt("\n\nKoniec rozdzialu 2\nHas³o do tego poziomu to: 2842.\nKliknij dowolny przycisk aby zacz¹æ rozdzia³ trzeci.",textSpeed);
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
	
	chklr(kolor,2);slwtxt("*Obudzi³ ciê szelest liœci. Wsta³eœ wypoczêty oraz twoje punkty HP siê odnowi³y.*\n",textSpeed);
	chklr(kolor,0);slwtxt("Iloœc punktów twojego ¿ycia wynosi: ",textSpeed);
	chklr(kolor,1);cout<<HP;
	chklr(kolor,0);slwtxt(".\n\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Ahh.. Czas wyruszyæ w drogê, dalej szukaæ jakieœ cywilizacji.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Zgasi³eœ ognisko i wyruszy³eœ w drogê. Po 2 godzinnej tu³aczce znalaz³eœ szlak z znakiem na którym by³o napisane: <--- Do miasta.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Œwietnie w koñcu bêdê móg³ z kimœ porozmawiaæ.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Nagle zauwa¿y³eœ, ¿e z daleka nadci¹ga jakiœ wóz, a na nim siedzi cz³owiek.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Haloo!! Czy móg³by Pan siê zatrzymaæ?.\n",textSpeed);
	chklr(kolor,4);slwtxt("Nieznajomy: ",textSpeed);
	chklr(kolor,0);slwtxt("Gdziê siê wybierasz cz³owieku?\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Chcê siê dostaæ do miasta.\n",textSpeed);
	chklr(kolor,4);slwtxt("Nieznajomy: ",textSpeed);
	chklr(kolor,0);slwtxt("w takim razie wskakuj na ty³y.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Jestem ",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(", a ty?\n",textSpeed);
	chklr(kolor,4);slwtxt("Nieznajomy: ",textSpeed);
	chklr(kolor,0);slwtxt("Mi³o poznaæ ",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(" ja jestem ",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel.",textSpeed);
	chklr(kolor,0);slwtxt(" Co cie sprowadza w nasze strony bo po ubiorze widzê, ¿e nietutejszy.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Zacze³em podró¿owaæ od jakiegoœ czasu i znalaz³em siê tutaj.\n",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel: ",textSpeed);
	chklr(kolor,0);slwtxt("Skoro mówisz, ¿e jesteœ poszukiwaczem przygód to powinnieneœ odwiedziæ gildiê w mieœcie. Myœlê, ¿e znaleŸli by zadanie dla ciebie.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": A wiêc jest tutaj zawód Poszukiwacza przygód? Da siê jakoœ na tym zarobiæ?\n",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel: ",textSpeed);
	chklr(kolor,0);slwtxt("HAHA ch³opcze, z k¹d siê ty urwa³eœ przecie¿ ",textSpeed);
	chklr(kolor,1);slwtxt("Poszukiwacz przygód",textSpeed);
	chklr(kolor,0);slwtxt(" jest aktualnie najbardziej p³atn¹ robot¹. Jakbym by³ m³odszy to pewnie teraz\nbym biega³ po jaskiniach szukaj¹c potworów.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Mo¿na powiedzieæ, ¿e jestem z miejsca dalszego ni¿ dok¹d ka¿demu znane. A masz mo¿e jakieœ porady co do miasta?\n",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel: ",textSpeed);
	chklr(kolor,0);slwtxt("Hmm pomyœlmy, dobrym miejscem do zatrzymania siê na troche jest karczma",textSpeed);
	chklr(kolor,1);slwtxt(" Winogrody",textSpeed);
	chklr(kolor,0);slwtxt(", co do miejsca z jakimœ ubiorem i ekwipunkiem to sklep\nu krasnoluda ",textSpeed);
	chklr(kolor,1);slwtxt("Mattarniego",textSpeed);
	chklr(kolor,0);slwtxt(". No i jak mówi³em gildia ",textSpeed);
	chklr(kolor,1);slwtxt("Poszukiwaczy przygód",textSpeed);
	chklr(kolor,0);slwtxt(" abyœ móg³ coœ zarobiæ.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": A propo miasta ju¿ prawie jesteœmy.\n",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel: ",textSpeed);
	chklr(kolor,0);slwtxt("Wiesz co ch³opcze masz tutaj kilka monet idŸ zmieñ ten ubiór bo mo¿esz miec k³opoty przez niego. A teraz zmykaj z powozu ¿eby nas razem nie\nzobaczyli.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Dziêkuje, a powiedz mi gdzie mogê ciebie znaleŸæ ¿eby sp³aciæ mój d³ug wobec ciebie.\n",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel: ",textSpeed);
	chklr(kolor,0);slwtxt("Czêsto wieczorami przesiadujê w",textSpeed);
	chklr(kolor,1);slwtxt(" Winogrodach",textSpeed);
	chklr(kolor,0);slwtxt(" wiêc myœlê, ¿e i tak siê spotkamy i napijemy razem.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Oczywiœcie za twoje zdrowie. Do zobaczenia i powodzenia.\n",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniel: ",textSpeed);
	chklr(kolor,0);slwtxt("Nawzajem m³ody.\n\n",textSpeed);
	chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przejœæ dalej.",textSpeed);
	getch();
	system("cls");
	chklr(kolor,2);slwtxt("*Po oddaleniu siê od wozu Nathaniela, wyruszy³eœ do bram zamku samemu, aby nie stwarzaæ problemów.*\n",textSpeed);
	chklr(kolor,5);slwtxt("Stra¿nik bramy: ",textSpeed);
	chklr(kolor,0);slwtxt("Ej ty stój!!\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Tak, w czym mogê pomóc?\n",textSpeed);
	chklr(kolor,5);slwtxt("Stra¿nik bramy: ",textSpeed);
	chklr(kolor,0);slwtxt("Widzê, ¿e jesteœ nie tutejszy. Wpuszczê ciê na teren miasta, lecz dam znaæ innym o twoim pobycie tutaj wiêc miej siê na bacznoœci.\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Dobrze, bêdê siê zachowywa³ najlepiej jak potrafiê. Mi³ego dnia.\n",textSpeed);
	chklr(kolor,5);slwtxt("Stra¿nik bramy: ",textSpeed);
	chklr(kolor,2);slwtxt(": *Wymamrota³ pod nosem* ",textSpeed);
	chklr(kolor,0);slwtxt("Dziwny ten cz³owiek jakby nie wiedzia³ co tutaj siê dzieje...\n\n",textSpeed);
	chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przejœæ dalej.",textSpeed);
	getch();
	system("cls");
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": A wiêc z informacji jakie zdoby³em od ",textSpeed);
	chklr(kolor,4);slwtxt("Nathaniela",textSpeed);
	chklr(kolor,0);slwtxt(" istniej¹ tutaj inne rasy ni¿ ludzie. Bardzo ten œwiat przypomina mi swojego rodzaju gry z Ziemi.\nNo có¿ mniejsza z tym czas udaæ siê w miejsca o których mówi³ mi mój nowy znajomy.\n\n",textSpeed);
	miasto:
	chklr(kolor,0);slwtxt("Gdzie chcesz siê udaæ?\n\n",textSpeed);
	chklr(kolor,2);slwtxt("1.",textSpeed);
	chklr(kolor,0);slwtxt("Sklep z ubraniami i ekwipunkiem.\n",textSpeed);
	chklr(kolor,2);slwtxt("2.",textSpeed);
	chklr(kolor,0);slwtxt("Karczma.\n",textSpeed);
	chklr(kolor,2);slwtxt("3.",textSpeed);
	chklr(kolor,0);slwtxt("Gildia Poszukiwaczy przygód.\n\n",textSpeed);
	chklr(kolor,0);slwtxt("Twój wybór to: ",textSpeed);
	cin>>wybor;
	
	
	
	if(wybor==1){
		if(wyborjeden==0){
			system("cls");
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dobra wieæ trzeba wtopiæ siê w t³um i zdobyæ jak¹œ lepsz¹ broñ ni¿ ten scyzoryk.\n",textSpeed);
			chklr(kolor,2);slwtxt("*Dotar³eœ do sklepu z ubraniami i ekwpinukiem.*\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dzieñ dobry, chcia³bym dokonaæ zakupku.\n",textSpeed);
			chklr(kolor,5);slwtxt("Kassarina: ",textSpeed);
			chklr(kolor,0);slwtxt(": Witam z tej strony Kassarina, co pana dok³aniej interesuje.\n",textSpeed);
			chklr(kolor,2);slwtxt("*Spogl¹dasz do kieszeni i sprawdzasz ile masz monet.*\n",textSpeed);
			chklr(kolor,2);slwtxt("Aktualnie posiadasz: ",textSpeed);
			chklr(kolor,1);slwtxt("2 z³ote oraz 34 srebrne ",textSpeed);
			chklr(kolor,2);slwtxt("monety.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Wiêc potrzebuje ekwipunku oraz ubioru dla pocz¹tkuj¹cego podró¿nika przygód.\n",textSpeed);
			chklr(kolor,5);slwtxt("Kassarina: ",textSpeed);
			chklr(kolor,0);slwtxt(": Zobaczmy... Mam komplet zbroi oraz krótki miecz. Cena tego zestawu to 30 srebrnych monet. Lecz mam dla Pana lepsz¹ propozycjê, podoba\nmi siê pana ubiór mo¿e dokonamy wymiany? Mój zestaw za pana ubiór.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Oczywiœcie, ¿e siê zgadzam.\n",textSpeed);
			chklr(kolor,5);slwtxt("Kassarina: ",textSpeed);
			chklr(kolor,0);slwtxt(": W takim razie zapraszam do przymierzalni.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": *w myœlach*",textSpeed);
			chklr(kolor,0);slwtxt(" Ale super mi siê uda³o nie doœæ, ¿e pozby³em siê tych szmat to ten ekwipunek lerzy na mnie jak ula³.\n",textSpeed);
			chklr(kolor,5);slwtxt("Kassarina: ",textSpeed);
			chklr(kolor,0);slwtxt(": Czy to wszystko? Czy mo¿e pan jescze czegoœ potrzebuje?\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Aktualnie podziêkuje, ale coœ mi poddpowiada, ¿e zawitam tutaj napewno. Dowidzenia.\n",textSpeed);
			chklr(kolor,5);slwtxt("Kassarina: ",textSpeed);
			chklr(kolor,0);slwtxt(": To ja dziêkuje. Dowidzenia.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dobra teraz czas siê udaæ za³atwiæ resztê.\n\n",textSpeed);
			chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przejœæ dalej.",textSpeed);
			getch();
			sklep=1;
			system("cls");
			wyborjeden=1;
			goto miasto;
		}else if(wyborjeden==1){
			system("cls");
			chklr(kolor,2);slwtxt("*Ju¿ kupi³eœ ekwpiunek, udaj siê do karczmy.*",textSpeed);
			getch();
			system("cls");
			goto miasto;
		}
	}else if(wybor==2){
		system("cls");
		if(sklep==0){
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Powinnienem najpierw kupiæ jakiœ ekwipunek zanim udam siê do karczmy.\n\n",textSpeed);
			chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przejœæ dalej.",textSpeed);
			getch();
			system("cls");
			goto miasto;
		}else if(sklep==1){
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dobra wiêc trzeba znaleŸæ lokum na dzisiejsz¹ noc, lecz muszê uwa¿aæ bo jescze nie znam cen. Myœlê, ¿e wybiore coœ najtañszego.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dzieñ Dobry, chcia³bym najtañszy pokój jaki jest na jedn¹ noc.\n",textSpeed);
			chklr(kolor,4);slwtxt("Karczmarka",textSpeed);
			chklr(kolor,0);slwtxt(": Dzieñ Dobry, dobrze w takim razie poproszê 5 srebrnych monet.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Proszê bardzo.\n",textSpeed);
			chklr(kolor,4);slwtxt("Karczmarka",textSpeed);
			chklr(kolor,0);slwtxt(": Pañski pokój znajdujê siê na piêtrze pierwsze drzwi po prawej. Oto klucz do pañskiego pokoju.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dziêkuje, mi³ego dnia.\n",textSpeed);
			chklr(kolor,4);slwtxt("Karczmarka",textSpeed);
			chklr(kolor,0);slwtxt(": Mi³ego pobytu w naszej karczmie!\n\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dobra teraz trzeba dostaæ siê do gildii i zapisaæ do niej.\n\n",textSpeed);
			chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przejœæ dalej.",textSpeed);
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
			chklr(kolor,0);slwtxt(": Najpierw pójde do karczmy wykupiæ pokój na t¹ noc.\n\n",textSpeed);
			chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przejœæ dalej.",textSpeed);
			getch();
			system("cls");
			goto miasto;
		}else if(karczma==1){
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": A wiêc czas zacz¹æ przygodê.\n\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Witam chcia³bym siê zapisaæ do gildi..\n",textSpeed);
			chklr(kolor,4);slwtxt("Rekrutantka",textSpeed);
			chklr(kolor,0);slwtxt(": Dobrze w takim razie, przedstawie panu zasady gildii:\n\n",textSpeed);
			chklr(kolor,0);slwtxt("1. Co miesiêczna op³ata w wysokoœci 30 srebnych monet.\n",textSpeed);
			chklr(kolor,0);slwtxt("2. Zakaz sprzedawania innych cz³onków gildii.\n",textSpeed);
			chklr(kolor,0);slwtxt("3. Godne chodzenie z tytu³em nadamym przez lidera gildii.\n\n",textSpeed);
			chklr(kolor,4);slwtxt("Rekrutantka",textSpeed);
			chklr(kolor,0);slwtxt(": Lecz najpierw muszê poproœiæ Pana o imiê oraz o uiszczenie wp³aty do gildi, wtedy zotanie pan pe³noprawnym cz³onkiem jako m³odszy poszukiwacz przygód.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Moje imiê to: ",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(". Proszê tutaj 30 srebrnych monet.\n",textSpeed);
			chklr(kolor,4);slwtxt("Rekrutantka",textSpeed);
			chklr(kolor,0);slwtxt(": Gratulujemy zosta³eœ oficjalnie cz³onkiem gildi! Niestety, ale wszystkie zadania na dziœ zosta³y rozdane. Zapraszam jutro z rana po nowe.\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Równie¿ dziêkujê i do jutra!\n\n",textSpeed);
			chklr(kolor,6);slwtxt(imie,textSpeed);
			chklr(kolor,0);slwtxt(": Dobra za du¿o wra¿eñ jak na dziœ, czas isæ spaæ.\n\n",textSpeed);
			chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przejœæ dalej.",textSpeed);
			getch();
			system("cls");
		}
		chklr(kolor,2);slwtxt("\nKoniec rozdzialu 3\nHas³o do tego poziomu to: 3256.\nKliknij dowolny przycisk aby zacz¹æ rozdzia³ czwarty.",textSpeed);
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

	chklr(kolor,2);slwtxt("*Po nocy w karczmie budzisz siê i szykujesz, aby wyruszyæ na pierwsz¹ misjê z gildii.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Dobra trzba zacz¹æ zarabiaæ na dostatnie ¿ycie w tym œwiecie. Czas iœæ do budynku gildii.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Kiedy ju¿ dotar³eœ do gildii odrazu podszed³eœ do tablicy og³oszeñ.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": W takim razie muszê wybraæ coœ z czym dam radê na pocz¹tku.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Kiedy przegl¹da³eœ og³oszenia nagle jedno z nich przyku³o twoj¹ uwagê.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Co to misja za 3 z³ote monety, a dla grupy m³odych poszukiwaczy przygód. Brzmi nieŸle tylko gdzie znajde osoby, które zdecyduj¹ sie tam pójœæ. Hmm chyba pójdê popytaæ po gildii.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Przy jednym ze sto³ów gildyjnych siedzia³o kilka osób z s³abym ekwipunkiem.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Czeœæ jestem",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(" czy mo¿e macie troszkê czasu?\n",textSpeed);
	chklr(kolor,1);slwtxt("Alezy",textSpeed);
	chklr(kolor,0);slwtxt(": Ahh to ty ten nowy o którym wczoraj mówili. Witam jestem ",textSpeed);
	chklr(kolor,1);slwtxt("Alezy",textSpeed);
	chklr(kolor,0);slwtxt(", a to moja dru¿yna w której w sk³ad wchodzi:\n",textSpeed);
	chklr(kolor,5);slwtxt("Alkais - potê¿ny wojownik",textSpeed);
	chklr(kolor,0);slwtxt(", ",textSpeed);
	chklr(kolor,3);slwtxt("Somatris - nasza druidka ",textSpeed);
	chklr(kolor,0);slwtxt("oraz ",textSpeed);
	chklr(kolor,4);slwtxt("Saiko - ³owca",textSpeed);
	chklr(kolor,0);slwtxt(". W czym mo¿emy ci pomóc?\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Znalaz³em w³aœnie og³oszenia na 3 z³ote monety, lecz potrzebuje dru¿yny aby je wykonaæ. Czy mo¿e checeie mi pomóc?\n",textSpeed);
	chklr(kolor,3);slwtxt("Somatris",textSpeed);
	chklr(kolor,0);slwtxt(": Pewnie, zawsze milej wykonuje siê zadania razem.\n",textSpeed);
	chklr(kolor,1);slwtxt("Alezy",textSpeed);
	chklr(kolor,0);slwtxt(": W takim razie wyruszajmy póki mo¿emy.\n",textSpeed);
	chklr(kolor,2);slwtxt("*W raz z nowymi kompanami wyruszyliœcie na zadanie poiwerzone przez gildie.*\n\n",textSpeed);
	chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przejœæ dalej.",textSpeed);
	getch();
	system("cls");
	chklr(kolor,2);slwtxt("*Mine³o 2 dni od k¹d wyruszyliœcie z miasta do wioski w której by³o zadanie do wykonania. W tym czasie ty wraz z nowymi kompanami strasznie sie z¿yliœcie.\nOpowiedzia³eœ im o swojej œmierci i o ¿yciu na Ziemi co nie do koñca ich zdziwi³o.*\n\n",textSpeed);
	chklr(kolor,2);slwtxt("*Kiedy dotarliœcie do wioski natychmiast wybraliœcie siê do wodza, który wyda³ te og³oszenie.*\n",textSpeed);
	chklr(kolor,1);slwtxt("Alezy",textSpeed);
	chklr(kolor,0);slwtxt(": Witamy wodzu jesteœmy cz³onkami gildii. Przybyliœmy, aby wykonaæ twoje zadanie.\n",textSpeed);
	chklr(kolor,1);slwtxt("Wódz",textSpeed);
	chklr(kolor,0);slwtxt(": O Bogowie dziêki, w koñcu wybawiciele. Dziêkuje, ¿e przybylisæie œmia³kowie na nasze wezwanie bowiem posiadamy problem z nieznan¹ kreatur¹, która\npl¹druje nasze ³¹ki. Czy rozprawicie siê z ni¹?\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Oczywiœcie, ¿e damy radê w koñcu po to przybyliœmy tutaj.\n",textSpeed);
	chklr(kolor,1);slwtxt("Wódz",textSpeed);
	chklr(kolor,0);slwtxt(": W takim razie wyruszajcie czym prêdzej, poniewa¿ czujê, ¿e ju¿ d³ugo nasza osada nie da rady jeœli ta kreatura bêdzie nam nisczy³a zbiory.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Po spotkaniu z wodzem, grupa œmia³ych poszukiwaczy przygód uda³a siê bezpoœrednio do jaskini.*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Jak myœlisz ",textSpeed);
	chklr(kolor,4);slwtxt("Saiko",textSpeed);
	chklr(kolor,0);slwtxt(" co to mo¿e byæ za stworzenie ?\n",textSpeed);
	chklr(kolor,4);slwtxt("Saiko",textSpeed);
	chklr(kolor,0);slwtxt(": Hmm dziwnie to wszystko, ja jako wybitny pocz¹tkuj¹cy ³owca nie mogê znaleŸæ rzadnych œladów ani nie czuje zapachu tej kreatury i nie wiem czym\nto mo¿e byæ. Lecz w¹tpie, aby by³o to cos potê¿nego skoro pl¹druje tylko plony a nikogo do tej pory nie zabi³o.\n",textSpeed);
	chklr(kolor,5);slwtxt("Alkais",textSpeed);
	chklr(kolor,0);slwtxt(": Skoro to pewnie jakieœ s³abe zwierz¹tko to zróbmy to jak najszybciej aby mieæ to ju¿ z g³owy i zgarn¹æ nasze wynagrodzenie.\n",textSpeed);
	chklr(kolor,2);slwtxt("*Po tych s³owach nasza grupa wesz³a do jaskini co by³o ogromnym b³êdem. Okaza³o siê, ¿e stworzenie to",textSpeed);
	chklr(kolor,5);slwtxt(" Assperghak ",textSpeed);
	chklr(kolor,2);slwtxt("jedno z legendarnych kreatur tego\nœwiata, którejest bardzo niebezpieczne kiedy wejdzie sie na jego teren.*\n",textSpeed);
	chklr(kolor,1);slwtxt("Alezy",textSpeed);
	chklr(kolor,0);slwtxt(": Bogowie co to jest!!! To nas wszystkich zabije!\n",textSpeed);
	chklr(kolor,5);slwtxt("Alkais",textSpeed);
	chklr(kolor,0);slwtxt(": Jeœli mam zostac zabity to tylko podczas walki!! Wy mo¿ecie uciekaæ!\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Nigdy w ¿yciu! Skoro przybyliœmy tutaj razem to nie pozwole ci samemu umrzeæ ja zostaje z ",textSpeed);
	chklr(kolor,5);slwtxt("Alkais'em",textSpeed);
	chklr(kolor,0);slwtxt("!\n",textSpeed);
	chklr(kolor,2);slwtxt("*Po bohaterskich wyznaniach bohaterów nast¹pi³a powa¿na walka.*\n",textSpeed);
	chklr(kolor,2);slwtxt("Kliknij dowolny przycisk, aby przejœæ dalej.",textSpeed);
	getch();
	system("cls");
	
	int HP=100,HPenemy=100,wyborwalka=0;
	
	walka:
	if(HP==0){
		system("cls");
		chklr(kolor,2);slwtxt("\nKoniec rozdzialu 4\nHas³o do tego poziomu to: 4987.\nKliknij dowolny przycisk aby zacz¹æ rozdzia³ czwarty.",textSpeed);
		stage5(kolor);
		
	}else{
	chklr(kolor,0);slwtxt("Iloœc punktów twojej dru¿yny wynosi: ",textSpeed);
	chklr(kolor,1);cout<<HP;
	chklr(kolor,0);slwtxt(".\n",textSpeed);
	chklr(kolor,0);slwtxt("Iloœc punktów ¿ycia przeciwnika wynosi: ",textSpeed);
	chklr(kolor,1);cout<<HPenemy;
	chklr(kolor,0);slwtxt(".",textSpeed);
	chklr(kolor,0);slwtxt("\n\nCo chcesz teraz zrobiæ?\n\n",textSpeed);
	chklr(kolor,2);slwtxt("1.",textSpeed);
	chklr(kolor,0);slwtxt("ATAK | ",textSpeed);
	chklr(kolor,2);slwtxt("2.",textSpeed);
	chklr(kolor,0);slwtxt("OBRONA | ",textSpeed);
	chklr(kolor,0);slwtxt("\n\nTwój wybór to: ",textSpeed);
	cin>>wyborwalka;
	
	if(wyborwalka==1){
		system("cls");
		chklr(kolor,0);slwtxt("Twój wybór to: ATAK.",textSpeed);
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
				chklr(kolor,2);slwtxt("*Niestety twoja dru¿yna wraz z tob¹ poleg³y.*",textSpeed);
			  };
	  	getch();
	  	system("cls");
	  	goto walka;
	}else if(wyborwalka==2){
		system("cls");
		chklr(kolor,0);slwtxt("Twój wybór to: OBRONA.\n",textSpeed);
		chklr(kolor,2);slwtxt("*Wasz obrona okaza³a siê byæ nie skuteczna! Potwór zada³ wam obra¿enia!*\n",textSpeed);
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
	chklr(kolor,0);slwtxt("Poznañ, Polska\n\n",textSpeed);
	chklr(kolor,2);slwtxt("*Budzisz siê jak co dzieñ w swoim ³ó¿ku z myœl¹, ¿e znowu musisz iœæ do pracy*\n",textSpeed);
	chklr(kolor,6);slwtxt(imie,textSpeed);
	chklr(kolor,0);slwtxt(": Ahh... i po co mi to wszystko by³o, ca³e te studia ¿eby teraz robiæ w jakimœ korpo do staroœci. Masakra...\n",textSpeed);
	int i=0;
	while(i<5){
		chklr(kolor,0);slwtxt("...",textSpeed);
		i++;
	};
	
	chklr(kolor,2);slwtxt("\n\n\nKliknij dowolny przycisk, aby zakoñczyæ grê.",textSpeed);
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

bool isnum( string t ) { //funkcja sprawdza czy podana wartosc jest cyfr¹
    for(int a=0;a<t.length();a++){ //sprawdŸ ka¿d¹ 'komórkê' z tablicy zmiennej
        if(t[a]>'0'+9||t[a]<'0') return false; //je¿eli którakolwiek z 'komórek' nie jest cyfr¹, cala funkcja zwraca false

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
        return menu; //zwracanie zmiennej menu, jezeli podana wartosc byla cyfra to j¹ zwróci, jezeli inna wartoœæ, zwróci 0
}
