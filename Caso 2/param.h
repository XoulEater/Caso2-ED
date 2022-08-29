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
        // Constructor
        Param(string PnameP, string Pvalor){
            this->nameP = PnameP;
            this->valor = Pvalor;
        }
        // Retorna el nombre del Parametro
        string getNameP(){
            return nameP;
        }

        // Retorna el valor del Parametro
        string getValor(){
            return valor;
        }

        // Define el valor del Parametro
        void setValor(string Pvalor){
            this->valor = Pvalor;
        }
};

#endif
