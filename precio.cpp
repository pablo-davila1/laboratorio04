#include "precio.h"


precio::precio(string _exit_rout, string _arrival_rout,map<string , map<string,int> >_exit)
{
    exit_rout = _exit_rout;
    arrival_rout = _arrival_rout;
    exit = _exit;
}

int precio::show_precioR(string exit_rout, string arrival_rout,map<string , map<string,int> >exit)
{
    vector <string>ruta;
    map<string,int>sup;
    bool one = true, two = true;
    int price=0;
    while (true){
        sup = exit[exit_rout];
        ruta.push_back(exit_rout);
        map<string, int>::iterator i;
        map<string, int>::reverse_iterator j;
        i = sup.begin();
        j = sup.rbegin();
        for (int unsigned it = 0; it<ruta.size() ; it++){
            if (i->first == ruta[it])
                one = false;
            else if (j->first == ruta[it])
                two = false;
        }
        if(exit_rout == arrival_rout)
            break;
        else if (one == true){
            exit_rout = i->first;
            price += i->second;
        }
        else if (two == true){
            exit_rout = j->first;
            price += j->second;
        }
        one = true;
        two = true;

    }

    return price;

}

int precio::show_precioL(string exit_rout, string arrival_rout,map<string, map<string, int> > exit)
{
    vector <string>ruta;
    map<string,int>sup;
    bool one = true, two = true;
    int price=0;
    while (true){
        sup = exit[exit_rout];
        ruta.push_back(exit_rout);
        map<string, int>::iterator j;
        map<string, int>::reverse_iterator i;
        j = sup.begin();
        i = sup.rbegin();
        for (int unsigned it = 0; it<ruta.size() ; it++){
            if (i->first == ruta[it])
                one = false;
            else if (j->first == ruta[it])
                two = false;
        }
        if(exit_rout == arrival_rout)
            break;
        else if (one == true){
            exit_rout = i->first;
            price += i->second;
        }
        else if (two == true){
            exit_rout = j->first;
            price += j->second;
        }
        one = true;
        two = true;

    }

    return price;

}
