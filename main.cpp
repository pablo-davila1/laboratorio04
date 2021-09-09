#include <stdlib.h>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <precio.h>

using namespace std;

void crear(string nombre);

map<string , map<string,int>> constructor(string nombre);

void cear_cargar_altrio(string nombre);

int main()
{
    map<string , map<string,int> >Exit; //mapa de mapas

    map<string,int>arrival; // mapa corriente
    string exit_rout = "";
    string arrival_rout = "";
    precio P(exit_rout,arrival_rout,Exit);


    int opcion = 1;
    while (opcion != 0){

        cout<<"·____________________________________________________·"<<endl;
        cout<<"|                Menu de la practica 4               |"<<endl;
        cout<<"º----------------------------------------------------º"<<endl;
        cout<<"|Para cargar una topoligia existente presione 1 (1)  |"<<endl;
        cout<<"|Para crear una topoligia nueva presione 2 (2)       |"<<endl;
        cout<<"|Para crear una topologia aleatoria presione 3 (3)   |"<<endl;
        cout<<"|Para salir presione (0)                             |"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cin>>opcion;
        cin.ignore();

        switch (opcion) {
        case 1:{
             string nombre_archivo = "";
             cout<<"ingrese el nombre del archivo que contiene la topografia: ";
             cin>>nombre_archivo;

             Exit= constructor(nombre_archivo);

             map<string, int>::iterator i;
             map<string, map<string, int> >::iterator j;
             for(j = Exit.begin(); j!= Exit.end(); j++){
                 cout<<"Clave :"<<j->first<<"-> ";

                 for (i = j->second.begin(); i != j->second.end() ; i++){
                     cout<<" [rout: "<<i->first<<", precio: "<<i->second<<"]";
                 }
                 cout<<endl;
             }

             cout<<"Ingrese el router de partida: ";
             cin>>exit_rout;
             cout<<"Ingrese el router de llegada: ";
             cin>>arrival_rout;
             cout<<"..................precios................."<<endl;
             cout<<"Precio de ruta 1: "<<P.show_precioL(exit_rout,arrival_rout,Exit)<<endl;
             cout<<"Precio de ruta 2: "<<P.show_precioR(exit_rout,arrival_rout,Exit)<<endl;


             break;}
        case 2:{
            string nombre_archivo = "";
            cout<<"ingrese el nombre del archivo que quiere crear: ";
            cin>>nombre_archivo;

            crear(nombre_archivo);

            break;}
        case 3:{
            string nombre_archivo = "";
            cout<<"ingrese el nombre del archivo que quiere crear: ";
            cin>>nombre_archivo;

            cear_cargar_altrio(nombre_archivo);

            break;}
        default:{
            cout<<opcion<<" no es una opcion valida, intente de nuevo";
        }

        }
    }

    return 0;
}

void crear(string nombre){ //"nombre" es el nombre del archivo que contiene la info de la topografia"
    ofstream archivo_w;
    archivo_w.open(nombre, ios::out );
    string enrutador = "",enrutadorL = "",enrutadorR = "", dec="";
    int priceL=0, priceR=0;

    if (archivo_w.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }

    cout<<".________________________________________________________________________________."<<endl;
    cout<<"|                                     AVISO                                      |"<<endl;
    cout<<".--------------------------------------------------------------------------------."<<endl;
    cout<<"|Todos los enrutadores estan enlazados a 2 enrutadores mas y el ultimo enrutador |"<<endl;
    cout<<"|estara conectado con el primer enrutador, le recomiendo hacer el esquema de la  |"<<endl;
    cout<<"|topografia en una hoja antes de crearlo aqui                                    |"<<endl;
    cout<<".--------------------------------------------------------------------------------."<<endl;
    cout<<endl<<endl;

    while(true){

        cout<<"Ingrese el nombre del enrutador que va a agragar: ";
        cin>>enrutador;
        cout<<"Recuerde que cada enrutador posee 2 enlaces."<<endl;
        cout<<"Ingrese el nombre del primer enrrutador al que esta enlazado ''"<<enrutador<<"'' :";
        cin>>enrutadorL;
        cout<<"Ingrese el costo del enlace del enrrutador ''"<<enrutador<<"'' al enrutador ''"<<enrutadorL<<"'' :";
        cin>>priceL;
        cout<<"Ingrese el nombre del segundo enrrutador al que esta enlazado ''"<<enrutador<<"'' :";
        cin>>enrutadorR;
        cout<<"Ingrese el costo del enlace del enrrutador ''"<<enrutador<<"'' al enrutador ''"<<enrutadorR<<"'' :";
        cin>>priceR;

        archivo_w<<enrutador;
        archivo_w<<" ";
        archivo_w<<enrutadorR;
        archivo_w<<" ";
        archivo_w<<priceR;
        archivo_w<<" ";
        archivo_w<<enrutadorL;
        archivo_w<<" ";
        archivo_w<<priceL;
        archivo_w<<endl;


        cout<<"Si desea seguir agregando enrutadores presione ''1'', de lo contrario presione ''0'' :";
        cin>>dec;

        if (dec == "0")
            break;
    }

    archivo_w.close();
}

map<string , map<string,int>> constructor(string nombre){

    map<string , map<string,int> >Exit; //mapa de mapas

    map<string,int>arrival; // mapa corriente

    ifstream archvo_r;
    archvo_r.open(nombre, ios::in);

    string rut="", conet1 = "", conet2 = "";
    int Pconet1=0 ,Pconet2=0;

    if (archvo_r.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }
    else{

        while(!archvo_r.eof() ){
            archvo_r>>rut;
            archvo_r>>conet1;
            archvo_r>>Pconet1;
            archvo_r>>conet2;
            archvo_r>>Pconet2;

            arrival.insert(make_pair(conet1,Pconet1));
            arrival.insert(make_pair(conet2,Pconet2));
            Exit.insert(make_pair(rut,arrival));
            arrival.clear();
        }
    }

    archvo_r.close();
    return Exit;
}

void cear_cargar_altrio(string nombre){
    ofstream archivo_w;
    archivo_w.open(nombre, ios::out );

    int precio1= 0,precio2 = 0,precio3 = 0,precio4 = 0,copprecio1=0,c=0;
    string name = "", Fletter="", Sletter="", Tletter="",init="",end="";
    vector<string>routs,names;

    bool conf = false;

    int a= rand() % 4;
    for (int i =0; i<5+a   ; i++){
        name = rand() % 25 + 65;
        for (int unsigned j = 0; j< names.size() ; j++){
            if (name == names[j]){
                conf = true;
                break;
            }
        }
        names.push_back(name);
        if (conf==false)
            routs.push_back(name);
        conf = false;
    }

    cout<<"la lista de routers creada es: ";
    cout<<"[";
    for (int unsigned i = 0; i< routs.size() ; i++){
        if (i< routs.size()-1)
            cout<<routs[i]<<",";
        else
            cout<<routs[i];
    }
    cout<<"]"<<endl;

    Fletter = routs[0], init= Fletter;
    Sletter = routs[1];
    Tletter = routs[2], end= Tletter;

    precio1=rand() % 20, copprecio1 = precio1;
    precio2=rand() % 20, precio3=precio2, c=precio3;


    precio4 =rand() % 20;

    archivo_w<<Fletter;
    archivo_w<<" ";
    archivo_w<<Sletter;
    archivo_w<<" ";
    archivo_w<<precio2;
    archivo_w<<" ";
    archivo_w<<Tletter;
    archivo_w<<" ";
    archivo_w<<precio1;
    archivo_w<<endl;
    routs.erase(routs.begin(),routs.begin()+3);


     while(routs.size() != 0){
        precio4=rand() % 20;
        Tletter = Fletter;
        Fletter = Sletter;
        Sletter = routs[0];


        routs.erase(routs.begin());
        archivo_w<<Fletter;
        archivo_w<<" ";
        archivo_w<<Sletter;
        archivo_w<<" ";
        archivo_w<<precio4;
        archivo_w<<" ";
        archivo_w<<Tletter;
        archivo_w<<" ";
        archivo_w<<precio3;
        archivo_w<<endl;
        precio3= precio4;


    }
    string Slettercop = Sletter;
    Sletter = Fletter;
    Fletter = Slettercop;
    Tletter = end;

    archivo_w<<Fletter;
    archivo_w<<" ";
    archivo_w<<Sletter;
    archivo_w<<" ";
    archivo_w<<precio4;
    archivo_w<<" ";
    archivo_w<<Tletter;

    precio4=rand() % 20;
    cout<<" "<<precio4<<endl;
    archivo_w<<" ";
    archivo_w<<precio4;
    archivo_w<<endl;

    Tletter= Fletter;
    Fletter = end;
    Sletter = init;

    archivo_w<<Fletter;
    archivo_w<<" ";
    archivo_w<<Sletter;
    archivo_w<<" ";
    archivo_w<<precio1;
    archivo_w<<" ";
    archivo_w<<Tletter;
    archivo_w<<" ";
    archivo_w<<precio4;
    archivo_w<<endl;


}

