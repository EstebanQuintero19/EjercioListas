#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};
void insertaLista(Nodo *&,int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *,int);
void eliminarCompleta(Nodo*&, int&);
int menu();

int main(){
    Nodo *lista = nullptr;
    int dato, eleccion;

    while(true){
        eleccion = menu();

        if (eleccion==1){
            cout<<"Ingrese el dato a agregar: ";
            cin>>dato;
            insertaLista(lista,dato);
        } else if (eleccion == 2){
            mostrarLista(lista);
        } else if (eleccion == 3) {
            cout << "Ingrese el dato a buscar: ";
            cin >> dato;
            buscarLista(lista, dato);
        } else if (eleccion == 4)
            eliminarCompleta(lista, dato);
        else if (eleccion == 5) {
            break;
        } else {
            cout << "Opcion no valida";
        }
    }
}

int menu(){
    int eleccion;
    cout<<"MENU DE OPCONES\n(1) Agregar elemento a la lista\n(2) Mostrar lista\n(3) Buscar elemento en lista\n(4) Eliminar lista completa\n(5) Salir"<<endl;
    cin>>eleccion;
    return eleccion;
}

void insertaLista(Nodo *&lista,int n){
    Nodo *nuevo_nodo = new Nodo ();
    nuevo_nodo -> dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;
    while ((aux1 != nullptr)&&(aux1->dato <n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if(lista== aux1){
        lista= nuevo_nodo;

    }else{
        aux2-> siguiente = nuevo_nodo;
    }
    nuevo_nodo -> siguiente = aux1;
    cout<<"\nElemento "<<n<<" insertadoa a lista correctamente\n\n"<<endl;

}
void mostrarLista(Nodo *lista){
    Nodo *actual;
    actual = lista;
    while (actual != nullptr){
        cout<<actual->dato<<endl;
        actual=actual->siguiente;
    }
}

void buscarLista(Nodo *lista, int n){
    bool band = false;
    Nodo *actual = lista;

    while ((actual!= nullptr)&&(actual->dato<=n)){
        if(actual->dato==n){
            band = true;
        }
        actual = actual ->siguiente;
    }
    if (band){
        cout<<"Elemento "<<n<<" se ha encontrado en la lista\n";
    } else {
        cout<<"Elemento "<<n<<" no se ha encontrado en la lista\n\n";
    }
}

void eliminarCompleta(Nodo*& lista, int &n){
    Nodo *aux = lista;
    n = aux->dato;
    lista = aux ->siguiente;
    delete aux;
}