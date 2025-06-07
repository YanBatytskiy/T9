/**
 * @file my_exception.h
 * @brief Заголовочный файл с определениями пользовательских исключений для T9.
 */

#pragma once
#include <exception>
#include <string>

/**
 * @class MyException
 * @brief Базовый класс для всех пользовательских исключений.
 */
class MyException : public std::exception {
private:
  std::string _message; ///< Сообщение об ошибке.
  std::string _utf8Message; ///< Резерв под расширения (не используется сейчас).

public:
  /**
   * @brief Конструктор с текстом ошибки.
   * @param message Текст сообщения.
   */
  explicit MyException(const std::string &message) : _message(message) {}

  /**
   * @brief Возвращает сообщение об ошибке.
   * @return C-строка с текстом ошибки.
   */
  const char *what() const noexcept override { return _message.c_str(); }
};

/**
 * @class WrongCharException
 * @brief Исключение при вводе недопустимого символа.
 */
class WrongCharException : public MyException {
public:
  /**
   * @brief Конструктор с текстом символа.
   * @param input Недопустимый символ или строка.
   */
  explicit WrongCharException(const std::string &input)
      : MyException("Вы ввели некорректный символ: " + input) {}
};

/**
 * @class EmptyInputException
 * @brief Исключение при пустом вводе.
 */
class EmptyInputException : public MyException {
public:
  /**
   * @brief Конструктор по умолчанию.
   */
  explicit EmptyInputException()
      : MyException("Вы ничего не ввели: ") {}
};

/**
 * @class WrongCommandException
 * @brief Исключение при вводе неизвестной команды.
 */
class WrongCommandException : public MyException {
public:
  /**
   * @brief Конструктор по умолчанию.
   */
  explicit WrongCommandException()
      : MyException("Вы ввели неправильную команду.") {}
};