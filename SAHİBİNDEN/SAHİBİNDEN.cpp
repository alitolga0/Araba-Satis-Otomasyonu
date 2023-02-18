#include <iostream>
#include <fstream>


using namespace std;

class araç {

public:

	string  renk, sehir, yil, marka;

	int ücret, satısNo;

	ofstream dosyaYaz;
	ifstream dosyaOku;
	virtual void listele() = 0;
	void arabaAra() {
		string ara;

		cout << "-------Aramak istediğiniz arabanın satış numarsaını biliyor musunuz?(e-h)--------" << endl;
		cin >> ara;
		if (ara == "e") {
			int i = 1;
			ifstream okuaraba;

			ifstream getiraraba;

			while (i == 1) {
				i = 0;
				cout << "Arabanın Satış Numarası  " << endl;

				cin >> satısNo;
				getiraraba.open("arabaKayit.txt");
				int gecici;

				string a;
				okuaraba.open("arabaKayit.txt");
				while (okuaraba >> gecici) {
					if (satısNo == gecici) {
						a = gecici;
						i = 0;

						break;
					}
				}
				okuaraba.close();
				if (a.size() != 0) {
					string satir;
					while (getiraraba >> satir)
						cout << satir << endl;

					break;
				}
				else {
					int j;
					cout << "Satış Numarası  Bulunamadı Tekrar Denemek için 1	Şehirle arama yapmak için 2 ye basınız" << endl;
					cin >> j;
					if (j == 2) {
						ara = "h";
						break;
					}
					if (j == 1) {
						i = 1;
					}
				}
			}
		}
		if (ara == "h") {

			cout << "Aramak İstediğiniz Şehri Giriniz" << endl;
			cin >> sehir;
			cout << "Güzel Şehir" << endl;
		}
	}

	virtual void arabaEkle() {
		system("cls");
		dosyaOku.open("arabaKayit.txt");
		cout << "marka giriniz";
		cin >> marka;
		cout << " sehiri giriniz";
		cin >> sehir;
		

			cout << "yil giriniz";
			cout << "(yıl sayılardan oluşmalıdır)";
			cin >> yil;
			
		
		cout << "renk giriniz";
		cin >> renk;
		

			cout << "ücret bölümüne rakamdan başka bir şey girilemez";

			cout << "ucret  giriniz";
			cin >> ücret;
			cout << "satış numarası bölümüne rakamdan başka bir şey girilemez";

			cout << "satış numarası giriniz";
			cin >> satısNo;
		
			cout << "sayı giriniz";
		
	
			cout << "sayı giriniz";
		

		dosyaYaz.open("arabaKayit.txt", ios::app);
		dosyaYaz << satısNo << "\t" << marka << "\t" << sehir << "\t" << yil << "\t" << renk << "\t" << ücret << endl;
		dosyaYaz.close();

		system("cls");
	}
	virtual void arabaSil() = 0;
		
};

class Kullanici {

public:
	string isim, soyisim, kullaniciadi;
	int yas;

	ofstream dosyaYaz;
	ifstream dosyaOku;




	void kulEkle() {
		system("cls");
		dosyaOku.open("kullaniciKayit.txt");
		cout << " adınızı giriniz";
		cin >> isim;
		cout << "soyadanızı giriniz";
		cin >> soyisim;
		cout << "yaşınızı giriniz";
		cout << "(yaş bölümüne sadece rakamlar girilebilir)";
		cin >> yas;
		int a = 0;
		cout << "kullanıcı adınızı giriniz";
		cin >> kullaniciadi;


		dosyaYaz.open("kullaniciKayit.txt", ios::app);
		dosyaYaz << isim << "\t" << soyisim << "\t" << yas << "\t" << kullaniciadi << endl;
		dosyaYaz.close();
		system("cls");
	}

	void kulSil() {
		system("cls");

		string sorgu;
		int a = 0;
		
		
		cout << "  kullanıcı adı	";
		cin >> sorgu;

		ofstream gecici;
		gecici.open("gecicisil.txt", ios::app);

		ifstream dosya_oku;
		dosya_oku.open("kullaniciKayit.txt", ios::app);

		string ifade;

		while (!dosya_oku.eof())

		{
			dosya_oku >> isim >> soyisim >> yas >> kullaniciadi;

			if (kullaniciadi != sorgu && kullaniciadi != ifade)
			{
				gecici << isim << "\t" << soyisim << "\t" << yas << "\t" << kullaniciadi << "\n";
				ifade = kullaniciadi;

			}
		}

		gecici.close();
		dosya_oku.close();
		remove("kullaniciKayit.txt");
		rename("gecicisil.txt", "kullaniciKayit.txt");
		if (a == 0)
		{
			cout << "\nMüşteri bulunamadi !" << endl;
		}
		if (a == 1)
		{
			cout << "\nMüşteri basari ile silindi..." << endl;
		}

		
	}






	 void kulListele() {
		system("cls");
		cout << "isim " << "\t" << "soyisim" << "\t" << "yas" << "\t" << "kullanıcı adı \n";

		dosyaOku.open("kullaniciKayit.txt");
		while (dosyaOku >> isim >> soyisim >> yas >> kullaniciadi) {

			cout << isim << "\t" << soyisim << "\t" << yas << "\t" << kullaniciadi << "\n";
		}
		dosyaOku.close();
		
		system("pause");
	}






};
struct node
{
	int araba;
	struct node* sonraki;
};
class liste
{
private:
	node* bas, * son;
public:
	liste()
	{
		bas = NULL;
		son = NULL;
	}
	void ekle(int n)
	{
		system("cls");

		node* temp = new node;
		temp->araba = n;
		temp->sonraki = NULL;

		if (bas == NULL)
		{
			bas = temp;
			son = temp;
		}
		else

		{
			son->sonraki = temp;
			son = son->sonraki;
		}
		system("cls");
	}
	void listele() {
	


		node* temp = new node;
		temp = bas;
		while (temp != NULL) {
			cout << temp->araba << "\t";
			temp = temp->sonraki;
		}system("pause");
		

	}
	void sil(int hangisi) {

		system("cls");

		node* suanki = new node;
		node* onceki = new node;

		suanki = bas;
		for (int i = 1; i < hangisi; i++) {
			onceki = suanki;
			suanki = suanki->sonraki;
		}


		onceki->sonraki = suanki->sonraki;
		delete suanki;
		system("cls");
	}
};
class araba : public araç{
public:
	void arabaSil() {
	system("cls");

	int no = 0;


	cout << "satış  numarası	";
	cin >> satısNo;


	ofstream gecici;
	gecici.open("gecicisil.txt", ios::app);


	ifstream dosya_oku;
	dosya_oku.open("arabaKayit.txt", ios::app);

	int ifade = 0;


	while (!dosya_oku.eof())

	{
		dosya_oku >> satısNo >> marka >> sehir >> yil >> renk >> ücret;

		if (no != satısNo && no != ifade)
		{
			gecici << satısNo << "	" << marka << "" << sehir << "" << yil << "" << renk << "" << ücret << "\n";
			ifade = satısNo;
		}
	}

	gecici.close();
	dosya_oku.close();
	remove("arabaKayit.txt");
	rename("gecicisil.txt", "arabaKayit.txt");
	cout << "araba başarı ile silindi";



}

void listele() {
	system("cls");
	cout << "satıs numarası " << "\t" << "marka" << "\t" << "sehir" << "\t" << " yıl " << "\t" << "renk" << "\t" << "ücret \n";

	dosyaOku.open("arabaKayit.txt");
	while (dosyaOku >> satısNo >> marka >> sehir >> yil>>renk>>ücret) {

		cout << satısNo << "\t"<<"\t" << marka << "\t" << sehir << "\t" << yil << "\t" << renk << "\t" << ücret << "\n";
	}
	dosyaOku.close();




}



};





void yükleniyor() {

	system("CLS");
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		cout << "-->";

		system("CLS");

	}
}

int main() {
	system("color 9");
	setlocale(LC_ALL, "Turkish");
	Kullanici kull;

	liste lis;
	
	araba araba;
	ofstream dosyaYaz;
	ifstream dosyaOku;
	int secim;
	do {
		
		yükleniyor();
		cout << "ALİ'DEN .COM'A HOŞGELDİNİZ" << endl;
		cout << "1 kullanıcı menüsü " << endl;
		cout << "2 araba menüsü" << endl;
		cout << "3 satış işlemleri" << endl;
		cin >> secim;
		if (secim == 1) {//kullancı
			int secim1;
			do {
				yükleniyor();
				
				cout << "1- kullanıcı ekle" << endl;
				cout << "2- kullanıcı sil " << endl;
				cout << "3- kullanıcı listele" << endl;
				cout << "77 üst menüye çıkmak için" << endl;
				cin >> secim1;
				// *****************************kullanıcı menüsü *********************************
				if (secim1 == 1) {
					cout << "******************* kullanıcı ekle*****************" << endl;
					yükleniyor();
					kull.kulEkle();
					break;
				}
				else if (secim1 == 2) {
					cout << "************************* kullanıcı sil *******************" << endl;
					yükleniyor();
					kull.kulSil();
					break;
				}
				else if (secim1 == 3) {
					cout << "************************kullanıcı listele******************************" << endl;
					yükleniyor();
					kull.kulListele();
					break;
				}

			} while (secim1 != 77);

		}
		//****************************************************araba menüsü**********************************************
		else if (secim == 2) {// araba
			int secima;
			do {
				yükleniyor();
				
				cout << "1- araba ekle" << endl;
				cout << "2- araba sil" << endl;
				cout << "3- araba listele" << endl;
				cout << "4- araba ara" << endl;
				cout << "77- üst menüye çıkmak için " << endl;
				cin >> secima;
				if (secima == 1) {
					int secimabc;
					do {
						
						cout << "********************************araba ekle****************************" << endl;
						yükleniyor();

						araba.arabaEkle();

						break;
					} while (secimabc != 77);
					
				}
				else if (secima == 2) {
					cout << "*********************************araba sil*************************************" << endl;
					yükleniyor();
					araba.arabaSil();
					break;
				}


				else if (secima == 3) {
					cout << "******************************araba listele******************************" << endl;
					yükleniyor();
					araba.listele();
					system("pause");
					break;
				}

				else if (secima == 4) {
					cout << "********************************* araba ara**********************************" << endl;
					yükleniyor();
					araba.arabaAra();
				}

			} while (secima != 77);

		}

		//********************satış menüsü*********************************
		else if (secim == 3) {// satış


			int secimb;
			do {
				yükleniyor();
				cout << "1- kapora ver" << endl;
				cout << "2- kapora sil" << endl;
				cout << "3- kapora listele" << endl;
				cin >> secimb;
				if (secimb == 1) {
					cout << "************************** kapora ver*************************" << endl;
					yükleniyor();
					cout << "eklemek istediginiz satıs numarasını giriniz" << endl;
					int a;
					cin >> a;
					lis.ekle(a);
				}
				else if (secimb == 2) {
					cout << "************************kapora sil*************************" << endl;
					yükleniyor();
					cout << "silmek istediginiz satıs numarasını giriniz" << endl;
					int a;
					cin >> a;
					lis.sil(a);
				}
				else if (secimb == 3) {
					cout << "******************************** kapora listele**********************" << endl;
					yükleniyor();
					lis.listele();
					break;
				}

			} while (secimb != 77);

		}



	} while (secim != 77);

}


