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

  std::cout <<std::endl;

  std::ifstream image_in;
  image_in.open(argv[1], std::fstream::binary);
 
	struct Header{
    char Type_Line1[3];
  	char Comment[1000];
    int width;
    int height;
    int max_value;
  };

  Header header; 
  // std::cout << argv[2] << std::endl;

	if(image_in.is_open()) {
	   std::cout << "File is open" <<std::endl;
	} else {
		std::cout << "Error opening" <<std::endl;
	};
  
  // First line: Type
	image_in.read(header.Type_Line1, 2);
	if((header.Type_Line1[0]!='P') || header.Type_Line1[1]!='5'){
		std::cout << "Image is not in binary PGM 'P5' format." << std::endl;
		exit(1);
	}

  header.Type_Line1[2]= '\0';

  image_in.get();

  // Second line: Comment
  image_in.getline(header.Comment, 1000, '\n');

  //Third line: Width and Height
  image_in >> header.width;
  image_in >> header.height;
  image_in.get();

  //Fourth line: Max Value
  image_in >> header.max_value;
  image_in.get();

  std::cout << header.Type_Line1 << std::endl << header.width << header.height << header.max_value;
  std::cout << std::endl;

  // int data_size;
  // data_size = header.width * header.height;
  // char Image_data[data_size];
  // //image data
  // image_in.getline(Image_data, data_size, '\n');

  char Image_data[header.width*header.height];
  image_in.read(Image_data, header.width*header.height);

  const char message[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin fringilla placerat mi vel pellentesque. Donec fermentum eu leo in feugiat. Cras mollis, nunc at pharetra dapibus, nunc augue bibendum augue, et convallis tortor nisi id felis. Proin porttitor feugiat lorem. Nulla aliquam justo tortor, sed molestie sem consectetur sed. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Sed odio mauris, vehicula auctor semper id, vulputate in odio. Nulla non urna nec purus sagittis posuere. Sed mi est, mattis lobortis rhoncus vel, mattis sit amet ante. Nunc id diam in nibh molestie eleifend.\
Vestibulum scelerisque faucibus nunc sed malesuada. Quisque pretium urna eget viverra pretium. Phasellus fermentum elementum placerat. Mauris consectetur ultrices mauris condimentum congue. Praesent maximus felis lacus, tincidunt malesuada libero congue in. Duis id tincidunt felis. Donec ut feugiat mauris. Proin faucibus nulla sit amet lectus porttitor sagittis. Morbi non turpis nec leo pulvinar lobortis nec ac ligula. Praesent maximus tortor vel sapien aliquet vulputate. In ac felis in erat tincidunt euismod eget quis ligula. Aenean efficitur luctus magna eu efficitur.\
Morbi pellentesque ipsum sed viverra accumsan. Sed ante enim, iaculis ac ullamcorper sit amet, auctor ut est. Nunc id posuere est. Quisque convallis pretium imperdiet. Vestibulum molestie finibus tortor ut fermentum. Donec quis hendrerit augue. Pellentesque et nulla et lacus euismod egestas non id neque. Ut consequat cursus urna, quis pulvinar tortor.\
Etiam vitae convallis nibh. Aliquam semper lorem neque, sed pulvinar ipsum ultricies sit amet. Praesent nisl risus, maximus a magna placerat, varius mollis quam. Curabitur eu lacinia lectus. Fusce pretium vestibulum dui, id consectetur justo eleifend nec. Aliquam ornare enim eget laoreet ultricies. Proin et ex nibh. In quis orci ut sem lobortis laoreet. Nullam elementum dapibus posuere. Nulla semper finibus nibh, at auctor nisl cursus quis. Sed posuere odio in purus tristique tristique. Nulla non faucibus erat, sit amet eleifend metus.\
Sed ac risus eu diam sagittis ornare. In velit sem, consequat nec tortor non, rutrum laoreet elit. Nam molestie, arcu eu placerat sodales, lacus orci eleifend orci, ut consectetur justo orci ut dolor. Cras facilisis volutpat massa, at eleifend libero consequat sit amet. Pellentesque id velit mattis tortor faucibus porttitor. Nulla interdum convallis sapien ac egestas. In hac habitasse platea dictumst. Sed vulputate dolor sed felis commodo volutpat. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Integer iaculis et ipsum a gravida. Proin pretium quam in imperdiet molestie. Nulla facilisi. Quisque a velit tincidunt, commodo ipsum a, mollis dui. Maecenas suscipit ante massa, id consequat justo tristique eget.\
Suspendisse molestie sodales sapien, quis volutpat purus. Nullam interdum ligula eget posuere tristique. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Sed accumsan sagittis venenatis. Cras mattis mi eget felis dignissim sodales. Morbi congue eget lectus commodo tincidunt. Nunc eget lorem eu turpis pretium luctus ut in arcu. Sed nec aliquam est. Mauris sagittis ac risus sed suscipit.\
Aenean placerat sapien tortor, ac ultrices neque porttitor quis. Donec accumsan sem ornare enim hendrerit viverra. Cras varius ante vitae risus pharetra, sit amet molestie ipsum commodo. Aliquam eleifend ligula interdum, commodo augue vitae, auctor est. Nunc ac laoreet sem, ut condimentum nunc. Aenean volutpat, tellus eu semper rhoncus, neque nisi consequat eros, vitae consequat dui dui quis nisi. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Donec a elit vitae ex egestas eleifend. Proin pharetra, nibh et pharetra luctus, ipsum orci commodo arcu, nec convallis est orci at neque. Vestibulum ipsum ligula, sodales eu ligula quis, feugiat interdum lacus.\
Vestibulum ac elementum leo. Ut viverra pulvinar metus, id ullamcorper mauris. Quisque nulla lacus, vulputate eget congue et, vulputate sit amet erat. Maecenas eget facilisis lorem. Integer mollis maximus dignissim. Curabitur tincidunt non augue ac tempor. Integer accumsan rutrum velit, quis fermentum purus consectetur sit amet. Nunc vel enim sed lectus iaculis feugiat. Cras eleifend, neque quis tempus ultrices, ex eros gravida est, id sollicitudin nibh mauris gravida enim.\
Integer tempus nisi sed bibendum sagittis. Cras malesuada rhoncus leo, sit amet fermentum massa sagittis in. Curabitur purus justo, fringilla a purus eu, lacinia suscipit enim. Integer venenatis rhoncus lectus non tincidunt. Etiam malesuada sagittis lectus, eget dapibus augue sodales et. Interdum et malesuada fames ac ante ipsum primis in faucibus. Sed a lobortis justo. Suspendisse vehicula porttitor neque ac condimentum. Morbi mollis sagittis lorem non mollis. Fusce pharetra accumsan quam vel aliquam. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.\
In vel dictum dui, ut consequat quam. Duis ac ante quis enim mollis feugiat. Duis et tempor magna, et sollicitudin nisl. Duis facilisis dolor velit. Donec volutpat neque justo, sed blandit orci suscipit quis. Aliquam sodales sagittis diam et rutrum. Donec posuere a turpis id scelerisque. Pellentesque finibus eros eu risus congue maximus. Nulla bibendum tellus sed odio tincidunt feugiat. Praesent vitae convallis sem. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Nullam venenatis ligula augue, eu egestas magna egestas quis. Nulla at ipsum sed nunc imperdiet pellentesque ut at erat. Fusce lectus urna, consequat id vulputate quis, congue vitae arcu. Praesent ultrices ipsum leo, ut tincidunt ex tempus eu. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.\
Fusce porttitor vulputate lectus ut fermentum. Aenean ante tortor, commodo non lobortis et, euismod ut nisi. Nullam vitae felis eget quam euismod tincidunt. Donec suscipit, lacus non varius fermentum, massa felis condimentum arcu, et luctus tellus urna eu nisl. Nam venenatis, diam sed ultrices sodales, massa velit vehicula elit, eu consectetur lectus lacus in quam. Duis enim dolor, laoreet eu cursus eget, tempus fringilla est. Aenean lorem sem, rutrum nec aliquet sit amet, placerat ac metus. Donec sit amet molestie dui. Vestibulum sagittis nibh nec dolor pellentesque, at sollicitudin nisi laoreet. Cras pulvinar, nulla ut finibus efficitur, eros massa sollicitudin sem, id tristique lacus odio quis nisl. Vivamus et feugiat leo, eu aliquet ipsum. Proin risus ligula, porttitor in quam et, molestie pellentesque augue. Nunc tellus diam, maximus nec dolor a, ullamcorper imperdiet ipsum.\
Vestibulum placerat enim sit amet scelerisque dapibus. Vestibulum laoreet lacinia turpis sit amet rutrum. Integer vitae accumsan tellus. Duis eu nisi id nulla sollicitudin lacinia ac non ligula. Quisque molestie mauris quis ex rutrum, quis egestas nunc fermentum. Aliquam dui mauris, sollicitudin dapibus finibus ut, fermentum et arcu. Morbi varius sed ligula commodo ullamcorper. Integer et elit a velit ullamcorper tempor et id neque. Vivamus odio risus, malesuada ut justo ac, varius consequat libero. Maecenas iaculis imperdiet maximus. Vestibulum justo enim, commodo sed vehicula nec, pretium ac ante.\
Nulla luctus, leo sed condimentum faucibus, nisl ligula ultricies erat, et feugiat ligula lectus vel dolor. Donec gravida tincidunt arcu, vel hendrerit dolor volutpat nec. Curabitur eu viverra nulla. Nam est enim, fermentum vitae libero in, mattis tristique orci. Nullam eleifend semper lacinia. Sed ante arcu, bibendum a malesuada quis, eleifend non urna. Integer eu augue pellentesque, ultrices metus a, mattis sapien. Aliquam in dignissim ex, vitae tempus mauris. Vestibulum tempor ex nunc.\
Quisque dapibus, massa eu finibus mollis, lorem risus dapibus est, at imperdiet augue erat ac est. Vestibulum vitae cursus lacus, ac ultricies diam. Proin at ornare orci. Phasellus quis pharetra metus, sit amet auctor erat. Ut vehicula risus vitae posuere aliquam. Sed ac tortor quis ante fermentum fringilla et quis libero. Quisque accumsan ultricies mi. Nam dolor dolor, fermentum eget porttitor at, facilisis porta urna. Etiam urna massa, hendrerit eget sollicitudin sit amet, aliquet vitae velit. Quisque sit amet elit fringilla, consectetur orci id, condimentum lorem. Pellentesque eget mauris id ante fermentum mollis a ut enim. Vestibulum sed rhoncus arcu. Nunc laoreet risus id magna rutrum scelerisque. Ut ultricies tellus eu metus sollicitudin, eu pulvinar enim dictum.\
Se vel gravida felis, eget mattis ligula. Phasellus tempus leo est. Morbi fermentum porttitor lacus, accumsan aliquet tortor volutpat vitae. Duis mattis enim vitae ex iaculis, non cursus diam tincidunt. Sed nisi risus, iaculis in orci in, consectetur consequat purus. In mattis nisl leo, vel accumsan ipsum eleifend in. Aliquam a eleifend nisi.\
Maecenas consectetur, massa ac dignissim dapibus, velit neque viverra neque, ac fermentum lacus libero nec elit. Donec at dolor mi. Duis aliquam feugiat iaculis. Aliquam convallis, leo a congue commodo, ex massa pretium justo, et luctus libero ex vitae nunc. Etiam vestibulum volutpat congue. Suspendisse ultricies neque nec ultricies dictum. Curabitur tempus eu mi quis rhoncus. Sed id feugiat augue, mattis tincidunt eros. Etiam velit nunc, ornare nec ultrices eu, elementum id augue. Nunc id scelerisque enim. Curabitur tortor nulla, euismod non nisl in, mollis ultricies lorem. Nullam tincidunt odio velit, eget bibendum risus blandit placerat. Duis at dolor et quam dignissim feugiat sed non nisl.\
Phasellus iaculis pulvinar dui. Suspendisse potenti. Etiam egestas felis eu nisl accumsan ultricies. Integer luctus ullamcorper erat, vitae tincidunt massa congue id. Nulla ac tortor eu nulla hendrerit tincidunt. Quisque in tellus vitae massa tempus pharetra id a nullam. ";
  int sizeOfMessage = sizeof(message);

  for(int i = 0; i < sizeOfMessage; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      int bit_num = (message[i] >> j) & 0x01;
      if (bit_num == 1){
        Image_data[8*i+j] |= 0x01;
      } else {
        Image_data[8*i+j] &= 0xFE;
      }
    }
  }

  char newMessage[sizeOfMessage];

  for(int i = 0; i < sizeOfMessage; i++)
  {
    newMessage[i] = (char)0;
    for(int j = 0; j < 8; j++)
    {
      int bit_num = Image_data[8*i+j] & 0x01;
      newMessage[i] |= (bit_num << j);

    }
  }
  std::cout << "Size of message: " << sizeOfMessage << std::endl;
  std::cout << "Original message: " << message << std::endl;
  std::cout << "New message: " << newMessage << std::endl;




  std::ofstream image_out;
  image_out.open("baboon_new.pgm");

  image_out << header.Type_Line1 << std::endl;
  image_out << header.Comment << std::endl;
  image_out << header.width <<" ";
  image_out << header.height << std::endl;
  image_out << header.max_value <<std::endl;
  image_out << Image_data;

	return 0;
}
