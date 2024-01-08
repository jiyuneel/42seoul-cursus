#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
private:
    std::string _ideas[100];

public:
    Brain();
    Brain(const Brain& brain);
    Brain& operator=(const Brain& brain);
    ~Brain();

    const std::string getIdea(int idx) const;
    void setIdea(const std::string idea, int idx);
};

#endif