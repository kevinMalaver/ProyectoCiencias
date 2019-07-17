#ifndef PASEADOR_H
#define PASEADOR_H

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include "Persona.h"

struct Horario{
	int horaDeInicio;
	int horaDeSalida;
	int horario[15][7];
};

class Paseador : public Persona{
	private:
		string tipoId;
		string telefono;
		string email;
		int edad;
		string ciudad;
		string pais;
		int calle;
		int carrera;
		string barrio;
		
	public:
		Paseador();
		Horario horario;
		void setTipoId(string tipoId);
		string getTipoId();
		void setTelefono(string telefono);
		string getTelefono();
		void setEmail(string email);
		string getEmail();
		void setEdad(int edad);
		int getEdad();
		void setCiudad(string ciudad);
		string getCiudad();
		void setPais(string pais);
		string getPais();
		void setCalle(int calle);
		int getCalle();
		void setCarrera(int carrera);
		int getCarrera();
		void setBarrio(string barrio);
		string getBarrio();
		void setHoraDeInicio(int horaDeInicio);
		int getHoraDeInicio();
		void setHoraDeSalida(int horaDeSalida);
		int getHoraDeSalida();
		void editarHorario(int HoraDeInicioDePaseo, int HoraDeFinDePaseo, string dia);
		void mostrarHorario();
		void inicializarHorario();
};

Paseador::Paseador(){
	this -> tipoId = "";
	this -> telefono = "";
	this -> email = "";
	this -> edad = 0;
	this -> ciudad = "";
	this -> pais = "";
	this -> calle = 0;
	this -> carrera = 0;
	this -> barrio = "";
	for (int i = 0 ; i<15;i++){
		for(int j = 0; j<7; j++){

			this -> horario.horario[i][j] = 0;
		}
	}
}

void Paseador::setTipoId(string tipoId){
	this -> tipoId = tipoId;
}

string Paseador::getTipoId(){
	return this -> tipoId;
}

void Paseador::setTelefono(string telefono){
	this -> telefono = telefono;
}

string Paseador::getTelefono(){
	return this -> telefono;
}

void Paseador::setEmail(string email){
	this -> email = email;
}

string Paseador::getEmail(){
	return this -> email;
}

void Paseador::setEdad(int edad){
	this -> edad = edad;
}

int Paseador::getEdad(){
	return this -> edad;
}

void Paseador::setCiudad(string ciudad){
	this -> ciudad = ciudad;
}

string Paseador::getCiudad(){
	return this -> ciudad;
}

void Paseador::setPais(string pais){
	this -> pais = pais;
}

string Paseador::getPais(){
	return this -> pais;
}

void Paseador::setCalle(int calle){
	this -> calle = calle;
}

int Paseador::getCalle(){
	return this -> calle;
}

void Paseador::setCarrera(int carrera){
	this -> carrera = carrera;
}

int Paseador::getCarrera(){
	return this -> carrera;
}

void Paseador::setBarrio(string barrio){
	this -> barrio = barrio;
}

string Paseador::getBarrio(){
	return this -> barrio;
}

void Paseador::setHoraDeInicio(int horaDeInicio){
	this -> horario.horaDeInicio = horaDeInicio;
}

int Paseador::getHoraDeInicio(){
	return this -> horario.horaDeInicio;
}

void Paseador::setHoraDeSalida(int horaDeSalida){
	this -> horario.horaDeSalida = horaDeSalida;
}

int Paseador::getHoraDeSalida(){
	return this -> horario.horaDeSalida;
}

void Paseador::editarHorario(int HoraDeInicioDePaseo, int HoraDeFinDePaseo,string dia){
	int aux = 0;
	if(dia=="lunes" || dia=="Lunes"){
		aux = 0;
	}
	if(dia=="martes" || dia=="Martes"){
		aux = 1;
	}
	if(dia=="miercoles" || dia=="Miercoles"){
		aux = 2;
	}
	if(dia=="jueves" || dia=="Jueves"){
		aux = 3;
	}
	if(dia=="viernes" || dia=="Viernes"){
		aux = 4;
	}
	if(dia=="sabado" || dia=="Sabado"){
		aux = 5;
	}
	if(dia=="domingo" || dia=="Domingo"){
		aux = 6;
	}
	for(int i =  HoraDeInicioDePaseo - this -> getHoraDeInicio(); i< HoraDeFinDePaseo - this -> getHoraDeInicio(); i++){
		this -> horario.horario[i][aux] = 1;
	}
	
}
void Paseador::inicializarHorario(){

	for (int i = 0 ; i<13;i++){
		for(int j = 0; j<7; j++){
			this -> horario.horario[i][j] = 0;
		}
	}
}

void Paseador::mostrarHorario(){
	if(this -> getHoraDeSalida() == 0){
		this -> setHoraDeSalida(20);
		this -> setHoraDeInicio(6); 
	}
	char dias[8] = {'H','L','M','M','J','V','S','D'};
	for(int i = 0; i<= this -> getHoraDeSalida() - this -> getHoraDeInicio(); i++){
		if(i == 0){
			for(int k = 0;k< 8;k++){
				cout<<dias[k]<<" ";
			}
			cout<<"\n";
		}
		for(int j = 0;j< 7;j++){
			
			if(j == 0){
				cout<<getHoraDeInicio() + i<<" ";
			}
			cout<<this -> horario.horario[i][j]<<" ";
		}
		cout<<"\n";
	}
}


#endif
