#ifndef ARBOLLOCALIDADES_H_
#define ARBOLLOCALIDADES_H_

#include <string.h>
#include <iostream>
#include "Localidad.h"
#define null 0

using namespace std;

class arbolLocalidades {
	
	Localidad* raiz; 
	
private:
		int altura(Localidad *N);
		int max(int a, int b);
		Localidad* newLocalidad(char* dato, int calleIn, int calleFin, int carrIn, int carrFin);
		Localidad* derRotate(Localidad *y);
		Localidad* izqRotate(Localidad *x);
		int getBalance(Localidad *N);
		Localidad* insert(Localidad* Localidad, char* nombre,int calleIn, int calleFin, int carrIn, int carrFin);
		Localidad* minValueLocalidad(Localidad* Localidad);
		Localidad* deleteLocalidad(Localidad* root, char* nombre);
		void preOrder(Localidad *root); 
		void inOrder(Localidad *root);
		bool localidadExiste(Localidad *nodo,char* busqueda); 
		bool ubicacionExiste(Localidad *nodo,int calle, int carrera);
		Localidad* buscarLocalidad(Localidad *nodo,char* busqueda); 
public:
	arbolLocalidades(){	
		raiz = NULL; 
	}
	void agregarLocalidad(char* nombre,int calleIn, int calleFin, int carrIn, int carrFin);
	void preOrden();
	void inOrden(); 
	bool localidadExiste(char* busqueda);
	bool ubicacionExiste(int calle,int carrera);
	bool ubicacionExiste(char *busqueda, int calle, int carrera);
}; 

bool arbolLocalidades::localidadExiste(char* busqueda){
	return localidadExiste(raiz,busqueda);
}

bool arbolLocalidades::ubicacionExiste(char *busqueda, int calle, int carrera){
	Localidad* nodo = buscarLocalidad(raiz,busqueda);
	if(nodo->calleInicio > calle && nodo->calleFin < calle && nodo->carreraFin < carrera && nodo->carreraInicio > carrera){
		return true; 
	}
	else{
		return false;
	}
}

bool arbolLocalidades::ubicacionExiste(int calle, int carrera){
	return ubicacionExiste(raiz,calle,carrera);
}
bool arbolLocalidades::ubicacionExiste(Localidad *nodo,int calle, int carrera){
	if(nodo!=NULL){
		if(nodo->calleInicio > calle && nodo->calleFin < calle && nodo->carreraFin < carrera && nodo->carreraInicio > carrera){
			return true; 
		}
		else{
			return ubicacionExiste(nodo->izq,calle,carrera)||ubicacionExiste(nodo->der,calle,carrera);
		}
	}
	return false;
}

Localidad* arbolLocalidades::buscarLocalidad(Localidad *nodo,char* busqueda){

	if(nodo!=NULL){
		if(strcmp(busqueda,nodo->nombre) == 0){
			return nodo; 
		}
		else{
			if((strcmp(busqueda,nodo->nombre) > 0))
				return buscarLocalidad(nodo->der,busqueda);
			else 
				return buscarLocalidad(nodo->izq,busqueda);
		}
	}
	return NULL; 
}

bool arbolLocalidades::localidadExiste(Localidad *nodo,char* busqueda){

	if(nodo!=NULL){
		if(strcmp(busqueda,nodo->nombre) == 0){
			return true; 
		}
		else{
			return localidadExiste(nodo->izq,busqueda)||localidadExiste(nodo->der,busqueda);
		}
	}
	return false; 
}

void arbolLocalidades::inOrden(){
	inOrder(raiz);
}

void arbolLocalidades::preOrden(){
	preOrder(raiz);
}

void arbolLocalidades::agregarLocalidad(char* nombre,int calleIn, int calleFin, int carrIn, int carrFin){
	raiz = insert(raiz, nombre, calleIn, calleFin, carrIn, carrFin);
}
  
int arbolLocalidades::altura(Localidad *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->altura;  
}  
 
int arbolLocalidades::max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
Localidad* arbolLocalidades::newLocalidad(char* dato, int calleIn, int calleFin, int carrIn, int carrFin)  
{  
    Localidad* localidad = new Localidad(); 
    localidad->nombre = dato; 
	localidad->calleInicio = calleIn;
	localidad->calleFin = calleFin;
	localidad->carreraInicio = carrIn;
	localidad->carreraFin = carrFin;  
    localidad->izq = NULL;  
    localidad->der = NULL;  
    localidad->altura = 1;
	 
    return(localidad);  
}  
   
Localidad* arbolLocalidades::derRotate(Localidad *y){  
    Localidad *x = y->izq;  
    Localidad *T2 = x->der;  
  
    // Perform rotation  
    x->der = y;  
    y->izq = T2;  
  
    // Update alturas  
    y->altura = max(altura(y->izq),  
                    altura(y->der)) + 1;  
    x->altura = max(altura(x->izq),  
                    altura(x->der)) + 1;  
  
    // Return new root  
    return x;  
}  
  
Localidad* arbolLocalidades::izqRotate(Localidad *x)  
{  
    Localidad *y = x->der;  
    Localidad *T2 = y->izq;  
  
    // Perform rotation  
    y->izq = x;  
    x->der = T2;  
  
    // Update alturas  
    x->altura = max(altura(x->izq),  
                    altura(x->der)) + 1;  
    y->altura = max(altura(y->izq),  
                    altura(y->der)) + 1;  
  
    // Return new root  
    return y;  
}  
  

int arbolLocalidades::getBalance(Localidad *N)  
{  
    if (N == NULL)  
        return 0;  
    return altura(N->izq) - altura(N->der);  
}  
  
Localidad* arbolLocalidades::insert(Localidad* Localidad, char* nombre,int calleIn, int calleFin, int carrIn, int carrFin){ 
  
 	
    /* 1. Perform the normal BST rotation */
    if (Localidad == NULL)  
        return newLocalidad(nombre,calleIn,calleFin,carrIn,carrFin);  
    if ((strcmp(nombre,Localidad->nombre) < 0))  
        Localidad->izq = insert(Localidad->izq, nombre,calleIn,calleFin,carrIn,carrFin);  
    else if ((strcmp(nombre,Localidad->nombre) > 0))  
        Localidad->der = insert(Localidad->der, nombre,calleIn,calleFin,carrIn,carrFin);  
    else // Equal nombres not allowed  
        return Localidad;  
  
    /* 2. Update altura of this ancestor Localidad */
    Localidad->altura = 1 + max(altura(Localidad->izq),  
                           altura(Localidad->der));  
  
    /* 3. Get the balance factor of this  
        ancestor Localidad to check whether  
        this Localidad became unbalanced */
    int balance = getBalance(Localidad);  
  
    // If this Localidad becomes unbalanced, 
    // then there are 4 cases  
    // izq izq Case  
    if (balance > 1 && (strcmp(nombre,Localidad->izq->nombre) < 0))  
        return derRotate(Localidad);  
  
    // der der Case  
    if (balance < -1 && (strcmp(nombre,Localidad->der->nombre) > 0))   
        return izqRotate(Localidad);  
  
    // izq der Case  
    if (balance > 1 && (strcmp(nombre,Localidad->izq->nombre) > 0))  
    {  
        Localidad->izq = izqRotate(Localidad->izq);  
        return derRotate(Localidad);  
    }  
  
    // der izq Case  
    if (balance < -1 && (strcmp(nombre,Localidad->der->nombre) < 0))  
    {  
        Localidad->der = derRotate(Localidad->der);  
        return izqRotate(Localidad);  
    }  
  
    /* return the (unchanged) Localidad pointer */
    return Localidad;  
}  
  
/* Given a non-empty binary search tree,  
return the Localidad with minimum nombre value  
found in that tree. Note that the entire  
tree does not need to be searched. */
Localidad* arbolLocalidades::minValueLocalidad(Localidad* localidad){  
    Localidad* current = localidad;  
  
    /* loop down to find the izqmost leaf */
    while (current->izq != NULL)  
        current = current->izq;  
  
    return current;  
}  
  
// Recursive function to delete a Localidad  
// with given nombre from subtree with  
// given root. It returns root of the  
// modified subtree.  
Localidad* arbolLocalidades::deleteLocalidad(Localidad* root, char* nombre){  
      
    // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)  
        return root;  
  
    // If the nombre to be deleted is smaller  
    // than the root's nombre, then it lies 
    // in izq subtree  
    
    if (strcmp(nombre,root->nombre) < 0) 
        root->izq = deleteLocalidad(root->izq, nombre);  
  
    // If the nombre to be deleted is greater  
    // than the root's nombre, then it lies  
    // in der subtree  
    else if(strcmp(nombre,root->nombre) > 0)  
        root->der = deleteLocalidad(root->der, nombre);  
  
    // if nombre is same as root's nombre, then  
    // This is the Localidad to be deleted  
    else
    {  
        // Localidad with only one child or no child  
        if( (root->izq == NULL) || 
            (root->der == NULL) )  
        {  
            Localidad *temp = root->izq ?  
                         root->izq :  
                         root->der;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp; // Copy the contents of  
                           // the non-empty child  
            //free(temp);  
        }  
        else
        {  
            // Localidad with two children: Get the inorder  
            // successor (smallest in the der subtree)  
            Localidad* temp = minValueLocalidad(root->der);  
  
            // Copy the inorder successor's  
            // data to this Localidad  
            root->nombre = temp->nombre;  
  
            // Delete the inorder successor  
            root->der = deleteLocalidad(root->der,  
                                     temp->nombre);  
        }  
    }  
  
    // If the tree had only one Localidad 
    // then return  
    if (root == NULL)  
    return root;  
  
    // STEP 2: UPDATE altura OF THE CURRENT Localidad  
    root->altura = 1 + max(altura(root->izq),  
                           altura(root->der));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS Localidad (to check whether this  
    // Localidad became unbalanced)  
    int balance = getBalance(root);  
  
    // If this Localidad becomes unbalanced,  
    // then there are 4 cases  
  
    // izq izq Case  
    if (balance > 1 &&  
        getBalance(root->izq) >= 0)  
        return derRotate(root);  
  
    // izq der Case  
    if (balance > 1 &&  
        getBalance(root->izq) < 0)  
    {  
        root->izq = izqRotate(root->izq);  
        return derRotate(root);  
    }  
  
    // der der Case  
    if (balance < -1 &&  
        getBalance(root->der) <= 0)  
        return izqRotate(root);  
  
    // der izq Case  
    if (balance < -1 &&  
        getBalance(root->der) > 0)  
    {  
        root->der = derRotate(root->der);  
        return izqRotate(root);  
    }  
  
    return root;  
}  
  
// A utility function to print preorder  
// traversal of the tree.  
// The function also prints altura  
// of every Localidad  
void arbolLocalidades::preOrder(Localidad *root)  
{  
    if(root != NULL)  
    {  
        cout << root->nombre << " ";  
        preOrder(root->izq);  
        preOrder(root->der);  
    }  
}

void arbolLocalidades::inOrder(Localidad *root) {
	if (root != null) {
		this->inOrder(root->izq);
		cout << root->nombre << " ";
		this->inOrder(root->der);
	}

}

#endif 
