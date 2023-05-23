#include "Proceso.hh"

Proceso::Proceso() {
    memoria_que_ocupa = 0;
    tiempo = 0;
    identificador_proceso = 0;
}

void Proceso::inicializar() {
    cin >> identificador_proceso >> memoria_que_ocupa >> tiempo;
    tiempo_restante = tiempo;
}

void Proceso::modificar_tiempo_restante(const int& tiempo) {
    tiempo_restante = tiempo_restante - tiempo;
}

void Proceso::imprimir_proceso() const{
    cout << identificador_proceso << ' ' << memoria_que_ocupa << ' ' << tiempo;
}

void Proceso::imprimir_proceso_tiempo_dif() const{
    cout << identificador_proceso << ' ' << memoria_que_ocupa << ' ' << tiempo_ejecucion_restante();
}

int Proceso::identificador_del_proceso() const{
    return identificador_proceso;
}

int Proceso::memoria_ocupada() const{
    return memoria_que_ocupa;
}

int Proceso::tiempo_ejecucion() const{
    return tiempo;
}

int Proceso::tiempo_ejecucion_restante() const{
    return tiempo_restante;
}