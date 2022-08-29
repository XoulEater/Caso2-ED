#include "param.h"
#include "action.h"
#include "List.h"
#include <string>

#ifndef DISP 

#define DISP 1

using namespace std;

class Dispositivo {
    private: 
        string nameD;
        int typeID;
        int roomID; 
        List<Param>* params = new List<Param>();
        List<Action>* actions = new List<Action>();

    public:
        // Constructor
        Dispositivo(string PnameD, int PtypeID, int ProomID) {
            this->nameD = PnameD;
            this->typeID = PtypeID;
            this->roomID = ProomID;
            this->params = NULL;
            this->actions = NULL;
        }

        // Retorna el nombre del Dispositivo
        string getNameD() {
            return nameD;
        }

        // Retorna el ID del Tipo del Dispositivo
        int getType() {
            return typeID;
        }

        // Retorna el ID de la Habitacion del Dispositivo
        int getRoom(){
            return roomID;
        };   

        // Define los Parametros del Dispositivo
        void SetParams(List<Param>* Pparams) {
            this->params = Pparams;
        }

        // Define las Acciones del Dispositivo
        void SetActs(List<Action>* Pactions) {
            this->actions = Pactions;
        }

        // Retorna los Parametros del Dispositivo
        List<Param>* getParams(){
            return params;
        } 

        // Retorna las Acciones del Dispositivo
        List<Action>* getActions(){
            return actions;
        } 

};

#endif