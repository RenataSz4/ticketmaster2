#include "menu/menu.h"
#include "cliente.h"
#include "ticket.h"
#include <string>
#include <iostream>
using namespace std;

vector<Cliente> clientes;
void crearUsuario ();
void iniciarSesion ();

Menu adminMenu ({
    // {}
}, "MENÚ DEL ADMINISTRADOR");

Menu clientMenu ({
    {'1', {"Crear usuario", crearUsuario}},
    {'2', {"Iniciar sesión", iniciarSesion}}
}, "MENÚ DEL CLIENTE");

Menu mainMenu ({
    {'1', {"Administrador", [] () { adminMenu.display(true, true); }}},
    {'2', {"Cliente", [] () { clientMenu.display(true, true); }}}
}, "MENÚ PRINCIPAL");

int main () {
    mainMenu.display(true, true);
}

void crearUsuario () {
    cout << "Proporciona una contraseña de 8 a 30 caracteres" << endl;
    string pswd;
    do {
        cout << "Contraseña: ";
        getline(cin, pswd);
    } while (pswd.size() < 8 || pswd.size() > 30);
    clientes.emplace_back(pswd);
}
void iniciarSesion () {
    int id;
    string pswd;
    cout << "ID: ";
    cin >> id;
    getchar();
    if (id < 1 || id > clientes.size()) {
        cout << "USUARIO INEXISTENTE" << endl;
        return;
    }
    for (int attempts = 0; clientes[id-1].getPassword() != pswd; attempts++) {
        if (attempts >= 3) {
            cout << "INTÉNTALO MÁS TARDE" << endl;
            return;
        }
        cout << "Contraseña: ";
        getline(cin, pswd);
    }
    cout << "Sesión iniciada" << endl;
}