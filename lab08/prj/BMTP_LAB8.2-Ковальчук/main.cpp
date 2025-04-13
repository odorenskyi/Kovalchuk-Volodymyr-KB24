#include <iostream>
#include <iomanip>
#include <locale.h>
#include "developer_info.h"
#include "logic_result.h"
#include "s_calculation.h"


using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
     double x, y, z;
     char a, b;

    cout << "¬вед≥ть значенн€ a та b (символи): ";
    cin >> a >> b;

    cout << "¬вед≥ть значенн€ x, y, z (число): ";
    cin >> x >> y >> z;

    developer_info();
    logic_result( a, b);
    s_calculation(x, y, z);

     return 0;
}
