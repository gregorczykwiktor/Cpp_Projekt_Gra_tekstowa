using namespace std;

int delay=75;

void logo(HANDLE kolor){
	chklr(kolor, 2);
		system("cls");
		cout<<"                                                                                                        "<<endl;Sleep(delay);
		cout<<"                                          d8b                                                           "<<endl;Sleep(delay);
		cout<<"                                    d8P   ?88                                                           "<<endl;Sleep(delay);
		cout<<"                                 d888888P  88b                                                          "<<endl;Sleep(delay);
		cout<<"  88bd88b?88,.d88b, d888b8b        ?88'    888888b  d8888b     d888b8b   d888b8b    88bd8b,d88b  d8888b "<<endl;Sleep(delay);
		cout<<"  88P'  ``?88'  ?88d8P' ?88        88P     88P `?8bd8b_,dP    d8P' ?88  d8P' ?88    88P'`?8P'?8bd8b_,dP "<<endl;Sleep(delay);
		cout<<" d88       88b  d8P88b  ,88b       88b    d88   88P88b        88b  ,88b 88b  ,88b  d88  d88  88P88b     "<<endl;Sleep(delay);
		cout<<"d88'       888888P'`?88P'`88b      `?8b  d88'   88b`?888P'    `?88P'`88b`?88P'`88bd88' d88'  88b`?888P' "<<endl;Sleep(delay);
		cout<<"           88P'           )88                                        )88                                "<<endl;Sleep(delay);
		cout<<"          d88            ,88P                                       ,88P                                "<<endl;Sleep(delay);
		cout<<"          ?8P        `?8888P                                    `?8888P                                 \n\n"<<endl;Sleep(delay);

		chklr(kolor, 0);
}
