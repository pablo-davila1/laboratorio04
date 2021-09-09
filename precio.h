#ifndef PRECIO_H
#define PRECIO_H
#include <string>
#include <stdlib.h>
#include <map>
#include <vector>
using namespace std;

class precio
{
private:
    string exit_rout="", arrival_rout="";

    map<string , map<string,int> >exit; //mapa de mapas

public:
    precio(string,string,map<string , map<string,int> >);
    int show_precioR(string exit_rout, string arrival_rout, map<string , map<string,int> >exit);
    int show_precioL(string exit_rout, string arrival_rout, map<string , map<string,int> >exit);
};

#endif // PRECIO_H
