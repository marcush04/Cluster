#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#include <iostream>
using namespace std;

int main() {
    Lavadora w;
    Cubeta c;
    int opcion;
    cin >> opcion;
    while (opcion != -8) {
        if (opcion == -1) {
            int p;
            bool c;
            cin >> p >> c;
            w.inicializar(p, c);
        }
        else if (opcion == -2) {
            int p;
            bool c;
            cin >> p >> c;
            Prenda pre(p, c);
            w.depositar(pre);
        }
        else if (opcion == -3) {
            int p;
            bool c;
            cin >> p >> c;
            Prenda pre(p, c);
            c.depositar(pre);
        }
        else if (opcion == -4) {
            w.completar(c);
        }
        else if (opcion == -5) {
            w.lavar();
        }
        else if (opcion == -6) {
            c.escribir();
        }
        else {
            w.escribir();
        }
    }
}
