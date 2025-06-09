#include <iostream>
#include <exception>
#include <array>

using namespace std;

int main()
{
    cout << "awal program" <<endl;
    try{
        array <int, 3> data = {1, 2, 3, };
        cout << data.at(5)<<endl;
    }
    catch (exception& e) {
        cout << e.what() <<endl;
    }
    cout << "baris program yang terahir " <<endl;
    
    return 0;
}