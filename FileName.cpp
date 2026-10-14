
#include <iostream>
#include <string>
using namespace std;

// CLASSE SESSIO USUARI
class SessioUsuari {

private:
    // Atributs privats
    string nomUsuari;
    int tempsLimitSegons;
    bool activa;

    // Funcio privada per tancar la sessio
    void tancarSessio() {
        activa = false;
    }

public:

    // 1. Constructor per defecte
    SessioUsuari()
        : nomUsuari("convidat"),
        tempsLimitSegons(300),
        activa(true) {
    }

    // 2. Constructor amb un parametre
    explicit SessioUsuari(string nom)
        : nomUsuari(nom),
        tempsLimitSegons(600),
        activa(true) {
    }

    // 3. Constructor amb dos parametres
    SessioUsuari(string nom, int temps)
        : nomUsuari(nom),
        tempsLimitSegons(60),
        activa(true) {

        // Comprovem que el temps sigui valid
        if (temps > 0) {
            tempsLimitSegons = temps;
        }
    }

    // Consultar el nom
    string getNomUsuari() const {
        return nomUsuari;
    }

    // Consultar si la sessio esta activa
    bool isActiva() const {
        return activa;
    }

    // Ampliar el temps de la sessio
    void ampliarTemps(int segons) {

        if (segons > 0) {
            tempsLimitSegons =
                tempsLimitSegons + segons;
        }
        else {
            cout << "Temps no valid" << endl;
        }
    }

    // Destructor
    ~SessioUsuari() {

        if (activa) {
            tancarSessio();

            cout << "[AUDITORIA] La sessió de '"
                << nomUsuari
                << "' s'ha tancat automàticament"
                << " en sortir d'àmbit."
                << endl;
        }
    }
};

int main() {

    // PROVA 1: Constructor per defecte
    {
        SessioUsuari sessio1;

        cout << "Usuari: "
            << sessio1.getNomUsuari() << endl;

        cout << "Activa: "
            << sessio1.isActiva() << endl;

        sessio1.ampliarTemps(100);
        sessio1.ampliarTemps(-20);
    }

    // PROVA 2: Constructor amb un parametre
    {
        SessioUsuari sessio2("Didac");

        cout << "Usuari: "
            << sessio2.getNomUsuari() << endl;
    }

    // PROVA 3: Constructor complet
    {
        SessioUsuari sessio3("Maria", 0);

        cout << "Usuari: "
            << sessio3.getNomUsuari() << endl;
    }

    return 0;
}
