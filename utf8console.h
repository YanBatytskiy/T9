/**
 * @file utf8console.h
 * @brief Утилита для включения UTF-8 режима в консоли.
 * @details Настраивает глобальную и стандартную локаль для корректного
 * отображения и ввода UTF-8 символов в Windows и Unix-подобных системах.
 */

#pragma once

#include <iostream>
#include <locale>

#ifdef _WIN32
#include <windows.h>
#endif

/**
 * @brief Включает поддержку UTF-8 в консоли.
 *
 * @details Устанавливает глобальную локаль "en_US.UTF-8" и
 * применяет её к std::wcin, std::wcout и std::wcerr.
 * В Windows дополнительно настраивает кодовые страницы консоли.
 */
inline void enableUTF8Console() {
  std::locale utf8_locale("en_US.UTF-8");
  std::locale::global(utf8_locale);

  std::wcin.imbue(utf8_locale);
  std::wcout.imbue(utf8_locale);
  std::wcerr.imbue(utf8_locale);

#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif
}
