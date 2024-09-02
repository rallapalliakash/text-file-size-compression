#include<bits/stdc++.h>
using namespace std;
int main()
{

    fstream newfile;
    newfile.open("com.txt",ios::in);
    unordered_map<string,string>sto;
    while(newfile)
    {
        string word;
        newfile>>word;
        if(word=="decode")
        {
            break;
        }
            string word1;
            newfile>>word1;
            sto[word1]=word;

     }
    string d="";
    fstream file;
    file.open("prohof.txt",ios::out);
    while(newfile)
    {
        char c;
        newfile>>c;
        d=d+c;
        if(sto.find(d)!=sto.end())
        {
              file<<sto[d];
              file<<" ";
              d="";
        }
    }
return 0;
}