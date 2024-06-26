#include "Cipher.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  
  if (argc != 2) {
    std::cerr << "Usage: ./Cipher [<{filePath,mode}>]" << std::endl;
    return 1;
  }

  for (int i = 0; i < argc; i++) {
    executeCryption(argv[i]);
  } 
  return 0;
}
