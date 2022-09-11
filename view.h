#pragma once

#include <iostream>
#include <memory>
#include "types.h"

class View 
{
public:    
    void ClearCanvas() const
    {
        std::cout << "=== Clear canvas ===\n";
    };
    
    void Draw(const std::shared_ptr<Document> document) const 
    {
        ClearCanvas();
        for (auto& i : *document) 
            i->Draw();        
    };
};
