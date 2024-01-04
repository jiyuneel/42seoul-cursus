#include "ClapTrap.hpp"

int main() {
    ClapTrap jiyun("Jiyun");
    ClapTrap abcde("Abcde");

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
}