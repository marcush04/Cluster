/** @file Areadeespera.hh
    @brief Especificación de la clase Área de espera
*/

#ifndef _AREA_DE_ESPERA_HH_
#define _AREA_DE_ESPERA_HH_

#include "Proceso.hh" 
#include "Cluster.hh"

#ifndef NO_DIAGRAM 
#include <list>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#endif


/** @class Areadeespera
    @brief Representa una área de espera de procesos. 

    Se ejecuta automáticamente al declarar una área de espera.
    Puede contener procesos. Puede usarse para enviar los procesos al cluster; en ese caso, los procesos se sacan de la área de espera en función de su prioridad
*/
class Areadeespera
{

public:
    //Constructoras
    
    /** @brief Creadora por defecto.
        \pre <em>Cierto</em>
        \post El resultado es una área de espera vacia
    */
    Areadeespera();


    //Modificadoras

    /** @brief Inicializa los valores de la área de espera
        \pre El parámetro implícito existe
        \post Inicializa los valores del parámetro implícito
    */
    void inicializar();

    /** @brief Agrega un proceso pendiente a la área de espera
        \pre El proceso no existe en la prioridad y la prioridad existe
        \post Agrega el proceso en la prioridad al parámetro implícito
    */
    void alta_proceso_espera(const string& prioridad, Proceso& proceso);

    /** @brief Elimina un proceso pendiente de la área de espera
        \pre El proceso existe 
        \post Elimina el proceso de mayor antigüedad de la prioridad del parámetro implícito
    */
    void eliminar_proceso_pendiente(const string& prioridad, Proceso& proceso);

    /** @brief Añade una prioridad a la área de espera
        \pre El parámetro implícito está inicializado
        \post Añade la prioridad al parámetro implícito
    */
    void alta_prioridad(const string& prioridad);

    /** @brief Elimina una prioridad de la área de espera
        \pre El parámetro implícito está inicializado
        \post Elimina la prioridad del parámetro implícito
    */
    void baja_prioridad(const string& prioridad);

    /** @brief Envia n procesos de la área de espera al cluster en orden de prioridad y antigüedad de los procesos
        \pre n es un entero no negativo
        \post Envia n procesos al cluster en orden de prioridad y los intenta colocar, si no han sido colocados vuelven a ser añadidos
    */
    void enviar_procesos_cluster(int n, Cluster& cluster);


    //Consultoras

    /** @brief Consultora que indica si existe una prioridad en la área de espera
        \pre <em>Cierto</em>
        \post El resultado indica si la prioridad existe en el parámetro implícito o no
    */
    bool existe_prioridad(const string& prioridad) const;

    /** @brief Consultora que indica si hay procesos pendientes
        \pre <em>Cierto</em>
        \post El resultado indica si existen procesos pendientes o no 
    */
    bool hay_procesos_pendientes(const string& prioridad) const;

    /** @brief Consultora que indica si existe un proceso en una prioridad
        \pre <em>Cierto</em>
        \post El resultado indica si el proceso existe en la prioridad del parámetro implícito o no
    */
    bool existe_proceso(const string& prioridad, Proceso& proceso) const;

    /** @brief Escribe los datos de la prioridad
        \pre <em>Cierto</em>
        \post Escribe los datos del parámetro implícito
    */
    void imprimir_prioridad(const string& prioridad) const;

    /** @brief Escribe los datos de todas las prioridades del área de espera
        \pre <em>Cierto</em>
        \post Escribe los datos de todas las prioridades del parámetro implícito
    */
    void imprimir_area_espera() const;

private:
    /** @Struct contenido @brief Struct que contiene los procesos colocados y rechazados y una lista ordenada por antigüedad de los procesos pendientes */
    struct contenido {
        /** @brief Numero de procesos colocados */
        int colocados;
        /** @brief Numero de procesos rechazados */
        int rechazados;
        /** @brief Lista de procesos de una prioridad */
        list<Proceso> lista;
    };
    /** @brief Mapa ordenador de las prioridades con respectivos procesos */
    map<string, contenido> procesos_pendientes;
};
#endif
