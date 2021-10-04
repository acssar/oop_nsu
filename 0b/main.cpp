#include <iostream>
#include <string>
#include <list>
#include <map>
#include <fstream>
#include <sstream>


using namespace std;

string find_separators(string s)
{
    unsigned len = s.length();
    for (int i = 0; i < len; i++)
        if(!isalpha(s[i]) && !isdigit(s[i]))
        {
            s[i] = ' ';
        }
    return s;
}


int main(int argc, char** argv) {

    ifstream inf (argv[1]);
    ofstream outf(argv[2]);

    map <string, int> word_table;
    string input_line, str;
    int cnt =  0;

    while(!inf.eof()) {

        getline(inf, input_line);
        input_line = find_separators(input_line); //getting rid of separators, ' ' now our separator
        stringstream ss(input_line); //to pull words from line

        for (; ss >> str; cnt++)
                word_table[str] ++; //counting words
    }

    list<pair<int, string>> result_table;
    auto map_it = word_table.begin();

    for(; map_it != word_table.end(); map_it++)
    {
        pair<int, string> p = {map_it->second, map_it->first};
        result_table.push_back(p);
    }

    result_table.sort();
    result_table.reverse();
    auto it = result_table.begin();

    for (; it != result_table.end(); it++)
        outf << it->second << "," << it->first << "," << double(it->first) / cnt << "\n";

    return 0;
}
