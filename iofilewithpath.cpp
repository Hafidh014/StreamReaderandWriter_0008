#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    string baris;
    string  namaFile;

    cout <<"masukan nama file"
    cin >> namaFile;
    
    // oprasi file dalam mode menulis    
    ofstream outfile;

    //menunjukan seuah nama file untuk membuka
    outfile.open("filewithpath.txt");

    cout << ">= menulis file, \'q\' untuk keluar" <<endl;

    //unlimited loop untuk menulis
    while (true) {
        cout << "- ";

        //mendapat setiap karakter dalam satu baris
        getline(cin, baris);

        //loop akan berhenti jika anda masukan karakter q
        if (baris == "q") break;

        outfile << baris << endl;
    }

        outfile.close();

        ifstream infile;

        infile.open("filewithpath.txt");

        cout << endl << ">= membuka dan membaca file " << endl;
        //jika file ada maka
        if (infile.is_open())
        {
            while (getline(infile, baris))
            {
                cout << baris <<'\n';
            }
            infile.close();
        }
    
    else cout << "unable to open file";
    return 0;
}
