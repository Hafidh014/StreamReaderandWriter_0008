#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int mai(){
    string baris;

    // oprasi file dalam mode menulis    
    ofstream outfile;

    //menunjukan seuah nama file untuk membuka
    outfile.open("contohfile.txt");

    cout << ">= menulis file, \'q\' untuk keluar" <<endl;
    
}
