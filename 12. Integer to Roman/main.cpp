#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        const char R[9] = "IVXLCDM";

        string ret;
        int decimal = 1000;
        int first = 6;

        while(num > 0){
            int cur = num / decimal;
            num = num % decimal;
            decimal = decimal / 10;

            switch (cur){
                case 1:
                case 2:
                case 3:
                    for (int i = 0; i < cur ; ++i) {
                        ret += R[first];
                    }
                    break;
                case 4:
                    ret += R[first];
                    ret += R[first + 1];
                    break;
                case 5:
                case 6:
                case 7:
                case 8:
                    ret += R[first + 1];
                    for (int i = 0; i < cur - 5; ++i) {
                        ret += R[first];
                    }
                    break;
                case 9:
                    ret += R[first];
                    ret += R[first + 2];
                    break;
                default:
                    break;
            }



            first -= 2;
        }

        return ret;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}