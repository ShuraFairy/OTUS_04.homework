#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "types.h"

class Controller;

class Model 
{
public:
    Model() : document(std::make_shared<Document>()) {};
    void ClearDocument() {
        document->clear();
        Update();
    }
    void setDocument(std::shared_ptr<Document> doc) 
    {
        document = doc;
        Update();
    };
    const std::shared_ptr<Document> getDocument() const 
    {
        return document;
    };
    void AddObject(std::unique_ptr<IShape>&& object) 
    {
        document->push_back(move(object));
        Update();
    }
    void RemoveObject(size_t index) 
    {
        document->erase(document->begin() + index);
        Update();
    }
    void setController(Controller& controller);
    void Update();

private:
    std::shared_ptr<Document> document;
    Controller* controller;
};



