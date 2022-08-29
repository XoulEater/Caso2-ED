# Caso2-ED

Para la resolucion de este caso lleve a cabo la utilizacion de 9 clases, 7 de ellas originales, y las otras 2 tomadas de las lecciones, las cuales van a ser explicadas a continuacion:

- Param
La clase parametro va a representar las caracteristicas de los dispositivos.

- Action
La clase accion representa las modificaciones que se le puede realizar a un dispositivo, contenteniendo en esta una lista de los parametros que modifica.

- Tipo
La clase tipo tiene la funcion de albergar los parametros y las acciones de un determinado tipo de dispositivo, esto facilita la asignacion de las mismas a un dispositivo nuevo. En el caso se define una lista de estos para manejarlos con ID

- Room  
La clase habitacion viene a representar a las habitaciones de la casa, siendo que contiene una lista para dispositvos. En el caso se define una lista de estas para manejarlas con ID

- Dispositivo
La clase dispositivo viene a ser la representacion virtual del dispositivo electronico, en la clase se incluyen datos de este, como son el nombre, el ID de la habitacion, el ID del tipo, una lista para sus parametros y una para sus acciones.

Las siguientes clases se emplean en la realizacion de tareas

- Proc
La clase procedimiento contiene un dispositivo y una lista de acciones que van a ejecutarse en él una vez se ejecute la tarea. 

- Tarea
La clase tarea contiene una lista de procedimientos los cuales se van a ir realizando en orden una vez se ejecute la tarea, los procedimientos pueden afectar diversos dispositivos.

Las ultimas 2 clases fueron creadas por el profesor y son las de la lista enlazada
- List
- Node

Para efectos de la ejecucion del programa en el main se empieza por definir los parametros para los tipos de dispositivos, en este caso se utilizan unicamente 2 tipos, bombillo y coffeemaker (para efectos de generalidad pudieron haber sido cualesquier otro tipo). Posteriormente se crean unas cuantas acciones que modifiquen estos parametros. A partir de esto se crean los 2 tipos y se añaden a una lista de tipos. Ademas creamos dos habitaciones con el nombre Cocina y Cuarto, las cuales agregamos a una lista tambien.

Una vez hecho esto se pueden crear los dispositivos a los cuales se les asigna nombre, tipo y habitacion, en este caso 2 bombillos (bombillo1 en la cocina y bombillo2 en el cuarto) y un coffeemaker (coffeemaker1 en la cocina). Posteriormente se configuran sus acciones y parametros en base a sus tipos. 

Con esto listo es posible empezar a crear tareas, en este caso vamos a hacer una tarea llamada Buenos dias
Para empezar debemos crear los procedimientos, para este caso van a ser 3:
- Apagar Bombillo1
- Encender CoffeeMaker1
- Encender Bombillo2

Con estos procedimientos creamos la tarea

Finalmente pasamos a la ejecucion

Empezamos con ejecutar la Tarea Buenos Dias 
Para esto realizamos varios ciclos:
- El primero recorre los procedimientos de la Tarea
- El segundo recorre las acciones del procedimiento
- El tercero recorre los parametros de la accion 
- El ultimo reccorre los parametros del dispositivo involucrado

Con esto finalmente realizamos el cambio en los parametros 

Ahora ejecutaremos una accion de forma individual
En este caso usaremos la accion Off del CoffeeMaker1
Para la ejecuccion de una accion de forma individual la cantidad de ciclos se reduce a 2:
- El primero recorre los parametros de la accion 
- El segundo reccorre los parametros del dispositivo 

Con esto finalmente realizamos el cambio en los parametros igual









