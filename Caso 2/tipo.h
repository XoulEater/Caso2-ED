#include <string>
#include "action.h"
#include "param.h"
#include "List.h"

#ifndef TIPO 

#define TIPO 1

using namespace std;

class Tipo
{
    private:
        int typeID;
        List<Action>* defaultActions = new List<Action>();
        List<Param>* defaultParams = new List<Param>();
    public:
        // Constructor
        Tipo(int PtypeID, List<Action>* PdefaultActions, List<Param>* PdefaultParams){
            this->typeID = PtypeID;
            this->defaultActions = PdefaultActions;
            this->defaultParams = PdefaultParams;
        }

        // Retorna las Acciones por defecto del Tipo 
        List<Action>* getActions(){
            return defaultActions;
        }
        
        // Retorna los Parametros por defecto del Tipo 
        List<Param>* getParams(){
            return defaultParams;
        }        
};

#endif