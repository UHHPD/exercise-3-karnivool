#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


double poisson(double mu, int k) {
    return 0;
}

int main() {
    ifstream f_daten("datensumme.txt");

    int zaehler[11] = {0};

    int n_i;
    while (true) {
        f_daten >> n_i;
        if (f_daten.eof()) { break; }

        zaehler[n_i]++;
    }

    ofstream f_hist("hist.txt");
    for (int i = 0; i < size(zaehler); i++) {
        cout << i << ":" << zaehler[i] << endl;
        f_hist << i << " " << zaehler[i] << endl;
    }

    f_daten.close();
    f_hist.close();
}