#include <locale.h>
#include "logic_result.h"

void logic_result(char a, char b) {
    bool result = (a + 5 >= b);
    cout << "Результат логічного виразу (a + 5 >= b): " << boolalpha << result << endl;
}
