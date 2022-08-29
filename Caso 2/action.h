#include "param.h"
#include <string>
#include "List.h"

#ifndef ACTION 

#define ACTION 1

class Action
{
    private:
        string nameA;
        List<Param>* modifications = new List<Param>();
    public:
        // Constructor
        Action(string Pname, List<Param>* Pmodifications){
            this->nameA = Pname;
            this->modifications = Pmodifications;
        }

        // Retorna el nombre de la Accion
        string getName(){
            return nameA;
        }
        
        // Retorna la lista con las Parametros a modificar en la Tarea
        List<Param>* getModif(){
            return modifications;
        }
};



#endif