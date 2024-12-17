#include <iostream>
#include <string>

using namespace std;

// Clase base Vehiculo
class Vehiculo {
protected:
    string numeroPlaca;
    string color;
    string marca;
    string modelo;
    int anio;
    string velocimetro;

public:
    Vehiculo(string m, string mo, int a, string placa = "", string col = "", string vel = "") 
        : marca(m), modelo(mo), anio(a), numeroPlaca(placa), color(col), velocimetro(vel) {}

    virtual void mostrarDatos() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anio << endl;
        if (!numeroPlaca.empty()) cout << "Placa: " << numeroPlaca << endl;
        if (!color.empty()) cout << "Color: " << color << endl;
        if (!velocimetro.empty()) cout << "Velocímetro: " << velocimetro << endl;
    }
    
    virtual void cambiarVelocidad() = 0;
};

// Clase derivada Automovil
class Automovil : public Vehiculo {
private:
    int numeroPuertas;
    int numeroPasajeros;

public:

    Automovil(string m, string mo, int a, int np, int pas, string placa = "", string col = "", string vel = "") 
        : Vehiculo(m, mo, a, placa, col, vel), numeroPuertas(np), numeroPasajeros(pas) {}

 
    void mostrarAutomovil() {
        mostrarDatos();
        cout << "Número de puertas: " << numeroPuertas << endl;
        cout << "Número de pasajeros: " << numeroPasajeros << endl;
    }

    void subirPasajeros() {
        cout << "Subiendo un pasajero..." << endl;
        numeroPasajeros++;
    }

    void bajarPasajeros() {
        cout << "Bajando un pasajero..." << endl;
        if (numeroPasajeros > 0) {
            numeroPasajeros--;
        }
    }

    void cambiarVelocidad() override {
        cout << "El automóvil está cambiando de velocidad." << endl;
    }
};

// Clase derivada Camion
class Camion : public Vehiculo {
private:
    double capacidadCarga;

public:

    Camion(string m, string mo, int a, double cc, string placa = "", string col = "", string vel = "") 
        : Vehiculo(m, mo, a, placa, col, vel), capacidadCarga(cc) {}

    void mostrarCamion() {
        mostrarDatos();
        cout << "Capacidad de carga: " << capacidadCarga << " toneladas" << endl;
    }


    void mostrarCarga() {
        cout << "Mostrando carga del camión..." << endl;
    }

    void cambiarVelocidad() override {
        cout << "El camión está cambiando de velocidad." << endl;
    }
};

int main() {
	
    Automovil auto1("Toyota", "Corolla", 2022, 4, 5, "ABC123", "Rojo", "120 km/h");
    Camion camion1("Volvo", "FH", 2020, 20.5, "XYZ987", "Azul", "80 km/h");

    cout << "Datos del Automóvil:" << endl;
    auto1.mostrarAutomovil();
    auto1.cambiarVelocidad();
    auto1.subirPasajeros();
    auto1.bajarPasajeros();

    cout << endl;

    cout << "Datos del Camión:" << endl;
    camion1.mostrarCamion();
    camion1.cambiarVelocidad();
    camion1.mostrarCarga();

    return 0;
}