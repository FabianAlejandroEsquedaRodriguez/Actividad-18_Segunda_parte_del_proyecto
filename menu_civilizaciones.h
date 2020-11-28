#include "civilizacion.h"
#include <iomanip>

void menu(Civilizacion &civi){

    size_t opc;
    do{
        cout<<"\t\tMENU DE OPCIONES PARA ADMINISTRAR ALDEANOS EN LA CIVILIZACION: "<<civi.getNombre()<<endl<<endl;

        cout<<"1) Agregar aldeano"<<endl;
        cout<<"2) Eliminar aldeano"<<endl;
        cout<<"3) Clasificar aldeanos"<<endl;
        cout<<"4) Buscar aldeano"<<endl;
        cout<<"5) Modificar aldeano"<<endl;
        cout<<"6) Mostrar aldeanos"<<endl;
        cout<<"0) Salir"<<endl;

        cout<<endl<<endl<<"ELIGE UNA OPCION DEL MENU: ";
        cin>>opc;
        cin.ignore();

        system("cls");

        if(opc == 1){
            //Leer informacion del aldeano
            Aldeano ald;
            float puntaje;

            cout<<"\t\t\tREGISTRAR INFORMACION DEL ALDEANO"<<endl<<endl;
            size_t op;

            cout<<"1) Agregar aldeano al inicio"<<endl<<endl;
            cout<<"2) Agregar aldeano al final"<<endl;

            cout<<endl<<endl<<"ELIGE UNA OPCION: "; 
            cin>>op;
            cin.ignore();
            system("cls");

            if(op == 1){
                cout<<"\t\t\tAGREGAR ALDEANO AL INICIO"<<endl<<endl;
                cin>>ald;

                puntaje += 100;

                cout<<"\n\nPuntaje: "<<puntaje<< "\n\n";
                civi.agregar_aldeano_inicio(ald);
            }
            else{
                cout<<"\t\t\tAGREGAR ALDEANO AL FINAL"<<endl<<endl;
                cin>>ald;

                puntaje += 100;

                cout<<"\n\nPuntaje: "<<puntaje<< "\n\n";
                civi.agregar_aldeano_final(ald);
            }
        }

        else if(opc == 2){
            cout<<"\t\t\tELIMINAR ALDEANO"<<endl<<endl;
            size_t op;

            cout<<"1) ELIMINAR POR NOMBRE"<<endl;
            cout<<"2) ELIMINAR POR SALUD"<<endl;
            cout<<"3) ELIMINAR POR EDAD"<<endl;

            cout<<endl<<"ELIGE UNA OPCION: ";
            cin>>op;
            cin.ignore();

            system("cls");

            if(op == 1){
                cout<<"\t\t\tELIMINAR POR NOMBRE DEL ALDEANO"<<endl<<endl;
                string nombre;

                cout<<"Nombre: ";
                getline(cin, nombre);

                cout<<"\n\n\t\t\tELIMINANDO ALDEANO"<<endl<<endl;

                civi.eliminar_nombre(nombre);
            }

            if(op == 2){
                cout<<"\t\t\tELIMINAR POR SALUD"<<endl<<endl;
                float salud;


                cout<<"Salud: ";
                cin>>salud;

                cout<<"\n\n\t\t\tELIMINANDO ALDEANO(S) CON SALUD MENOR A: "<<salud<<endl<<endl;

                civi.eliminar_salud(salud);
            }
        
            if(op == 3){
                cout<<"\t\t\t\t\tELIMINAR POR EDAD"<<endl<<endl;

                cout<<endl<<"\t\t\tELIMINANDO ALDEANO(S) CON UNA EDAD MAYOR O IGUAL A 60"<<endl<<endl;
                civi.eliminar_edad();
            }
        }

        else if(opc == 3){
            cout<<"\t\t\tCLASIFICAR ALDEANOS"<<endl<<endl;
            size_t opc;

            cout<<"1) CLASIFICAR POR NOMBRE"<<endl;
            cout<<"2) CLASIFICAR POR EDAD"<<endl;
            cout<<"3) CLASIFICAR POR SALUD"<<endl;

            cout<<"\n\nDIGITA UNA OPCION: ";
            cin>>opc;
            cin.ignore();
            system("cls");

            if(opc == 1){
                cout<<"\t\t\tCLASIFICANDO ALDEANOS POR NOMBRE (ORDEN ASCENDENTE)"<<endl<<endl;

                civi.calsificar_nombre();
            }
            
            if(opc == 2){
                cout<<"\t\t\tCLASIFICANDO ALDEANOS POR EDAD (ORDEN DESCENDENTE)"<<endl<<endl;

                civi.clasificar_edad();
            }

            if(opc == 3){
                cout<<"\t\t\tCLASIFICANDO ALDEANOS POR SALUD (ORDEN DESCENDENTE)"<<endl<<endl;

                civi.clasificar_salud();
            }
        }

        else if(opc == 4){
            cout<<"\t\t\tBUSCAR ALDEANO"<<endl<<endl;
            string nombre;

            Aldeano ald;
            cout<<"NOMBRE DEL ALDEANO A BUSCAR: ";
            getline(cin, nombre);

            ald.setNombre(nombre);

            Aldeano *ptr = civi.buscar_aldeano(ald);

            if(ptr == nullptr){
                cout<<"\n\n\t\t\tNO SE ENCONTRO EL ALDEANO QUE QUIERES BUSCAR"<<endl<<endl;
            }

            else{
                system("cls");
                cout<<"\t\t\tALDEANO ENCONTRADO"<<endl<<endl;
                
                cout<<left;
                cout << setw(20)<<"NOMBRE";
                cout << setw(20)<<"EDAD";
                cout << setw(20)<<"SALUD";
                cout << setw(15)<<"GENERO";
                cout << endl<<endl;

                cout<<*ptr<<endl<<endl;
            }
        }

        else if(opc == 5){
            cout<<"\t\t\tMODIFICAR ALDEANO"<<endl<<endl;

            string nombre;
            Aldeano ald;

            cout<<"NOMBRE DEL ALDEANO A MODIFICAR: ";
            getline(cin, nombre);

            ald.setNombre(nombre);

            Aldeano *ptr = civi.buscar_aldeano(ald);

            if(ptr == nullptr){
                cout<<"\n\n\t\t\tNO SE ECONTRO EL ALDEANO"<<endl<<endl;
            }
            else{
                system("cls");
                cout<<"\t\t\tALDEANO ENCONTRADO"<<endl;

                cout<<left;
                cout<<endl;
                cout << setw(20)<<"NOMBRE";
                cout << setw(20)<<"EDAD";
                cout << setw(20)<<"SALUD";
                cout << setw(15)<<"GENERO";
                cout << endl;

                cout<<endl<<*ptr<<endl<<endl;
                system("pause"); system("cls");

                civi.modificar_aldeano(ptr);
            }
        }

        else if(opc == 6){
            cout<<"\t\t\tALDEANOS REGISTRADOS"<<endl<<endl;
            cout<<left;
            cout << "\n";
            cout << setw(20)<<"NOMBRE";
            cout << setw(20)<<"EDAD";
            cout << setw(20)<<"SALUD";
            cout << setw(15)<<"GENERO";
            cout << endl << endl;

            civi.mostrar();
        }

        cout<<endl<<endl;
        system("pause"); system("cls");
    
    }while(opc != 0);
    
}