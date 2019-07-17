#ifndef CLIENTE_H
#define CLIENTE_H
#include "lista.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include "Persona.h"
struct Resumen{
	string nombrePaseador;
	string fecha;
	string hora;
	int duracion;
	string actividad;
	string observaciones;
};

template <class T>
struct Mascota{
	string nombreMascota;
	int edadMas;
	string raza;
	string tipoConcentrado;
	char tam;
	lista<T> resumen;
};

class Cliente : public Persona{
	private:
		string localidad;
		int calle;
		int carrera;
		int numeroDePerros;
	public:
		Cliente();
		void setLocalidad(string localidad);
		string getLocalidad();
		Resumen resumen;
		Mascota<Resumen> mascota;
		lista< Mascota<Resumen> > listaMascota;
		void setCalle(int calle);
		int getCalle();
		void setCarrera(int carrera);
		int getCarrera();
		void setNumeroDePerros(int numeroDePerros);
		int getNumeroDePerros();
		void setNombrePaseador(string nombrePaseador);
		string getNombrePaseador();
		void setActividad(string actividad);
		string getActividad();
		void setDuracion(int duracion);
		int getDuracion();
		void setFecha(string fecha);
		string getFecha();
		void setHora(string hora);
		string getHora();
		void setObservaciones(string observaciones);
		string getObservaciones();
		void setNombreMascota(string nombreMascota);
		string getNombreMascota();
		void setEdadMas(int edadMas);
		int getEdadMas();
		void setRaza(string raza);
		string getRaza();
		void setTam(char tam);
		char getTam();
		void setTipoConcentrado(string tipoConcentrado);
		string getTipoConcentrado();
};

Cliente::Cliente(){
	localidad = "";
	calle = 0;
	carrera = 0;
}

/*
	Setters
*/
void Cliente::setLocalidad(string localidad){
	this -> localidad = localidad;
} 

void Cliente::setNombrePaseador(string nombrePaseador){
	this -> resumen.nombrePaseador = nombrePaseador;
}
 
void Cliente::setActividad(string actividad){
	this -> resumen.actividad = actividad;
}

void Cliente::setDuracion(int duracion){
	this -> resumen.duracion = duracion;
}

void Cliente::setFecha(string fecha){
	this -> resumen.fecha = fecha;
}

void Cliente::setHora(string hora){
	this -> resumen.hora = hora;
}

void Cliente::setObservaciones(string observaciones){
	this -> resumen.observaciones = observaciones;
}

void Cliente::setNombreMascota(string nombreMascota){
	this -> mascota.nombreMascota = nombreMascota;
}

void Cliente::setEdadMas(int edadMas){
	this -> mascota.edadMas = edadMas;
}

void Cliente::setTipoConcentrado(string tipoConcentrado){
	this -> mascota.tipoConcentrado = tipoConcentrado;
}

void Cliente::setRaza(string raza){
	this -> mascota.raza = raza;
}

void Cliente::setTam(char tam){
	this -> mascota.tam = tam;
}

void Cliente::setCalle(int calle){
	this -> calle = calle;
}

void Cliente::setCarrera(int carrera){
	this -> carrera = carrera;
}

void Cliente::setNumeroDePerros(int numeroDePerros){
	this -> numeroDePerros = numeroDePerros;
}

/*
	Getters
*/
string Cliente::getNombrePaseador(){
	return this -> resumen.nombrePaseador;
}

string Cliente::getLocalidad(){
	return this -> localidad;
}

string Cliente::getActividad(){
	return this -> resumen.actividad;
}

int Cliente::getDuracion(){
	return this -> resumen.duracion;
}

string Cliente::getFecha(){
	return this -> resumen.fecha;
}

string Cliente::getHora(){
	return this -> resumen.hora;
}

string Cliente::getObservaciones(){
	return this -> resumen.observaciones;
}


string Cliente::getNombreMascota(){
	return this -> mascota.nombreMascota;
}

int Cliente::getEdadMas(){
	return this -> mascota.edadMas;
}


string Cliente::getTipoConcentrado(){
	return this -> mascota.tipoConcentrado;
}

string Cliente::getRaza(){
	return this -> mascota.raza;
}

char Cliente::getTam(){
	return this -> mascota.tam;
}

int Cliente::getCalle(){
	return this -> calle;
}

int Cliente::getCarrera(){
	return this -> carrera;
}

int Cliente::getNumeroDePerros(){
	return this -> numeroDePerros;
}


#endif
