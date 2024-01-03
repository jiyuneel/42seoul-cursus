#include "ClapTrap.hpp"

int main() {
    ClapTrap jiyun("Jiyun");
    ClapTrap Abcde("Abcde");

    jiyun.attack("Abcde");
    Abcde.takeDamage(jiyun.getAttackDamage());
    jiyun.beRepaired(10);

    Abcde.attack("jiyun");
    jiyun.takeDamage(Abcde.getAttackDamage());

    while (jiyun.getEnergyPoint()) {
        jiyun.attack("Abcde");
        Abcde.takeDamage(jiyun.getAttackDamage());
    }
    jiyun.attack("Abcde");
}