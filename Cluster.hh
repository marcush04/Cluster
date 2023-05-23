/** @file Cluster.hh
    @brief Especificación de la clase Cluster 
*/

#ifndef _CLUSTER_HH_
#define _CLUSTER_HH_

#include "Procesador.hh"

#ifndef NO_DIAGRAM  
#include <map>
#include "BinTree.hh"
#include <iostream>
#include <queue>
using namespace std;
#endif

/** @class Cluster
    @brief Representa un cluster 

    Dispone de una serie de procesadores ubicados en forma de árbol y un tiempo pasivo.
*/
class Cluster
  {

public:
//Constructoras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un cluster.
      \pre <em>cierto</em>
      \post El resultado es un cluster no inicializado
  */  
Cluster();


//Modificadoras

  /** @brief Inicializa el cluster
      \pre El parámetro implícito no está inicializado
      \post El parámetro implícito pasa a estar inicializado 
  */
void configurar_cluster();

  /** @brief Modifica una rama del cluster añadiéndole otra rama solo si el procesador existe, no tiene procesos en ejecución y no tiene procesadores auxiliares
      \pre El parámetro implícito está inicializado
      \post El nuevo cluster se coloca en el lugar del procesador del parámetro implícito
  */
void modificar_cluster(const string& identificador_procesador);

  /** @brief El proceso se ejecuta en el procesador
      \pre El parámetro implícito está inicializado
      \post El proceso pasa a ejecutarse en el procesador
  */
void alta_proceso_procesador(const string& identificador_procesador, Proceso proceso);

  /** @brief El proceso deja de ejecutarse en el procesador
      \pre El parámetro implícito está inicializado
      \post El proceso deja de ejecutarse en el procesador
  */
void baja_proceso_procesador(const string& identificador_procesador,const int& identificador_proceso);

  /** @brief Elimina los procesos activos que hayan acabado en un intervalo de tiempo (tiempo)
      \pre t es un entero no negativo
      \post Elimina los procesos activos del parámetro implícito que hayan acabado en un tiempo(tiempo)
  */
void avanzar_tiempo(const int& tiempo);

  /** @brief Mueve todos los procesos hacia el principio de la memoria del procesador especificado
      \pre El procesador existe
      \post Mueve todos los procesos hacia el principio de la memoria del procesador del parámetro implícito, sin dejar huecos, sin solaparse y respetando el orden inicial
  */
void compactar_memoria_procesador(const string& identificador_procesador);

  /** @brief Mueve todos los procesos hacia el principio de la memoria de todos los procesadores del cluster
      \pre El parámetro implícito está inicializado
      \post Mueve todos los procesos hacia el principio de la memoria de todos los procesadores del parámetro implícito, sin dejar huecos, sin solaparse y respetando el orden inicial
  */
void compactar_memoria_cluster();

//Consultoras

  /** @brief Consultora del identificador del procesador en que se tendra que colocar el proceso, si no existe será "-1"
      \pre <em>Cierto</em>
      \post El resultado es el identificador del procesador del parámetro implícito donde se tendrá que colocar el proceso, si no existe será "-1"
  */
string agujero_ajustado(Proceso& proceso) const;

  /** @brief Consultora que indica si existe un procesador en el cluster
      \pre <em>Cierto</em>
      \post El resultado indica si el procesador existe en el parámetro implícito
  */
bool existe_procesador(const string& identificador_procesador) const;

  /** @brief Escribe la estructura del cluster
      \pre El parámetro implícito está inicializado
      \post Escribe la estructura del parámetro implícito
  */
void imprimir_arbol() const;

  /** @brief Escribe los procesos del procesador 
      \pre El procesador existe en el parámetro implícito
      \post Escribe los procesos de dicho procesador por orden creciente de primera posición de memoria, incluyendo dicha posición y el resto de datos de cada proceso
  */
void imprimir_procesador(const string& identificador_procesador) const;

  /** @brief Escribe los procesos de todos los procesadores 
      \pre El procesador existe en el parámetro implícito
      \post Escribe los procesos de todos los procesadores del parámetro implícito por orden creciente de primera posición de memoria, incluyendo dicha posición y el resto de datos de cada proceso
  */
void imprimir_procesadores_cluster() const;


private: 
  /** @brief Inicializa la estructura del cluster
      \pre <em>Cierto</em>
      \post Inicializa la estructura del parámetro implícito
  */
  static void leer_arbol(BinTree<string>& a, map<string, Procesador>& p);
  
  /** @brief Consultora que indica si el procesador no tiene auxiliares y si es el caso junta la estructura del cluster antiguo con el nuevo
      \pre El parámetro implícito está inicializado
      \post Consultora que indica si el procesador del parámetro implícito no tiene auxiliares y si es el caso junta la estructura del parámetro implícito con el nuevo cluster
  */
  static bool grapar(const string& identificador_procesador, BinTree<string>& arbol_previo, BinTree<string>& arbol_grapar);
  
  /** @brief Escribe la estructura del cluster
      \pre El parámetro implícito está inicializado
      \post Escribe la estructura del parámetro implícito
  */
  static void imprimir_arbol_i(const BinTree<string>& a);

private:
    /** @brief Árbol con la estructura de los procesadores */
    BinTree<string> estructura_procesadores;
    /** @brief Mapa ordenado de los procesadores según su identificador */
    map<string, Procesador> procesadores;
};
#endif
