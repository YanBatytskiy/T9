#include "menu_release.h"
#include "my_exception.h"
#include "prefix_tree.h"
#include "utf8console.h"
#include <iostream>
#include <string>
#include <vector>

/**B
 * @brief Главное текстовое меню T9.
 *
 * @param trie Ссылка на объект Trie (префиксное дерево), с которым работает
 * пользователь.
 * @return short Возвращает 0 при вводе команды выхода ("/exit"), иначе цикл
 * продолжается.
 *
 * @throws EmptyInputException если строка пуста.
 * @throws WrongCommandException если команда неизвестна.B
 */
short authMenu(Trie &trie) {
  while (true) {
    std::cout << std::endl
              << "T9_Bot 'Shark' Версия 1.0. @2025" << std::endl
              << std::endl;
    std::cout << "Введите префикс для поиска и команду: " << std::endl;
    std::cout << "'/exit' для выхода" << std::endl;
    std::cout << "'/sugg' для поиска автодополнений префикса" << std::endl;
    std::cout << "'/add' для добавления слова в словарь" << std::endl;
    std::cout << "'/del' для удаления слова из словаря" << std::endl;
    std::cout << "'/print' напечатать словарь" << std::endl;

    std::string userChoice;

    while (true) {
      std::getline(std::cin, userChoice);
      try {
        if (userChoice.empty())
          throw EmptyInputException();

        if (userChoice == "/exit" || userChoice == "/учше")
          return 0;

        if (userChoice == "/sugg") {
          std::vector<std::string> results{};
          suggMenu(trie, results);
          break;
        }
        if (userChoice == "/add") {
          addMenu(trie);
          break;
        }
        if (userChoice == "/del") {
          delMenu(trie);
          break;
        }

        if (userChoice == "/print") {
          trie.printTrie();
          break;
        }

        throw WrongCommandException();

      } catch (const MyException &ex) {
        std::cout << " ! " << ex.what() << " Попробуйте еще раз." << std::endl;
        continue;
      }
    }
  }
}

/**
 * @brief Точка входа в приложение T9.
 *
 * @return int Возвращает 0 при успешном завершении.
 *
 * @details Инициализирует консоль в режиме UTF-8, создает дерево Trie,
 * добавляет стартовые слова, запускает главное меню.
 */
int main() {
  std::setlocale(LC_ALL, "");
  enableUTF8Console();

  Trie *trie = new Trie();
  std::vector<std::string> dictionary = {};

  dictionary.push_back("кни");
  dictionary.push_back("книжка");
  dictionary.push_back("код");
  dictionary.push_back("кот");
  dictionary.push_back("котище");
  dictionary.push_back("котик");
  dictionary.push_back("котико");
  dictionary.push_back("котофей");
  dictionary.push_back("котомка");
  dictionary.push_back("котлин");
  dictionary.push_back("котомафия");
  dictionary.push_back("рак");
  dictionary.push_back("ракот");
  dictionary.push_back("рачок");
  dictionary.push_back("рокот");
  dictionary.push_back("рокотать");
  dictionary.push_back("рокотал");

  for (const std::string &word : dictionary) {
    trie->insert(word);
  }

  trie->printTrie();

  short userChoice;

  while (true) {
    userChoice = authMenu(*trie);
    if (!userChoice)
      break;
  }

  delete trie;
  return 0;
}
