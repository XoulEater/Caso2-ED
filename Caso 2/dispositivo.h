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
        Dispositivo(string PnameD, int PtypeID, int ProomID) {
            this->nameD = PnameD;
            this->typeID = PtypeID;
            this->roomID = ProomID;
            this->params = NULL;
            this->actions = NULL;
        };

        string getNameD() {
            return nameD;
        };

        int getType() {
            return typeID;
        };

        int getRoom() {
            return roomID;
        };   

        void SetParams(List<Param>* Pparams) {
            this->params = Pparams;
        };

        void SetActs(List<Action>* Pactions) {
            this->actions = Pactions;
        };    

};

#endif