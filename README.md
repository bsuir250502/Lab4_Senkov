#﻿Lab4_Senkov
 
##Условие задачи:
Дано бинарное дерево. Записи бинарного дерева содержат
указатель на функцию и указатель на стек, хранящий строку знаков.
Одна из функций определяет правильность расстановки скобок в строке.
Вторая функция переставляет самую длинную и самую короткую строки
в соответствующих стеках.

###Решение задачи:
##### Содержание дерева:
	* указатель на стек.
	* содержание стека - сивмолы.
	* колличество символов.
	* в зависимости от колличества символов заполняется дерево элементов.
#####Содержание стека:
	* символ.
	* указатель на следующий элемент стека.

#####Функция для прверки ввода + функция для перестановки местами наименьшей и наибольшей строки.

####Информация для пользователя:
	* по-символьный ввод информации.
	* колличество вводимых символов выберает пользователь.
	* проверка строки на содержание скобок.
	* вывод дерева в введенной последовательности.
	* вывод дерева в измененной последовательности.
