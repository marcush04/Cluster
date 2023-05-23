/** @file Procesador.hh
    @brief Especificación de la clase Procesador 
*/

#ifndef _PROCESADOR_HH_
#define _PROCESADOR_HH_

#include "Proceso.hh"

#ifndef NO_DIAGRAM          
#include <list>      
#include <iostream>   
#include <string>
#include <map>
#include <set>
using namespace std;
#endif                      

/** @class Procesador
    @brief Representa un procesador con memoria
*/
class Procesador
{
public:
//Constructoras 

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un procesador.
      \pre <em>Cierto</em>
      \post El resultado es un procesador vacío
  */   
Procesador();


//Modificadoras

  /** @brief Inicializa los parámetros del procesador 

      \pre El parámetro implícito no está inicializado
      \post El parámetro implícito pasa a estar inicializado
  */   
void inicializar();

  /** @brief Agrega un proceso al procesador

      \pre <em>Cierto</em>
      \post El proceso se ejecuta en el parámetro implícito
  */  
void agregar_proceso_activo(Proceso& proceso);

  /** @brief Elimina un proceso del procesador

      \pre <em>Cierto</em>
      \post El proceso deja de ejecutarse en el parámetro implícito
  */  
void elimina_proceso_activo_directo(const int& identificador_proceso);

  /** @brief Elimina un proceso del procesador si ha transcurrido el suficiente tiempo

      \pre <em>Cierto</em>, el tiempo es un entero no negativo
      \post El proceso deja de ejecutarse en el parámetro implícito si ha superado o igualado el tiempo del transcurrido
  */  
void elimina_proceso_activo_tiempo(const int& tiempo_actual);

  /** @brief Compacta los procesos activos en el procesador

      \pre <em>Cierto</em>
      \post Se han compactado los procesos del parámetro implícito
  */  
void compactar();

  /** @brief Actualiza el espacio de memoria restante cuando borremos un proceso
      \pre <em>Cierto</em>
      \post Actualiza el espacio de memoria restante del parámetro implícito cuando borremos un proceso
  */
void actualizar_memoria_restante_add(int size);

  /** @brief Actualiza el espacio de memoria restante cuando añadamos un proceso
      \pre <em>Cierto</em>
      \post Actualiza el espacio de memoria restante del parámetro implícito cuando añadamos un proceso
  */
void actualizar_memoria_restante_sub(Proceso& proceso);

//Consultoras

  /** @brief Consultora que indica si el procesador tiene procesos activos
      \pre <em>Cierto</em>
      \post El resultado indica si el parámetro implícito tiene procesos activos o no
  */
bool procesador_activo() const;

  /** @brief Consultora que indica si el procesador tiene activo ese proceso
      \pre <em>Cierto</em>
      \post El resultado indica si el parámetro implícito tiene activo el proceso o no
  */
bool contiene_proceso(const int& identificador_proceso) const;

  /** @brief Escribe los procesos activos del procesador
      \pre El parámetro implícito no está vacío
      \post Escribe los procesos activos del parámetro implícito en orden creciente y con los datos de cada uno
  */
void imprimir_procesador_procesador() const; //falta hacer una funcion en el proceso

  /** @brief Consultora que indica la cantidad de memoria libre del procesador
      \pre <em>Cierto</em>
      \post El resultado indica la memoria libre del parámetro implícito
  */
int cantidad_memoria_libre() const;

  /** @brief Consultora del tamaño del agujero más pequeño y a la vez más grande o igual que lo que ocupa el proceso
      \pre memoria_proceso > 0
      \post El resultado devuelve el tamaño del agujero más pequeño y a la vez más grande o igual que lo que ocupa el proceso del parámetro implícito
  */
int revisar_agujeros(const int& memoria_proceso) const;


private:
  /** @brief Tamaño total del procesador */
  int size;
  /** @brief  Memoria libre del procesador*/
  int memoria_restante;
  /** @brief Mapa ordenado de la posición inicial de cada proceso y cada proceso */
  map<int, Proceso> pos_proceso;//Pos inicial y proceso
  /** @brief Mapa ordenado del identificador y la posición del proceso */
  map<int,int> id_pos_memoria;//Id proceso y posición proceso
  /** @brief Mapa ordenado del tamaño de los huecos y un set de las posiciones iniciales de estos */
  map<int,set<int>> size_pos_memoria;//tamaño del hueco y posiciones donde esta 
  };
#endif
