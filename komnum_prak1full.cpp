#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

double f(double x) {
    return exp(-x) - x;
}
int main() {
    double a, b, xt;
    double tolerance;
    int iterasi = 0;
    int max_iter = 100;

    cout << "nilai a: ";
    cin >> a;

    cout << "nilai b: ";
    cin >> b;

    cout << "toleransi: ";
    cin >> tolerance;

    double fa = f(a);
    double fb = f(b);

    if (fa * fb > 0) {
        cout << "Interval tidak valid (tidak ada perubahan tanda)" << endl;
        return 0;
    }

    cout << "\nIterasi | xt        | f(xt)\n";

    while (iterasi < max_iter) {
        xt = (a * fb - b * fa) / (fb - fa);
        double fxt = f(xt);

        iterasi++;

        cout << iterasi << " | " << xt << " | " << fxt << endl;

        if (fabs(fxt) < tolerance) break;

        if (fa * fxt < 0) {
            b = xt;
            fb = fxt;
        } else {
            a = xt;
            fa = fxt;
        }
    }

    cout << "\nAkar = " << xt << endl;

    ofstream file("grafik.csv");

    for (double x = -1; x <= 2; x += 0.01) {
        file << x << " " << f(x) << endl;
    }

    file.close();

    system("gnuplot -p -e \"plot 'grafik.csv' using 1:2 with lines\"");

int width = 60;
int height = 20;

for (int i = height; i >= -height; i--) {
    double y = i / 10.0;

    cout << setw(6) << fixed << setprecision(1) << y << " ";

    for (int j = 0; j < width; j++) {
        double x = (j - width/2) / 10.0;

        if (fabs(f(x) - y) < 0.05)
            cout << "*";
        else if (fabs(x) < 0.05 && fabs(y) < 0.05)
            cout << "+"; 
        else if (fabs(x) < 0.05)
            cout << "|"; 
        else if (fabs(y) < 0.05)
            cout << "-"; 
        else
            cout << " ";
    }
    cout << endl;
}

cout << "       ";
for (int j = 0; j < width; j++) {
    if ((j - width/2) % 10 == 0) {
        double x = (j - width/2) / 10.0;

        cout << setw(5) << fixed << setprecision(0) << x;
        j += 4;
        } else {
        cout << " ";
    }
}
cout << endl;

cout << "       ";
for (int j = 0; j < width; j++) {
    if ((j - width/2) % 10 == 0)
        cout << "+";
    else if ((j - width/2) % 5 == 0)
        cout << "|";
    else
        cout << "-";
    }
    cout << endl;
    return 0;
}
