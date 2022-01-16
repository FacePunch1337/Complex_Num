#include <iostream>
#include <math.h>
#include <string>


class ComplexClass {
private:
    double Re, Im;
public:
    void setRe(double Re) { this->Re = Re; }
    double getRe() { return Re; }

    void setIm(double Im) { this->Im = Im; }
    double getIm() { return Im; }

    ComplexClass() : Re{ 0 }, Im{ 0 } { printf("Constructor works: %p\n", this); }
    ComplexClass(double Re) : ComplexClass() { this->Re = Re; }
    ComplexClass(double Re, double Im) : ComplexClass() { this->Re = Re; this->Im = Im; }

    ComplexClass operator +(ComplexClass n2) {
        ComplexClass res;
        res.setRe(this->Re + n2.getRe());
        res.setIm(this->Im + n2.getIm());
        return res;
    }

    double Abs() {
        return sqrt(pow(Re, 2) + pow(Im, 2));
    }

    void print() {
        std::cout << Re << " + " << Im << "i";
    }
};

// Struct
struct ComplexStruct {
    //private:
    double Re, Im;
    //public:
        /*
        void setRe(double Re) { this->Re = Re; }
        double getRe() { return Re; }

        void setIm(double Im) { this->Im = Im; }
        double getIm() { return Im; }
        */

    ComplexStruct() : Re{ 0 }, Im{ 0 } { printf("Constructor works: %p\n", this); }
    ComplexStruct(double Re) : ComplexStruct() { this->Re = Re; }
    ComplexStruct(double Re, double Im) : ComplexStruct() { this->Re = Re; this->Im = Im; }

    ComplexStruct operator +(ComplexStruct n2) {
        ComplexStruct res;
        res.Re = this->Re + n2.Re;
        res.Im = this->Im + n2.Im;
        return res;
    }

    double Abs() {
        return sqrt(pow(Re, 2) + pow(Im, 2));
    }

    void print() {
        std::cout << Re << " + " << Im << "i";
    }
};

int main()
{
    puts("Class:\n");
    ComplexClass c1;
    c1.print();
    std::cout << std::endl;
    ComplexClass c2(2);
    c2.print();
    std::cout << std::endl;
    ComplexClass c3(2, 3);
    c3.print();
    std::cout << std::endl;

    puts("----------------------------");
    ComplexClass c4 = c3 + c2;
    std::cout << "( ";
    c2.print();
    std::cout << " ) + ( ";
    c3.print();
    std::cout << ") = ";
    c4.print();
    std::cout << std::endl;

    puts("----------------------------");
    std::cout << "Abs of ( ";
    c4.print();
    std::cout << " ) = ";
    std::cout << c4.Abs() << std::endl;

    puts("\n\n\nStruct:\n");

    ComplexStruct s1;
    s1.print();
    std::cout << std::endl;
    ComplexStruct s2(2);
    s2.print();
    std::cout << std::endl;
    ComplexStruct s3(2, 3);
    s3.print();
    std::cout << std::endl;

    puts("----------------------------");
    ComplexStruct s4 = s3 + s2;
    std::cout << "( ";
    s2.print();
    std::cout << " ) + ( ";
    s3.print();
    std::cout << ") = ";
    s4.print();
    std::cout << std::endl;

    puts("----------------------------");
    std::cout << "Abs of ( ";
    s4.print();
    std::cout << " ) = ";
    std::cout << s4.Abs() << std::endl;
    return 0;
}