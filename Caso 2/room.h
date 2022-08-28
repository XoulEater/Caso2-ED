#include <string>
#include "List.h"
#include "dispositivo.h"

#ifndef ROOM 

#define ROOM 1

using namespace std;

class Room
{
    private:
        int roomID;
        string nameR;
        List<Dispositivo>* dispositivos = new List<Dispositivo>(); 
    public:
        Room(int ProomID, string PnameR, List<Dispositivo>* Pdispositivos){
            this->roomID = ProomID;
            this->nameR = PnameR;
            this->dispositivos = Pdispositivos;
        }

};


#endif