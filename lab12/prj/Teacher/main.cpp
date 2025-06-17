#include <iostream>
#include <fstream>
#include <Windows.h>
#include <locale.h>
#include <iomanip>
#include <string>
#include <cmath>
#include "ModulseKovalchuk.h"

using namespace std;

// Функція для звукового сигналу при порушенні вимог
void beep100times() {
    cout << "УВАГА: Порушено вимоги виконання лабораторної роботи!" << endl;
    for (int i = 0; i < 100; ++i) {
        Beep(750, 100); // 750 Гц, 100 мс
        if (i % 10 == 0) {
            cout << "Beep " << i + 1 << "/100" << endl;
        }
    }
}

// Покращена перевірка коректності директорії
bool isInCorrectDirectory() {
    char buffer[MAX_PATH];
    DWORD length = GetCurrentDirectoryA(MAX_PATH, buffer);

    if (length == 0 || length > MAX_PATH) {
        cerr << "Помилка при отриманні поточної директорії." << endl;
        return false;
    }

    string path(buffer);
    cout << "Поточна директорія: " << path << endl;

    // Конвертуємо в нижній регістр для порівняння
    string lowerPath = path;
    for (char& c : lowerPath) {
        c = tolower(c);
    }

    // Перевіряємо різні варіанти назв
    bool hasLab12 = (lowerPath.find("lab12") != string::npos ||
                     lowerPath.find("лаб12") != string::npos ||
                     lowerPath.find("lab_12") != string::npos);

    bool hasPrj = (lowerPath.find("prj") != string::npos ||
                   lowerPath.find("proj") != string::npos ||
                   lowerPath.find("project") != string::npos ||
                   lowerPath.find("проект") != string::npos);

    cout << "Перевірка структури:" << endl;
    cout << "- Містить Lab12: " << (hasLab12 ? "так" : "ні") << endl;
    cout << "- Містить prj: " << (hasPrj ? "так" : "ні") << endl;

    // Якщо не знайдено обидва компоненти, запитуємо користувача
    if (!hasLab12 || !hasPrj) {
        cout << "\nУВАГА: Автоматична перевірка не знайшла очікувану структуру." << endl;
        cout << "Чи бажаєте продовжити виконання програми? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore(); // очищаємо буфер

        if (choice == 'y' || choice == 'Y' || choice == 'т' || choice == 'Т') {
            cout << "Продовжуємо виконання за вашим вибором..." << endl;
            return true;
        } else {
            return false;
        }
    }

    return true;
}

// Створення директорії TestSuite
void ensureTestSuiteDirectory() {
    // Спробуємо різні варіанти створення директорії
    const char* testDirs[] = {
        "..\\TestSuite",
        ".\\TestSuite",
        "TestSuite"
    };

    bool created = false;
    for (const char* dir : testDirs) {
        if (CreateDirectoryA(dir, NULL)) {
            cout << "Створено директорію: " << dir << endl;
            created = true;
            break;
        } else if (GetLastError() == ERROR_ALREADY_EXISTS) {
            cout << "Директорія " << dir << " вже існує." << endl;
            created = true;
            break;
        }
    }

    if (!created) {
        cout << "Попередження: Не вдалося створити директорію TestSuite." << endl;
        cout << "Результати будуть збережені в поточній директорії." << endl;
    }
}

// Розширена функція тестування
void runTests(const string& resultPath) {
    ofstream fout(resultPath);
    if (!fout.is_open()) {
        // Якщо не можемо створити файл за вказаним шляхом, створимо в поточній директорії
        string localPath = "TestResults.txt";
        fout.open(localPath);
        if (!fout.is_open()) {
            cerr << "Не вдалося відкрити файл для запису результатів тестів." << endl;
            return;
        }
        cout << "Результати збережено в поточній директорії: " << localPath << endl;
    }

    cout << "Виконання модульного тестування..." << endl;
    fout << "============================================" << endl;
    fout << "   РЕЗУЛЬТАТИ МОДУЛЬНОГО ТЕСТУВАННЯ" << endl;
    fout << "   Модуль: ModulseKovalchuk.h" << endl;
    fout << "   Клас: ClassLab12_Kovalchuk" << endl;
    fout << "============================================" << endl;
    fout << fixed << setprecision(6);

    int passedTests = 0;
    int totalTests = 0;

    cout << "\n--- Початок тестування ---" << endl;

    // Тест 1: Конструктор за замовчуванням
    totalTests++;
    fout << "\nТест 1: Конструктор за замовчуванням" << endl;
    cout << "\nВиконується Тест 1..." << endl;
    ClassLab12_Kovalchuk obj1;
    double expectedA1 = 5.0, expectedB1 = 3.0;
    bool test1 = (obj1.getA() == expectedA1 && obj1.getB() == expectedB1);
    fout << "  Очікувано: a=" << expectedA1 << ", b=" << expectedB1 << endl;
    fout << "  Отримано:  a=" << obj1.getA() << ", b=" << obj1.getB() << endl;
    fout << "  Результат: " << (test1 ? "ПРОЙДЕНО" : "НЕ ПРОЙДЕНО") << endl;
    cout << "Тест 1: " << (test1 ? " ПРОЙДЕНО" : " НЕ ПРОЙДЕНО") << endl;
    if (test1) passedTests++;

    // Тест 2: Конструктор з параметрами
    totalTests++;
    fout << "\nТест 2: Конструктор з параметрами" << endl;
    cout << "\nВиконується Тест 2..." << endl;
    ClassLab12_Kovalchuk obj2(3.0, 2.0);
    bool test2 = (obj2.getA() == 3.0 && obj2.getB() == 2.0);
    fout << "  Очікувано: a=3.0, b=2.0" << endl;
    fout << "  Отримано:  a=" << obj2.getA() << ", b=" << obj2.getB() << endl;
    fout << "  Результат: " << (test2 ? "ПРОЙДЕНО" : "НЕ ПРОЙДЕНО") << endl;
    cout << "Тест 2: " << (test2 ? " ПРОЙДЕНО" : " НЕ ПРОЙДЕНО") << endl;
    if (test2) passedTests++;

    // Тест 3: Обчислення площі
    totalTests++;
    fout << "\nТест 3: Обчислення площі еліпса" << endl;
    cout << "\nВиконується Тест 3..." << endl;
    double expectedArea = M_PI * 3.0 * 2.0;
    double actualArea = obj2.calculateArea();
    bool test3 = (abs(actualArea - expectedArea) < 1e-10);
    fout << "  Очікувано: " << expectedArea << ", Отримано: " << actualArea << endl;
    fout << "  Результат: " << (test3 ? "ПРОЙДЕНО" : "НЕ ПРОЙДЕНО") << endl;
    cout << "Тест 3: " << (test3 ? " ПРОЙДЕНО" : " НЕ ПРОЙДЕНО") << endl;
    if (test3) passedTests++;

    // Тест 4: Методи встановлення
    totalTests++;
    fout << "\nТест 4: Методи setA() та setB()" << endl;
    cout << "\nВиконується Тест 4..." << endl;
    obj2.setA(4.0);
    obj2.setB(5.0);
    bool test4 = (obj2.getA() == 4.0 && obj2.getB() == 5.0);
    fout << "  Результат: " << (test4 ? "ПРОЙДЕНО" : "НЕ ПРОЙДЕНО") << endl;
    cout << "Тест 4: " << (test4 ? " ПРОЙДЕНО" : " НЕ ПРОЙДЕНО") << endl;
    if (test4) passedTests++;

    // Тест 5: Площа після зміни параметрів
    totalTests++;
    fout << "\nТест 5: Площа після зміни параметрів" << endl;
    cout << "\nВиконується Тест 5..." << endl;
    double newArea = obj2.calculateArea();
    double expectedNewArea = M_PI * 4.0 * 5.0;
    bool test5 = (abs(newArea - expectedNewArea) < 1e-10);
    fout << "  Очікувано: " << expectedNewArea << ", Отримано: " << newArea << endl;
    fout << "  Результат: " << (test5 ? "ПРОЙДЕНО" : "НЕ ПРОЙДЕНО") << endl;
    cout << "Тест 5: " << (test5 ? " ПРОЙДЕНО" : " НЕ ПРОЙДЕНО") << endl;
    if (test5) passedTests++;

    // Тест 6: Граничні значення
    totalTests++;
    fout << "\nТест 6: Граничні значення" << endl;
    cout << "\nВиконується Тест 6..." << endl;
    ClassLab12_Kovalchuk obj3(0.1, 0.1);
    double area3 = obj3.calculateArea();
    double expected3 = M_PI * 0.1 * 0.1;
    bool test6 = (abs(area3 - expected3) < 1e-10);
    fout << "  Очікувана площа: " << expected3 << ", Отримана площа: " << area3 << endl;
    fout << "  Результат: " << (test6 ? "ПРОЙДЕНО" : "НЕ ПРОЙДЕНО") << endl;
    cout << "Тест 6: " << (test6 ? " ПРОЙДЕНО" : " НЕ ПРОЙДЕНО") << endl;
    if (test6) passedTests++;

    // Підсумок
    fout << "\n============================================" << endl;
    fout << "             ПІДСУМКИ ТЕСТУВАННЯ" << endl;
    fout << "============================================" << endl;
    fout << "Загальна кількість тестів: " << totalTests << endl;
    fout << "Пройдено тестів:           " << passedTests << endl;
    fout << "Не пройдено тестів:        " << (totalTests - passedTests) << endl;
    fout << "Відсоток успішності:       " << (100.0 * passedTests / totalTests) << "%" << endl;

    if (passedTests == totalTests) {
        fout << "\n ВСІ ТЕСТИ ПРОЙДЕНО УСПІШНО!" << endl;
        cout << "\n ВСІ ТЕСТИ ПРОЙДЕНО УСПІШНО!" << endl;
    } else {
        fout << "\n ДЕЯКІ ТЕСТИ НЕ ПРОЙДЕНО!" << endl;
        cout << "\n ДЕЯКІ ТЕСТИ НЕ ПРОЙДЕНО! Перевірте результати." << endl;
    }

    fout.close();
    cout << "\nРезультати тестування збережено у файл: " << resultPath << endl;
}

// Демонстрація роботи класу
void demonstrateClass() {
    cout << "\n=== ДЕМОНСТРАЦІЯ РОБОТИ КЛАСУ ===" << endl;

    cout << "\n1. Створення столів:" << endl;
    ClassLab12_Kovalchuk table1; // за замовчуванням
    ClassLab12_Kovalchuk table2(6.0, 4.0); // з параметрами

    cout << "\n2. Відображення інформації:" << endl;
    cout << "\nСтіл 1 (за замовчуванням):" << endl;
    table1.displayInfo();

    cout << "Стіл 2 (з параметрами):" << endl;
    table2.displayInfo();

    cout << "\n3. Зміна параметрів столу 1:" << endl;
    table1.setA(7.5);
    table1.setB(5.2);
    cout << "Оновлений стіл 1:" << endl;
    table1.displayInfo();

    cout << "\n4. Порівняння столів:" << endl;
    if (table1.isLargerThan(table2)) {
        cout << "Стіл 1 має більшу площу ніж стіл 2" << endl;
    } else {
        cout << "Стіл 2 має більшу або рівну площу зі столом 1" << endl;
    }

    cout << "\n5. Використання оператора виводу:" << endl;
    cout << "Стіл 1: " << table1 << endl;
    cout << "Стіл 2: " << table2 << endl;
}

// Головна функція
int main() {
    // Налаштування кодування для української мови
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukrainian");

    cout << "=========================================" << endl;
    cout << "    ЛАБОРАТОРНА РОБОТА 12" << endl;
    cout << "    Варіант 38" << endl;
    cout << "    Модуль: ModulseKovalchuk.h" << endl;
    cout << "    Клас: ClassLab12_Kovalchuk" << endl;
    cout << "    Тема: Еліптичні столи" << endl;
    cout << "=========================================" << endl;

    string resultFile = "TestResults.txt";

    // Перевірка структури директорій
    if (!isInCorrectDirectory()) {
        cout << "\n ПОМИЛКА: Структура директорій не відповідає вимогам!" << endl;
        cout << "Або ви вирішили не продовжувати виконання." << endl;

        // Звуковий сигнал про помилку
        beep100times();

        // Запис помилки у файл
        ofstream fout(resultFile);
        if (fout.is_open()) {
            fout << "ПОМИЛКА ВИКОНАННЯ ПРОГРАМИ" << endl;
            fout << "Дата: " << __DATE__ << " " << __TIME__ << endl;
            fout << "Очікувана структура: ...\\Lab12\\prj" << endl;
            fout << "Програма не може продовжити роботу." << endl;
            fout.close();
        }

        cout << "\nПомилка записана у файл: " << resultFile << endl;
        cout << "Натисніть будь-яку клавішу для завершення..." << endl;
        cin.get();
        return 1;
    }

    cout << " Перевірка структури завершена." << endl;

    // Створення директорії для тестів
    ensureTestSuiteDirectory();

    // Спробуємо різні шляхи для збереження результатів
    string testResultPaths[] = {
        "..\\TestSuite\\TestResults.txt",
        ".\\TestSuite\\TestResults.txt",
        "TestSuite\\TestResults.txt",
        "TestResults.txt"
    };

    bool testExecuted = false;
    for (const string& path : testResultPaths) {
        try {
            runTests(path);
            testExecuted = true;
            break;
        } catch (...) {
            continue;
        }
    }

    if (!testExecuted) {
        cout << "Помилка: Не вдалося виконати тестування." << endl;
    }

    // Демонстрація роботи класу
    demonstrateClass();

    cout << "\n=========================================" << endl;
    cout << "         ПРОГРАМА ЗАВЕРШЕНА" << endl;
    cout << "=========================================" << endl;
    cout << "Натисніть Enter для завершення..." << endl;
    cin.get();

    return 0;
}
