#include <iostream>
#include <string>

const int MAX_INVENTORY_SIZE = 10;

using namespace std;

// Funció per mostrar l'inventari
void displayInventory(const string inventory[], int size) {
    cout << "Inventari de l'heroi:" << endl;
    for (int i = 0; i < size; ++i) {
        if (!inventory[i].empty()) {
            cout << i + 1 << ". " << inventory[i] << endl;
        }
    }
    cout << endl;
}

// Funció per afegir un objecte a l'inventari
void addObject(string inventory[], const string& newItem) {
    for (int i = 0; i < MAX_INVENTORY_SIZE; ++i) {
        if (inventory[i].empty()) {
            inventory[i] = newItem;
            cout << "Has afegit " << newItem << " a l'inventari." << endl;
            return;
        }
    }
    cout << "L'inventari esta ple. No es pot afegir mes objectes." << endl;
}

// Funció per eliminar un objecte de l'inventari
void removeObject(string inventory[], int index) {
    if (index >= 1 && index <= MAX_INVENTORY_SIZE) {
        if (!inventory[index - 1].empty()) {
            cout << "Has eliminat " << inventory[index - 1] << " de l'inventari." << endl;
            inventory[index - 1] = "";
        }
        else {
            cout << "L'element seleccionat no existeix a l'inventari." << endl;
        }
    }
    else {
        cout << "Index no valid." << endl;
    }
}

// Funció per afegir diversos objectes a l'inventari
void addMultipleObjects(string inventory[], int count) {
    for (int i = 0; i < count; ++i) {
        string newItem;
        cout << "Entra l'objecte " << i + 1 << ": ";
        cin >> newItem;
        addObject(inventory, newItem);
    }
}

// Funció per buidar completament l'inventari
void clearInventory(string inventory[]) {
    for (int i = 0; i < MAX_INVENTORY_SIZE; ++i) {
        inventory[i] = "";
    }
    cout << "L'inventari s'ha buidat." << endl;
}

int main() {
    string inventory[MAX_INVENTORY_SIZE];

    int option;
    do {
        cout << "Menu:" << endl;
        cout << "1. Afegir objecte" << endl;
        cout << "2. Eliminar objecte" << endl;
        cout << "3. Afegir multiples objectes" << endl;
        cout << "4. Buidar inventari" << endl;
        cout << "0. Sortir" << endl;
        cout << "Selecciona una opcio: ";
        cin >> option;

        switch (option) {
        case 1: {
            string newItem;
            cout << "Entra l'objecte: ";
            cin >> newItem;
            addObject(inventory, newItem);
            break;
        }
        case 2: {
            int index;
            cout << "Entra l'index de l'objecte a eliminar: ";
            cin >> index;
            removeObject(inventory, index);
            break;
        }
        case 3: {
            int count;
            cout << "Quants objectes vols afegir? ";
            cin >> count;
            addMultipleObjects(inventory, count);
            break;
        }
        case 4:
            clearInventory(inventory);
            break;
        case 0:
            cout << "Programa finalitzat." << endl;
            break;
        default:
            cout << "Opcio no valida. Torna a intentar." << endl;
        }

        displayInventory(inventory, MAX_INVENTORY_SIZE);

    } while (option != 0);

    return 0;
}