#include <iostream>
#include <string>
#include <list>
#include <map>
#include <fstream>


int main(int argc, char** argv) {
    using namespace std;

    ifstream inf(argv[1]);
    ofstream outf(argv[2]);

    string text;
    getline(inf, text);
    outf << text;







    return 0;
}
