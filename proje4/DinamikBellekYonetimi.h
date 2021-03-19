class DinamikBellekYonetimi{ //DinamikBellekYonetimi adýnda class tanýmlandý
	
	private:
		int *satirinEnKucuguDizisi; //2.Matris için satýrlarýn en küçük deðerlerini tutacak dinamik dizi private olarak tanýmlandý
		int *sutununEnBuyuguDizisi; //2.Matris için sütunlarýn en büyük deðerlerini tutacak dinamik dizi private olarak tanýmlandý
		int satirinEnKucugu; //2.Matris için satirin o anki en küçük deðerini tutacacak deðiþken private olarak tanýmlandý
		int sutununEnBuyugu; //2.Matris için sütunun o anki en büyük deðerini tutacacak deðiþken private olarak tanýmlandý
		
	public:
		bool GizemliMatrisMi(int**,int,int); //Gizemli matris olup olmayacaðýný belirleneceði bool tipinde public fonksiyon tanýmlandý
		void GizemliMatrisDoldur(int**,int,int); //Gizemli matrisin içini kullanýcý tarafýndan dolduracak void tipli public fonksiyon tanýmlandý
		int SansliMatrisElemanlarininSayisi(int**,int,int); //Þanslý matris elemanlarýný sayacak int tipinde public fonksiyon tanýmlandý
		void SansliMatrisDoldur(int**,int,int);//Þanslý matrisin içini kullanýcý tarafýndan dolduracak void tipli public fonksiyon tanýmlandý
};
