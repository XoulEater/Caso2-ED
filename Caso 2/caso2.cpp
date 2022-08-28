#include <string>
#include <vector>
#include "param.h"
#include "action.h"
#include "list.h"
#include "dispositivo.h"
#include "room.h"
#include "tipo.h"
#include "proc.h"
#include "tarea.h"

#define BOMBILLO 0
#define COCINA 0

using namespace std;


int main(){

    //=========================================================================//

    // Parametros para los Tipo Bombillo
    Param* brillo = new Param("Brillo", "0");
    Param* color = new Param("Color", "255/255/255");

    List<Param>* bombilloParams = new List<Param>();
    bombilloParams->add(brillo);
    bombilloParams->add(color);

    //=========================================================================//

    // Parametros para las Acciones de los Tipo Bombillo
    List<Param>* offParams = new List<Param>();
    Param* offState = new Param("Brillo", "0");
    offParams->add(offState);
    Action* off = new Action("Off", offParams);

    List<Param>* onParams = new List<Param>();
    Param* onState = new Param("Brillo", "1");
    onParams->add(onState);
    Action* on = new Action("On", offParams);

    // Acciones para los Tipo Bombillo
    List<Action>* bombilloActions = new List<Action>();
    bombilloActions->add(off);
    bombilloActions->add(on);

    //=========================================================================//

    // Creacion del Tipo Bombillo
    Tipo* typeBombillo = new Tipo(0, bombilloActions, bombilloParams);

    // Lista para los Tipos
    List<Tipo>* Types = new List<Tipo>();
    Types->add(typeBombillo);

    //=========================================================================//

    // Creacion del primer Bombillo
    Dispositivo *Bombillo1 = new Dispositivo("Bombillo 1", BOMBILLO, COCINA);
        // Configuracion del Bombillo1 en base al tipo Bombillo
    Bombillo1->SetParams(Types->find(Bombillo1->getType())->getParams());
    Bombillo1->SetActs(Types->find(Bombillo1->getType())->getActions());

    //=========================================================================//

    // Creacion de una lista que alberga los dispositivos de la cocina
    List<Dispositivo>* DispCocina = new List<Dispositivo>();
    DispCocina->add(Bombillo1);

    // Creacion de la Habitacion Cocina
    Room* Room1 = new Room(COCINA, "Cocina", DispCocina);

    //=========================================================================//

    // Lista de acciones que va a ejecutar el Bombillo1 en la Tarea1
    List<Action>* T1Bom1Procs = new List<Action>();
    T1Bom1Procs->add(off);

    // Procedimiento del Bombillo1
    Proc* T1Bombillo1 = new Proc(Bombillo1, T1Bom1Procs);
    
    // Lista para los procedimientos de la Tarea1
    List<Proc>* T1Procs = new List<Proc>();
    T1Procs->add(T1Bombillo1);

    // Creacion de Tarea1: Buenos dias
    Tarea* Tarea1 = new Tarea("Buenos dias", T1Procs);

    return 0;
};