#include "civilizacion.h"

Civilizacion::Civilizacion(){
    //Constructor
}

void Civilizacion::setNombre(string &nombre){
    this->nombre = nombre;
}
string Civilizacion::getNombre() const{
    return nombre;
}

void Civilizacion::setUbicacionX(size_t ubicacion_x){
    this->ubicacion_x = ubicacion_x;
}
size_t Civilizacion::getUbicacionX() const{
    return ubicacion_x;
}

void Civilizacion::setUbicacionY(size_t ubicacion_y){
    this->ubicacion_y = ubicacion_y;
}
size_t Civilizacion::getUbicacionY() const{
    return ubicacion_y;
}

void Civilizacion::setPuntuacion(float puntuacion){
    this->puntuacion = puntuacion;
}
float Civilizacion::getPuntuacion() const{
    return puntuacion;
}

void Civilizacion::agregar_aldeano_inicio(const Aldeano &aldeano){
    aldeanos.push_front(aldeano);
}

void Civilizacion::agregar_aldeano_final(const Aldeano &aldeano){
    aldeanos.push_back(aldeano);
}

void Civilizacion::eliminar_nombre(const string &nombre){
    
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &ald = *it;

        if(nombre == ald.getNombre()){
            aldeanos.erase(it);
            break;
        }
    }
    cout<<endl;
}

void Civilizacion::eliminar_salud(float salud){
    aldeanos.remove_if([salud](const Aldeano &ald){return ald.getSalud() < salud;});
}

void Civilizacion::eliminar_edad(){
    aldeanos.remove_if([](const Aldeano &ald){return ald.getEdad() >= 60;});
}

void Civilizacion::calsificar_nombre(){
    aldeanos.sort();
}

void Civilizacion::clasificar_edad(){
    aldeanos.sort([](const Aldeano &ald1, const Aldeano &ald2){return ald1.getEdad() > ald2.getEdad();});
}

void Civilizacion::clasificar_salud(){
    aldeanos.sort([](const Aldeano &ald1, const Aldeano &ald2){return ald1.getSalud() > ald2.getSalud();});
}

Aldeano* Civilizacion::buscar_aldeano(const Aldeano &ald){
    auto it = find(aldeanos.begin(), aldeanos.end(), ald);//Recorre todo el vector y busca ela civilizacion civi

    if(it == aldeanos.end()){//Si el iterador esta apuntando al final del vector
        return nullptr;//No se encontró la civilizacion
    } 
    else{
        //Accede a la posicion y con & me va a regresar la posicion de memoria donde esta esa civilizacion
        return &(*it);//Acceder al elemento haciendo referencia a un puntero
    }
}

void Civilizacion::modificar_aldeano(Aldeano *ald){
    size_t opc;
    string nombre, genero;
    int edad;
    float salud;

    do{
    cout<<"\t\t\tMODIFICAR ATRIBUTOS INDIVIDUALES DEL ALDEANO: "<<ald->getNombre()<<endl<<endl;
    cout<<"1) NOMBRE"<<endl;
    cout<<"2) EDAD"<<endl;
    cout<<"3) SALUD"<<endl;
    cout<<"4) GENERO"<<endl;
    cout<<"0) TERMINAR"<<endl;

    cout<<endl<<"DIGITA UNA OPCION: ";
    cin>>opc;
    cin.ignore();

    cout<<endl<<endl;

    switch(opc){
        case 1: cout<<"MODIFICAR NOMBRE: "; getline(cin, nombre); ald->setNombre(nombre); cout<<"\n\n"; 
                 system("pause"); system("cls"); break;
        case 2: cout<<"MODIFICAR EDAD: "; cin>>edad; ald->setEdad(edad); cout<<"\n\n";
                 system("pause"); system("cls"); break;
        case 3: cout<<"MODIFICAR SALUD: "; cin>>salud; ald->setSalud(salud); cout<<"\n\n";
                 system("pause"); system("cls"); break;
        case 4: cout<<"MODIFICAR GENERO: "; getline(cin, genero); ald->setGenero(genero); cout<<"\n\n";
                 system("pause"); system("cls"); break;
    }
       
    }while(opc != 0);
}

void Civilizacion::mostrar(){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout<<*it<<endl;
    }
}