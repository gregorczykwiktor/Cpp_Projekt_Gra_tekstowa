using namespace std;

	void chklr (HANDLE kolor, int a){
		if(a==0){ // BIALY
			SetConsoleTextAttribute(kolor,FOREGROUND_RED| FOREGROUND_GREEN| FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}else if(a==1){ // CZERWONY
			SetConsoleTextAttribute(kolor,FOREGROUND_RED| FOREGROUND_INTENSITY);
		}else if(a==2){ // ZIELONY
			SetConsoleTextAttribute(kolor,FOREGROUND_GREEN);
		}else if(a==3){ // NIEBIESKI
			SetConsoleTextAttribute(kolor,FOREGROUND_BLUE);
		}else if(a==4){ // ZOLTY
			SetConsoleTextAttribute(kolor,FOREGROUND_RED| FOREGROUND_GREEN);
		}else if(a==5){ // ZOLTY
			SetConsoleTextAttribute(kolor,FOREGROUND_RED| FOREGROUND_BLUE| FOREGROUND_INTENSITY);
		}else if(a==6){ // JASNY NIEB
			SetConsoleTextAttribute(kolor,FOREGROUND_BLUE| FOREGROUND_INTENSITY);
		}
	}
