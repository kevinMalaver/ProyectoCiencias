/*

*/
#include <iostream>  
#include <time.h>
#include "arbolLocalidades.h"
#include "Localidad.h"
#include "Paseador.h"
#include "Cliente.h"
#include "Fecha.h"
#include "lista.h"

using namespace std;


template<class S,class P,class C>
struct InfLocalidades{
	char* nombre;
	int calleInicio,calleFin,carreraInicio,carreraFin; 
	lista<S> sucursales;
	lista<P> paseadores;
	lista<C> clientes;
};

template<class P,class C>
struct Sucursal{
	string nombre,nombreGerente;
	int calleInicio,calleFin,carreraInicio,carreraFin; 
	lista<P> paseadores;
	lista<C> clientes;
/*
	cliente.mascota.resumen.insertar_inicio(cliente.resumen);
	cliente.listaMascota.insertar_inicio(cliente.mascota);
	sucursal.clientes.insertar_inicio(cliente);
	sucursal.paseadores.insertar_inicio(paseador);
	listaSucursal.insertar_inicio(sucursal);
	InfLocalidades[7].sucursales.insertar_final(sucursal)
*/	
};


time_t theTime = time(NULL);
struct tm *aTiempo = localtime(&theTime);

bool es_numero(string s){
   for(int i = 0; i < s.length(); i++)
      if(! (s[i] >= '0' && s[i] <= '9' || s[i] == ' ') ) 
			return false;
   return true;
}

int desplegarMenuModificacionDatos(){
	int opc;
	do{
		cout<<"Presione: "<<endl;
		cout<<"1. Para menu de Clientes"<<endl;
		cout<<"2. Para menu de Sucursales"<<endl;
		cout<<"3. Para menu de Paseadores"<<endl;
		cin>>opc;	
	}while(opc<1||opc>3);
	return opc;   
}
int desplegarSubMenuModificacionDatos(){
	int opc; 
	do{
		cout<<"Presione: "<<endl;
		cout<<"1. Para ingresar "<<endl;
		cout<<"2. Para eliminar"<<endl;
		cout<<"3. Para editar"<<endl;
		cin>>opc;
	}while(opc<1||opc>3);
	return opc;
}
int desplegarMenuConsultas(){
	int opc;
	do{
		cout<<"Presione: "<<endl;
		cout<<"1. Para ingresar un area y observar las sucursales que podrian hacerse cargo de perros"<<endl;
		cout<<"2. Para ingresar un horario y localidad y mostrar los paseadores que podrian estar disponibles"<<endl;
		cout<<"3. Para ingresar un horario y un cliente y mostrar los paseadores que podrian hacerse cargo de sus perros"<<endl;
		cout<<"4. Para ingresar una localidad y una raza de perro y mostrar todos los clientes que poseen perros de dicha raza"<<endl;
		cout<<"5. Para ingresar un paseador y un rango de tiempo y mostrar toda la informacion de los perros paseados por dicho paseador"<<endl;
		cout<<"6. Para ingresar un perro y un rango de tiempo y mostrar toda la informacion de sus paseos"<<endl; 
		cout<<"7. Para ingresar una localidad y un tamano para mostrar los perros de dicho tamano adscritos a la localidad"<<endl;
		cout<<"8. Para ingresar un rango de edad y mostrar la informacion de los perros pertenecientes al rango"<<endl;
		cout<<"9. Lista de Clientes"<<endl;
		cout<<"10. Lista de Paseadores"<<endl;
		cout<<"11. Lista Clientes Y Paseadores de una localidad"<<endl;
		cin>>opc;
	}while(opc<1||opc>11);
	return opc; 
}

int hallarEdad(int ano){
	return 2019 - ano;	   
}	

/*


void paseadoresDispo(int horaInicio, int horaFin, string dia,string nombreLocalidad){
	for(int j = 1; j<=LOCALIDADES[bucarPosDeLocalidad(nombreLocalidad)].paseadores.get_tam();j++){
		if((LOCALIDADES[bucarPosDeLocalidad(nombreLocalidad)].paseadores.buscar(j).getHoraDeInicio() >= horaInicio) &&
			(LOCALIDADES[bucarPosDeLocalidad(nombreLocalidad)].paseadores.buscar(j).getHoraDeSalida() <= horaFin)){
			cout<<LOCALIDADES[bucarPosDeLocalidad(nombreLocalidad)].paseadores.buscar(j).getId()<<" ";
			cout<<LOCALIDADES[bucarPosDeLocalidad(nombreLocalidad)].paseadores.buscar(j).getNombre()<<" ";
			cout<<LOCALIDADES[bucarPosDeLocalidad(nombreLocalidad)].paseadores.buscar(j).getApellido()<<"\n";
		}
	}
}


void paseadoresClientes(string raza,string nombreLocalidad){
	for(int k = 0; k <LOCALIDADES[bucarPosDeLocalidad(nombreLocalidad)].clientes.get_tam();k++){
		for(int i= 0; i <LOCALIDADES[bucarPosDeLocalidad(nombreLocalidad)].clientes.buscar(i).listaMascota.get_tam();i++){
			if(LOCALIDADES[bucarPosDeLocalidad(nombreLocalidad)].clientes.buscar(i).mascota.raza == raza){
				cout<<LOCALIDADES[bucarPosDeLocalidad(nombreLocalidad)].clientes.buscar(k).getId()<<" ";
				cout<<LOCALIDADES[bucarPosDeLocalidad(nombreLocalidad)].clientes.buscar(k).getNombre()<<" ";
				cout<<LOCALIDADES[bucarPosDeLocalidad(nombreLocalidad)].clientes.buscar(k).getApellido()<<"\n";	
			}
		}		
	}
}
*/

InfLocalidades< Sucursal<Paseador, Cliente>, Paseador, Cliente >  LOCALIDADES[17];
Paseador paseador;
Cliente cliente;
Sucursal< Paseador, Cliente> sucursal;
lista< Sucursal<Paseador, Cliente> > listaSucursal;
lista<Cliente> listaClientes;
lista<Paseador> listaPaseador;

int main(int argc, char **argv) { 
	   
	LOCALIDADES[0].nombre = "Suba"; LOCALIDADES[0].calleInicio = 247; LOCALIDADES[0].calleFin = 100; LOCALIDADES[0].carreraInicio = 24; LOCALIDADES[0].carreraFin = 1; 
	LOCALIDADES[1].nombre = "Chapinero"; LOCALIDADES[1].calleInicio = 99; LOCALIDADES[1].calleFin = 39; LOCALIDADES[1].carreraInicio = 14; LOCALIDADES[1].carreraFin = 1; 
	LOCALIDADES[2].nombre = "Santa_fe"; LOCALIDADES[2].calleInicio = 38; LOCALIDADES[2].calleFin = 1; LOCALIDADES[2].carreraInicio = 14; LOCALIDADES[2].carreraFin = 1; 
	LOCALIDADES[3].nombre = "San_cristobal"; LOCALIDADES[3].calleInicio = -1; LOCALIDADES[3].calleFin = -53; LOCALIDADES[3].carreraInicio = 10; LOCALIDADES[3].carreraFin = -13; 
	LOCALIDADES[4].nombre = "Usme"; LOCALIDADES[4].calleInicio = -54; LOCALIDADES[4].calleFin = -116; LOCALIDADES[4].carreraInicio = 5; LOCALIDADES[4].carreraFin = -13; 
	LOCALIDADES[5].nombre = "Rafael_Uribe"; LOCALIDADES[5].calleInicio = -22; LOCALIDADES[5].calleFin = -53; LOCALIDADES[5].carreraInicio = 30; LOCALIDADES[5].carreraFin = 11; 
	LOCALIDADES[6].nombre = "Antonio_Narino"; LOCALIDADES[6].calleInicio = -1; LOCALIDADES[6].calleFin = -21; LOCALIDADES[6].carreraInicio = 30; LOCALIDADES[6].carreraFin = 11; 
	LOCALIDADES[7].nombre = "Martires"; LOCALIDADES[7].calleInicio = 26; LOCALIDADES[7].calleFin = 1; LOCALIDADES[7].carreraInicio = 30; LOCALIDADES[7].carreraFin = 15; 
	LOCALIDADES[8].nombre = "Teusaquillo"; LOCALIDADES[8].calleInicio = 63; LOCALIDADES[8].calleFin = 27; LOCALIDADES[8].carreraInicio = 68; LOCALIDADES[8].carreraFin = 15; 
	LOCALIDADES[9].nombre = "Barrios_unidos"; LOCALIDADES[9].calleInicio = 99; LOCALIDADES[9].calleFin = 64; LOCALIDADES[9].carreraInicio = 68; LOCALIDADES[9].carreraFin = 15; 
	LOCALIDADES[10].nombre = "Suba"; LOCALIDADES[10].calleInicio = 247; LOCALIDADES[10].calleFin = 100; LOCALIDADES[10].carreraInicio = 160; LOCALIDADES[10].carreraFin = 25; 
	LOCALIDADES[11].nombre = "Engativa"; LOCALIDADES[11].calleInicio = 99; LOCALIDADES[11].calleFin = 26; LOCALIDADES[11].carreraInicio = 126; LOCALIDADES[11].carreraFin = 69; 
	LOCALIDADES[12].nombre = "Puente_aranda"; LOCALIDADES[12].calleInicio = 26; LOCALIDADES[12].calleFin = -45; LOCALIDADES[12].carreraInicio = 68; LOCALIDADES[12].carreraFin = 31; 
	LOCALIDADES[13].nombre = "Tunjuelito"; LOCALIDADES[13].calleInicio = -46; LOCALIDADES[13].calleFin = -56; LOCALIDADES[13].carreraInicio = 68; LOCALIDADES[13].carreraFin = 31; 
	LOCALIDADES[14].nombre = "Bosa"; LOCALIDADES[14].calleInicio = -57; LOCALIDADES[14].calleFin = -88; LOCALIDADES[14].carreraInicio = 107; LOCALIDADES[14].carreraFin = 63; 
	LOCALIDADES[15].nombre = "Kennedy"; LOCALIDADES[15].calleInicio = 17; LOCALIDADES[15].calleFin = -56; LOCALIDADES[15].carreraInicio = 107; LOCALIDADES[15].carreraFin = 69; 
	LOCALIDADES[16].nombre = "Fontibon"; LOCALIDADES[16].calleInicio = 25; LOCALIDADES[16].calleFin = 18; LOCALIDADES[16].carreraInicio = 138; LOCALIDADES[16].carreraFin = 69; 

	arbolLocalidades arbolAVLLocal;
	
		         
	for(int i=0;i<17;i++){
		arbolAVLLocal.agregarLocalidad(LOCALIDADES[i].nombre,
									   LOCALIDADES[i].calleInicio,
									   LOCALIDADES[i].calleFin,
									   LOCALIDADES[i].carreraInicio,
									   LOCALIDADES[i].carreraFin
									   ); 		
	}
	
	int opc = 0;
	const size_t BUFFER_SIZE = 1024;
	char *texto = new char[BUFFER_SIZE];
	cliente.setNombre("Kevin");
	cliente.setId("100");
	cliente.setCalle(60);
	cliente.setCarrera(60);
	cliente.setLocalidad("Bosa");
	cliente.setNombreMascota("Pepe");
	cliente.setRaza("Dalmata");
	cliente.setEdadMas(5);
	cliente.listaMascota.insertar_final(cliente.mascota);
	for(int i = 0; i<17;i++){
		if(cliente.getLocalidad() == LOCALIDADES[i].nombre){
			cout<<"hola\n";
			LOCALIDADES[i].clientes.insertar_final(cliente);
		}
	}
	listaClientes.insertar_final(cliente);
	
	paseador.setNombre("Esteban");
	paseador.setId("101");
	paseador.setCalle(60);
	paseador.setCarrera(60);
	paseador.setBarrio("Bosa");
	paseador.setHoraDeInicio(8);
	paseador.setHoraDeSalida(16);
	for(int i = 0; i<17;i++){
		if(paseador.getBarrio() == LOCALIDADES[i].nombre){
			cout<<"hola\n";
			LOCALIDADES[i].paseadores.insertar_final(paseador);
		}
	}
	listaPaseador.insertar_final(paseador);
	
	sucursal.nombre = "Marly";
	sucursal.calleInicio= 40;
	sucursal.calleFin=80;
	sucursal.carreraInicio=40;
	sucursal.carreraFin=80;
	for(int j = 1; j<=listaClientes.get_tam();j++){
		if(((listaClientes.buscar(j).getCalle() <= sucursal.calleInicio) && (listaClientes.buscar(j).getCalle() >= sucursal.calleFin)) ||
		((listaClientes.buscar(j).getCarrera() <= sucursal.calleFin) && (listaClientes.buscar(j).getCarrera() >= sucursal.carreraFin)))
		{
			sucursal.clientes.insertar_final(listaClientes.buscar(j));
		}
	}
	for(int j = 1; j<=listaClientes.get_tam();j++){
		if(((listaPaseador.buscar(j).getCalle() <= sucursal.calleInicio) && (listaPaseador.buscar(j).getCalle() >= sucursal.calleFin)) ||
		((listaPaseador.buscar(j).getCarrera() <= sucursal.calleFin) && (listaPaseador.buscar(j).getCarrera() >= sucursal.carreraFin)))
		{
			sucursal.paseadores.insertar_final(listaPaseador.buscar(j));
		}
	}
	listaSucursal.insertar_final(sucursal);
	
	
	do{
		int horaInicio,horaFin,calleInicio,calleFin,carreraInicio,carreraFin,edadMinima,edadMaxima;
		string nombreLocalidad, dia, raza,idCliente, nombrePerro, idPaseador;
		cout<<"Bienvenido al software de Paseadores de perros Cesar Millan :V"<<endl;
		cout<<"Menu: Seleccione"<<endl<<"1. Para realizar consultas"<<endl;
		cout<<"2. Para ingresar, editar o eliminar informacion"<<endl;
		cout<<"3. Para realizar la simulacion de paseo de perros"<<endl;
		cout<<"4. Para salir del programa"<<endl; 
		cin>>opc;
		switch(opc){
			case 1:{
				switch(desplegarMenuConsultas()){
					case 1:{
						cout<<"Ingrese calle de inicio:\n";
						cin>>calleInicio;
						cout<<"Ingrese calle de Finalizacion:\n";
						cin>>calleFin;
						cout<<"Ingrese carrera de inicio:\n";
						cin>>carreraInicio;
						cout<<"Ingrese carrera de Finalizacion:\n";
						cin>>carreraFin;
						for(int i = 1; i<=listaSucursal.get_tam(); i++){							
							if((listaSucursal.buscar(i).calleInicio <= calleInicio && listaSucursal.buscar(i).calleFin >=calleInicio) ||
								(listaSucursal.buscar(i).calleInicio <= calleFin && listaSucursal.buscar(i).calleFin >= calleFin) ||
								(listaSucursal.buscar(i).carreraInicio <= carreraInicio && listaSucursal.buscar(i).carreraFin >= carreraInicio) ||
								(listaSucursal.buscar(i).carreraInicio <= carreraFin && listaSucursal.buscar(i).carreraFin>= carreraFin)){
								cout<<listaSucursal.buscar(i).nombre<<"\n";
							}
						}
						break;
					}
					case 2:{
						cout<<"Ingrese Hora de inicio:\n";
						cin>>horaInicio;
						cout<<"Ingrese Hora de Finalizacion:\n";
						cin>>horaFin;
						cout<<"Ingrese Dia:\n";
						cin>>dia;
						cout<<"Ingrese Localidad:\n";
						cin>>nombreLocalidad;
						for(int i = 0; i<17;i++){
							if(nombreLocalidad == LOCALIDADES[i].nombre){
								for(int j = 1; j<=LOCALIDADES[i].paseadores.get_tam();j++){
									if((LOCALIDADES[i].paseadores.buscar(j).getHoraDeInicio() <= horaInicio) &&
									(LOCALIDADES[i].paseadores.buscar(j).getHoraDeSalida() >= horaFin)){
										cout<<LOCALIDADES[i].paseadores.buscar(j).getId()<<" ";
										cout<<LOCALIDADES[i].paseadores.buscar(j).getNombre()<<" ";
										cout<<LOCALIDADES[i].paseadores.buscar(j).getApellido()<<"\n";
									}
								}
							}
						}
											
						break;
					}
					case 3:{
						cout<<"Ingrese ID de Cliente:\n";
						cin>>idCliente;
						cout<<"Ingrese Hora de inicio:\n";
						cin>>horaInicio;
						cout<<"Ingrese Hora de Finalizacion:\n";
						cin>>horaFin;
						
						for(int i = 0; i<17;i++){
							for(int k = 1;k<=LOCALIDADES[i].clientes.get_tam();k++){
								if(LOCALIDADES[i].clientes.buscar(k).getId() == idCliente){
									for(int j = 1; j<=LOCALIDADES[i].paseadores.get_tam();j++){
										if((LOCALIDADES[i].paseadores.buscar(j).getHoraDeInicio() <= horaInicio) &&
										(LOCALIDADES[i].paseadores.buscar(j).getHoraDeSalida() >= horaFin)){
											cout<<LOCALIDADES[i].paseadores.buscar(j).getId()<<" ";
											cout<<LOCALIDADES[i].paseadores.buscar(j).getNombre()<<" ";
											cout<<LOCALIDADES[i].paseadores.buscar(j).getApellido()<<"\n";
										}
									}
								}
							}
						}
						
						break;
					}
					case 4:{
						cout<<"Ingrese Localidad:\n";
						cin>>nombreLocalidad;
						cout<<"Ingrese raza:\n";
						cin>>raza;
						for(int i = 0; i<17;i++){
							if(nombreLocalidad == LOCALIDADES[i].nombre){
								for(int k = 1; k <=LOCALIDADES[i].clientes.get_tam();k++){
									for(int j= 1; j <=LOCALIDADES[i].clientes.buscar(k).listaMascota.get_tam();j++){
										if(LOCALIDADES[i].clientes.buscar(k).listaMascota.buscar(j).raza == raza){
											cout<<LOCALIDADES[i].clientes.buscar(k).getId()<<" ";
											cout<<LOCALIDADES[i].clientes.buscar(k).getNombre()<<" ";
											cout<<LOCALIDADES[i].clientes.buscar(k).getApellido()<<"\n";	
										}
									}		
								}
							}
						}
						break;
					}
					case 5:{
						
						break;
					}
					case 6:{
						/*
						cout<<"Ingrese Nombre del perro:\n";
						cin>>nombrePerro;
						for(int i = 1; i<= listaClientes.get_tam(); i++){
							for(int j = 1; j <= listaClientes.buscar(i).listaMascota.get_tam(); j++){
								if(listaClientes.buscar(i).listaMascota.buscar(j).nombreMascota == nombrePerro){
									for(int k = 1; k < listaClientes.buscar(i).listaMascota.buscar(j).resumen.get_tam(); k++){
										cout<<listaClientes.buscar(i).listaMascota.buscar(j).resumen.buscar(k).fecha<<" ";
										cout<<listaClientes.buscar(i).listaMascota.buscar(j).resumen.buscar(k)<<" ";
										cout<<listaClientes.buscar(i).listaMascota.buscar(j).resumen.buscar(k)<<"\n";
									}
								}
							
						}*/
						break;
					}
					case 7:{
						
						cout<<"Ingrese Localidad:\n";
						cin>>nombreLocalidad;
						for(int i = 0; i<17;i++){
							if(nombreLocalidad == LOCALIDADES[i].nombre){
								for(int k = 1; k <=LOCALIDADES[i].clientes.get_tam();k++){
									for(int j= 1; j <=LOCALIDADES[i].clientes.buscar(k).listaMascota.get_tam();j++){
										cout<<LOCALIDADES[i].clientes.buscar(k).listaMascota.buscar(j).nombreMascota<<"\n";	
									}
								}		
							}
						}
						break;
					}
					case 9:{
						string encaCliente[8] = {"id","Nombre","Apellido","Genero","Localidad","Calle","Carrera","NumeroDePerros"};
						for(int i = 1; i<=listaClientes.get_tam();i++){
							if(i == 1){
								for(int k = 0;k< 8;k++){
									cout<<encaCliente[k]<<"\t";
								}
								cout<<"\n";
							}
							cout<<listaClientes.buscar(i).getId()<<"\t";
							cout<<listaClientes.buscar(i).getNombre()<<"\t";
							cout<<listaClientes.buscar(i).getApellido()<<"\t";
							cout<<listaClientes.buscar(i).getGenero()<<"\t";
							cout<<listaClientes.buscar(i).getLocalidad()<<"\t";
							cout<<listaClientes.buscar(i).getCalle()<<"\t";
							cout<<listaClientes.buscar(i).getCarrera()<<"\t";
							cout<<listaClientes.buscar(i).getNumeroDePerros()<<"\n";
						}
						}
						break;
					case 10:{
						string encaCliente[7] = {"id","Nombre","Apellido","Telefono","Localidad","Calle","Carrera"};
						for(int i = 1; i<=listaPaseador.get_tam();i++){
							if(i == 1){
								for(int k = 0;k< 7;k++){
									cout<<encaCliente[k]<<"\t";
								}
								cout<<"\n";
							}
							cout<<listaPaseador.buscar(i).getId()<<"\t";
							cout<<listaPaseador.buscar(i).getNombre()<<"\t";
							cout<<listaPaseador.buscar(i).getApellido()<<"\t";
							cout<<listaPaseador.buscar(i).getTelefono()<<"\t";
							cout<<listaPaseador.buscar(i).getBarrio()<<"\t";
							cout<<listaPaseador.buscar(i).getCalle()<<"\t";
							cout<<listaPaseador.buscar(i).getCarrera()<<"\n";
						}
						}
						break;
					case 8:{
						cout<<"Ingrese Edad minima:\n";
						cin>>edadMinima;
						cout<<"Ingrese Edad maxima:\n";
						cin>>edadMaxima;
						for(int i = 0; i<17;i++){
								for(int k = 1; k <=LOCALIDADES[i].clientes.get_tam();k++){
									for(int j= 1; j <=LOCALIDADES[i].clientes.buscar(k).listaMascota.get_tam();j++){
										if((LOCALIDADES[i].clientes.buscar(k).listaMascota.buscar(j).edadMas >= edadMinima) &&
										(LOCALIDADES[i].clientes.buscar(k).listaMascota.buscar(j).edadMas<= edadMaxima)){
											cout<<LOCALIDADES[i].clientes.buscar(k).getNombre()<<" ";
											cout<<LOCALIDADES[i].clientes.buscar(k).listaMascota.buscar(j).nombreMascota<<" ";
											cout<<LOCALIDADES[i].clientes.buscar(k).listaMascota.buscar(j).edadMas<<" ";
											cout<<LOCALIDADES[i].nombre<<"\n";
											
										}	
									}
								}		
							}
						}
						break;
					
					case 11:{
						cout<<"Ingrese Localidad:\n";
						cin>>nombreLocalidad;
						string encaCliente[8] = {"id","Nombre","Apellido","Genero","Localidad","Calle","Carrera","NumeroDePerros"};
						for(int j = 0; j<17;j++){
							if(LOCALIDADES[j].nombre == nombreLocalidad){
								for(int i = 1; i<=LOCALIDADES[j].clientes.get_tam();i++){
									if(i == 1){
										cout<<"Clientes "<<LOCALIDADES[j].nombre<<"\n";
										for(int k = 0;k< 8;k++){
											cout<<encaCliente[k]<<"\t";
										}
										cout<<"\n";
									}
									cout<<LOCALIDADES[j].clientes.buscar(i).getId()<<"\t";
									cout<<LOCALIDADES[j].clientes.buscar(i).getNombre()<<"\t";
									cout<<LOCALIDADES[j].clientes.buscar(i).getApellido()<<"\t";
									cout<<LOCALIDADES[j].clientes.buscar(i).getGenero()<<"\t";
									cout<<LOCALIDADES[j].clientes.buscar(i).getLocalidad()<<"\t";
									cout<<LOCALIDADES[j].clientes.buscar(i).getCalle()<<"\t";
									cout<<LOCALIDADES[j].clientes.buscar(i).getCarrera()<<"\t";
									cout<<LOCALIDADES[j].clientes.buscar(i).getNumeroDePerros()<<"\n";
								}
							}
						}
						string encaCliente2[7] = {"id","Nombre","Apellido","Telefonoo","Localidad","Calle","Carrera"};
						for(int j = 0; j<17;j++){
							if(LOCALIDADES[j].nombre == nombreLocalidad){
								for(int i = 1; i<=LOCALIDADES[j].paseadores.get_tam();i++){
									if(i == 1){
										for(int k = 0;k< 7;k++){
											cout<<encaCliente[k]<<"\t";
										}
										cout<<"\n";
									}
									cout<<LOCALIDADES[j].paseadores.buscar(i).getId()<<"\t";
									cout<<LOCALIDADES[j].paseadores.buscar(i).getNombre()<<"\t";
									cout<<LOCALIDADES[j].paseadores.buscar(i).getApellido()<<"\t";
									cout<<LOCALIDADES[j].paseadores.buscar(i).getTelefono()<<"\t";
									cout<<LOCALIDADES[j].paseadores.buscar(i).getBarrio()<<"\t";
									cout<<LOCALIDADES[j].paseadores.buscar(i).getCalle()<<"\t";
									cout<<LOCALIDADES[j].paseadores.buscar(i).getCarrera()<<"\n";
								}
							}
						}
					}
					break;
				}
			}
			break;
			case 2:{
				int tipoDato;
				tipoDato = desplegarMenuModificacionDatos();
													 
				switch(tipoDato){
					case 1:{
						cout<<"1";
						switch(desplegarSubMenuModificacionDatos()){
							case 1:{
								int calle,carrera;
								Cliente cliente;
								cout<<"Ingrese el nombre: ";
								texto =  new char[BUFFER_SIZE];
								cin>>texto;
								cliente.setNombre(texto);
								
								cout<<endl<<"Ingrese el apellido: ";
								texto =  new char[BUFFER_SIZE];
								cin>>texto;
								cliente.setApellido(texto);
								
								do{
									cout<<endl<<"Ingrese el numero de Cedula: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;
									if(!es_numero(texto)){
										cout<<"debe ingresar numeros"<<endl;
									}
								}while(!es_numero(texto));
								//VERIFICAR QUE SEA UNICO!!!
							    cliente.setId(texto);
								
								do{
									cout<<"Seleccione una opcion para ingresar su genero:"<<endl;
									cout<<"1. Femenino"<<endl;
									cout<<"2. Masculino"<<endl;
									cin>>opc; 
								}while(opc<1||opc>2);
								if(opc==1)
									cliente.setGenero("F");
								else
									cliente.setGenero("M");
								
								bool localidadValida; 
								do{
									localidadValida = true;
									cout<<endl<<"Ingrese el nombre de la localidad: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;  
									if(!arbolAVLLocal.localidadExiste(texto)){
										cout<<"Localidad no encontrada"<<endl;
										localidadValida = false; 
									}
								}while(!localidadValida);
								
								cliente.setLocalidad(texto);
								
								bool ubicacionValida; 
								do{
									ubicacionValida = true; 
									cout<<endl<<"Ingrese la calle de residencia: ";
									cin>>calle;
									
									cout<<endl<<"Ingrese la carrera de residencia: ";
									cin>>carrera;
									
									if(!arbolAVLLocal.ubicacionExiste(calle,carrera)){
										cout<<"Direccion no valida"<<endl;
										ubicacionValida = false; 
									}
										
								}while(!ubicacionValida);
								
								cliente.setCalle(calle);
								cliente.setCarrera(carrera); 
								
								int cantidadPerros;
								cout<<"Ingrese la cantidad de perros: ";
								cin>>cantidadPerros; 	
								for(int i=1;i<=cantidadPerros;i++){
									cout<<"Perro Numero: "<<i<<endl;
									cout<<"Ingrese el nombre: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto; 
									cliente.setNombreMascota(texto);
									cout<<"Ingrese la fecha de nacimiento Dia ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;
									cout<<"Ingrese la fecha de nacimiento Mes ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto; 
									cout<<"Ingrese la fecha de nacimiento ano ";
									int ano;
									cin>>ano;  
									cliente.setEdadMas(hallarEdad(ano));
									cout<<"Ingrese la raza: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto; 
									cliente.setRaza(texto);
									do{
										cout<<"Seleccione una opcion para ingresar su tamanio:"<<endl;
										cout<<"1. Pequenio"<<endl;
										cout<<"2. Mediano"<<endl;
										cout<<"3. Grande"<<endl;
										cin>>opc; 
									}while(opc<1||opc>3);
									switch(opc){
										case 1:{
											cliente.setTam('p');
											break;
										}
										case 2:{
											cliente.setTam('m');
											break;
										}
										case 3:{
											cliente.setTam('g');
											break;
										}
									}
									cout<<"Ingrese el tipo de concentrado de consume: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto; 
									cliente.setTipoConcentrado(texto); 
									cliente.listaMascota.insertar_final(cliente.mascota); 
								}
								
								for(int i = 0; i<17;i++){
									if(cliente.getLocalidad() == LOCALIDADES[i].nombre){
										LOCALIDADES[i].clientes.insertar_final(cliente);
									}
								}
								/*
								for(int i = 1; i<=listaSucursal.get_tam();i++){
									if(((cliente.getCalle() <= listaSucursal.buscar(i).calleInicio) && (cliente.getCalle() >= listaSucursal.buscar(i).calleFin)) ||
									((cliente.getCarrera() <= listaSucursal.buscar(i).calleFin) && (cliente.getCarrera() >= listaSucursal.buscar(i).carreraFin)))
									{
										listaSucursal.buscar(i).clientes.insertar_final(cliente);
									}
								}*/
								listaClientes.insertar_final(cliente);
								/*
								for(int i = 1; i<=listaSucursal.get_tam();i++){
									for(int i = 1; i<=listaSucursal.get_tam();i++){
									listaSucursal.buscar(i).clientes.
								}*/
								break;
							}
							case 2:{
								cout<<"Ingrese ID de Cliente que desea eliminar:\n";
								cin>>idCliente;
								int aux;
								
								for(int i = 1; i<=listaClientes.get_tam();i++){
									if(listaClientes.buscar(i).getId() == idCliente){
										aux = i;
									}
								}
								listaClientes.borrar_nodo(aux);
								for(int i = 1; i<=listaSucursal.get_tam();i++){
									for(int j = 1; j<=listaSucursal.get_tam();j++){
										if(listaSucursal.buscar(i).clientes.buscar(j).getId()==idCliente){
											aux = j;
										}
									}
									listaSucursal.buscar(i).clientes.borrar_nodo(aux);
								}
								for(int i = 0; i<17;i++){
									for(int j = 1; j<=LOCALIDADES[i].clientes.get_tam();j++){
										if(LOCALIDADES[i].clientes.buscar(j).getId() == idCliente){
											LOCALIDADES[i].clientes.borrar_nodo(j);
										}
									}
								}
								
								break;
							}
							case 3:{
								//Editar cliente
								break;
							}
						}
						break;
					}
					case 2:{
						
						cout<<"2";
						switch(desplegarSubMenuModificacionDatos()){
							case 1:{
								//Crear sucursal
								for(int j = 1; j<=listaClientes.get_tam();j++){
									if(((listaClientes.buscar(j).getCalle() <= sucursal.calleInicio) && (listaClientes.buscar(j).getCalle() >= sucursal.calleFin)) ||
									((listaClientes.buscar(j).getCarrera() <= sucursal.calleFin) && (listaClientes.buscar(j).getCarrera() >= sucursal.carreraFin)))
									{
										sucursal.clientes.insertar_final(listaClientes.buscar(j));
									}
								}
								for(int j = 1; j<=listaClientes.get_tam();j++){
									if(((listaPaseador.buscar(j).getCalle() <= sucursal.calleInicio) && (listaPaseador.buscar(j).getCalle() >= sucursal.calleFin)) ||
									((listaPaseador.buscar(j).getCarrera() <= sucursal.calleFin) && (listaPaseador.buscar(j).getCarrera() >= sucursal.carreraFin)))
									{
										sucursal.paseadores.insertar_final(listaPaseador.buscar(j));
									}
								}
								listaSucursal.insertar_final(sucursal);	
								for(int i = 0; i<17;i++){
									for(int j = 0; j <listaSucursal.get_tam(); j++){
										if((((listaSucursal.buscar(j).calleFin + listaSucursal.buscar(j).calleInicio)/2)>= LOCALIDADES[i].calleInicio) && (((listaSucursal.buscar(j).calleFin + listaSucursal.buscar(j).calleInicio)/2)<= LOCALIDADES[i].calleFin) ||
											(((listaSucursal.buscar(j).carreraInicio +listaSucursal.buscar(j).carreraFin)/2)>=LOCALIDADES[i].carreraInicio) && (((listaSucursal.buscar(j).carreraInicio + listaSucursal.buscar(j).carreraFin)/2)>=LOCALIDADES[i].carreraFin)){
											LOCALIDADES[i].sucursales.insertar_final(listaSucursal.buscar(j));
										}
									}
								}
								
								break;
							}
							case 2:{
								//Borrar sucursal
								break;
							}
							case 3:{
								//Editar sucursal
								break;
							}
						}
						break;
					}

					case 3:{
						
						cout<<"3";
						switch(desplegarSubMenuModificacionDatos()){
							case 1:{
								int dia,mes,anio;
								int calle, carrera; 
								Paseador paseador;
								cout<<"Ingrese el nombre: ";
								texto =  new char[BUFFER_SIZE];
								cin>>texto;
								paseador.setNombre(texto);
								cout<<endl<<"Ingrese el apellido: ";
								texto =  new char[BUFFER_SIZE];
								cin>>texto;
								paseador.setApellido(texto);
								do{
									cout<<endl<<"Seleccione una opcion para el tipo de identificacion:"<<endl;
									cout<<"1. Cedula de ciudadania"<<endl;
									cout<<"2. Cedula de extrangeria"<<endl;
									cin>>opc; 
								}while(opc<1||opc>2);
								if(opc==1)
									paseador.setTipoId("CC");
								else
									paseador.setTipoId("CE");
									
								do{
									cout<<endl<<"Ingrese el numero de Cedula: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;
									if(!es_numero(texto)){
										cout<<"debe ingresar numeros"<<endl;
									}
								}while(!es_numero(texto));
								
								//VERIFICAR QUE SEA UNICO !!!
								
								paseador.setId(texto);
								do{
									cout<<"Seleccione una opcion para ingresar su genero:"<<endl;
									cout<<"1. Femenino"<<endl;
									cout<<"2. Masculino"<<endl;
									cin>>opc; 
								}while(opc<1||opc>2);
								if(opc==1)
									paseador.setGenero("F");
								else
									paseador.setTipoId("M");
									
								do{
									cout<<endl<<"Ingrese el numero de Telefono: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;
									if(!es_numero(texto)){
										cout<<"debe ingresar numeros"<<endl;
									}
								}while(!es_numero(texto));
								
								paseador.setTelefono(texto);
								cout<<endl<<"Ingrese el correo electronico: ";
								texto =  new char[BUFFER_SIZE];
								cin>>texto;
								//VERIFICAR QUE CONTENGA ARROBA Y PUNTO
								paseador.setEmail(texto); 
								
								cout<<endl<<"Ingrese la fecha de nacimiento: ";
								cout<<endl<<"Dia: ";
								cin>>dia;
								cout<<endl<<"Mes: ";
								cin>>mes; 
								cout<<endl<<"Anio: ";
								cin>>anio;
								
								int diaActual = aTiempo->tm_mday;
								int mesActual = aTiempo->tm_mon + 1; 
								int anioActual = aTiempo->tm_year + 1900;
								
								Date dt1 = {dia, mes, anio}; 
								Date dt2 = {diaActual, mesActual, anioActual}; 
								
								if((getDifference(dt1, dt2)/365)<18){
									cout<<"No se permiten edades menores a 18"<<endl; 	
								}
								else{ 		
									paseador.setEdad(getDifference(dt1, dt2)/365);  
									
									cout<<endl<<"Ingrese el pais de nacimiento: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;
									paseador.setPais(texto); 
									
									cout<<endl<<"Ingrese la ciudad de nacimiento: ";
									texto =  new char[BUFFER_SIZE];
									cin>>texto;
									paseador.setCiudad(texto); 
									
									bool localidadValida; 
									do{
										localidadValida = true;
										cout<<endl<<"Ingrese el nombre de la localidad de residencia: ";
										texto =  new char[BUFFER_SIZE];
										cin>>texto;  
										if(!arbolAVLLocal.localidadExiste(texto)){
											cout<<"Localidad no encontrada"<<endl;
											localidadValida = false; 
										}
									}while(!localidadValida);
									paseador.setBarrio(texto);  
									
									cout<<"Ingrese la hora de inicio de trabajo (Min. 6:00) : "; 
									cin>>opc;
									paseador.setHoraDeInicio(opc);
									cout<<endl<<"Ingrese la hora final de trabajo (Max. 20:00): "; 
									cin>>opc;
									paseador.setHoraDeSalida(opc);
									
								}
								for(int i = 0; i<17;i++){
									if(paseador.getBarrio() == LOCALIDADES[i].nombre){
										LOCALIDADES[i].paseadores.insertar_final(paseador);
									}
								}
								listaPaseador.insertar_final(paseador);
								/*sucursal.paseadores.insertar_final(paseador);
								listaSucursal.insertar_final(sucursal);
								LOCALIDADES.paseador.i
								listaPaseLocalidad.insertar_final(paseador);*/
															
								//Crear paseador
								break;
							}
							case 2:{
								//Borrar paseador
								cout<<"Ingrese ID de Paseador que desea eliminar:\n";
								cin>>idPaseador;
								int aux;
								
								for(int i = 1; i<=listaPaseador.get_tam();i++){
									if(listaPaseador.buscar(i).getId() == idPaseador){
										aux = i;
									}
								}
								listaPaseador.borrar_nodo(aux);
								for(int i = 1; i<=listaSucursal.get_tam();i++){
									for(int j = 1; j<=listaSucursal.get_tam();j++){
										if(listaSucursal.buscar(i).paseadores.buscar(j).getId()==idPaseador){
											aux = j;
										}
									}
									listaSucursal.buscar(i).paseadores.borrar_nodo(aux);
								}
								for(int i = 0; i<17;i++){
									for(int j = 1; j<=LOCALIDADES[i].paseadores.get_tam();j++){
										if(LOCALIDADES[i].paseadores.buscar(j).getId() == idPaseador){
											LOCALIDADES[i].paseadores.borrar_nodo(j);
										}
									}
								}
								break;
							}
							case 3:{
								//Editar paseador
								break;
							}
						}
						break;
					}
				}
				break;
			}
			case 3:{
				cout<<"Bienvenido al simulador de paseos para paseos: "<<endl;
				
				break;
			}
			case 4:{
				//Aqui hay que poner el guardado de los datos
				cout<<"Programa Finalizado"<<endl;
				break;
			}
			default:{
				cout<<"Comando incorrecto"<<endl;
				break;
			}
		}
	 system("pause");
	 system("cls");
	}while(opc!=4); 

	//arbolAVLLocal.preOrden();
	arbolAVLLocal.inOrden();
	
	


	return 0;	
	
}

/*
int bucarSucursal(int calle, int carrera, nombreLocalidad){
	for(int i = 0; i<17; i++){
		if(LOCALIDADES[i].nombre == nombreLocalidad){
			for(j = 0, j < LOCALIDADES[i].sucursales.get_tam();j++){
				
			}
			
		}
	}
}

void determinarSucursales(int calleInicio, int carreraInicio,int calleFin,int carreraFin){
	for(int i = 0; i<listaSucursal.get_tam(); i++){
		if((listaSucursal.buscar(i).sucursal.calleInicio >= calleInicio && listaSucursal.buscar(i).sucursal.calleFin <=calleInicio) ||
			(listaSucursal.buscar(i).sucursal.calleInicio >= calleFin && listaSucursal.buscar(i).sucursal.calleFin <= calleFin) ||
			(listaSucursal.buscar(i).sucursal.carreraInicio >= carreraInicio && listaSucursal.buscar(i).sucursal.carreraFin <= carreraInicio) ||
			(listaSucursal.buscar(i).sucursal.carreraInicio >= carreraFin && listaSucursal.buscar(i).sucursal.carreraFin<= carreraFin){
			cout<<listaSucursal.buscar(i).sucursal.nombre<<"\n";
		}
	}	
}*/
