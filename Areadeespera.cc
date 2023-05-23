#include "Areadeespera.hh"

Areadeespera::Areadeespera() {}

//Modificadoras

void Areadeespera::inicializar(){
    int num;
    cin >> num;
    string prioridad;

    for (int i = 0; i < num; ++i){
        cin >> prioridad;
        contenido contingut;
        list<Proceso> lista;
        contingut.lista = lista;
        contingut.colocados = 0;
        contingut.rechazados = 0;
        procesos_pendientes[prioridad] = contingut;
    }
}

void Areadeespera::alta_proceso_espera(const string& prioridad, Proceso& proceso) {
    map<string, contenido>::iterator it = procesos_pendientes.find(prioridad);
    if(not existe_prioridad(prioridad)) cout << "error: no existe prioridad" << endl;
    else {
        if(existe_proceso(prioridad, proceso)) cout << "error: ya existe proceso" << endl;
        else {
            it->second.lista.insert(it->second.lista.end(), proceso);
        }
    }
}

void Areadeespera::eliminar_proceso_pendiente(const string& prioridad, Proceso& proceso) {
    map<string, contenido>::iterator it = procesos_pendientes.find(prioridad);
    list<Proceso>::iterator it_list = it->second.lista.begin();
    bool found = false;
    while (not found) {
        if ((*it_list).identificador_del_proceso() == proceso.identificador_del_proceso()) {
            found = true;
            (*it).second.lista.erase(it_list);
        }
        else ++it_list;
    }
}

void Areadeespera::alta_prioridad(const string& prioridad) {
    if(existe_prioridad(prioridad)) cout << "error: ya existe prioridad" << endl;
    else {
        contenido contingut;
        contingut.colocados = 0;
        contingut.rechazados = 0;
        procesos_pendientes[prioridad] = contingut;
    }
}

void Areadeespera::baja_prioridad(const string& prioridad) {
    if(not existe_prioridad(prioridad))  cout << "error: no existe prioridad" << endl;
    else {
        if(hay_procesos_pendientes(prioridad)) cout << "error: prioridad con procesos" << endl;
        else {
            map<string, contenido>::iterator it = procesos_pendientes.find(prioridad);
            procesos_pendientes.erase(it);
        }
    }
}

void Areadeespera::enviar_procesos_cluster(int n, Cluster& cluster) {
    map<string, contenido>::iterator it = procesos_pendientes.begin();
    list<Proceso>::iterator it_list = it->second.lista.begin();
    
    while (n != 0 and it != procesos_pendientes.end()) {
        int n2 = it->second.lista.size();
        //Recorremos la prioridad
        while(n2 != 0 and n != 0) {
            if(not it->second.lista.empty()) {
                string procesador_id = cluster.agujero_ajustado(*it_list);

                //en procesador_id quedara el nombre del procesador donde colocaremos el proceso
                //si no se puede colocar sera -1
                if (procesador_id != "-1") {
                    cluster.alta_proceso_procesador(procesador_id, *it_list);
                    ++it->second.colocados;
                    eliminar_proceso_pendiente(it->first, *it_list);
                    it_list = it->second.lista.begin();
                    --n;
                }
                else {
                    ++it->second.rechazados;
                    Proceso& p = *it_list;
                    eliminar_proceso_pendiente(it->first, *it_list);
                    alta_proceso_espera(it->first, p);
                    it_list = it->second.lista.begin();
                }
                --n2;
            }
        }
        ++it;
        if(it != procesos_pendientes.end()) it_list = it->second.lista.begin();
    }
}


//Consultoras

bool Areadeespera::existe_prioridad(const string& prioridad) const{
    map<string, contenido>::const_iterator it = procesos_pendientes.find(prioridad);
    if (it == procesos_pendientes.end()) return false;
    else return true;
}

bool Areadeespera::hay_procesos_pendientes(const string& prioridad) const{
    map<string, contenido>::const_iterator it = procesos_pendientes.find(prioridad);
    if (not it->second.lista.empty()) return true;
    return false;
}

bool Areadeespera::existe_proceso(const string& prioridad, Proceso& proceso) const{
    map<string, contenido>::const_iterator it = procesos_pendientes.find(prioridad);
    list<Proceso>::const_iterator it_list = it->second.lista.begin();
    bool found = false;
    while ((it_list != it->second.lista.end()) and (not found)) {
        if((*it_list).identificador_del_proceso() == proceso.identificador_del_proceso()) found = true;
        else ++it_list;
    }
    return found;
}

void Areadeespera::imprimir_prioridad(const string& prioridad) const{ 
    if(not existe_prioridad(prioridad)) cout << "error: no existe prioridad" << endl;
    else {
        map<string, contenido>::const_iterator it = procesos_pendientes.find(prioridad);
        list<Proceso>::const_iterator it_list = it->second.lista.begin();
        while(it_list != it->second.lista.end()) {
            (*it_list).imprimir_proceso();
            cout << endl;
            ++it_list;
        }
        cout << it->second.colocados << ' ' << it->second.rechazados << endl;
    }
}

void Areadeespera::imprimir_area_espera() const{
    map<string, contenido>::const_iterator it = procesos_pendientes.begin();
    while(it != procesos_pendientes.end()) {
        cout << it->first << endl;
        imprimir_prioridad(it->first);
        ++it;
    }
}