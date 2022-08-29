#include "dispositivo.h"
#include "action.h"
#include "List.h"


#ifndef PROC 

#define PROC 1

using namespace std;

class Proc
{
    private:
        Dispositivo* Disp;
        List<Action>* actions = new List<Action>(); 
    public:
        // Constructor 
        Proc(Dispositivo *Pdispositvo, List<Action>* Pactions){
            this->Disp = Pdispositvo;
            this->actions = Pactions;
        }

        // Retorna la lista de Actiones del Procedimiento
        List<Action>* getProcActions(){
            return actions;
        }
    
        // Retorna el Dispositvo involucrado en el Procemiento
        Dispositivo* getProcDisp(){
            return Disp;
        }

};



#endif