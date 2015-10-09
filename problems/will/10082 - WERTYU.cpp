#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, char> mapping;
    
    mapping['W'] = 'Q';
    mapping['E'] = 'W';
    mapping['R'] = 'E';
    mapping['T'] = 'R';
    mapping['Y'] = 'T';
    mapping['U'] = 'Y';
    mapping['I'] = 'U';
    mapping['O'] = 'I';
    mapping['P'] = 'O';
    mapping['['] = 'P';
    mapping[']'] = '[';
    mapping['\\'] = ']';
    
    mapping['S'] = 'A';
    mapping['D'] = 'S';
    mapping['F'] = 'D';
    mapping['G'] = 'F';
    mapping['H'] = 'G';
    mapping['J'] = 'H';
    mapping['K'] = 'J';
    mapping['L'] = 'K';
    mapping[';'] = 'L';
    mapping['\''] = ';';
    
    mapping['X'] = 'Z';
    mapping['C'] = 'X';
    mapping['V'] = 'C';
    mapping['B'] = 'V';
    mapping['N'] = 'B';
    mapping['M'] = 'N';
    mapping[','] = 'M';
    mapping['.'] = ',';
    mapping['/'] = '.';
    
    mapping['1'] = '`';
    mapping['2'] = '1';
    mapping['3'] = '2';
    mapping['4'] = '3';
    mapping['5'] = '4';
    mapping['6'] = '5';
    mapping['7'] = '6';
    mapping['8'] = '7';
    mapping['9'] = '8';
    mapping['0'] = '9';
    mapping['-'] = '0';
    mapping['='] = '-';
    
    mapping[' '] = ' ';
    
    string s;
    while (getline(cin, s)) {
        for (auto c : s) {
            cout << mapping[c];
        }
        cout << endl;
    }
    return 0;
}