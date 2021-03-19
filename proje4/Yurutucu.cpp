#include <iostream> //Iostream k�t�phanesi include edildi
#include<locale.h> //T�rk�e karakter k�t�phanesi
#include <stdio.h> //Stdio k�t�phanesi dahil edildi
#include <stdlib.h> //Stdlib k�t�phanesi include edildi
#include "DinamikBellekYonetimi.h"; //Dinamik Bellek Y�netimi Header Dosyas� �nclude Edildi
 
using namespace std; //Std nesnesi kullan�ld� 
int main() {
	setlocale(LC_ALL, "Turkish"); //T�rk�e karakter Kodu
	
	int gizemliMatrisSatir,gizemliMatrisSutun,sansliMatrisSatir,sansliMatrisSutun; //Sat�r ve s�tunlar� tutan de�i�ken tan�mland�
	cout << "L�tfen Gizemli Matris ��in Sat�r Ve S�t�n Say�lar�n� Girin: "; //Kullan�c�dan 1.matris i�in sat�r s�t�n de�erleri al�nd�
	cin >> gizemliMatrisSatir >> gizemliMatrisSutun; //al�nan sat�r ve s�t�n de�erleri de�i�kenlere at�ld�
	
	cout << "L�tfen �ansl� Matris ��in Sat�r Ve S�t�n Say�lar�n� Girin: "; //Kullan�c�dan 2.matris i�in sat�r s�t�n de�erleri al�nd�
	cin >> sansliMatrisSatir >> sansliMatrisSutun;//al�nan sat�r ve s�t�n de�erleri de�i�kenlere at�ld�
	
	DinamikBellekYonetimi matrislerNesnesi; //DinamikBellekY�netimi class�ndan matrislerNesnesi ad�nda nesne olu�turuldu
	
	/*Dinamik Bellekler Olu�turuluyor...*/
	int **gizemliMatris = new int*[gizemliMatrisSatir]; //Gizemli Matris Dizisinin Birinci Boyutu
	for(int i=0;i<gizemliMatrisSatir;i++)
		gizemliMatris[i] = new int[gizemliMatrisSutun]; //Gizemli Matris Dizisinin �kinci Boyutu
		
	int **sansliMatris = new int*[sansliMatrisSatir]; //�ansl� Matris Dizisinin Birinci Boyutu
	for(int i=0;i<sansliMatrisSatir;i++)
		sansliMatris[i] = new int[sansliMatrisSutun]; //�ansl� Matris Dizisinin �kinci Boyutu
	
	matrislerNesnesi.GizemliMatrisDoldur(gizemliMatris,gizemliMatrisSatir,gizemliMatrisSutun); //Gizemli matrisin i�erisini dolduracak fonksiyon �a��l�rd�l
	matrislerNesnesi.SansliMatrisDoldur(sansliMatris,sansliMatrisSatir,sansliMatrisSutun);//�ansl� matrisin i�erisini dolduracak fonksiyon �a��l�rd�l
	/*Yukar�daki fonksiyonar public olarak tan�mlanm�� olarak matrislerin i�ini kulan�c�dan almay� sa�lar*/
	
	
	cout << "\n\n-------------------------------------------\n";
	/*Gizemli matrisin sonucunu veren ve bool parametre d�nd�ren fonksiyon �a�r�l�p ekrana bast�r�ld�*/
	cout << "Gizemli Matris Sonucu(True/False) : "<<matrislerNesnesi.GizemliMatrisMi(gizemliMatris,gizemliMatrisSatir,gizemliMatrisSutun) << endl;
	/*�ansl� matrisin sonucunu veren ve int parametre d�nd�ren fonksiyon �a�r�l�p ekrana bast�r�ld�*/
	cout << "�ansl�  Matris Elemanlar�n�n Say�s� : "<<matrislerNesnesi.SansliMatrisElemanlarininSayisi(sansliMatris,sansliMatrisSatir,sansliMatrisSutun) << endl;
	cout << "-------------------------------------------\n";
	
	/*Olu�an Dinamik Bellekler Siliniyor..*/
	for(int i=0;i<gizemliMatrisSatir;i++) 
		delete[] gizemliMatris[i]; //s�t�nlar� sil
	delete[] gizemliMatris; //sat�rlar� sil
	
	for(int i=0;i<sansliMatrisSatir;i++)
		delete[] sansliMatris[i]; //s�t�nlar� sil
	delete[] sansliMatris; //sat�rlar� sil
	
	return 0;
}
