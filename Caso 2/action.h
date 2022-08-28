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
        Action(string Pname, List<Param>* Pmodifications){
            this->nameA = Pname;
            this->modifications = Pmodifications;
        }

        string getName(){
            return nameA;
        }

        List<Param>* getModif(){
            return modifications;
        }
};



#endif