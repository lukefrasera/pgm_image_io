#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
// #include "../images/baboon.pgm"

// Header

// P5
// #comment line
// 512 width 512 height
// 255 max_value
// <raw image data> 
int main(int argc, char*argv[]){

  std::ifstream image_in;
  image_in.open(argv[1], std::fstream::binary);
 
	char Type_Line1[3];
	std::string Comment;
  int width;
  int height;
  int max_value;

  // std::cout << argv[2] << std::endl;

	if(image_in.is_open()) {
	   std::cout << "File is open" <<std::endl;
	} else {
		std::cout << "Error opening" <<std::endl;
	};
  
	image_in.getline(Type_Line1, 2,'\n');vi~/.
	if((Type_Line1[0]!='P') || Type_Line1[1]!='5'){
		std::cout << "Image is not in binary PGM 'P5' format." << std::endl;
		exit(1);
	}

	// First line: Type
	image_in.getline(Type_Line1, 2);
	std::cout << "Type : " << Type_Line1 << std::endl; 

 // Second line: Comment
  //	image_in.getline(Comment,100);
  // std::cout << "Comment : " << Comment << std::endl;

  // int i = 0;
  // while(fin.peek() != EOF && i < 255){
  //   fin.read(input + i, 1);
  //   //read (char_tyoe* s, streamsize n);
  //   i++;
  // }
  // if (i < 255) {
  //   input[i] = '\0';
  // } else {
  //   input[254] = '\0';
  // }

  // printf("%s\n", input);


 // std::ofstream fout;
 // fout.open("baboon_new.png");
	return 0;
}
