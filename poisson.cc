#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

double poisson(double mu, int k);


int main() {
    ifstream f_daten("datensumme.txt");

    int zaehler[11] = {0};

    int n_i;
    int lengthOfDatensumme = 0;
    while (true) {
        f_daten >> n_i;
        if (f_daten.eof()) { break; }

        zaehler[n_i]++;
        lengthOfDatensumme++;
    }

    ofstream f_hist("histpoi.txt");
    double mu_ex2 = 3.11538;
    for (int i = 0; i < size(zaehler); i++) {
        cout << i << ":" << zaehler[i] << endl;
        f_hist << i << " " << zaehler[i] << " " << lengthOfDatensumme * poisson(mu_ex2, i) << endl;

    }

    //Aufgabe 1c:
    

    f_daten.close();
    f_hist.close();
}

double poisson(double mu, int k){
    return (pow(mu, k) * exp(-mu)) / tgamma(k + 1);
}
