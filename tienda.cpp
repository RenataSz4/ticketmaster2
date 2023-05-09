/*  nombre: Cliente
    contribuidores: David Emmanuel Santana Romero
    fecha: 9 de mayo de 2023
*/

#include "tienda.h"
#include <string>
#include <vector>
#include "ticket.h"
#include "cliente.h"
#include <iostream>
#include <iomanip>
using namespace std;

Tienda :: Tienda () {
    inventario.emplace_back();
    inventario.emplace_back(
        "Cuarteto de Nos",
        true,
        100,
        "En un mundo que discrimina y tortura\nQue al diferente le pasa factura\nAl que va contra corriente, tritura\nClausura y quiere esconder como basura\nQue margina, incrimina y censura\nPor delante aprueba y por detrás murmura\nQue castiga al que se va de la estructura\nY que nunca sutura lo que fisura\nY el que desafina en su partitura\nVa contra natura o tiene una intención oscura\nY su lucha será dura con fachadas que parecen blandas\nPero almas que no se fracturan",
        array <int, 4> {2023, 03, 28, 20},
        array <string, 4> {"México", "Baja California", "Tijuana", "BlackBox"}
    );
}

Tienda :: ~Tienda () {
    inventario.clear();
}

void Tienda :: display (Cliente & C) {
    for (int i = 0; i < inventario.size(); i++) {
        inventario[i].display();
        cout << "\tPrecio: " << (C.getCash() >= inventario[i].getPrice() ? "[$" + to_string(inventario[i].getPrice()) + "]" : "<<$" + to_string(inventario[i].getPrice()) + ">>") << endl;
    }
    int boleto;
    do {
        boleto = 0;
        C.displayCash();
        cout << "Especifica el ID de boleto a comprar [0 para regresar]: ";
        cin >> boleto;
        getchar();
        if (boleto < 1 || boleto > inventario.size()) {
            cout << "Regresando ..." << endl;
            break;
        }
        if (inventario[boleto-1].getPrice() > C.getCash()) {
            cout << "A chambear, Buddy. Necesitas $" << fixed << setprecision (2) << (inventario[boleto-1].getPrice() - C.getCash()) << " más." << endl;
            return;
        }
        C.setCash(C.getCash() - inventario[boleto-1].getPrice());
        C.addTicket(inventario[boleto-1]);
        cout << "Transacción completada" << endl << endl;
    } while (boleto != 0);
}