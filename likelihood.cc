#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

double likelihood_poisson(vector<int> daten, double mu);
double poisson(double mu, int k);


int main() {
    ifstream f_daten("datensumme.txt");
    ofstream f_likelihood("likelihood.txt");
    ofstream f_nll("nll.txt");
    ofstream f_deltanll("deltanll.txt");

    vector<int> daten;

    int n_i;
    int lengthOfDatensumme = 0;
    while (true) {
        f_daten >> n_i;
        if (f_daten.eof()) {
            break;
        }
        daten.push_back(n_i);
        lengthOfDatensumme++;

    }
    cout << "Likelihood_poisson von daten: " << likelihood_poisson(daten, 3.11538) << endl;
    
    for (double mu = 0; mu <= 6; mu += 0.1){
        f_likelihood << mu << " " << likelihood_poisson(daten, mu) << endl;
        f_nll << mu << " " << -2 * log(likelihood_poisson(daten, mu)) << endl;
        f_deltanll << mu << " " << -2 * log(likelihood_poisson(daten, mu)) + 2 * log(likelihood_poisson(daten, 3.11538)) << endl;
    }

    double result_likelihood = 1;
    double result_normalization = 1;
    for (int k : daten){
        result_likelihood *= poisson(3.11538, k);
        result_normalization *= poisson(k, k);
    }

    double lambda = result_likelihood / result_normalization;
    double z = (-2 * log(lambda) - (lengthOfDatensumme - 1))/(sqrt(2*(lengthOfDatensumme - 1)));

    cout << "result_normalization: " << result_normalization << endl;
    cout << "result_likelihood: " << result_likelihood << endl; //hier Fehler->Ergebnis ist null
    cout << "Lambda: " << lambda << endl;
    cout << "log Lambda: " << -2 * log(lambda) << endl;

    f_daten.close();
    f_likelihood.close();
    f_nll.close();
    f_deltanll.close();
}

double likelihood_poisson(vector<int> daten, double mu){
    double result = 1;
    for (int k : daten) {
        result *= pow(mu, k) * exp(-mu) / tgamma(k +1 );
    }
    return result;
}

double poisson(double mu, int k){
    return (pow(mu, k) * exp(-mu)) / tgamma(k + 1);
}