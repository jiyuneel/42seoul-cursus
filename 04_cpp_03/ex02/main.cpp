#include "FragTrap.hpp"

int main() {
    FragTrap jiyun("Jiyun");
    FragTrap abcde("Abcde");

    jiyun.showStatus();
    abcde.showStatus();

    jiyun.attack("Abcde");
    abcde.takeDamage(jiyun.getAttackDamage());
    jiyun.beRepaired(10);

    jiyun.showStatus();
    abcde.showStatus();

    abcde.attack("jiyun");
    jiyun.takeDamage(abcde.getAttackDamage());

    jiyun.showStatus();
    abcde.showStatus();

    abcde.highFivesGuys();
}