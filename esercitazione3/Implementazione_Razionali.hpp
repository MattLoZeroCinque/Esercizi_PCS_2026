// WARNING! USO LEGGERO DELL'IA PER LA CORRETTA IMPLEMENTAZIONE DEL MCD E PER COMPRENDERE MEGLIO I CONCETTI DIETRO AL CODICE DA ME CREATO


#include <iostream>
#include <concepts>
#include <numeric>


template<typename I> requires std::integral<I>
class rational
{
  I num_;
  I den_;
  
public:
    // Si implementa il Costruttore di default
    rational()
        : num_(I{1}), den_(I{1})
    {}

    // Si implementa il Costruttore user-defined
    rational(const I& pnum, const I& pden)
        : num_(pnum), den_(pden)
    {
        // Si gestisce l'output di "Infinito" e di "NaN"
        if (den_ == 0) {
            // Ogni numero diviso per zero diventa "1/0" (Infinito generico)
            if (num_ != 0) {
                num_ = 1; 
            }
        } else {
            // Si calcola il massimo comune divisore (MCD)
            I comune_divisore = std::gcd(num_, den_);
            
            num_ /= comune_divisore;
            den_ /= comune_divisore;
            
            // Se il denominatore è negativo, si porta il segno meno al numeratore
            if (den_ < 0) {
                num_ = -num_;
                den_ = -den_;
            }
        }
    }

    // Si restituiscono i valori del numeratore e del denominatore
    I num() const { return num_; }
    I den() const { return den_; }
	
    // Si implementa l'incremento di somma
    rational& operator+=(const rational& other) {
        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;
        *this = rational(num_, den_); 
        return *this;
    }
    
    // Si implementa la somma
    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }

    // Si implementa il decremento di differenza
    rational& operator-=(const rational& other) {
        num_ = num_ * other.den_ - other.num_ * den_;
        den_ = den_ * other.den_;
        *this = rational(num_, den_);
        return *this;
    }
    
    // Si implementa la differenza
    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }

    // Si implementa l'incremento di prodotto
    rational& operator*=(const rational& other) {
        num_ *= other.num_;
        den_ *= other.den_;
        *this = rational(num_, den_);
        return *this;
    }
    
    // Si implementa il prodotto
    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;
    }
	
    // Si implementa il decremento di rapporto
    rational& operator/=(const rational& other) {
        num_ *= other.den_;
        den_ *= other.num_;
        *this = rational(num_, den_);
        return *this;
    }
    
    // Si implementa il rapporto
    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        return ret;
    }
};

// Si stampa in output il numero richiesto
template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    if (r.den() == 0) {
        if (r.num() != 0) os << "Inf";
        else os << "NaN";
    } else {
        os << r.num() << "/" << r.den();
    }
    return os;
}