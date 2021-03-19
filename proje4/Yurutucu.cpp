#include <iostream> //Iostream kütüphanesi include edildi
#include<locale.h> //Türkçe karakter kütüphanesi
#include <stdio.h> //Stdio kütüphanesi dahil edildi
#include <stdlib.h> //Stdlib kütüphanesi include edildi
#include "DinamikBellekYonetimi.h"; //Dinamik Bellek Yönetimi Header Dosyasý Ýnclude Edildi
 
using namespace std; //Std nesnesi kullanýldý 
int main() {
	setlocale(LC_ALL, "Turkish"); //Türkçe karakter Kodu
	
	int gizemliMatrisSatir,gizemliMatrisSutun,sansliMatrisSatir,sansliMatrisSutun; //Satýr ve sütunlarý tutan deðiþken tanýmlandý
	cout << "Lütfen Gizemli Matris Ýçin Satýr Ve Sütün Sayýlarýný Girin: "; //Kullanýcýdan 1.matris için satýr sütün deðerleri alýndý
	cin >> gizemliMatrisSatir >> gizemliMatrisSutun; //alýnan satýr ve sütün deðerleri deðiþkenlere atýldý
	
	cout << "Lütfen Þanslý Matris Ýçin Satýr Ve Sütün Sayýlarýný Girin: "; //Kullanýcýdan 2.matris için satýr sütün deðerleri alýndý
	cin >> sansliMatrisSatir >> sansliMatrisSutun;//alýnan satýr ve sütün deðerleri deðiþkenlere atýldý
	
	DinamikBellekYonetimi matrislerNesnesi; //DinamikBellekYönetimi classýndan matrislerNesnesi adýnda nesne oluþturuldu
	
	/*Dinamik Bellekler Oluþturuluyor...*/
	int **gizemliMatris = new int*[gizemliMatrisSatir]; //Gizemli Matris Dizisinin Birinci Boyutu
	for(int i=0;i<gizemliMatrisSatir;i++)
		gizemliMatris[i] = new int[gizemliMatrisSutun]; //Gizemli Matris Dizisinin Ýkinci Boyutu
		
	int **sansliMatris = new int*[sansliMatrisSatir]; //Þanslý Matris Dizisinin Birinci Boyutu
	for(int i=0;i<sansliMatrisSatir;i++)
		sansliMatris[i] = new int[sansliMatrisSutun]; //Þanslý Matris Dizisinin Ýkinci Boyutu
	
	matrislerNesnesi.GizemliMatrisDoldur(gizemliMatris,gizemliMatrisSatir,gizemliMatrisSutun); //Gizemli matrisin içerisini dolduracak fonksiyon çaðýlýrdýl
	matrislerNesnesi.SansliMatrisDoldur(sansliMatris,sansliMatrisSatir,sansliMatrisSutun);//Þanslý matrisin içerisini dolduracak fonksiyon çaðýlýrdýl
	/*Yukarýdaki fonksiyonar public olarak tanýmlanmýþ olarak matrislerin içini kulanýcýdan almayý saðlar*/
	
	
	cout << "\n\n-------------------------------------------\n";
	/*Gizemli matrisin sonucunu veren ve bool parametre döndüren fonksiyon çaðrýlýp ekrana bastýrýldý*/
	cout << "Gizemli Matris Sonucu(True/False) : "<<matrislerNesnesi.GizemliMatrisMi(gizemliMatris,gizemliMatrisSatir,gizemliMatrisSutun) << endl;
	/*Þanslý matrisin sonucunu veren ve int parametre döndüren fonksiyon çaðrýlýp ekrana bastýrýldý*/
	cout << "Þanslý  Matris Elemanlarýnýn Sayýsý : "<<matrislerNesnesi.SansliMatrisElemanlarininSayisi(sansliMatris,sansliMatrisSatir,sansliMatrisSutun) << endl;
	cout << "-------------------------------------------\n";
	
	/*Oluþan Dinamik Bellekler Siliniyor..*/
	for(int i=0;i<gizemliMatrisSatir;i++) 
		delete[] gizemliMatris[i]; //sütünlarý sil
	delete[] gizemliMatris; //satýrlarý sil
	
	for(int i=0;i<sansliMatrisSatir;i++)
		delete[] sansliMatris[i]; //sütünlarý sil
	delete[] sansliMatris; //satýrlarý sil
	
	return 0;
}
