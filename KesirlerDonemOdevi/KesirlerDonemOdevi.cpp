// KesirlerDonemOdevi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
class Kesir {
public:
    Kesir() {}
    Kesir(int pay, int payda) : pay_(pay), payda_(payda){} //Kesir s�n�f�n�n kurucu fonksiyonu
    int pay() const { return pay_; };  //getter pay
    int payda() const { return payda_; };  // getter payda 

    
    Kesir operator+(const Kesir& d) const {
        // Toplama i�lemini ger�ekle�tirir.
        int pay = pay_ * d.payda_ + d.pay_ * payda_;
        int payda = payda_ * d.payda_;
        return Kesir(pay, payda);
    }

    Kesir operator-(const Kesir& d) const {
        // ��karma i�lemini ger�ekle�tirir.
        int pay = pay_ * d.payda_ - d.pay_ * payda_;
        int payda = payda_ * d.payda_;
        return Kesir(pay, payda);
    }

    Kesir operator*(const Kesir& d) const {
        // �arpma i�lemini ger�ekle�tirir.
        int pay = pay_ * d.pay_;
        int payda = payda_ * d.payda_;
        return Kesir(pay, payda);
    }

    Kesir operator/(const Kesir& d) const {
        // B�lme i�lemini ger�ekle�tirir.
        int pay = pay_ * d.payda_;
        int payda = payda_ * d.pay_;
        return Kesir(pay, payda);
    }
    //Girdi Cikti Islemleri
    friend std::istream& operator>>(std::istream& in, Kesir& kesir);
    friend std::ostream& operator<<(std::ostream& out, const Kesir& kesir);
    //Esitlik Kontrolu
    bool operator==(const Kesir& d) const;
    bool operator!=(const Kesir& d) const;
    //Karsilastirma Kontrolu
    bool operator<(const Kesir& d) const;
    bool operator>(const Kesir& d) const;
    bool operator<=(const Kesir& d) const;
    bool operator>=(const Kesir& d) const;
    //Sadelestirme
    void Sadelestir();
    //Yaklas�k deger bulmak
    static Kesir YaklasikDeger(double x);

private:
    int pay_;  // Pay de�i�keni.
    int payda_;  // Payda de�i�keni.
};
std::istream& operator>>(std::istream& in, Kesir& r) {
    // Girdi i�lemini ger�ekle�tirir.
    int pay, payda;

    in >> pay >> payda;
    r = Kesir(pay, payda);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Kesir& r) {
    // ��kt� i�lemini ger�ekle�tirir.
    out << r.pay() << '/' << r.payda();
    return out;
}
bool Kesir::operator==(const Kesir& d) const {
    // E�itlik kar��la�t�rmas�n� ger�ekle�tirir.
    return pay_ * d.payda_ == d.pay_ * payda_;
}

bool Kesir::operator!=(const Kesir& d) const {
    // E�it de�il kar��la�t�rmas�n� ger�ekle�tirir.
    return !(*this == d);
}
bool Kesir::operator<(const Kesir& d) const {
    // K���k kar��la�t�rmas�n� ger�ekle�tirir.
    return pay_ * d.payda_ < d.pay_* payda_;
}

bool Kesir::operator>(const Kesir& d) const {
    // B�y�k kar��la�t�rmas�n� ger�ekle�tirir.
    return d < *this;
}
bool Kesir::operator<=(const Kesir& d) const {
    // K���k veya e�it kar��la�t�rmas�n� ger�ekle�tirir.
    return !(d < *this);
}

bool Kesir::operator>=(const Kesir& d) const {
    // B�y�k veya e�it kar��la�t�rmas�n� ger�ekle�tirir.
    return !(*this < d);
}
void Kesir::Sadelestir() {
    // �klid algoritmas�n� kullanarak pay ve payda de�erlerini sadele�tirir.
    int a = pay_;
    int b = payda_;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    int gcd = a;  // a ve b'nin en b�y�k ortak b�lenidir (gcd).
    pay_ /= gcd;
    payda_ /= gcd;
}


//Kesir Kesir::YaklasikDeger(double x) {
//    // �lk �nce x'in mutlak de�erine bakal�m.
//    bool isNegative = (x < 0);
//    x = fabs(x);
//
//    // �ki rasyonel say� aras�ndaki fark� kontrol edecek bir de�i�ken.
//    double epsilon = 1e-6;
//
//    // x'in mutlak de�eri ile 0 aras�ndaki fark azsa, 0'� d�nd�relim.
//    if (x < epsilon) return Kesir(0, 1);
//
//    // x'in mutlak de�eri ile 1 aras�ndaki fark azsa, 1'i d�nd�relim.
//    if (x > 1.0 - epsilon) return Kesir(1, 1);
//
//    // x'in mutlak de�erinin k�s�ratl� kar��l���n� bulal�m.
//    int pay = x * 1000000;  // �rnek i�in 1000000 kulland�k.
//    int payda = 1000000;    // �rnek i�in 1000000 kulland�k.
//
//    // x'in mutlak de�erinin k�s�ratl� kar��l��� ile x aras�ndaki fark azsa,
//    // k�s�ratl� kar��
//}
int main()
{
    /*Kesir a(5, 30);
    Kesir b(7, 6);
    Kesir c = a + b;
    cout << c;
    c.Sadelestir();
    cout << endl;
    cout << c;*/
    Kesir k;
    cin >> k;
    cout << k;
    return 0;
}


