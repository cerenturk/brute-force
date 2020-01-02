#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>//dosyaama
#include <ctime>
#include <time.h>//rastgele sayı
#include <string.h>//string ifade
#include <locale.h>//türkçe dil
using namespace std;


string arananKelime, cumle, cumle1, cumle2, cumle3;//değişken
ifstream dosyaOku;//dosya okumak için değişken


int brute_force(string aranan, int kelimeBoyutu, string okunanCumle, int metinBoyutu) { // Dosya içinde arama BruteForce
	int sayac = 0;//içinde kaç tane oldugu
	int i;
	/* Arama */
	for (int j = 0; j <= metinBoyutu - kelimeBoyutu; ++j)//dosyadaki metin sayısından  kelime sayısını çıkardıjk
	{
		for ( i = 0; i < kelimeBoyutu && tolower(aranan[i]) == tolower(okunanCumle[i + j]); ++i);//büyük karakter alma/küçük karakter alma
			if (i >= kelimeBoyutu)//aranan kelimenin boyutundan büyükse
			{
				cout<<j+1<<". indiste mevcut."<<endl;
				sayac++;
			}
		}
	
	return sayac;
}

void rtfoku() {
	dosyaOku.open("Ceren.rtf");

	for (int i = 0; i <= 100000; i++)
		getline(dosyaOku, cumle, '\0');//getline satır satır hangi değişkeni okuyacagı,hangi değişkene atayacagıo , sonlama karaktere /0dosya sonu

	dosyaOku.close();
}

void txtoku() {
	dosyaOku.open("Ceren.txt");

	for (int i = 0; i <= 100000; i++)
		getline(dosyaOku, cumle1, '\0');

	dosyaOku.close();
}

 void htmloku() {
	dosyaOku.open("Ceren.html");

	for (int i = 0; i <= 100000; i++)
		getline(dosyaOku, cumle2, '\0');

	dosyaOku.close();
}

void xmloku() {
	dosyaOku.open("Ceren.xml");

	for (int i = 0; i <= 100000; i++)
		getline(dosyaOku, cumle3, '\0');

	dosyaOku.close();
}

int _tmain(int argc, _TCHAR* argv[]) {
	char devam;//tekrar arama için
	int rtfBulunanSayi, txtBulunanSayi, htmlBulunanSayi, xmlBulunanSayi;//dönen sayaç için 

	setlocale(LC_ALL, "Turkish");//türkçe karakter
	clock_t t1, t2;//işlemi süresi karşılastırm baslangıc bitiş farkı
	
	cout << "Dosyalar okunuyor...";
	rtfoku();
	txtoku();
	htmloku();
	xmloku();

	int metinBoyutu = cumle.size();//dosyalardan okudunan kelimelerin boyutu
	int metinBoyutu1 = cumle1.size();
	int metinBoyutu2 = cumle2.size();
	int metinBoyutu3 = cumle3.size();

	do
	{
		system("cls"); // Ekranı temizle
		cout<<"Aranan kelimeyi yaziniz -> ";
		cin>>arananKelime;
		cout<<endl;
		int kelimeBoyutu = arananKelime.size();//aranan kelimenin  boyutunu değişkene atadı

		t1 = clock();//baslangıc
		cout << "***** RTF OKUNUYOR *****"<<endl;
		rtfBulunanSayi = brute_force(arananKelime, kelimeBoyutu, cumle, metinBoyutu);//parametreleri yolladı

		cout << "***** TXT OKUNUYOR *****" << endl;
		txtBulunanSayi = brute_force(arananKelime, kelimeBoyutu, cumle1, metinBoyutu1);

		cout << "***** HTML OKUNUYOR *****"<<endl;
		htmlBulunanSayi = brute_force(arananKelime, kelimeBoyutu, cumle2, metinBoyutu2);

		cout << "***** XML OKUNUYOR *****"<<endl;
		xmlBulunanSayi = brute_force(arananKelime, kelimeBoyutu, cumle3, metinBoyutu3);


		t2 = clock();//bitiş
		float s1 = t1, s2 = t2;//noktalı biçimde gösterme süreyi

		if(rtfBulunanSayi !=0)//aranan kelime bulunduysa
			cout<<"\n\n\nRtf dosyasinda '"<<arananKelime<<"' kelimesinden "<<rtfBulunanSayi<<" adet bulundu."<<endl;
		else
			cout<<"Rtf dosyasinda sonuc bulunamadi."<<endl;


		if(txtBulunanSayi !=0)
			cout<<"Txt dosyasinda '"<<arananKelime<<"' kelimesinden "<<txtBulunanSayi<<" adet bulundu."<<endl;
		else
			cout<<"Txt dosyasinda sonuc bulunamadi."<<endl;


		if(htmlBulunanSayi !=0)
			cout<<"Html dosyasinda '"<<arananKelime<<"' kelimesinden "<<htmlBulunanSayi<<" adet bulundu."<<endl;
		else
			cout<<"Html dosyasinda sonuc bulunamadi."<<endl;


		if(xmlBulunanSayi !=0)
			cout<<"Xml dosyasinda '"<<arananKelime<<"' kelimesinden "<<xmlBulunanSayi<<" adet bulundu."<<endl;
		else
			cout<<"Xml dosyasinda sonuc bulunamadi."<<endl;


		cout<<"Arama islemi suresi "<<(s2-s1)/1000<<" saniye\n\n"<<endl;

		cout << "Tekrar arama yapmak istiyor musunuz? (E/e) : ";
		cin >> devam;
	} while (devam == 'E' || devam == 'e');
	
	system("pause");
	return 0;	
}
