#include <iostream>
#include "Console.h"

void Console::showMenu() {
    std::cout << "1. Adauga cheltuiala" << '\n';
    std::cout << "2. Afisare toate cheltuielile" << '\n';
    std::cout << " 3. Eliminare dupa id" << '\n';
    std::cout << " 4. Elimina toate cheltuielile unui apartament" << '\n';
    std::cout << " 5. Elimina toate cheltuielile cu un anumit tip" << '\n';
    std::cout << " 6. Modificarea unei cheltuieli" << '\n';
    std::cout << " 7. Listarea tuturor cheltuielilor unui apartament" << '\n';
    std::cout << " 8. Listeaza toate cheltuielile mai mari decat o valoare data" << '\n';
    std::cout << " 9. Listeaza toate cheltuielile egale cu o valoare data" << '\n';
    std::cout << " a. Afisare suma pentru un anumit tip" << '\n';
    std::cout << " b. Afisare cea mai valoroasa cheltuiala pt un apartament" << '\n';
    std::cout << " c. Ordonare descrescator in functie de tip" << '\n';
    std::cout << " d. Filtrare in fuctie de tip" << '\n';
    std::cout << " e. Filtrare cheltuieli mai mici decat o suma data" << '\n';
    std::cout << " u. Undo" << '\n';
    std::cout << "x. Exit" << '\n';

}

void Console::runMenu() {

    Cheltuiala ap;
    unsigned int nrApartament;
    int sum;
    char choice;
    bool shouldRun = true;
    while (shouldRun) {
        showMenu();
        std::cout << "Dati optiunea: ";
        cin >> choice;
        cin.get();
        switch (choice) {
            case '1': {
                try {
                    std::string type;

                    std::cout << "Introduceti numarul apartamentului: ";
                    std::cin >> nrApartament;
                    std::cout << "Dati tipul(apa, gaz, curent, caldura, altele) = ";
                    cin >> type;
                    const char *type_chr = type.c_str();
                    std::cout << "Dati suma: ";
                    cin >> sum;
                    serv.addCheltuiala(nrApartament, type_chr, sum);
                } catch (invalid_argument) {
                    std::cout << "Tipul poate fi: apa/gaz/curent/caldura/altele" << '\n';
                }
                break;

            }
            case '2': {
                Vector<Cheltuiala> ch = serv.read();
                for (int i = 0; i < ch.size(); i++) {
                    cout << ch[i] << '\n';
                }
                break;
            }
            case '3': {
                int id;
                std::cout << "Dati id-ul cheltuielii pe care doriti sa o stergeti: ";
                std::cin >> id;
                serv.deleteCheltuialaId(id);
                break;
            }
            case '4': {
                int nrAp;
                std::cout << "Dati numarul apartamentului: ";
                std::cin >> nrAp;
                serv.deleteCheltuialaNrApartament(nrAp);
                break;
            }
            case '5': {
                std::string type;
                std::cout << "Dati tipul cheltuieli: ";
                std::cin >> type;
                serv.deleteCheltuialaType(type);
                break;
            }
            case '6': {
                try {
                    int id, sum1, nrAp;
                    std::string type;
                    std::cout << "Dati id-ul cheltuielii ce urmeaza sa fie modificata: ";
                    std::cin >> id;
                    std::cout << "Dati noul numar de apartament: ";
                    std::cin >> nrAp;
                    std::cout << "Dati noul tip de cheltuiala: ";
                    std::cin >> type;
                    std::cout << "Dati noua suma: ";
                    std::cin >> sum1;
                    serv.updateCheltuiala(id, nrAp, type, sum1);
                }
                catch (invalid_argument) {
                    std::cout << "Tipul poate fi: apa/gaz/curent/caldura/altele" << '\n';
                }
                break;
            }
            case '7': {
                int nrAp;
                std::cout << "Dati numarul apartamentului: ";
                std::cin >> nrAp;
                Vector<Cheltuiala> result = serv.read();
                for (int i = 0; i < result.size(); i++) {
                    if (result[i].getNrApartament() == nrAp) {
                        std::cout << result[i];
                    }
                }

                break;
            }
            case '8': {
                std::cout << "Dati suma: ";
                std::cin >> sum;
                Vector<Cheltuiala> result = serv.read();
                for (int i = 0; i < result.size(); i++) {
                    if (result[i].getSum() > sum) {
                        std::cout << result[i] << '\n';
                    }
                }

                break;
            }
            case '9': {
                std::cout << "Dati suma: ";
                std::cin >> sum;
                Vector<Cheltuiala> result = serv.read();
                for (int i = 0; i < result.size(); i++) {
                    if (result[i].getSum() == sum) {
                        std::cout << result[i] << '\n';
                    }
                }

                break;
            }
            case 'a': {
                std::string type;
                std::cout << "Dati tipul: ";
                std::cin >> type;
                std::cout << "Suma pentru " << type << " este: " << serv.getSumByType(type) << '\n';
                break;
            }
            case 'b': {
                int nr;
                std::cout << "Dati numarul apartamentului: ";
                std::cin >> nr;
                std::cout<<serv.getMax(nr) << '\n';

                break;
            }
            case 'c': {
                std::string type;
                std::cout << "Dati tipul: ";
                std::cin >> type;
                serv.sortDescending(type);
                break;
            }
            case 'd': {
                std::string type;
                std::cout << "Dati tipul: ";
                std::cin >> type;
                serv.filterByType(type);
                break;
            }
            case 'e': {
                int sum;
                std::cout << "Dati suma: ";
                std::cin >> sum;
                serv.filterBySum(sum);
                break;
            }
            case 'u': {
                serv.undo();
                break;
            }
            case 'x': {
                shouldRun = false;
                break;
            }
            default: {
                cout << "Optiune gresita!" << '\n';
            }
        }
    }

}


