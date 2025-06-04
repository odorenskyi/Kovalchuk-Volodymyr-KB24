#include "struct_type_project_9.h"
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

// Файлові константи
const string REGISTRY_DATA_FILE = "educational_registry.dat";
const string REGISTRY_BACKUP_FILE = "educational_backup.dat";

// Декларації функцій
void printMainMenu();
int getUserMenuChoice();
void waitForUserInput();
void displayProgramHeader();
void displayProgramFooter();
bool confirmAction(const string& message);

int main() {
    // Налаштування консолі
    system("chcp 65001 > nul");
    system("cls");

    EducationalInstitution* mainRegistry = nullptr;
    int userChoice;
    bool programRunning = true;

    // Початкова ініціалізація
    displayProgramHeader();
    cout << endl;
    cout << "┌─────────────────────────────────────┐" << endl;
    cout << "│        ІНІЦІАЛІЗАЦІЯ СИСТЕМИ        │" << endl;
    cout << "└─────────────────────────────────────┘" << endl;
    cout << "⏳ Завантаження реєстру з файлу..." << endl;

    mainRegistry = loadFromFile(REGISTRY_DATA_FILE);

    cout << "✅ Система успішно ініціалізована!" << endl;
    waitForUserInput();

    // Основний цикл програми
    while (programRunning) {
        system("cls");
        displayProgramHeader();
        printMainMenu();

        userChoice = getUserMenuChoice();

        switch (userChoice) {
            case 1: {
                cout << endl;
                cout << "╔════════════════════════════════════════╗" << endl;
                cout << "║         ПЕРЕГЛЯД ВСЬОГО РЕЄСТРУ        ║" << endl;
                cout << "╚════════════════════════════════════════╝" << endl;
                displayRegistry(mainRegistry);
                waitForUserInput();
                break;
            }

            case 2: {
                cout << endl;
                cout << "╔════════════════════════════════════════╗" << endl;
                cout << "║           ЕКСПОРТ У ФАЙЛ               ║" << endl;
                cout << "╚════════════════════════════════════════╝" << endl;

                string exportFileName;
                cout << "📁 Введіть назву файлу для експорту: ";
                cin.ignore();
                getline(cin, exportFileName);

                if (exportFileName.empty()) {
                    exportFileName = "educational_export.txt";
                    cout << "ℹ️  Використовується назва за замовчуванням: " << exportFileName << endl;
                }

                displayRegistry(mainRegistry, exportFileName);
                waitForUserInput();
                break;
            }

            case 3: {
                cout << endl;
                cout << "╔════════════════════════════════════════╗" << endl;
                cout << "║        ДОДАВАННЯ НОВОГО ЗАКЛАДУ        ║" << endl;
                cout << "╚════════════════════════════════════════╝" << endl;
                mainRegistry = addRecord(mainRegistry);
                waitForUserInput();
                break;
            }

            case 4: {
                cout << endl;
                cout << "╔════════════════════════════════════════╗" << endl;
                cout << "║          ПОШУК ЗА КОДОМ ЄДЕБО          ║" << endl;
                cout << "╚════════════════════════════════════════╝" << endl;

                int searchCode;
                cout << "🔍 Введіть код ЄДЕБО для пошуку: ";

                while (!(cin >> searchCode) || searchCode <= 0) {
                    cout << "❌ Некоректне значення! Введіть додатне число: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                searchByCode(mainRegistry, searchCode);
                waitForUserInput();
                break;
            }

            case 5: {
                cout << endl;
                cout << "╔════════════════════════════════════════╗" << endl;
                cout << "║         ВИДАЛЕННЯ ІЗ РЕЄСТРУ           ║" << endl;
                cout << "╚════════════════════════════════════════╝" << endl;

                int deleteCode;
                cout << "🗑️  Введіть код ЄДЕБО для видалення: ";

                while (!(cin >> deleteCode) || deleteCode <= 0) {
                    cout << "❌ Некоректне значення! Введіть додатне число: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (confirmAction("Ви дійсно хочете видалити цей запис?")) {
                    mainRegistry = deleteRecord(mainRegistry, deleteCode);
                }
                waitForUserInput();
                break;
            }

            case 6: {
                cout << endl;
                cout << "╔════════════════════════════════════════╗" << endl;
                cout << "║           ЗБЕРЕЖЕННЯ ДАНИХ             ║" << endl;
                cout << "╚════════════════════════════════════════╝" << endl;

                if (validateDataIntegrity(mainRegistry)) {
                    saveToFile(mainRegistry, REGISTRY_DATA_FILE);

                    if (confirmAction("Створити резервну копію?")) {
                        createBackup(mainRegistry, REGISTRY_BACKUP_FILE);
                    }
                } else {
                    cout << "⚠️  Збереження відмінено через помилки в даних!" << endl;
                }
                waitForUserInput();
                break;
            }

            case 7: {
                cout << endl;
                cout << "╔════════════════════════════════════════╗" << endl;
                cout << "║          СТАТИСТИКА РЕЄСТРУ            ║" << endl;
                cout << "╚════════════════════════════════════════╝" << endl;

                int totalInstitutions = getRegistrySize(mainRegistry);

                cout << "📊 ЗАГАЛЬНА СТАТИСТИКА:" << endl;
                cout << "   └─ Всього закладів: " << totalInstitutions << endl;

                if (totalInstitutions > 0) {
                    int stateInstitutions = 0, privateInstitutions = 0;
                    int withMilitaryDept = 0, crimUkraineInstitutions = 0, donbasUkraineInstitutions = 0;

                    EducationalInstitution* current = mainRegistry;
                    while (current != nullptr) {
                        if (current->ownershipForm.find("Державна") != string::npos) {
                            stateInstitutions++;
                        } else if (current->ownershipForm.find("Приватна") != string::npos) {
                            privateInstitutions++;
                        }

                        if (current->militaryDepartment) withMilitaryDept++;
                        if (current->crimUkraine) crimUkraineInstitutions++;
                        if (current->donbasUkraine) donbasUkraineInstitutions++;

                        current = current->next;
                    }

                    cout << "\n🏛️  РОЗПОДІЛ ЗА ФОРМОЮ ВЛАСНОСТІ:" << endl;
                    cout << "   ├─ Державні: " << stateInstitutions << endl;
                    cout << "   └─ Приватні: " << privateInstitutions << endl;

                    cout << "\n🎖️  ДОДАТКОВІ ХАРАКТЕРИСТИКИ:" << endl;
                    cout << "   ├─ З військовою кафедрою: " << withMilitaryDept << endl;
                    cout << "   ├─ ОЦ 'Крим-Україна': " << crimUkraineInstitutions << endl;
                    cout << "   └─ ОЦ 'Донбас-Україна': " << donbasUkraineInstitutions << endl;
                }
                waitForUserInput();
                break;
            }

            case 0: {
                cout << endl;
                cout << "╔════════════════════════════════════════╗" << endl;
                cout << "║        ЗАВЕРШЕННЯ РОБОТИ               ║" << endl;
                cout << "╚════════════════════════════════════════╝" << endl;

                cout << "💾 Виконується автоматичне збереження..." << endl;
                if (validateDataIntegrity(mainRegistry)) {
                    autoSave(mainRegistry, REGISTRY_DATA_FILE);
                    cout << "✅ Дані збережено успішно!" << endl;
                } else {
                    cout << "⚠️  УВАГА: Знайдено помилки в даних!" << endl;
                    if (confirmAction("Зберегти незважаючи на помилки?")) {
                        saveToFile(mainRegistry, REGISTRY_DATA_FILE);
                    }
                }

                cout << "🧹 Очищення пам'яті..." << endl;
                clearRegistry(mainRegistry);

                displayProgramFooter();
                programRunning = false;
                break;
            }

            default: {
                cout << "❌ Невірний вибір! Будь ласка, спробуйте знову." << endl;
                waitForUserInput();
                break;
            }
        }
    }

    return 0;
}

/**
 * Відображення головного меню програми
 */
void printMainMenu() {
    cout << endl;
    cout << "╔══════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                        ГОЛОВНЕ МЕНЮ                          ║" << endl;
    cout << "╠══════════════════════════════════════════════════════════════╣" << endl;
    cout << "║ 1️ Переглянути весь реєстр на екрані                         ║" << endl;
    cout << "║ 2️ Експортувати реєстр у текстовий файл                      ║" << endl;
    cout << "║ 3️ Додати новий заклад до реєстру                            ║" << endl;
    cout << "║ 4️ Знайти заклад за кодом ЄДЕБО                              ║" << endl;
    cout << "║ 5️ Видалити заклад з реєстру                                 ║" << endl;
    cout << "║ 6️ Зберегти реєстр у файл                                    ║" << endl;
    cout << "║ 7️ Переглянути статистику реєстру                            ║" << endl;
    cout << "║ 0️ Завершити роботу програми                                 ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════════╝" << endl;
}

/**
 * Отримання вибору користувача з валідацією
 */
int getUserMenuChoice() {
    int choice;
    cout << "➤ Ваш вибір: ";

    while (!(cin >> choice)) {
        cout << "❌ Помилка введення! Введіть число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return choice;
}

/**
 * Очікування натискання клавіші користувачем
 */
void waitForUserInput() {
    cout << "\n⏸️  Натисніть Enter для продовження...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

/**
 * Відображення заголовка програми
 */
void displayProgramHeader() {
    cout << "╔═══════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                 ЕЛЕКТРОННА СИСТЕМА УПРАВЛІННЯ РЕЄСТРОМ                    ║" << endl;
    cout << "║                        СУБ'ЄКТІВ ОСВІТНЬОЇ ДІЯЛЬНОСТІ                     ║" << endl;
    cout << "║                            ЗАКЛАДИ ВИЩОЇ ОСВІТИ                           ║" << endl;
    cout << "║                                 ВАРІАНТ 9                                 ║" << endl;
    cout << "╠═══════════════════════════════════════════════════════════════════════════╣" << endl;
    cout << "║ Команда розробників: Авраменко, Ковальчук, Терещенко                      ║" << endl;
    cout << "║ Предмет: Базові методології та технології програмування                   ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════════════════════╝" << endl;
}

/**
 * Відображення завершального повідомлення
 */
void displayProgramFooter() {
    cout << endl;
    cout << "╔════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                    ДЯКУЄМО ЗА КОРИСТУВАННЯ!                    ║" << endl;
    cout << "║              Електронна система реєстру закрита                ║" << endl;
    cout << "║          Розробники: Авраменко, Ковальчук, Терещенко           ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════╝" << endl;
}

/**
 * Підтвердження дії користувача
 */
bool confirmAction(const string& message) {
    char response;
    cout << "❓ " << message << " (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}

// Реалізація допоміжних функцій

/**
 * Звільнення пам'яті від всього реєстру
 */
void clearRegistry(EducationalInstitution* head) {
    while (head != nullptr) {
        EducationalInstitution* temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * Підрахунок загальної кількості записів
 */
int getRegistrySize(EducationalInstitution* head) {
    int count = 0;
    EducationalInstitution* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

/**
 * Перевірка коректності введених даних
 */
bool validateInput(int code, const string& name) {
    if (code <= 0) {
        cout << "❌ Помилка: код ЄДЕБО має бути додатнім числом!" << endl;
        return false;
    }

    if (name.empty()) {
        cout << "❌ Помилка: назва закладу не може бути порожньою!" << endl;
        return false;
    }

    return true;
}
