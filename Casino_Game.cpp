#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void drawLine(int n, char sembol);
void kurallar();
void intro();

int main()
{
    intro();
    setlocale(LC_ALL, "Turkish");
    string OyuncuAdı;
    int para_miktarı;
    int bahis_miktarı;
    int tahmin;
    int zar; // rastgele sayıyı tutar
    char secim;

    srand(time(0));
    
    drawLine(60, '_');
    cout << "\n\n\n\t\t CASINO OYUNU\n\n\n\n";
    drawLine(60, '_');
    
    cout << "\n\n İsminizi Giriniz: ";
    getline(cin, OyuncuAdı);

    cout << "\n\n Oyunu Oynayacağınız Para Miktarını Giriniz: ";
    cin >> para_miktarı;


    do {
        
        system("cls");
        kurallar();
        cout << "\n\n Mevcut Paranız: " << para_miktarı << " TL "<<"\n";

        do {

            cout << OyuncuAdı << " , bahis oynayacağınız parayı giriniz: ";
            cin >> bahis_miktarı;
            if (bahis_miktarı > para_miktarı) {
                cout << "Bahis miktarınız para miktarınızdan daha fazla\n" << "\nBahis miktarını yeniden giriniz: ";
            }

        } while (bahis_miktarı > para_miktarı);

        do {
            cout << "1 ile 10 arasında bir sayi tahmin ediniz: ";
            cin >> tahmin;
            if (tahmin <= 0 || tahmin > 10) {
                cout << "Lütfen numarayı kontrol ediniz. Sayı 1 ile 10 arasında olmalı.";
            }
        } while (tahmin <= 0 || tahmin > 10); 

        zar = rand() % 10 + 1;

        if (zar == tahmin) {
            cout << "Tebrikler!! Kazandığınız miktar: " << bahis_miktarı * 10;
            para_miktarı = para_miktarı + bahis_miktarı*10;
        }

        else {

            cout << "Bu sefer şanssızdınız!! Kaybettiğiniz miktar: " << bahis_miktarı<<"\n ";
            para_miktarı = para_miktarı - bahis_miktarı;
        }


        cout << "Kazanan sayı : " << zar << "\n";
        cout << "\n" << OyuncuAdı << " , Mevcut Paranız: " << para_miktarı << "\n";

        if (para_miktarı == 0) {
            cout << "Oynayacak paranız yok. ";
            break;
        }


        cout << "Tekrar oynamak ister misiniz? (e/h) ";
        cin >> secim;



    } while (secim == 'E' || secim == 'e');

    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "Oynadığınız için teşekkür ederiz. Mevcut paranız: " << para_miktarı << "\n\n\n";
    drawLine(70, '=');

    return 0;



}


void drawLine(int n, char sembol) {

    for (int i = 0; i < n; i++) {
        cout << sembol;
         }
    cout << "\n";
}

void kurallar() {
    system("cls");

    cout << "\n\n";
    drawLine(80, '-');
    cout << "\t\t OYUNUN KURALLARI<\n";
    drawLine(80, '-');

    cout << "\t1. 1-ile 10 arasındaki herhangi bir sayıyı seçiniz.\n";
    cout << "\t2. Eğer kazanırsanız koyduğunuz paranın 10 katını alırsınız.\n ";
    cout << "\t3. Eğer kaybederseniz koydğunuz parayı kaybedersiniz.\n\n";
}

void intro()
{
    cout << "\n\n\n\t  CASINO";
    cout << "\n\n\TAHMIN";
    cout << "\n\n\t  OYUNU";
    cout << "\n\n\n\KODLAYAN : ISMAIL UCEL";
    cin.get();
}



