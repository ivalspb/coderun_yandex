﻿/*
Около Петиного университета недавно открылось новое кафе, в котором действует следующая система скидок: при каждой покупке более чем на 100 рублей покупатель получает купон, дающий право на один бесплатный обед (при покупке на сумму 100 рублей и меньше такой купон покупатель не получает).

Однажды Пете на глаза попался прейскурант на ближайшие N дней. Внимательно его изучив, он решил, что будет обедать в этом кафе все N дней, причем каждый день он будет покупать в кафе ровно один обед. Однако стипендия у Пети небольшая, и поэтому он хочет по максимуму использовать предоставляемую систему скидок так, чтобы его суммарные затраты были минимальны. Требуется найти минимально возможную суммарную стоимость обедов и номера дней, в которые Пете следует воспользоваться купонами.

Формат ввода
В первой строке входного файла записано целое число N (0
≤
≤ N
≤
≤ 100). В каждой из последующих N строк записано одно целое число, обозначающее стоимость обеда в рублях на соответствующий день. Стоимость — неотрицательное целое число, не превосходящее 300.

Формат вывода
В первой строке выдайте минимальную возможную суммарную стоимость обедов. Во второй строке выдайте два числа
�
1
K
1
​
  и
�
2
K
2
​
  — количество купонов, которые останутся неиспользованными у Пети после этих N дней и количество использованных им купонов соответственно.

В последующих
�
2
K
2
​
  строках выдайте в возрастающем порядке номера дней, когда Пете следует воспользоваться купонами. Если существует несколько решений с минимальной суммарной стоимостью, то выдайте то из них, в котором значение
�
1
K
1
​
  максимально (на случай, если Петя когда-нибудь ещё решит заглянуть в это кафе). Если таких решений несколько, выведите любое из них.

Пример 1
Ввод
5
35
40
101
59
63
Вывод
235
0 1
5
*/
#include <iostream>
#include <vector>

int main()
{
    size_t N_days;
    std::cin>>N_days;
    std::vector<size_t>prices(N_days);
    for (size_t i = 0; i < N_days; i++) 
        std::cin >> prices[i];


    std::cout << "Hello World!\n";
    return 0;
}
