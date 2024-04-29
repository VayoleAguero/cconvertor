## Руководство по использованию Convertor

Convertor - это утилита командной строки, которая предоставляет функции для конвертации чисел между различными системами счисления и выполнения побитовых операций.

### Установка

1. Склонируйте репозиторий с помощью команды:
   ```
   git clone 
   ```

2. Перейдите в папку src:
   ```
   cd src
   ```

3. Выполните сборку с помощью Makefile:
   ```
   make
   ```

### Использование

#### Конвертация чисел
- Для конвертации числа в различные системы счисления используйте следующий формат:
  ```
  ./convertor <число> [-s <системы>...]
  ```
  Например:
  ```
  ./convertor 251
  ./convertor 251 -s 13 14
  ```

#### Побитовые операции
- Для выполнения побитовой операции AND или OR используйте следующий формат:
  ```
  ./convertor --and <число1> <число2>
  ./convertor --or <число1> <число2>
  ```
  Например:
  ```
  ./convertor --and 30 952
  ./convertor --or 251 12
  ```

### Примеры вывода

- Пример вывода конвертации числа:
  ```
  Value 251 -
  bin: 11111011
  octal: 373
  hex: 0xFB
  13base: 164
  14base: 13d
  ```

- Пример вывода побитовой операции AND:
  ```
  30 AND 952 = 24
  ```

- Пример вывода побитовой операции OR:
  ```
  251 OR 12 = 255
  ```

С удовольствием используйте Convertor для удобной работы с числами и побитовыми операциями!