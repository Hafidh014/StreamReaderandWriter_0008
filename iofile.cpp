#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    string baris;

    // oprasi file dalam mode menulis    
    ofstream outfile;

    //menunjukan seuah nama file untuk membuka
    outfile.open("contohfile.txt");

    cout << ">= menulis file, \'q\' untuk keluar" <<endl;

    //unlimited loop untuk menulis
    while (true) {
        cout << "- ";

        //mendapat setiap karakter dalam satu baris
        getline(cin, baris);

        //loop akan berhenti jika anda masukan karakter q
        if (baris == "q") break;

        outfile << baris << endl;

        outfile.close();

        infile.open("contohfile.txt");

    }
}
