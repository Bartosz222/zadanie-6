#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;
class program{
	public:
		program();
		~program();
		ifstream wejscie;
		ofstream wyjscie;
		string napis;
		
	void sprawdzPliki();
	void wczytaj();
	void sprawdzWyrazenie(string napis);
	void zapis();
};
program::program(){
	wejscie.open("wejscie.txt");
	wyjscie.open("wyjscie.txt");
	wyjscie<<"["<<endl;
}
program::~program(){
	wyjscie<<"]";
	wejscie.close();
	wyjscie.close();
}
void program::sprawdzPliki(){
	if(wejscie.good()&&wyjscie.good()){}
	else {
		cout<<"blad";
		exit(0);
	};
}
void program::wczytaj(){

	while(!wejscie.eof()){
		wejscie>>napis;
		sprawdzWyrazenie(napis);
	}
}
void program::sprawdzWyrazenie(string napis){
	regex regularne("^[A-Z]{1}[a-z]+-[A-Z]{1}[a-z]+$");
	if(regex_match(napis,regularne)){
		cout<<napis<<", ";
		zapis();
	}
}
void program::zapis(){
	wyjscie<<"{\"nazwisko_podwojne\":\""+napis+"\"},"<<endl;
}
int main() {
	program p1;
	p1.sprawdzPliki();
	p1.wczytaj();
	return 0;
}
