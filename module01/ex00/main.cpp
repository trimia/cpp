//
// Created by Matteo Mariani on 12/08/23.
//

#include "Zombie.hpp"

int main() {
/*
 * this zombie "gino" born and die with the main function
 */
    Zombie gino("gino");
/*
 * this zombie lino is created with new so is allocated in the heap and we have
 * to use delete in the future if we won't leak is allocated in the heap so we
 * can use it out of the scope of main function.
 */
    Zombie *lino = new Zombie("lino");

/*
 * this zombie "pino" is created with randomchump which create it in the stack
 * without allocated it so it born live and die at the enter of the randomcump
 * function
 */
    randomChump("pino");

    delete lino;
    return 0;
}