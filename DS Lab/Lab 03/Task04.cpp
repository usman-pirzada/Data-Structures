#include <iostream>
using namespace std;

int main() {
    int wards, days;
    cin >> wards >> days;

    int** patients = new int*[wards];
    for(int i = 0; i < wards; i++) patients[i] = new int[days];

    for(int i = 0; i < wards; i++)
        for(int j = 0; j < days; j++)
            cin >> patients[i][j];

    int maxWard = 0, maxDay = 0, maxPatients = patients[0][0];

    for(int i = 0; i < wards; i++) {
        int sum = 0;
        for(int j = 0; j < days; j++) {
            sum += patients[i][j];
            if(patients[i][j] > maxPatients) {
                maxPatients = patients[i][j];
                maxWard = i;
                maxDay = j;
            }
        }
        cout << "Average admissions in Ward " << i+1 << ": " 
             << (double)sum/days << endl;
    }

    cout << "Ward " << maxWard+1 << " had the highest single-day admissions (" 
         << maxPatients << ") on Day " << maxDay+1 << endl;

    for(int i = 0; i < wards; i++) delete[] patients[i];
    delete[] patients;
}