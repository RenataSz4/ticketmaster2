#include "menu/menu.h"

Menu mainMenu ({
    {'1', {"Administrador", [] () {  }}},
    {'2', {"Cliente", [] () {  }}}
}, "MENÚ PRINCIPAL");

int main () {
    mainMenu.display(true, true);
}