#include <iostream>
#include "color.hpp"

int main() {
  
    std::cout << dye::light_purple("Nie staraj się zostać człowiekiem sukcesu, lecz człowiekiem wartościowym") + dye::light_aqua_on_black(" ~Albert Einstein") << std::endl;
    std::cout << dye::light_purple("Jeśli sądzisz, że potrafisz to masz rację. Jeśli sądzisz, że nie potrafisz - również masz rację.") + dye::light_aqua_on_black(" ~Henry Ford") << std::endl;
    std::cout << dye::light_purple("Bądź zmianą, którą pragniesz ujrzeć w świecie.") + dye::light_aqua_on_black(" ~Mahatma Gandhi") << std::endl;
    std::cout << dye::light_purple("Jesteśmy tym, co w swoim życiu powtarzamy. Doskonałość nie jest jednorazowym aktem, lecz nawykiem.") + dye::light_aqua_on_black(" ~Arystoteles") << std::endl;
  
    return 0;
}
