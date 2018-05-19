#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
 *   std::ofstream outfile;
  outfile.open ("test.txt");

  outfile.write ("This is an apple",16);
  long pos = outfile.tellp();
  outfile.seekp (pos-7);
  outfile.write (" sam",4);

  outfile.close();
*/

int bufferSize = 10;

void copyFiles(string str_in, string str_out)
{
    char tabBuffer[bufferSize+1];
    tabBuffer[bufferSize] = 0;
    char * buffer = tabBuffer;
    ofstream out;
    ifstream in;
    in.open(str_in.c_str());
    out.open(str_out.c_str(), std::ios::trunc);

    int pos = 0;
    do{
        in.seekg(pos);
        out.seekp(pos);
        in.read(buffer, bufferSize);
        out.write(buffer, bufferSize);


        pos+=bufferSize;
    }while(bufferSize==in.gcount());

    in.close();
    out.close();

    in.open(str_out.c_str());

    pos = 0;
    do{
        in.seekg(pos);

        in.read(buffer, bufferSize);
        cout<<"buffer " << pos << "\t" << buffer << endl ;
//        for(char & c:buffer)
//            cout<< c;
//        cout << endl;


        pos+=bufferSize;
    }while(bufferSize==in.gcount());

    in.close();







}




int main(int argc, char *argv[])
{
    ofstream out;
    out.open("plik.txt", std::ios::trunc);
    out << "1234567890123456789012345678901234567890321";
    out.close();

    cout << "Hello World!" << endl;
    copyFiles("plik.txt", "copy.txt");
    return 0;
}
