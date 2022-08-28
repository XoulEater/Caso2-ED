#include <string>
#ifndef PARAM 
#define PARAM 1


using namespace std;

class Param
{
    private:
        string nameP;
        string valor;
    public:
        Param(string PnameP, string Pvalor){
            this->nameP = PnameP;
            this->valor = Pvalor;
        }

        string getNameP(){
            return nameP;
        };

        string getValor(){
            return valor;
        };
};

#endif
