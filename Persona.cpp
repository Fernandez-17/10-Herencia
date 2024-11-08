#include <iostream>
#include <string>
using namespace std;
// Clase base de Persona.
class Persona{
	protected:
	    string Nombre;
		string DNI;
		int    Edad;
	public:
	    Persona (string,string,int);
		void MostrarDatos();
};
Persona::Persona(string n,string d ,int e){
	Nombre = n;
	DNI     = d;
	Edad    = e;
	
}
void Persona::MostrarDatos(){
	cout<<"          Datos            \n"<<endl;
	cout<<Nombre<<" tiene el DNI "<<DNI<<" y tiene "<<Edad;
	cout<<" anios de edad."<<endl;
}
// Clase derivada de Docente------------------------------------------------------
class Docente: public Persona{
	protected:
	    int Sueldo;
		string Especialidad;
	public:
		Docente (string,string,int,int,string);
		void MostrarDocente();
		//IngresarNota();
		//VisualizarRegistro();
};
Docente::Docente(string n,string d,int e, int s, string es):Persona(n,d,e){
	Sueldo = s;
	Especialidad = es;
}
void Docente::MostrarDocente(){
	MostrarDatos();
	cout << " \t es un docente con un sueldo de S/ "<< Sueldo;
	cout << " y tiene la especilaidad de: "<< Especialidad <<endl;
}
// Clase derivada de Estudiante.
class Estudiante: public Persona{
	protected:
	    int Notas [5];
		int nNotas;
		string Codigo;
	public:
		Estudiante(string,string,int,int[],int,string);
		void MostrarEstudiante();
		//VisualizarNotas();
};
Estudiante::Estudiante (string n,string d,int e, int no[],int nN, string c): Persona(n,d,e){
	nNotas = nN;
	for (int i=0; i<nN; i++){
		Notas [i] = no[i];
	}
	Codigo = c;
}
 void Estudiante :: MostrarEstudiante(){
 	MostrarDatos(),
 	cout << "\t es un estudiante con codigo "<< Codigo <<" y tiene "<<nNotas<<" notas: ";
 	for (int i=0; i<nNotas; i++){
 		cout<< Notas[i] << "  ";
	}
	cout << endl;
 }
 
int main (){
	string Nombre;
	Persona p("Juan Perez","40302010",25);
	p.MostrarDatos(); cout << endl;
	Docente d("Pablo Iglesias","10203040",54,3000,"Auditoria Informatica");
	d.MostrarDocente();
	cout << endl;
	int nota [] = {20,19,18};
	cout<<"Ingrese el nombre del estudiante: ";fflush (stdin);getline(cin,Nombre);
	Estudiante e(Nombre,"90705060",19,nota,3,"2021-123");
	e.MostrarEstudiante();
	cout << endl;
	return 0;
	
}










