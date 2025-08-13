#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
     if(s[8]== 'P'){
        string s1;
        s1=s.substr(0,2);
        int aa;
        aa = stoi(s1);
        if(aa==12)
        {
            return s= s.substr(0,8);
        }
        else{
            aa+=12;
            string s2;
            s2= to_string(aa);
            s2+=s.substr(2,6);
            return s2;
        }
        
     } 
     else{
        string s3;
        s3=s.substr(0,2);
        int bb;
        bb = stoi(s3);
        if(bb==12)
        {   
            string s4="00";
            s4+= s.substr(2,6);
            return s4;
        }
        else{
            return s.substr(0,8);
        }
     }
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}