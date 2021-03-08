#include <iostream>
#include <cmath>
using namespace std;
 
class ComplexNumber
{
private:
    double x;
    double y;
public:
    //конструкторы
    ComplexNumber();
    ComplexNumber(double x, double y);
 
    //вывод комплексного числа
    void showComplexNumber();
    //вычисление степени комплексного числа
    void POW_ComplexNumber();
 
    //вычисление модуля комплексного числа
    double module();
 
    //перегруженные операции: сложение, умножение
    ComplexNumber operator+(ComplexNumber num);
    ComplexNumber operator*(ComplexNumber num);
};
 
void ComplexNumber::showComplexNumber()
{
    cout << x << showpos << y << "i" << noshowpos;
}
 
ComplexNumber::ComplexNumber()
{
    x = 0;
    y = 0;
}
 
ComplexNumber::ComplexNumber(double x, double y)
{
    this->x = x;
    this->y = y;
}
 
double ComplexNumber::module()
{
    return sqrt(x * x + y * y);
}
 
ComplexNumber ComplexNumber::operator+(ComplexNumber num)
{
    ComplexNumber newNum (x + num.x, y + num.y);
    return newNum;
}
 
ComplexNumber ComplexNumber::operator*(ComplexNumber num)
{
    ComplexNumber newNum (x * num.x - y * num.y, y * num.x + x * num.y);
    return newNum;
}

int main()
{
    setlocale (LC_ALL, "rus");
    ComplexNumber z1(5,3), z2(2,4);
    
    long double x,y,X,Y;
    double r,phi,R,Phi;
    int n;

    cout << "Два комплексных числа:" << '\n'; 
    cout << "z1 = ";
      z1.showComplexNumber();
    cout << "   ";
    cout << "z2 = ";
      z2.showComplexNumber();
    
    cout << '\n';
    
    cout << "Модуль z1: " << z1.module() << '\n';
    cout << "Модуль z2: " << z2.module() << '\n' << '\n';

    cout << "z1 + z2 = ";
    (z1 + z2).showComplexNumber();
    cout << '\n';
    cout << "z1 * z2 = ";
    (z1 * z2).showComplexNumber();
    cout << '\n' << '\n';

    cout << "     Степень: " << '\n';
    cout << "Вещественное число = "; cin >> x;
    cout << "Мнимое число = "; cin >> y;
    cout << "Степень = " << '\n'; cin >> n;
    //Вычисление результата:
    phi=atan2(y,x);
    r=sqrt(x*x+y*y);
    R=pow(r,n);
    Phi=n*phi;
    X=R*cos(Phi);
    Y=R*sin(Phi);
    cout << "Результат:\n";
    cout << "Вещественное число: " << X << "\n";
    cout << "Мнимое число: " << Y << "\n";
    
    return 0;
}
