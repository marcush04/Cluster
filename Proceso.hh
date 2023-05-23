/** @file Proceso.hh
    @brief Especificación de la clase Prenda 
*/


#ifndef _PROCESO_HH_
#define _PROCESO_HH_

#ifndef NO_DIAGRAM          
#include <iostream>    
using namespace std;     
#endif                      

/** @class Proceso
    @brief Representa un proceso con identificador, ocupa una memoria y tiene una durada 
*/
class Proceso
{
public:
//Constructoras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un proceso.
      \pre <em>cierto</em>
      \post El resultado es un proceso no inicializado
  */   
Proceso();


//Modificadoras

  /** @brief Inicializa los atributos
      \pre <em>Cierto</em>
      \post El parámetro implícito se inicializa con sus características
  */
void inicializar();

  /** @brief Actualiza el tiempo de ejecución restante del proceso
      \pre <em>Cierto</em>
      \post Actualiza el tiempo de ejecución restante del parámetro implícito
  */
void modificar_tiempo_restante(const int& tiempo);

//Consultoras

  /** @brief Escribe el proceso con sus atributos
      \pre <em>Cierto</em>
      \post Se escriben los atributos del parámetro implícito
  */
void imprimir_proceso() const;

  /** @brief Escribe el proceso con sus atributos pero con el tiempo restante
      \pre <em>Cierto</em>
      \post Se escriben los atributos del parámetro implícito
  */
void imprimir_proceso_tiempo_dif() const;

  /** @brief Consultora del identificador
      \pre <em>Cierto</em>
      \post Consultora del identificador del parámetro implícito
  */
int identificador_del_proceso() const;

  /** @brief Consultora de la memoria que ocupa el proceso
      \pre <em>Cierto</em>
      \post Consultora de la memoria que ocupa el parámetro implícito
  */
int memoria_ocupada() const;

  /** @brief Consultora del tiempo de ejecución del proceso
      \pre <em>Cierto</em>
      \post Consultora del tiempo de ejecución del parámetro implícito
  */
int tiempo_ejecucion() const;

  /** @brief Consultora del tiempo restante de ejecución del proceso
      \pre <em>Cierto</em>
      \post Consultora del tiempo de ejecución restante del parámetro implícito
  */
int tiempo_ejecucion_restante() const;

private: 
    /** @brief Identificador del proceso */
    int identificador_proceso;
    /** @brief Memoria que ocupa el proceso */
    int memoria_que_ocupa;
    /** @brief Tiempo de ejecución del proceso */
    int tiempo;
    /** @brief Tiempo de ejecución restante del proceso */
    int tiempo_restante;
};
#endif
