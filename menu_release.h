/**
 * @file menu_release.h
 * @brief Заголовок для текстового интерфейса T9-бота (меню команд).
 */

#pragma once

#include "prefix_tree.h"
#include <vector>
#include <string>

/**
 * @brief Меню автодополнения по префиксу.
 * @param trie Ссылка на префиксное дерево.
 * @param results Вектор для хранения результатов.
 * @return short 0 — выход из меню, иначе бесконечный цикл.
 */
short suggMenu(Trie &trie, std::vector<std::string> results);

/**
 * @brief Меню добавления слова в словарь.
 * @param trie Ссылка на префиксное дерево.
 * @return short 0 — выход из меню, иначе бесконечный цикл.
 */
short addMenu(Trie &trie);

/**
 * @brief Меню удаления слова из словаря.
 * @param trie Ссылка на префиксное дерево.
 * @return short 0 — выход из меню, иначе бесконечный цикл.
 */
short delMenu(Trie &trie);
