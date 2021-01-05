using namespace std;

	void slwtxt(string text,int d){
		int textSpeed;
		char s;
		for(int i=0;i<text.length();i++){
			cout<<text[i];
			Sleep(d);
			if(kbhit()){
				s = getch();
				textSpeed = d;
				d=0;
			}
		}
	 d = textSpeed;
}
