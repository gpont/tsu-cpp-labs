#ifndef HANOI_HPP
#define HANOI_HPP

#include "stack.hpp"

/**
 * @param *s - 3 стека с дисками
 * @param n - кол-во дисков, которое нужно переложить
 * @param from - откуда
 * @param to - куда
 * @param help - вспомогательный диск
 */
void hanoi_towers(Stack<int>* s, int n, int from, int to, int help);

#endif // HANOI_HPP