#include <iostream> //Iostream k�t�phanesi include edildi
#include <stdio.h> //Stdio k�t�phanesi dahil edildi
#include <stdlib.h> //Stdlib k�t�phanesi include edildi
#include "DinamikBellekYonetimi.h"; //Dinamik Bellek Y�netimi Header Dosyas� �nclude Edildi
#include <Math.h> //Pow komutunu kullanmak i�in Math. 

using namespace std; //Std nesnesi kullan�ld� 

//Void tipinde Gizemli Matrisin i�ini kullan�c� taraf�ndan doldurulacak public fonksiyon
void DinamikBellekYonetimi::GizemliMatrisDoldur(int**gizemliMatris,int gizemliSatir,int gizemliSutun){
	int i,j,deger; //i,j ve kullan�c�dan al�nacak de�er de�i�keni tan�mand�
	for(i=0;i<gizemliSatir;i++){ //Gizemli Matrisin sat�r say�s�na kadar say
		for(int j=0;j<gizemliSutun;j++){ //Gizemli matrisin s�t�n say�s�na kadar say
			cout << "Gizemli Matrisin " << i+1 << ".Sat�r� " << j+1 <<".S�tununu Girin : "; //Ekrana giri� bilgisi bast�r
			cin >> deger; //De�eri Al
			gizemliMatris[i][j] = deger; //Matrisin i�ini doldur.
		}
	}	
}

//Void tipinde �ansl� Matrisin i�ini kullan�c� taraf�ndan doldurulacak public fonksiyon
void DinamikBellekYonetimi::SansliMatrisDoldur(int**sansliMatris,int sansliMatrisSatir,int sansliMatrisSutun){
	cout << endl;
	int i,j,deger; //i,j ve kullan�c�dan al�nacak de�er de�i�keni tan�mand�
	for(i=0;i<sansliMatrisSatir;i++){ //�ansl� Matrisin sat�r say�s�na kadar say
		for(int j=0;j<sansliMatrisSutun;j++){ //�ansl� matrisin s�t�n say�s�na kadar say
			cout << "�ansl� Matrisin " << i+1 << ".Sat�r� " << j+1 <<".S�tununu Girin : "; //Ekrana giri� bilgisi bast�r
			cin >> deger; //Kullan�c�dan de�eri Al
			sansliMatris[i][j] = deger; //�ansl� Matrisin i�ini doldur.
		}
	}	
}

//Bool tipinde Gizemli Matrisinin Olup Olmayaca��n� Anlayan Public Fonksiyon
bool DinamikBellekYonetimi::GizemliMatrisMi(int**gizemliMatris,int gizemliSatir,int gizemliSutun){
	if(gizemliSatir != gizemliSutun) //Sat�r say�s� s�t�n say�s�na e�it de�ilse yani n != n ise
		return false; //false d�nd�r
	else{ //Sat�r ve s�t�n e�it ise
		int i,j,M,toplam = 0; //i,j,M ve toplam� tutacak toplam de�i�keni tan�mland�
		M = (gizemliSatir*(pow(gizemliSatir,2)+1))/2; //M form�l� hesapland�
		for(i=0;i<gizemliSatir;i++){ //Gizemli matrisin sat�r say�s�na kadar say
			for(int j=0;j<gizemliSutun;j++){ //Gizemli matrisin s�t�n say�s�na kadar say
				toplam += gizemliMatris[i][j]; //Gizemli matriste toplama i�lemlerini yap
			}
			if(toplam != M) //E�er toplam M form�l�n e�it de�ilse
				return false; //false d�nd�r
			else
				toplam = 0; //E�er e�it ise toplam� 0 yap�p devam et
		}
	}	
	return true; //Bu a�amaya geldiyse herhangi bir false g�rmemi� demektir true d�nd�r.
}

//Int tipinde �ansl� Matrisinin Elemanlar�n�n Say�lar�n� Verecek Public Fonksiyon
int DinamikBellekYonetimi::SansliMatrisElemanlarininSayisi(int**sansliMatris,int sansliMatrisSatir,int sansliMatrisSutun){
	int i,j,k,sansliEleman = 0; //i,j,k ve �ansl� elemanlar�n toplam�n� tutacak sansliEleman de�i�keni tan�mland�
	
	satirinEnKucuguDizisi = (int*) malloc(sansliMatrisSatir*sizeof(int)); //Her Sat�rlar�n en k�����n� tutacak dinamik dizi tan�mland�
	sutununEnBuyuguDizisi = (int*) malloc(sansliMatrisSutun*sizeof(int)); //Her s�t�n�n en b�y���n� tutacak dinamik dizi tan�mland�
	
	satirinEnKucugu = sansliMatris[0][0]; //O anki Sat�r�n en k���k de�erini tutacak fonksiyon tan�mland� ve ilk de�er olarak dizinin ilk eleman� atand�
	sutununEnBuyugu = sansliMatris[0][0]; //O anki S�t�n�n en b�y�k de�erini tutacak fonksiyon tan�mland� ve ilk de�er olarak dizinin ilk eleman� atand�
	for(i=0;i<sansliMatrisSutun;i++){ //�ansl� matrisin s�t�n say�s�na kadar say
		for(int j=0;j<sansliMatrisSatir-1;j++){ //�ansl� matrisin sat�r say�s� -1 e kadar say
			if(sutununEnBuyugu < sansliMatris[j+1][i]) //E�er sutununEnBuyugu de�i�keninden daha b�y�k bir �ey var ise 
				sutununEnBuyugu = sansliMatris[j+1][i]; //Yeni en b�y�k de�er odur.
		}
		sutununEnBuyuguDizisi[i] = sutununEnBuyugu; //En son bulunan en b�y�k de�eri  sutununEnBuyuguDizisi adl� diziye ekle
		sutununEnBuyugu = sansliMatris[0][i+1]; //S�t�n�n en b�y�k de�eri i�in di�er s�t�na ge�
	}
	
	for(i=0;i<sansliMatrisSatir;i++){  //�ansl� matrisin sat�r say�s�na kadar say
		for(int j=0;j<sansliMatrisSutun;j++){  //�ansl� matrisin sat�r say�s�na kadar say
			if(satirinEnKucugu > sansliMatris[i][j]) //E�er satirinEnKucugu de�i�keninden daha k���k bir �ey var ise 
				satirinEnKucugu = sansliMatris[i][j]; //Yeni en k���k de�er odur.
		}
		satirinEnKucuguDizisi[i] = satirinEnKucugu; //En son bulunan en k���k de�eri  satirinEnKucuguDizisi adl� diziye ekle
		if(i!=sansliMatrisSatir-1) //E�er son elemana gelmediyse(i+1 yapt���m�z i�in ta�ma olacakt�r)
			satirinEnKucugu = sansliMatris[i+1][0]; //Sat�r�n en k���k de�eri i�in di�er sat�ra ge�		
	}
	
	/*Toplam ��lemi*/
	for(i=0;i<sansliMatrisSutun;i++){  //�ansl� matrisin s�t�n say�s�na kadar say
		for(j=0;j<sansliMatrisSatir;j++){ //�ansl� matrisin sat�r say�s�na kadar say
			if(sutununEnBuyuguDizisi[i] == satirinEnKucuguDizisi[j]) // sutununEnBuyuguDizisi ile satirinEnKucuguDizisi elemanlar� ortak ise o elemanar �ansl�d�r.
				sansliEleman++; //�ansl� eleman� artt�r.
		}
	}
	
	return sansliEleman; //�ansl� eleman toplam de�i�kenini return et.
}
