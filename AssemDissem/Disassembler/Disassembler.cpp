//Name: Afreen Fatima & UIN:230009299
// CSCE 312 Section 398


//This program just requires the user to enter a .hack file and a .asm file will be produced after compiling


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Disassembler{
    public:
    ifstream userInput;
    ofstream output_file;
    Disassembler(string);
};


int main(){ //main will prompt for user to enter file

    string input;
    cout << "Enter file with .hack extension (ex: File.hack): ";
    cin >>  input;
    Disassembler disassemble(input);
    cout << "Asm file has been made" << endl;
    return 0;
}

Disassembler::Disassembler(string str_file){ //file gets passed in & it starts 
    userInput.open(str_file);

    if(!userInput.is_open()){
        cout<< "File failed to open";
    }
    
    str_file.erase(str_file.length()-5); //erase the back of .hack 
    output_file.open(str_file + ".asm"); //convert to asm file 

    if(!output_file.is_open()){
        cout<< "File failed to open";
    }

    string line;
    while(getline(userInput, line)){
      if(line.substr(0,3) == "111"){//it's a C instruction
        // 111 a c1 c2 c3 c4 c5 c6 d1 d2 d3 j1 j2 j3
        string c_bits = line.substr(3,7); //a + c bits position 4
        string d_bits = line.substr(10,3); //dest bits position 10 
        string j_bits = line.substr(13,3); //jump bits position 13
        string dest;
        // dest = comp;jmp
        
        bool destNotExist = false;
        bool jmpNotExist = false;

         if (d_bits== "000"){
            destNotExist = true;
         }
         if(destNotExist ==false){
          if(d_bits == "001"){
              dest = "M";
          }else if (d_bits == "010"){
              dest = "D";
          }else if (d_bits == "011"){
              dest = "MD";
          }else if (d_bits == "100"){
              dest = "A";
          }else if (d_bits == "101"){
              dest = "AM";
          }else if(d_bits== "110"){
              dest= "AD";
          }else if(d_bits == "111"){
            dest = "AMD";
          }
          dest += "=";
        }

      
            //switch(c_bits){
            //  case "0101010"
            //}

            if(c_bits == "0101010"){
                dest += "0";
            }else if(c_bits == "0111111"){
              dest += "1";
            }else if(c_bits == "0111010"){
              dest += "-1";
            }else if(c_bits == "0001100"){
              dest += "D";
            }else if(c_bits ==  "0110000"){
              dest += "A";
            }else if(c_bits == "0001101"){
              dest += "!D";
            }else if(c_bits ==  "0110001"){
              dest += "!A";
            }else if(c_bits == "0001111"){
              dest += "-D";
            }else if(c_bits == "0110011"){
                dest +="-A";
            }else if(c_bits ==  "0011111"){
                  dest +="D+1";
              }else if(c_bits == "0110111"){
                    dest +="A+1";
              }else if(c_bits ==  "0001110"){
                      dest +="D-1";
               }else if(c_bits == "0010101"){
                dest += "D|A";
                }else if(c_bits ==  "0110010"){
                  dest += "A-1";
                  }else if(c_bits == "0000010" ){
                    dest += "D+A";
                    }else if(c_bits == "0010011"){
                      dest += "D-A";
               }else if(c_bits ==  "0000111"){
                dest += "A-D"; 
                }else if((c_bits == "0000000" )){
                   dest += "A&D"; 
            }else 
              if(c_bits == "1110000"){
                dest += "M";
            }else if(c_bits == "1110001"){
              dest += "!M";
            }else if(c_bits =="1110011" ){
              dest += "-M";
            }else if(c_bits == "1110111"){
              dest += "M+1";
            }else if(c_bits == "1110010"){
              dest += "M-1";     
            }else if(c_bits == "1000010"){
              dest += "D+M";
            }else if(c_bits == "1010011"){
              dest += "D-M";  
            }else if(c_bits ==  "1000111"){
              dest += "M-D";
            }else if(c_bits == "1000000"){
              dest += "D&M";
            }else if(c_bits == "1010101"){
              dest += "D|M";
            }
          

        

         if (j_bits== "000"){
            jmpNotExist = true;
         }
         if(jmpNotExist == false){
          dest += ";";
           if(j_bits == "001"){
            dest +=  "JGT";
         }else if (j_bits == "010"){
            dest += "JEQ";
        }else if (j_bits == "011"){
            dest +=  "JGE";
         }else if (j_bits == "100"){
            dest += "JLT";
        }else if (j_bits == "101"){
            dest += "JNE";
        }else if(j_bits== "110"){
            dest += "JLE";
        }else if(j_bits== "111"){
            dest += "JMP";
        }
        }
       
          output_file << dest << endl;
      

      }else if(line[0] == '0'){ //it's an A instruction
        int value = stoi(line, 0, 2); //convert binary to decimal
        output_file << "@" << to_string(value) << endl;
      }

      }


    }
