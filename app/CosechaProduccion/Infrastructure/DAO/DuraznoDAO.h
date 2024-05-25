#ifndef DURAZNODAO_H
#define DURAZNODAO_H
#include <vector>

#include "../../Business/Models/Durazno.h"

class DuraznoDAO
{
public:
    static void save(Durazno& durazno);
    
    static Durazno findById(int id);
    
    static  vector<Durazno> findAll();
};

#endif // DURAZNODAO_H
