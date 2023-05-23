/** @mainpage Es una simulación del funcionamiento de un multiprocesador. Cada procesador tiene su propia memoria y es capaz de ejecutar más de un proceso simultáneamente.
&bull; Se inicializa un Cluster con procesadores vacíos y una Area de espera con n prioridades inicializadas 

&bull; Se ejecutaran comandos hasta que se ejecute el comando "fin"
*/

/** @file program.cc
    @brief Programa principal
*/

#ifndef NO_DIAGRAM  
#include <iostream>
#endif
#include "Areadeespera.hh"
#include "Cluster.hh"
using namespace std;


int main() {
    Cluster cluster;
    cluster.configurar_cluster();
    Areadeespera area_de_espera;
    area_de_espera.inicializar();
    
    string comando;
    cin >> comando;
    while (comando != "fin") {
        if (comando == "cc" or comando == "configurar_cluster") {
            cout << "#" << comando << endl;
            cluster.configurar_cluster(); 
        }
        else if (comando == "mc" or comando == "modificar_cluster") {
            string identificador_procesador;
            cin >> identificador_procesador;
            cout << "#" << comando << ' ' << identificador_procesador << endl;

            cluster.modificar_cluster(identificador_procesador);
        }
        else if (comando == "ap" or comando == "alta_prioridad") {
            string prioridad;
            cin >> prioridad;
            cout << "#" << comando << ' ' << prioridad << endl;
            area_de_espera.alta_prioridad(prioridad); 
        }
        else if (comando == "bp" or comando == "baja_prioridad") {
            string prioridad;
            cin >> prioridad;
            cout << "#" << comando << ' ' << prioridad << endl;
            area_de_espera.baja_prioridad(prioridad); 
        }
        else if (comando == "ape" or comando == "alta_proceso_espera") {
            string prioridad;
            cin >> prioridad;
            Proceso p;
            p.inicializar();
            cout << "#" << comando << ' ' << prioridad << ' ' << p.identificador_del_proceso() << endl;
            area_de_espera.alta_proceso_espera(prioridad, p); 
        }
        else if (comando == "app" or comando == "alta_proceso_procesador") {
            string identificador_procesador;
            cin >> identificador_procesador;
            Proceso p;
            p.inicializar();
            cout << "#" << comando << ' ' << identificador_procesador << ' ' << p.identificador_del_proceso() << endl;
            cluster.alta_proceso_procesador(identificador_procesador, p); 
        }
        else if (comando == "bpp" or comando == "baja_proceso_procesador") {
            string identificador_procesador;
            cin >> identificador_procesador;
            int identificador_proceso;
            cin >> identificador_proceso;
            cout << "#" << comando << ' ' << identificador_procesador << ' ' << identificador_proceso << endl;
            cluster.baja_proceso_procesador(identificador_procesador, identificador_proceso); 
        }
        else if (comando == "epc" or comando == "enviar_procesos_cluster") {
            int n;
            cin >> n;
            cout << '#' << comando << " " << n << endl;
            area_de_espera.enviar_procesos_cluster(n, cluster); 
        }
        else if (comando == "at" or comando == "avanzar_tiempo") {
            int tiempo;
            cin >> tiempo;
            cout << "#" << comando << ' ' << tiempo << endl;
            cluster.avanzar_tiempo(tiempo); 
        }
        else if (comando == "ipri" or comando == "imprimir_prioridad") {
            string prioridad;
            cin >> prioridad;
            cout << "#" << comando << ' ' << prioridad << endl;
            area_de_espera.imprimir_prioridad(prioridad); 
        }
        else if (comando == "iae" or comando == "imprimir_area_espera") {
            cout << "#" << comando << endl;
            area_de_espera.imprimir_area_espera(); 
        }
        else if (comando == "ipro" or comando == "imprimir_procesador") {
            string identificador_procesador;
            cin >> identificador_procesador;
            cout <<  "#" << comando << ' ' << identificador_procesador << endl;
            cluster.imprimir_procesador(identificador_procesador); 
        }
        else if (comando == "ipc" or comando == "imprimir_procesadores_cluster") {
            cout << "#" << comando << endl;
            cluster.imprimir_procesadores_cluster(); 
        }
        else if (comando == "iec" or comando == "imprimir_estructura_cluster") {
            cout << "#" << comando << endl;
            cluster.imprimir_arbol(); 
        }
        else if (comando == "cmp" or comando == "compactar_memoria_procesador") {
            string identificador_procesador;
            cin >> identificador_procesador;
            cout << "#" << comando <<  ' ' << identificador_procesador << endl;
            cluster.compactar_memoria_procesador(identificador_procesador); 
        }
        else if (comando == "cmc" or comando == "compactar_memoria_cluster") {
            cout <<"#" << comando << endl;
            cluster.compactar_memoria_cluster(); 
        }
        cin >> comando;
    }
}