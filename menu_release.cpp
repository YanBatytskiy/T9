/**
 * @file menu_release.cpp
 * @brief Реализация текстового интерфейса для взаимодействия с Trie (меню T9).
 */

#include "menu_release.h"
#include "my_exception.h"
#include "prefix_tree.h"
#include <iostream>
#include <string>
#include <vector>
#include "menu_release.h"
#include "my_exception.h"
#include "prefix_tree.h"
#include <iostream>
#include <string>
#include <vector>

short suggMenu(Trie &trie, std::vector<std::string> results) {

  while (true) {
    std::cout << "Поиск автодополнений. Введите префикс для поиска либо /exit "
                 "для выхода:"
              << std::endl;
    std::string key;
    std::getline(std::cin, key);

    try {
      if (key.empty())
        throw EmptyInputException();

      if (key == "/exit")
        return 0;

      std::cout << std::endl;
      trie.findAllByKey(key, results);

      std::cout << "Первые пять вариантов (всего " << results.size()
                << "результатов):" << std::endl;

      for (int i = 0; i < std::min<int>(results.size(), 5); ++i) {
        std::cout << results[i] << " ";
      }
      std::cout << std::endl;

      std::cout << "Вывести все варианты? (да-y / нет -любой другой символ): ";
      std::getline(std::cin, key);

      if (key.empty())
        throw EmptyInputException();

      if (key == "y") {
        for (int i = 0; i < results.size(); ++i) {
          std::cout << results[i] << " ";
        }
        std::cout << std::endl;
      }
    } catch (const MyException &ex) {
      std::cout << " ! " << ex.what() << " Попробуйте еще раз." << std::endl;
      continue;
    }
  } // first while
}

short addMenu(Trie &trie) {

  while (true) {
    std::cout << "Добавление слова в словарь. Введите слово либо /exit "
                 "для выхода:"
              << std::endl;
    std::string key;
    std::getline(std::cin, key);

    try {
      if (key.empty())
        throw EmptyInputException();

      if (key == "/exit" || key == "/учше")
        return 0;

      //   std::cout << std::endl;

      if (trie.findOneByKey(key)) {
        std::cout << "Такое слово уже есть в словаре." << std::endl;
        continue;
      } else {
        trie.insert(key);
        std::cout << "Добавлено." << std::endl;
        continue;
      }
    } catch (const MyException &ex) {
      std::cout << " ! " << ex.what() << " Попробуйте еще раз." << std::endl;
      continue;
    }
  } // first while
}

short delMenu(Trie &trie) {

  while (true) {
    std::cout << "Удаление слова из словаря. Введите слово либо /exit "
                 "для выхода:"
              << std::endl;
    std::string key;
    std::getline(std::cin, key);

    try {
      if (key.empty())
        throw EmptyInputException();

      if (key == "/exit" || key == "/учше")
        return 0;

      if (!trie.findOneByKey(key)) {
        std::cout << "Такого слова нет в словаре." << std::endl;
        continue;
      } else {
        trie.delWord(trie.getRoot(), key,0);
        std::cout << "Удалено." << std::endl;
        trie.printTrie();
        continue;
      }
    } catch (const MyException &ex) {
      std::cout << " ! " << ex.what() << " Попробуйте еще раз." << std::endl;
      continue;
    }
  } // first while
}
/**
 * @brief Меню поиска автодополнений по префиксу.
 * 
 * @param trie Ссылка на префиксное дерево.
 * @param results Вектор для хранения найденных слов.
 * @return short 0 — если введена команда "/exit", иначе цикл продолжается.
 *
 * @throws EmptyInputException если ввод пуст.
 */
short suggMenu(Trie &trie, std::vector<std::string> results) {
  while (true) {
    std::cout << "Поиск автодополнений. Введите префикс для поиска либо /exit для выхода:" << std::endl;
    std::string key;
    std::getline(std::cin, key);

    try {
      if (key.empty())
        throw EmptyInputException();

      if (key == "/exit")
        return 0;

      std::cout << std::endl;
      trie.findAllByKey(key, results);

      std::cout << "Первые пять вариантов (всего " << results.size() << " результатов):" << std::endl;
      for (int i = 0; i < std::min<int>(results.size(), 5); ++i) {
        std::cout << results[i] << " ";
      }
      std::cout << std::endl;

      std::cout << "Вывести все варианты? (да-y / нет -любой другой символ): ";
      std::getline(std::cin, key);

      if (key.empty())
        throw EmptyInputException();

      if (key == "y") {
        for (const auto& result : results) {
          std::cout << result << " ";
        }
        std::cout << std::endl;
      }
    } catch (const MyException &ex) {
      std::cout << " ! " << ex.what() << " Попробуйте еще раз." << std::endl;
      continue;
    }
  }
}

/**
 * @brief Меню добавления нового слова в словарь.
 * 
 * @param trie Ссылка на префиксное дерево.
 * @return short 0 — если введена команда "/exit", иначе цикл продолжается.
 *
 * @throws EmptyInputException если ввод пуст.
 */
short addMenu(Trie &trie) {
  while (true) {
    std::cout << "Добавление слова в словарь. Введите слово либо /exit для выхода:" << std::endl;
    std::string key;
    std::getline(std::cin, key);

    try {
      if (key.empty())
        throw EmptyInputException();

      if (key == "/exit" || key == "/учше")
        return 0;

      if (trie.findOneByKey(key)) {
        std::cout << "Такое слово уже есть в словаре." << std::endl;
        continue;
      } else {
        trie.insert(key);
        std::cout << "Добавлено." << std::endl;
        continue;
      }
    } catch (const MyException &ex) {
      std::cout << " ! " << ex.what() << " Попробуйте еще раз." << std::endl;
      continue;
    }
  }
}

/**
 * @brief Меню удаления слова из словаря.
 * 
 * @param trie Ссылка на префиксное дерево.
 * @return short 0 — если введена команда "/exit", иначе цикл продолжается.
 *
 * @throws EmptyInputException если ввод пуст.
 */
short delMenu(Trie &trie) {
  while (true) {
    std::cout << "Удаление слова из словаря. Введите слово либо /exit для выхода:" << std::endl;
    std::string key;
    std::getline(std::cin, key);

    try {
      if (key.empty())
        throw EmptyInputException();

      if (key == "/exit" || key == "/учше")
        return 0;

      if (!trie.findOneByKey(key)) {
        std::cout << "Такого слова нет в словаре." << std::endl;
        continue;
      } else {
        trie.delWord(trie.getRoot(), key, 0);
        std::cout << "Удалено." << std::endl;
        trie.printTrie();
        continue;
      }
    } catch (const MyException &ex) {
      std::cout << " ! " << ex.what() << " Попробуйте еще раз." << std::endl;
      continue;
    }
  }
}
