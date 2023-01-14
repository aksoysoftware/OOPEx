// KesirlerDonemOdevi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
class Kesir {
public:
    Kesir() {}
    Kesir(int pay, int payda) : pay_(pay), payda_(payda){} //Kesir sınıfının kurucu fonksiyonu
    int pay() const { return pay_; };  //getter pay
    int payda() const { return payda_; };  // getter payda 

    
    Kesir operator+(const Kesir& d) const {
        // Toplama işlemini gerçekleştirir.
        int pay = pay_ * d.payda_ + d.pay_ * payda_;
        int payda = payda_ * d.payda_;
        return Kesir(pay, payda);
    }

    Kesir operator-(const Kesir& d) const {
        // Çıkarma işlemini gerçekleştirir.
        int pay = pay_ * d.payda_ - d.pay_ * payda_;
        int payda = payda_ * d.payda_;
        return Kesir(pay, payda);
    }

    Kesir operator*(const Kesir& d) const {
        // Çarpma işlemini gerçekleştirir.
        int pay = pay_ * d.pay_;
        int payda = payda_ * d.payda_;
        return Kesir(pay, payda);
    }

    Kesir operator/(const Kesir& d) const {
        // Bölme işlemini gerçekleştirir.
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
    //Yaklasık deger bulmak
    static Kesir YaklasikDeger(double x);

private:
    int pay_;  // Pay değişkeni.
    int payda_;  // Payda değişkeni.
};
std::istream& operator>>(std::istream& in, Kesir& r) {
    // Girdi işlemini gerçekleştirir.
    int pay, payda;

    in >> pay >> payda;
    r = Kesir(pay, payda);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Kesir& r) {
    // Çıktı işlemini gerçekleştirir.
    out << r.pay() << '/' << r.payda();
    return out;
}
bool Kesir::operator==(const Kesir& d) const {
    // Eşitlik karşılaştırmasını gerçekleştirir.
    return pay_ * d.payda_ == d.pay_ * payda_;
}

bool Kesir::operator!=(const Kesir& d) const {
    // Eşit değil karşılaştırmasını gerçekleştirir.
    return !(*this == d);
}
bool Kesir::operator<(const Kesir& d) const {
    // Küçük karşılaştırmasını gerçekleştirir.
    return pay_ * d.payda_ < d.pay_* payda_;
}

bool Kesir::operator>(const Kesir& d) const {
    // Büyük karşılaştırmasını gerçekleştirir.
    return d < *this;
}
bool Kesir::operator<=(const Kesir& d) const {
    // Küçük veya eşit karşılaştırmasını gerçekleştirir.
    return !(d < *this);
}

bool Kesir::operator>=(const Kesir& d) const {
    // Büyük veya eşit karşılaştırmasını gerçekleştirir.
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


