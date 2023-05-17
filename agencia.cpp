/*
16 de noviembre del 2021
miguel angel vasquez plascencia 21110419
Luis David Araiza  - 21110410
2-G2
*/

//Agencia de autos
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>


using namespace std;

class articulo {
    public:
        articulo(){}
        articulo(int id, int precio, string nombre){
            idArticulo= id;
            precioArticulo = precio;
            nombreArticulo = nombre;
        }
    private:
    int idArticulo;
    int precioArticulo;
    string nombreArticulo;

    friend class listaAutos;
    friend class nodoAuto;

};

class nodoAuto{
    public:
        int index=0;
        articulo autoArticulos[22];
        nodoAuto(int id, string usuario, string nombre) {
            idAuto=id;
            usuarioAuto = usuario;
            nombreAuto = nombre;
            
            costoAuto = 0;
            siguiente = NULL;
            anterior = NULL;
        }
        
        
        
        
    private:
        int idAuto;
        string usuarioAuto;
        string nombreAuto;
        
        int costoAuto;
        nodoAuto* siguiente;
        nodoAuto* anterior;

    friend class listaAutos;
};
typedef nodoAuto* pNodoAuto;

class listaAutos {
    public:
    articulo articulos[22];
    listaAutos() {
        plistaAuto=NULL ;
        for(int i=0; i<22; i++){
            articulos[i].idArticulo=i;
            articulos[i].precioArticulo=precios[i];
            articulos[i].nombreArticulo=nombres[i];
        }
    }
    ~listaAutos();
    bool Insertar(string, string);
    bool Borrar();
    bool ListaVacia() { return plistaAuto == NULL; }
    void Mostrar(int);
    bool Siguiente();
    bool Anterior();
    void Primero();
    void Ultimo();
    bool Actual() { return plistaAuto != NULL; }
    int ValorActual() { return plistaAuto->idAuto; }
    void mostrarArticulos(){
        for(int i=0;i<11;i++){
                    cout<<"["<<i<<"] "<< articulos[i].nombreArticulo<< " $"<<articulos[i].precioArticulo<<" MXN \t\t";
                    cout<<"["<<i+11<<"] "<< articulos[i+11].nombreArticulo<< " $"<<articulos[i+11].precioArticulo<<" MXN \n";
                }
    }
    void imprimirAutomovil(){
        ofstream archivo;  // objeto de la clase ofstream
        archivo.open("Ticket.txt",ios::trunc); //Forma de apertura:  ios::Trunc genera el archivo, si ya exste, lo borra y lo crea
        archivo << "                        Ticket" << endl;
        archivo << "Agencia de autos SA de CV"<<endl;
        archivo << "Ing. Luis David Araiza "<<endl;
        archivo << "Ing. Miguel Angel Vasquez Plascencia"<<endl;
        archivo << ""<<endl;
        archivo << "Cliente: " << plistaAuto->usuarioAuto <<endl;
        archivo << "Automovil: "<< plistaAuto->nombreAuto << endl;
        archivo << "Numero de serie: " << plistaAuto->idAuto <<endl;
        archivo << endl;
        for(int i=0;i<22;i++){
            if(plistaAuto->autoArticulos[i].nombreArticulo==""){
                break;
            }
            archivo<< "\t "<< plistaAuto->autoArticulos[i].nombreArticulo<< " $"<<plistaAuto->autoArticulos[i].precioArticulo<<endl;
        }
        archivo << "Total------ $"<<plistaAuto->costoAuto<<" MXN" << endl;
        archivo << endl;
        archivo << "Direccion: Lamborghini miami sa.DEsv_todos los derechos reservados_ R)\n"<<endl;
        archivo << "\t GRACIAS POR SU COMPRA"<<endl;
        archivo.close();


        // Confirma los datos guardados imprimiendo el archivo generado en consola
        string cadena;
        
        ifstream archivo_;  // objeto de la clase ofstream
        archivo_.open("Ticket.txt"); //Forma de apertura:  ios::Trunc genera el archivo, si ya exste, lo borra y lo crea
        if(archivo_.fail()){
        } else{
            while (!archivo_.eof()) {
            getline(archivo_, cadena);
            cout << cadena << endl;
            }
        }
        archivo_.close();
    }
    void anadirArticulo(int art){
            plistaAuto->autoArticulos[plistaAuto->index].idArticulo = articulos[art].idArticulo;
            plistaAuto->autoArticulos[plistaAuto->index].precioArticulo = articulos[art].precioArticulo;
            plistaAuto->autoArticulos[plistaAuto->index].nombreArticulo = articulos[art].nombreArticulo;
            plistaAuto->index++;
    }
    void CalcularTotal(){
            plistaAuto->costoAuto=0;
            for(int i=0;i<22;i++){
                if(plistaAuto->autoArticulos[i].precioArticulo < 0){break;}
                plistaAuto->costoAuto=plistaAuto->autoArticulos[i].precioArticulo + plistaAuto->costoAuto;
            }
        }

    int getIdAuto(){return plistaAuto->idAuto;}
    string getUsuario() {return plistaAuto->usuarioAuto; }
    string getNombre(){return plistaAuto->nombreAuto;}
    nodoAuto* Buscar(const int);  //Retorna un puntero al auto buscado
    void muestraAuto();
    private:
    pNodoAuto plistaAuto;
    string nombres[22]={
    "Pintura Blanca",
    "Pintura Negra",
    "Pintura Gris",
    "Pintura Roja",
    "Pintura Azul",
    "Rines tempest 19 pulgadas",
    "Rines tempest 21 pulgadas",
    "Rines Serie S1SC",
    "Rines Serie P1SC",
    "Frenos alcon",
    "Frenos Willwood ventilados 2 pistones",
    "Frenos brembo ventilados 6 pistones",
    "Fib Car paquete sport, aleron, difusor",
    "Fib Car paquete sport, aleron, difusor",
    "Interior Negro",
    "Interior Rojo",
    "Interior Azul",
    "Interior Gris",
    "Interior Magenta",
    "Interior Caoba",
    "Interior Chocolate",
    "Interior Oro"
    };
    int precios[22] = {
        0,
        30000,
        30000,
        50000,
        30000,
        0,
        90000,
        242000,
        124000,
        0,
        50000,
        85000,
        150000,
        211000,
        0,
        40000,
        35000,
        28000,
        40000,
        35000,
        20000,
        1000000
    };


};





int main(){
    int opc;
    string cliente;
    string automovil;
    listaAutos autos;
    pNodoAuto autoSeleccionado;
    while(1){
    
        system("cls");
        cout<<"\t\tAgencia de autos: \n\n";
        
        //Listado de carros
        autos.muestraAuto();

        //Menú
        cout<<"\n\n Press key [a] Back    [d] Next \n";
        cout<<"[q] Edit car   [w] Delete    [e] New Car     [r]Imprimir     [x] Exit\n\n";
        opc=(int) tolower(getch()); // Espera una entrada del teclado, en cuanto la recibe la convierte a minuscula, la convierte a entera y la almecena en int opc
        switch(opc){
            case 97: //  Left
                //Cambia la posicion de la lista al anterior auto
                autos.Anterior();
                system("cls");
                
            break;
            case 100: // Right
                //Cambia la posicion de la lista al siguiente auto
                autos.Siguiente();
                system("cls");
                
            break;
            case 113: // Edit 
                //Elimina, agrega Items y modifica el precio
                if(autos.ListaVacia()){
                    break;
                }
                int newArticulo;
                system("cls");
                cout<<"Seleccione el codigo de un articulo para anadirlo\n\n";
                autos.mostrarArticulos();
                cin>>newArticulo;
                autos.anadirArticulo(newArticulo);
                autos.CalcularTotal();
                

                system("PAUSE");
            break;
            case 119: // Delete
                //Elimina el elemento de la lista
                autos.Borrar();
            break;
            case 101:// New
                //Formulario y agregar Items
                
                fflush(stdin);
                cout<<"Ingrese el nombre completo del cliente: ";
                getline(cin,cliente,'\n');
                fflush(stdin);
                cout<<"\nIngrese el modelo y ano del vehiculo (Ford_Azul 2001)\n";
                getline(cin,automovil,'\n');
                fflush(stdin);
                autos.Insertar(cliente,automovil);
                autos.Primero();
                system("PAUSE");
            break;
            case 114: //Imprimir
                autos.imprimirAutomovil();
                cout<<endl;
                system("pause");
            break;
            case 120: // Exit

                system("cls");
                return 0;
            break;
        }
    }
    
    



    

    return 0;
}



listaAutos::~listaAutos()
{  pNodoAuto aux;
   Primero();
   while(plistaAuto) {
      aux = plistaAuto;
      plistaAuto = plistaAuto->siguiente;
      delete aux;
  }
    cout<<"\nLista eliminada\n";
}

nodoAuto* listaAutos::Buscar(const int v)
{ 
    pNodoAuto nodo;
    nodo = plistaAuto;
    while(nodo && nodo->idAuto < v) nodo = nodo->siguiente;
    while(nodo && nodo->idAuto > v) nodo = nodo->anterior;
    if(!nodo || nodo->idAuto != v)  return NULL;
    else {  plistaAuto = nodo; return nodo;}
}

bool listaAutos::Insertar(string usuario, string nombre)
{ 
    pNodoAuto nuevo;
    Ultimo();
   // Si la lista est� vac�a
    if(ListaVacia()){
        nuevo = new nodoAuto(1, usuario, nombre);
        plistaAuto=nuevo;
        return true;
    } else{
        nuevo = new nodoAuto(plistaAuto->idAuto+1, usuario, nombre);
        plistaAuto->siguiente = nuevo;
        nuevo->anterior=plistaAuto;
        nuevo->siguiente=NULL;
        plistaAuto = nuevo;
        return true;
    }
    return false;
}

//_________________________________________________________________________________
//Borrar el primer dato, un dato intermedio, el �ltimo dato
bool listaAutos::Borrar(){  
    if(ListaVacia()){
        return false;
    } if(plistaAuto->siguiente == NULL && plistaAuto->anterior == NULL) {
        pNodoAuto aux = plistaAuto;
        plistaAuto = NULL;
        delete aux;
    }else if(plistaAuto->anterior == NULL){
        pNodoAuto aux = plistaAuto;
        aux->siguiente->anterior = NULL;
        plistaAuto = aux->siguiente;
        delete aux;
        return true;
    } else if(plistaAuto->siguiente == NULL){
        pNodoAuto aux = plistaAuto;
        aux->anterior->siguiente = NULL;
        plistaAuto = aux->anterior;
        delete aux;
        return true;
    } else{
        pNodoAuto aux = plistaAuto;
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
        plistaAuto = aux->anterior;
        delete aux;
        return true;
    }
}
//__________________________________________________________________________________________
void listaAutos::muestraAuto(){
    if(ListaVacia()){
        cout<<"Lista vacia";
        return;
    }
    cout<<"\t\t ************************\n";
        cout<<"\t\t * ID: "<<plistaAuto->idAuto<<"\n";
        cout<<"\t\t * "<<plistaAuto->nombreAuto<<"\n";
        cout<<"\t\t * Modifi. $"<< plistaAuto->costoAuto << " MXN \n";
        for(int i=0; i< 22 ; i++){
            if(plistaAuto->autoArticulos[i].nombreArticulo==""){
                break;
            }
            cout<<"\t\t\t "<< plistaAuto->autoArticulos[i].nombreArticulo <<" $"<<plistaAuto->autoArticulos[i].precioArticulo <<" MXN\n";
        }
        cout<<"\t\t ************************";
}
//______
bool listaAutos:: Siguiente(){    
    if(plistaAuto->siguiente!=NULL) {
        plistaAuto = plistaAuto->siguiente; 
        return true;
    } else {
        return false; 
    }
}
bool listaAutos::Anterior() {    
    if(plistaAuto->anterior!=NULL) {
        plistaAuto = plistaAuto->anterior; 
        return true;
    } else {
        return false; 
    }
}

void listaAutos::Primero()
{   while(plistaAuto && plistaAuto->anterior) plistaAuto = plistaAuto->anterior;
}

void listaAutos::Ultimo()
{   while(plistaAuto && plistaAuto->siguiente) plistaAuto = plistaAuto->siguiente;
}
//






