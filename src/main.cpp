#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void Encrypt_Message(const std::string[],const char[]);
void Decrypt_Message(const std::string[],const char[]);

int main(){
  std::string Morse_Alphabet[50]{".-","-...",".--","--.","-..",".","...-","--..","..",".---",//Alphabet
                                "-.-",".-..","--","-.","---",".--.",".-.","...","-","..-",
                                "..-.","....","-.-.","--.-","-.--","-..-",
                                ".----","..---","...--","....-",".....","-....","--...","---..","----.","-----",//Numbers
                                "......",".-.-.-","---...","-.-.-.","-.--.-",".----.",".-..-.","-....-","-..-.","..--.-","..--..","--..--",".-.-.",".--.-."};//Spetial symbvols
  char English_Alphabet[51]{"ABWGDEVZIJKLMNOPRSTUFHCQYX1234567890.,:;(\'\"-/_?!+@"};
  enum Choise:char{
    DEC = 'd',
    ENC = 'e',
    EXT = 'q'
  };
  char choise;
  std::cout << "Hello monkeys!!! Here is program which handling a morse code\n" 
               "Type d for decrypt your morse mess to human readable lanquage\n"
               "Type e for encrypt your mess on morse code\n"
               "Type q tu quit the program\n"
  << std::endl;
  do{
    std::cout << ">Main function<" << std::endl;
    std::cin >> choise;
    switch (choise){
      case ENC:{
        Encrypt_Message(Morse_Alphabet,English_Alphabet);
        break;
      }
      case DEC:{
        Decrypt_Message(Morse_Alphabet,English_Alphabet);
        break;
      }
      case EXT:{
        return 0;
      }
      default:{
        std::cout << "Wrong input. Try again. " << std::endl;
        break;
      }
    }
  }
  while (true);
}

void Encrypt_Message(const std::string Morse_Alphabet[50],const char English_Alphabet[50]){
  std::cout <<">Encrypt function begin<" << std::endl;

  std::string Input_Message;
  std::vector<std::string> Output_Message;

  std::cout << "Alpabet ========================================== \n" 
  "A(.-) B(-...) W(.--) G(--.) D(-..) E(.) V(...-) Z(--..) I(..) J(.---)\n"
  "K(-.-) L(.-..) M(--) N(-.) O(---) P(.--.) R(.-.) S(...) T(-) Y(..-)\n"
  "F(..-.) H(....) C(-.-.) Q(--.-) Y(-.--) X(-..-)\n"
  "1(.----) 2(..---) 3(...--) 4(....-) 5(.....) 6(-....) 7(--...) 8(---..) 9(----.) 0(-----)\n"
  ".(......) ,(.-.-.-) :(---...) ;(-.-.-.) ((-.--.-) \'(.----.)\n \"(.-..-.) -(-....-) /(-..-.) _(..--.-) ?(..--..) !(--..--) +(.-.-.) @(.--.-.)\n"
  << std::endl;
  std::cout << "Enter your message" << std::endl;
  std::cin >> Input_Message;
  
  for (size_t i = 0; i != Input_Message.size() ;i++){
    for (size_t j = 0; j != 50 ;j++){
      if (Input_Message[i] == English_Alphabet[j]){
        Output_Message.push_back(Morse_Alphabet[j]);
      }
    }
  }
  for (const auto &i : Output_Message){
    std::cout << i << " ";
  }
}
void Decrypt_Message(const std::string Morse_Alphabet[50],const char English_Alphabet[50]){
  std::cout <<">Decrypt function<" << std::endl;
  std::vector<std::string> Input_Message;
  std::string Output_Message;
  std::string Temp_Input_Message;
  
  std::cout << "Enter your message" << std::endl;
  std::cin.ignore();
  getline(std::cin, Temp_Input_Message);
  
  std::istringstream ss(Temp_Input_Message);
  std::string Buffer;
  while(ss >> Buffer) Input_Message.push_back(Buffer);

  for (size_t i = 0; i != Input_Message.size() ;i++){
    for (size_t j = 0; j != 50 ;j++){
      if (Input_Message[i] == Morse_Alphabet[j]){
        Output_Message.push_back(English_Alphabet[j]);
      }
    }
  }
  std::cout << Output_Message << std::endl;
}