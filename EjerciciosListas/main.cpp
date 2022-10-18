#include <iostream>

using namespace std;

//Estructura del nodo materia
struct Materia{
    string nombre;
    float nota;
    Materia *siguiente{};
};


//Prototipado de funciones
void insertaLista(Materia *&, string, float);
void mostrarLista(Materia *);
void buscarLista(Materia *, string);
void eliminarMateriaMenorNota(Materia *&, string &, float &);
float calcularPromedio(Materia *);
int menu();
int menu2();
int menu3();
int menu4();
int menu5();

//funcion principal
int main(){
    Materia *listaEstudiante1 = nullptr;
    Materia *listaEstudiante2 = nullptr;
    int eleccion;
    float nota, prom1, prom2;
    string materia;

    while(true) {
        eleccion = menu();

        if (eleccion == 1) {
            eleccion = menu2();

            if (eleccion == 1) {

                cout << "Ingrese la materia a agregar: ";
                cin >> materia;
                cout << "Ingrese la nota de la materia: ";
                cin >> nota;
                insertaLista(listaEstudiante1, materia, nota);

            } else if (eleccion == 2) {

                cout << "Ingrese la materia a agregar: ";
                cin >> materia;
                cout << "Ingrese la nota de la materia: ";
                cin >> nota;
                insertaLista(listaEstudiante2, materia, nota);

            } else if (eleccion == 3) {
                break;
            } else {
                cout << "Opcion no valida\n" << endl;
            }
        } else if (eleccion == 2) {
            eleccion = menu3();

            if (eleccion == 1) {
                mostrarLista(listaEstudiante1);
            } else if (eleccion == 2) {
                mostrarLista(listaEstudiante2);
            } else if (eleccion == 3) {
                break;
            } else {
                cout << "Opcion no valida\n" << endl;
            }
        } else if (eleccion == 3) {
            eleccion = menu4();

            if (eleccion == 1) {
                cout << "Ingrese la materia a buscar: ";
                cin >> materia;
                buscarLista(listaEstudiante1, materia);
            } else if (eleccion == 2) {
                cout << "Ingrese la materia a buscar: ";
                cin >> materia;
                buscarLista(listaEstudiante2, materia);
            } else if (eleccion == 3) {
                break;
            } else {
                cout << "Opcion no valida\n" << endl;
            }
        } else if (eleccion == 4){
            eleccion = menu5();
            if (eleccion == 1)
                if (listaEstudiante1 != nullptr){
                    eliminarMateriaMenorNota(listaEstudiante1, materia, nota);
                } else{
                    cout << "La lista del estudiante 1 se encuenta vacia\n" << endl;
                }
            else if (eleccion == 2) {
                if (listaEstudiante2 != nullptr){
                    eliminarMateriaMenorNota(listaEstudiante2, materia, nota);
                } else {
                    cout << "La lista del estudiante 2 se encuenta vacia\n" << endl;
                }
            } else if (eleccion == 3) {
                break;
            } else {
                cout << "Opcion no valida\n" << endl;
            }
        }else if (eleccion == 5) {

            if ((listaEstudiante1==nullptr)&&(listaEstudiante2== nullptr)){
                cout << "Ambos estudiantes tienen sus listas vacias, debe llenarlas\n" << endl;
            } else if (listaEstudiante1 == nullptr){
                cout << "El estudiante 1 tiene su lista vacia, debe llenarla\n" << endl;
                prom2 = calcularPromedio(listaEstudiante2);
                cout << "Promedio estudiante 2: " << prom2 << "\n" << endl;
            } else if (listaEstudiante2 == nullptr){
                cout << "El estudiante 2 tiene su lista vacia, debe llenarla\n" << endl;
                prom1 = calcularPromedio(listaEstudiante1);
                cout << "Promedio estudiante 1: " << prom1 << "\n" << endl;
            } else {
                prom1 = calcularPromedio(listaEstudiante1);
                prom2 = calcularPromedio(listaEstudiante2);

                if (prom1>prom2){
                    cout << "El estudiante 1 tiene mejor promedio que el estudiante 2" << endl;
                    cout << "Promedio estudiante 1: " << prom1 << "\n" << endl;
                } else if (prom1<prom2){
                    cout << "El estudiante 2 tiene mejor promedio que el estudiante 1" << endl;
                    cout << "Promedio estudiante 2: " << prom2 << endl;
                } else if (prom2==prom1){
                    cout << "Ambos estudiantes tienen el mismo promedio"<<endl;
                    cout << "Promedio estudiante 1: " << prom1 << endl;
                    cout << "Promedio estudiante 2: " << prom2 << endl;
                }
            }
        } else if (eleccion == 6) {
            break;
        } else {
            cout << "Opcion no valida\n" << endl;
        }
    }
}


//FUNCIONES

//Funciones de los menus
int menu(){
    int eleccion;
    cout << "MENU DE OPCIONES\n(1) Agregar elemento a la lista\n(2) Mostrar lista\n(3) Buscar elemento en lista\n"
            "(4) Eliminar peor nota\n(5) Cual es el estudiante con el mejor promedio?\n(6) Salir" << endl;
    cin >> eleccion;
    return eleccion;
}

int menu2(){
    int eleccion;
    cout << "MENU DE OPCIONES PARA AGREGAR MATERIA\n(1) Agregar materia al estudiante 1\n"
            "(2) Agregar materia al estudiante 2\n(3) Salir" << endl;
    cin >> eleccion;
    return eleccion;
}

int menu3(){
    int eleccion;
    cout << "MENU DE OPCIONES PARA MOSTRAR LAS MATERIAS\n(1) Mostrar las materias del estudiante 1\n"
            "(2) Mostrar las materias del estudiante 2\n(3) Salir" << endl;
    cin >> eleccion;
    return eleccion;
}

int menu4(){
    int eleccion;
    cout << "MENU DE OPCIONES PARA BUSCAR EN LAS LISTAS DE MATERIAS\n(1) Buscar en las materias del estudiante 1\n"
            "(2) Buscar en las materias del estudiante 2\n(3) Salir" << endl;
    cin >> eleccion;
    return eleccion;
}

int menu5(){
    int eleccion;
    cout << "MENU DE OPCIONES PARA VACIAR LAS LISTAS DE MATERIAS\n(1) Eliminar la peor nota del estudiante 1\n"
            "(2) Eliminar la peor nota del estudiante 2\n(3) Salir" << endl;
    cin >> eleccion;
    return eleccion;
}


//Funciones para interactuar con las listas
void insertaLista(Materia *&lista, string nombre, float n){
    Materia *nuevo_nodo = new Materia ();
    nuevo_nodo->nombre = nombre;
    nuevo_nodo->nota = n;

    Materia *aux1 = lista;
    Materia *aux2;
    while ((aux1 != nullptr)&&(aux1->nota < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if(lista == aux1){
        lista = nuevo_nodo;

    }else{
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
    cout << "\nMateria " << nombre << " insertada a la lista correctamente\n\n";
}

void mostrarLista(Materia *lista){
    Materia *actual;
    actual = lista;
    while (actual != nullptr){
        cout << actual->nombre << " --> ";
        cout << actual->nota << endl;
        actual=actual->siguiente;
    }
}

void buscarLista(Materia *lista, string nombre){
    bool band = false;
    Materia *actual = lista;

    while ((actual!= nullptr)&&(actual->nombre == nombre)){
        if(actual->nombre == nombre){
            band = true;
        }
        actual = actual->siguiente;
    }
    if (band){
        cout << "Materia " << nombre << " se ha encontrado en la lista\n";
    } else {
        cout << "Materia " << nombre << " no se ha encontrado en la lista\n\n";
    }
}

void eliminarMateriaMenorNota(Materia *&lista, string &nombre, float &n){
    Materia *aux = lista;
    nombre = aux->nombre;
    n = aux->nota;

    lista = aux->siguiente;
    delete aux;
}

float calcularPromedio(Materia *lista){
    Materia *actual;
    actual = lista;

    float sumaNotas = 0;
    int numeroMaterias = 0;

    while (actual != nullptr){
        sumaNotas = sumaNotas + actual->nota;
        actual=actual->siguiente;
        numeroMaterias++;
    }
    return sumaNotas/numeroMaterias;
}