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
   
    int a = pay_;
    int b = payda_;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    int gcd = a;  // EBOB gcd
    pay_ /= gcd;
    payda_ /= gcd;
}



int main()
{
    
  
    return 0;
}


