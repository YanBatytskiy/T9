/**
 * @file utf8console.h
 * @brief Утилита для включения UTF-8 режима в консоли.
 * @details Настраивает глобальную и стандартную локаль для корректного
 * отображения и ввода UTF-8 символов в Windows и Unix-подобных системах.
 */

#pragma once

#include <iostream>
#include <locale>

#if defined(_WIN32)
    #include <windows.h>
#endif

/**
 * @brief Включает поддержку UTF-8 в консоли.
 *
 * @details Настраивает глобальную локаль и кодировку консоли.
 * Работает стабильно на Windows (MSYS2/MinGW), Linux и macOS.
 */
inline void enableUTF8Console() {
#if defined(_WIN32)
    try {
        std::locale utf8_locale(""); // системная локаль (обычно UTF-8 в MSYS2)
        std::locale::global(utf8_locale);

        std::wcin.imbue(utf8_locale);
        std::wcout.imbue(utf8_locale);
        std::wcerr.imbue(utf8_locale);
    } catch (const std::exception& e) {
        std::cerr << "Failed to set UTF-8 locale on Windows: " << e.what() << std::endl;
    }

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

#else
    try {
        std::locale utf8_locale("en_US.UTF-8");
        std::locale::global(utf8_locale);

        std::wcin.imbue(utf8_locale);
        std::wcout.imbue(utf8_locale);
        std::wcerr.imbue(utf8_locale);
    } catch (const std::exception& e) {
        std::cerr << "Failed to set UTF-8 locale on Unix: " << e.what() << std::endl;
    }
#endif
}
