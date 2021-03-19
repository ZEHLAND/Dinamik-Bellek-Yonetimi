#include <iostream> //Iostream kütüphanesi include edildi
#include <stdio.h> //Stdio kütüphanesi dahil edildi
#include <stdlib.h> //Stdlib kütüphanesi include edildi
#include "DinamikBellekYonetimi.h"; //Dinamik Bellek Yönetimi Header Dosyasý Ýnclude Edildi
#include <Math.h> //Pow komutunu kullanmak için Math. 

using namespace std; //Std nesnesi kullanýldý 

//Void tipinde Gizemli Matrisin içini kullanýcý tarafýndan doldurulacak public fonksiyon
void DinamikBellekYonetimi::GizemliMatrisDoldur(int**gizemliMatris,int gizemliSatir,int gizemliSutun){
	int i,j,deger; //i,j ve kullanýcýdan alýnacak deðer deðiþkeni tanýmandý
	for(i=0;i<gizemliSatir;i++){ //Gizemli Matrisin satýr sayýsýna kadar say
		for(int j=0;j<gizemliSutun;j++){ //Gizemli matrisin sütün sayýsýna kadar say
			cout << "Gizemli Matrisin " << i+1 << ".Satýrý " << j+1 <<".Sütununu Girin : "; //Ekrana giriþ bilgisi bastýr
			cin >> deger; //Deðeri Al
			gizemliMatris[i][j] = deger; //Matrisin içini doldur.
		}
	}	
}

//Void tipinde Þanslý Matrisin içini kullanýcý tarafýndan doldurulacak public fonksiyon
void DinamikBellekYonetimi::SansliMatrisDoldur(int**sansliMatris,int sansliMatrisSatir,int sansliMatrisSutun){
	cout << endl;
	int i,j,deger; //i,j ve kullanýcýdan alýnacak deðer deðiþkeni tanýmandý
	for(i=0;i<sansliMatrisSatir;i++){ //Þanslý Matrisin satýr sayýsýna kadar say
		for(int j=0;j<sansliMatrisSutun;j++){ //Þanslý matrisin sütün sayýsýna kadar say
			cout << "Þanslý Matrisin " << i+1 << ".Satýrý " << j+1 <<".Sütununu Girin : "; //Ekrana giriþ bilgisi bastýr
			cin >> deger; //Kullanýcýdan deðeri Al
			sansliMatris[i][j] = deger; //Þanslý Matrisin içini doldur.
		}
	}	
}

//Bool tipinde Gizemli Matrisinin Olup Olmayacaðýný Anlayan Public Fonksiyon
bool DinamikBellekYonetimi::GizemliMatrisMi(int**gizemliMatris,int gizemliSatir,int gizemliSutun){
	if(gizemliSatir != gizemliSutun) //Satýr sayýsý sütün sayýsýna eþit deðilse yani n != n ise
		return false; //false döndür
	else{ //Satýr ve sütün eþit ise
		int i,j,M,toplam = 0; //i,j,M ve toplamý tutacak toplam deðiþkeni tanýmlandý
		M = (gizemliSatir*(pow(gizemliSatir,2)+1))/2; //M formülü hesaplandý
		for(i=0;i<gizemliSatir;i++){ //Gizemli matrisin satýr sayýsýna kadar say
			for(int j=0;j<gizemliSutun;j++){ //Gizemli matrisin sütün sayýsýna kadar say
				toplam += gizemliMatris[i][j]; //Gizemli matriste toplama iþlemlerini yap
			}
			if(toplam != M) //Eðer toplam M formülün eþit deðilse
				return false; //false döndür
			else
				toplam = 0; //Eðer eþit ise toplamý 0 yapýp devam et
		}
	}	
	return true; //Bu aþamaya geldiyse herhangi bir false görmemiþ demektir true döndür.
}

//Int tipinde Þanslý Matrisinin Elemanlarýnýn Sayýlarýný Verecek Public Fonksiyon
int DinamikBellekYonetimi::SansliMatrisElemanlarininSayisi(int**sansliMatris,int sansliMatrisSatir,int sansliMatrisSutun){
	int i,j,k,sansliEleman = 0; //i,j,k ve þanslý elemanlarýn toplamýný tutacak sansliEleman deðiþkeni tanýmlandý
	
	satirinEnKucuguDizisi = (int*) malloc(sansliMatrisSatir*sizeof(int)); //Her Satýrlarýn en küçüðünü tutacak dinamik dizi tanýmlandý
	sutununEnBuyuguDizisi = (int*) malloc(sansliMatrisSutun*sizeof(int)); //Her sütünün en büyüðünü tutacak dinamik dizi tanýmlandý
	
	satirinEnKucugu = sansliMatris[0][0]; //O anki Satýrýn en küçük deðerini tutacak fonksiyon tanýmlandý ve ilk deðer olarak dizinin ilk elemaný atandý
	sutununEnBuyugu = sansliMatris[0][0]; //O anki Sütünün en büyük deðerini tutacak fonksiyon tanýmlandý ve ilk deðer olarak dizinin ilk elemaný atandý
	for(i=0;i<sansliMatrisSutun;i++){ //Þanslý matrisin sütün sayýsýna kadar say
		for(int j=0;j<sansliMatrisSatir-1;j++){ //Þanslý matrisin satýr sayýsý -1 e kadar say
			if(sutununEnBuyugu < sansliMatris[j+1][i]) //Eðer sutununEnBuyugu deðiþkeninden daha büyük bir þey var ise 
				sutununEnBuyugu = sansliMatris[j+1][i]; //Yeni en büyük deðer odur.
		}
		sutununEnBuyuguDizisi[i] = sutununEnBuyugu; //En son bulunan en büyük deðeri  sutununEnBuyuguDizisi adlý diziye ekle
		sutununEnBuyugu = sansliMatris[0][i+1]; //Sütünün en büyük deðeri için diðer sütüna geç
	}
	
	for(i=0;i<sansliMatrisSatir;i++){  //Þanslý matrisin satýr sayýsýna kadar say
		for(int j=0;j<sansliMatrisSutun;j++){  //Þanslý matrisin satýr sayýsýna kadar say
			if(satirinEnKucugu > sansliMatris[i][j]) //Eðer satirinEnKucugu deðiþkeninden daha küçük bir þey var ise 
				satirinEnKucugu = sansliMatris[i][j]; //Yeni en küçük deðer odur.
		}
		satirinEnKucuguDizisi[i] = satirinEnKucugu; //En son bulunan en küçük deðeri  satirinEnKucuguDizisi adlý diziye ekle
		if(i!=sansliMatrisSatir-1) //Eðer son elemana gelmediyse(i+1 yaptýðýmýz için taþma olacaktýr)
			satirinEnKucugu = sansliMatris[i+1][0]; //Satýrýn en küçük deðeri için diðer satýra geç		
	}
	
	/*Toplam Ýþlemi*/
	for(i=0;i<sansliMatrisSutun;i++){  //Þanslý matrisin sütün sayýsýna kadar say
		for(j=0;j<sansliMatrisSatir;j++){ //Þanslý matrisin satýr sayýsýna kadar say
			if(sutununEnBuyuguDizisi[i] == satirinEnKucuguDizisi[j]) // sutununEnBuyuguDizisi ile satirinEnKucuguDizisi elemanlarý ortak ise o elemanar þanslýdýr.
				sansliEleman++; //Þanslý elemaný arttýr.
		}
	}
	
	return sansliEleman; //Þanslý eleman toplam deðiþkenini return et.
}
