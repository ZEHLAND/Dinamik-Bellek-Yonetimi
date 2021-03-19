class DinamikBellekYonetimi{ //DinamikBellekYonetimi ad�nda class tan�mland�
	
	private:
		int *satirinEnKucuguDizisi; //2.Matris i�in sat�rlar�n en k���k de�erlerini tutacak dinamik dizi private olarak tan�mland�
		int *sutununEnBuyuguDizisi; //2.Matris i�in s�tunlar�n en b�y�k de�erlerini tutacak dinamik dizi private olarak tan�mland�
		int satirinEnKucugu; //2.Matris i�in satirin o anki en k���k de�erini tutacacak de�i�ken private olarak tan�mland�
		int sutununEnBuyugu; //2.Matris i�in s�tunun o anki en b�y�k de�erini tutacacak de�i�ken private olarak tan�mland�
		
	public:
		bool GizemliMatrisMi(int**,int,int); //Gizemli matris olup olmayaca��n� belirlenece�i bool tipinde public fonksiyon tan�mland�
		void GizemliMatrisDoldur(int**,int,int); //Gizemli matrisin i�ini kullan�c� taraf�ndan dolduracak void tipli public fonksiyon tan�mland�
		int SansliMatrisElemanlarininSayisi(int**,int,int); //�ansl� matris elemanlar�n� sayacak int tipinde public fonksiyon tan�mland�
		void SansliMatrisDoldur(int**,int,int);//�ansl� matrisin i�ini kullan�c� taraf�ndan dolduracak void tipli public fonksiyon tan�mland�
};
