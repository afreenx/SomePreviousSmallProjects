//Name: Afreen Fatima & UIN:230009299
// CSCE 312 Section 398

//This program just requires the user to enter an .asm file and a .hack file will be produced after compiling
//I haven't done any variables or loop assembly in this, but I have the built in symbols.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include  <cctype>
#include <bitset>
#include<algorithm>
using namespace std;

class Assemble{
    public:
    ifstream userInput;
    ofstream output_file;
    Assemble(string);
};

int main(){ //main will prompt for user to enter file

    string input;
    cout << "Enter file with .asm extension (ex: File.asm): ";
    cin >>  input;
    Assemble assemble(input);
    cout << "Hack file has been made" << endl;
    return 0;
}

Assemble::Assemble(string str_file){ //file gets passed in & it starts 
    userInput.open(str_file);

    if(!userInput.is_open()){
        cout<< "File failed to open";
    }
    
    str_file.erase(str_file.length()-4); //erase the back of .asm 
    output_file.open(str_file + ".hack"); //convert to hack file 

    if(!output_file.is_open()){
        cout<< "File failed to open";
    }

    string line;
    while(getline(userInput, line)){
         if(!line.empty()){ //if there is nothing in the line then we skip to the next line by doing nothing

         remove(line.begin(), line.end(), ' '); //remove all the spaces
         int findComment = line.find('/');  //find the char if exists then position exist else -1
         if(findComment != -1){   // deal with /* block */ later
            line = line.substr(0, findComment); //trim line
         }
         
         //now going to check if it's an A instruction if not then assume it is a C inst
         if(line[0] == '@'){
            string after_A = line.substr(1, line.length());

            bool num = true;
            for(int i = 0; i<after_A.length(); i++){
                if(!isdigit(after_A[i])){
                    num = false;
                }
            }
            if(num == true){
             //make digit to binary conversion & put in file
                int val = stoi(after_A);
                output_file << bitset<16>(val).to_string() << endl; //put hack binary of number 
                //checked - A inst numbers working 

            }else if(num == false)
            {
                //it's a symbol 
                   
                    
                if(line == "@R0" || line == "SP" ){
                    output_file << "0000000000000000" << endl;
                }else if(line == "@R1" || line == "LCL"){
                    output_file << "0000000000000001" <<endl;
                }else if(line == "@R2" || line == "ARG"){
                    output_file << "0000000000000010"<<endl;
                }else if(line == "@R3"  || line == "THIS"){
                    output_file << "0000000000000011"  <<endl;
                }else if(line == "@R4" || line == "THAT"){
                    output_file << "0000000000000100"  <<endl;
                }else if(line == "@R5"){
                    output_file << "0000000000000101"  <<endl;
                }else if(line == "@R6"){
                    output_file << "0000000000000110"   <<endl;
                }else if(line == "@R7"){
                    output_file <<  "0000000000000111"  <<endl;
                }else if(line == "@R8"){
                    output_file <<  "0000000000001000" <<endl;
                }else if(line == "@R9"){
                    output_file <<  "0000000000001001"  <<endl;
                }else if(line == "@R10"){
                    output_file <<  "0000000000001010" <<endl;
                }else if(line == "@R11"){
                    output_file << "0000000000001011"  <<endl;
                }else if(line == "@R12"){
                    output_file << "0000000000001100"  <<endl;
                }else if(line == "@R13"){
                    output_file << "0000000000001101" <<endl;
                }else if(line == "@R14"){
                    output_file <<   "0000000000001110" <<endl;
                }else if(line == "@R15"){
                    output_file <<  "0000000000001111"  <<endl;
                }else if(line == "@KBD"){
                      output_file << "0110000000000000"  <<endl;
                }else if(line == "@SCREEN"){
                      output_file <<  "0100000000000000"  <<endl;
                }

                
            }
            //this means C inst if it is a letter ex: D = A or if number ex: 0;JMP
         }else if(isalpha(line[0]) || isdigit(line[0])){
            //start with dest


            //extract everything before equals 
            string destBinary;
            string lineCopy = line;
            string jumpchar;
            int locationDest =  line.find('=');
            if(locationDest!= -1){
                string dest = line.substr(0,locationDest);

                if(dest == "M"){
                    destBinary = "001";
                }else if(dest == "D"){
                    destBinary = "010";
                }else if(dest == "MD"){
                    destBinary = "011";
                }else if(dest == "A"){
                    destBinary = "100";
                }else if(dest == "AM"){
                    destBinary = "101";
                }else if(dest == "AD"){
                    destBinary = "110";
                }else if(dest == "AMD"){
                    destBinary = "111";
                }

                line= line.substr(locationDest+1, line.length()-locationDest); //erase D instructions
               

            }else if(locationDest == -1) { //not found
                destBinary = "000";
            }
            int locationComp = line.find(";");
            string comp;
            if(locationComp != -1){
                line = line.substr(0,locationComp+1);
                 jumpchar = lineCopy.substr(lineCopy.length()-3);
            }
            comp = line;

            string binaryComp = "111";
           
             
            if(comp == "0"){
                binaryComp += "0101010";
            }else if(comp == "1"){
                binaryComp += "0111111";
            }else if(comp == "-1"){
                binaryComp += "0111010";
            }else if(comp == "D"){
                binaryComp += "0001100";
            }else if(comp == "A"){
                binaryComp += "0110000";
            }else if(comp == "-D"){
                binaryComp += "0001111";
            }else if(comp == "!D"){
                binaryComp += "0001101";
            }else if(comp == "!A"){
                binaryComp +=  "0110001";
            }else if(comp == "-A"){
                binaryComp += "0110011";
            }else if(comp == "D+1"){
                binaryComp += "0011111";
            }else if(comp == "A+1"){
                binaryComp +=  "0110111";
            }else if(comp == "D-1"){
                binaryComp += "0001110";
            }else if(comp == "A-1"){
                binaryComp +=  "0110010";
            }else if(comp == "D+A"){
                binaryComp += "0000010";
            }else if(comp == "D-A"){
                binaryComp += "0010011";
            }else if(comp == "A-D"){
                binaryComp += "0000111";
            }else if(comp == "A&D"){
                binaryComp += "0000000";
            }else if(comp == "D|A"){
                binaryComp += "0010101";
            }else if(comp == "M"){
                binaryComp += "1110000";
            }else if(comp == "!M"){
                binaryComp += "1110001";
            }else if(comp == "-M"){
                binaryComp += "1110011";
            }else if(comp == "M+1"){
                binaryComp +="1110111" ;
            }else if(comp == "M-1"){
                binaryComp +=  "1110010";
            }else if(comp == "D+M"){
                binaryComp += "1000010";
            }else if(comp == "D-M"){
                binaryComp += "1010011";
            }else if(comp == "M-D"){
                binaryComp += "1000111";
            }else if(comp == "D&M"){
                binaryComp += "1000000";
            }else if(comp == "D|M"){
                binaryComp += "1010101";
            }

              
            if(comp == "0;"){
                binaryComp += "0101010";
            }else if(comp == "1;"){
                binaryComp += "0111111";
            }else if(comp == "-1;"){
                binaryComp += "0111010";
            }else if(comp == "D;"){
                binaryComp += "0001100";
            }else if(comp == "A;"){
                binaryComp += "0110000";
            }else if(comp == "-D;"){
                binaryComp += "0001111";
            }else if(comp == "!D;"){
                binaryComp += "0001101";
            }else if(comp == "!A;"){
                binaryComp +=  "0110001";
            }else if(comp == "-A;"){
                binaryComp += "0110011";
            }else if(comp == "D+1;"){
                binaryComp += "0011111";
            }else if(comp == "A+1;"){
                binaryComp +=  "0110111";
            }else if(comp == "D-1;"){
                binaryComp += "0001110";
            }else if(comp == "A-1;"){
                binaryComp +=  "0110010";
            }else if(comp == "D+A;"){
                binaryComp += "0000010";
            }else if(comp == "D-A;"){
                binaryComp += "0010011";
            }else if(comp == "A-D;"){
                binaryComp += "0000111";
            }else if(comp == "A&D;"){
                binaryComp += "0000000";
            }else if(comp == "D|A;"){
                binaryComp += "0010101";
            }else if(comp == "M;"){
                binaryComp += "1110000";
            }else if(comp == "!M;"){
                binaryComp += "1110001";
            }else if(comp == "-M;"){
                binaryComp += "1110011";
            }else if(comp == "M+1;"){
                binaryComp +="1110111" ;
            }else if(comp == "M-1;"){
                binaryComp +=  "1110010";
            }else if(comp == "D+M;"){
                binaryComp += "1000010";
            }else if(comp == "D-M;"){
                binaryComp += "1010011";
            }else if(comp == "M-D;"){
                binaryComp += "1000111";
            }else if(comp == "D&M;"){
                binaryComp += "1000000";
            }else if(comp == "D|M;"){
                binaryComp += "1010101";
            }

           
           
            string jump;
            string jumpBinary;
            if(locationComp != -1){
                //means found
                line = line.substr(locationComp+1, line.length()-locationComp);
                string jump = line;
                destBinary = "000";
            }else{
              jumpBinary = "000";
            }

            string first_bits = binaryComp + destBinary;

           
            if(jumpchar == "JGT"){
                    jumpBinary = "001";
                }else if(jump == "JEQ"){
                    jumpBinary = "010";
                }else if(jumpchar == "JGE"){
                    jumpBinary = "011";
                }else if(jumpchar == "JLT"){
                    jumpBinary = "100";
                }else if(jumpchar == "JNE"){
                    jumpBinary = "101";
                }else if(jumpchar == "JLE"){
                    jumpBinary = "110";
                }else if(jumpchar == "JMP"){
                    jumpBinary = "111";
                }

            if(jump == "JGT"){
                    jumpBinary = "001";
                }else if(jump == "JEQ"){
                    jumpBinary = "010";
                }else if(jump == "JGE"){
                    jumpBinary = "011";
                }else if(jump == "JLT"){
                    jumpBinary = "100";
                }else if(jump == "JNE"){
                    jumpBinary = "101";
                }else if(jump == "JLE"){
                    jumpBinary = "110";
                }else if(jump == "JMP"){
                    jumpBinary = "111";
                }

            output_file << first_bits << jumpBinary << endl;
            


         }
     }

    }
       

}
