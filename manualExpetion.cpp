#include <iostream>
using namespace std;

int main()
{
    try {
        cout << "Selamat Belajar di Prodi TI UMY" << endl;
        throw 0.5;
        cout << "pernyataan tidak akan dieksekusi" <<endl;
    }
    catch (int a) {
        //blok ini akan di eksekusi
        cout << "pengecualian akan di esekusi" << endl;
    }
    catch (...) {
        /*jika selain integer mala block ini akan dieksekusi*/
        cout << "default pengecualian dieksekusi" <<endl;
    }
    return 0;
}