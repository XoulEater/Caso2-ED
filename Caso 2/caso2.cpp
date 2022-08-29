#include <string>
#include <vector>
#include <iostream>
#include "param.h"
#include "action.h"
#include "list.h"
#include "dispositivo.h"
#include "room.h"
#include "tipo.h"
#include "proc.h"
#include "tarea.h"

#define BOMBILLO 0
#define COFFEEMAKER 1
#define COCINA 0
#define CUARTO 1

using namespace std;


int main(){

    //=========================================================================//

    // Parametros para los Tipo Bombillo
    Param* brillo = new Param("Brillo", "0");
    Param* color = new Param("Color", "255/255/255");

    List<Param>* bombilloParams = new List<Param>();
    bombilloParams->add(brillo);
    bombilloParams->add(color);

    // Parametros para los Tipo CoffeeMaker
    Param* estado = new Param("Estado", "Off");

    List<Param>* coffeemakerParams = new List<Param>();
    coffeemakerParams->add(estado);

    //=========================================================================//

    // Parametros para las Acciones de los Tipo Bombillo
    List<Param>* offBParams = new List<Param>();
    Param* offBState = new Param("Brillo", "0");
    offBParams->add(offBState);
    Action* offB = new Action("Off", offBParams);

    List<Param>* onBParams = new List<Param>();
    Param* onBState = new Param("Brillo", "1");
    onBParams->add(onBState);
    Action* onB = new Action("On", onBParams);

    List<Param>* redBParams = new List<Param>();
    Param* redBState = new Param("Color", "255/0/0");
    redBParams->add(redBState);
    Action* redB = new Action("Rojo", redBParams);


    // Parametros para las Acciones de los Tipo CoffeeMaker
    List<Param>* offCMParams = new List<Param>();
    Param* offCMState = new Param("Estado", "Off");
    offCMParams->add(offCMState);
    Action* offCM = new Action("Off", offCMParams);

    List<Param>* onCMParams = new List<Param>();
    Param* onCMState = new Param("Estado", "On");
    onCMParams->add(onCMState);
    Action* onCM = new Action("On", onCMParams);


    // Acciones para los Tipo Bombillo
    List<Action>* bombilloActions = new List<Action>();
    bombilloActions->add(offB);
    bombilloActions->add(onB);
    bombilloActions->add(redB);

    // Acciones para los Tipo CoffeeMaker
    List<Action>* coffeemakerActions = new List<Action>();
    coffeemakerActions->add(offCM);
    coffeemakerActions->add(onCM);

    //=========================================================================//

    // Creacion del Tipo Bombillo
    Tipo* typeBombillo = new Tipo(0, bombilloActions, bombilloParams);

    // Creacion del Tipo CoffeeMaker
    Tipo* typeCoffeeMaker = new Tipo(0, coffeemakerActions, coffeemakerParams);

    // Lista para los Tipos
    List<Tipo>* Types = new List<Tipo>();
    Types->add(typeBombillo);
    Types->add(typeCoffeeMaker);

    //=========================================================================//

    // Creacion del primer Bombillo
    Dispositivo *Bombillo1 = new Dispositivo("Bombillo 1", BOMBILLO, COCINA);
        // Configuracion del Bombillo1 en base al tipo Bombillo
    Bombillo1->SetParams(Types->find(Bombillo1->getType())->getParams());
    Bombillo1->SetActs(Types->find(Bombillo1->getType())->getActions());


    // Creacion del segundo Bombillo
    Dispositivo *Bombillo2 = new Dispositivo("Bombillo 2", BOMBILLO, CUARTO);
        // Configuracion del Bombillo2 en base al tipo Bombillo
    Bombillo2->SetParams(Types->find(Bombillo2->getType())->getParams());
    Bombillo2->SetActs(Types->find(Bombillo2->getType())->getActions());


    // Creacion del primer CoffeeMaker
    Dispositivo *CoffeeMaker1 = new Dispositivo("CoffeeMaker 1", COFFEEMAKER, COCINA);
        // Configuracion del CoffeeMaker1 en base al tipo CoffeeMaker
    CoffeeMaker1->SetParams(Types->find(CoffeeMaker1->getType())->getParams());
    CoffeeMaker1->SetActs(Types->find(CoffeeMaker1->getType())->getActions());

    //=========================================================================//

    // Creacion de una lista que alberga los dispositivos de la cocina
    List<Dispositivo>* DispCocina = new List<Dispositivo>();
    DispCocina->add(Bombillo1);
    DispCocina->add(CoffeeMaker1);

    // Creacion de la Habitacion Cocina
    Room* Room1 = new Room(COCINA, "Cocina", DispCocina);

    // Creacion de una lista que alberga los dispositivos del cuarto
    List<Dispositivo>* DispCuarto = new List<Dispositivo>();
    DispCuarto->add(Bombillo2);

    // Creacion de la Habitacion Cuarto
    Room* Room2 = new Room(CUARTO, "Cuarto", DispCuarto);

    //=========================================================================//

    // Lista de acciones que va a ejecutar el Bombillo1 en la Tarea1
    List<Action>* T1Bom1Procs = new List<Action>();
    T1Bom1Procs->add(offB);

    // Procedimiento del Bombillo1
    Proc* T1Bombillo1 = new Proc(Bombillo1, T1Bom1Procs);

    // Lista de acciones que va a ejecutar el Bombillo2 en la Tarea1
    List<Action>* T1Bom2Procs = new List<Action>();
    T1Bom2Procs->add(onB);

    // Procedimiento del Bombillo2
    Proc* T1Bombillo2 = new Proc(Bombillo2, T1Bom2Procs);

    // Lista de acciones que va a ejecutar el CoffeeMaker1 en la Tarea1
    List<Action>* T1Coffee2Procs = new List<Action>();
    T1Coffee2Procs->add(onCM);

    // Procedimiento del CoffeeMaker1
    Proc* T1CoffeeMaker2 = new Proc(CoffeeMaker1, T1Coffee2Procs);

    // Lista para los procedimientos de la Tarea1
    List<Proc>* T1Procs = new List<Proc>();
    T1Procs->add(T1Bombillo1);
    T1Procs->add(T1Bombillo2);
    T1Procs->add(T1CoffeeMaker2);

    // Creacion de Tarea1: Buenos dias
    Tarea* Tarea1 = new Tarea("Buenos dias", T1Procs);

    //=========================================================================//

    // Ejecucion de Tareas
    cout << "Ejecutando Tarea: " << Tarea1->getNameh() << ". . ." << endl;

    // Recorrido por la lista de Procedimientos de la Tarea 1
    for (int i = 0; i < Tarea1->getTProcs()->getSize(); i++)
    {
        // Recorrido por cada uno de los Procedimientos
        for (int p = 0; p < Tarea1->getTProcs()->find(i)->getProcActions()->getSize(); p++)
        {
            // Dispositivo al que se le van a realizar los cambios
            Dispositivo* DispAfectado = Tarea1->getTProcs()->find(i)->getProcDisp();
            // Lista con las modificaciones a realizar en el Dispositivo
            List<Param>* Modificaciones = Tarea1->getTProcs()->find(i)->getProcActions()->find(p)->getModif();

            // Recorrido por los Parametros del Dispositivo
            for (int t = 0; t < DispAfectado->getParams()->getSize(); t++)
            {
                // Recorrido por las Acciones incluidas en las Modificaciones 
                for (int y = 0; y < Modificaciones->getSize(); y++)
                {
                    // Identificacion del Parametro a modificar 
                    if (Modificaciones->find(y)->getNameP() == DispAfectado->getParams()->find(t)->getNameP())
                    {
                        // Set del nuevo Valor del Parametro 
                        DispAfectado->getParams()->find(t)->setValor(Modificaciones->find(y)->getValor());

                        cout << "El parametro " << Modificaciones->find(y)->getNameP();
                        cout << " del dispositivo " << DispAfectado->getNameD();
                        cout << " ha sido cambiado a " << Modificaciones->find(y)->getValor() << endl;
                    }
                }
            }
        }
    }
    cout << "Ejecucion finalizada" << endl;  
    cout << endl;  

    //=========================================================================//

    // Ejecucion de Accion Individual
    cout << "Ejecutando Accion: " << CoffeeMaker1->getActions()->find(0)->getName();
    cout << " del dispositivo " << CoffeeMaker1->getNameD() << ". . ." << endl;

    // Seleccion de la Accion a ejecutar
    Action* actionTest = CoffeeMaker1->getActions()->find(0);

    // Recorrido por los Parametros del Dispositivo
    for (int c = 0; c < CoffeeMaker1->getParams()->getSize(); c++)
    {
        // Recorrido por las Acciones incluidas en las Modificaciones 
        for (int f = 0; f < actionTest->getModif()->getSize(); f++)
        {
            // Identificacion del Parametro a modificar 
            if (CoffeeMaker1->getParams()->find(c)->getNameP() == actionTest->getModif()->find(f)->getNameP())
            {
                // Set del nuevo Valor del Parametro 
                CoffeeMaker1->getParams()->find(c)->setValor(actionTest->getModif()->find(f)->getValor());

                cout << "El parametro " << actionTest->getModif()->find(f)->getNameP();
                cout << " del dispositivo " << CoffeeMaker1->getNameD();
                cout << " ha sido cambiado a " << actionTest->getModif()->find(f)->getValor() << endl;
            }
        }   
    }
    cout << "Ejecucion finalizada" << endl;  
    

    return 0;
};