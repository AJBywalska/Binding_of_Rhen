#include <stage.h>
#include <objects.h>
#include <iostream>

int main()
{
    std::cout << "Hello in game: Binding of Rhen!\n" << std::endl;
    stage s(1900, 1000);
    s.drawing();
    s.loop();
    return 0;
}
