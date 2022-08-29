#include <string>
#include "List.h"
#include "proc.h"

#ifndef TAREA 

#define TAREA 1

using namespace std;

class Tarea
{
    private:
        string nameH;
        List<Proc>* procs = new List<Proc>(); 
    public:
        // Constructor
        Tarea(string PnameH, List<Proc>* Pprocs){
            this->nameH = PnameH;
            this->procs = Pprocs;
        }

        // Retorna los Procedimientos de la Tarea
        List<Proc>* getTProcs(){
            return procs;
        }
        
        // Retorna el nombre de la Tarea
        string getNameh(){
            return nameH;
        }
};



#endif