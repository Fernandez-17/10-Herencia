#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Clase base Figura
class Figura {
protected:
    string color;
    double area;
    double perimetro;

public:
   
    Figura(string c = "Blanco") : color(c), area(0), perimetro(0) {}

    virtual void calcularArea() = 0;
    virtual void calcularPerimetro() = 0;

    void mostrarColor() {
        cout << "Color: " << color << endl;
    }

    virtual void mostrarDatos() {
        mostrarColor();
        cout << "Área: " << area << endl;
        cout << "Perímetro: " << perimetro << endl;
    }
};

// Clase derivada Circulo
class Circulo : public Figura {
private:
    double radio;

public:
    
    Circulo(double r, string c = "Blanco") : Figura(c), radio(r) {}

    void calcularArea() override {
        area = M_PI * radio * radio;  
    }
    void calcularPerimetro() override {
        perimetro = 2 * M_PI * radio; 
    }
    void mostrarDatos() override {
        cout << "Datos del Círculo:" << endl;
        Figura::mostrarDatos();
        cout << "Radio: " << radio << endl;
    }
};

// Clase derivada Rectangulo
class Rectangulo : public Figura {
private:
    double base;
    double altura;

public:
    // Constructor de la clase Rectangulo
    Rectangulo(double b, double h, string c = "Blanco") : Figura(c), base(b), altura(h) {}

    void calcularArea() override {
        area = base * altura; 
    }
    void calcularPerimetro() override {
        perimetro = 2 * (base + altura);  
    }

    void mostrarDatos() override {
        cout << "Datos del Rectángulo:" << endl;
        Figura::mostrarDatos();
        cout << "Base: " << base << endl;
        cout << "Altura: " << altura << endl;
    }
};

// Clase derivada Triangulo
class Triangulo : public Figura {
private:
    double base;
    double altura;
    string tipo;

public:

    Triangulo(double b, double h, string t = "Equilátero", string c = "Blanco") : Figura(c), base(b), altura(h), tipo(t) {}

    void calcularArea() override {
        area = (base * altura) / 2;  
    }

    // Calcular el perímetro del triángulo
    void calcularPerimetro() override {
        perimetro = 3 * base; 
    }
    void mostrarDatos() override {
        cout << "Datos del Triángulo:" << endl;
        Figura::mostrarDatos();
        cout << "Base: " << base << endl;
        cout << "Altura: " << altura << endl;
        cout << "Tipo: " << tipo << endl;
    }
};

// Programa principal
int main() {

    Circulo circulo(5, "Rojo");
    Rectangulo rectangulo(4, 6, "Azul");
    Triangulo triangulo(3, 4, "Escaleno", "Verde");

    circulo.calcularArea();
    circulo.calcularPerimetro();
    circulo.mostrarDatos();

    cout << endl;

    rectangulo.calcularArea();
    rectangulo.calcularPerimetro();
    rectangulo.mostrarDatos();

    cout << endl;

    triangulo.calcularArea();
    triangulo.calcularPerimetro();
    triangulo.mostrarDatos();

    return 0;
}

