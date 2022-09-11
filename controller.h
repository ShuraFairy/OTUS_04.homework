#pragma once

#include "types.h"
#include <memory>

int checkPointInFigure(const std::shared_ptr<Document> figures, int x, int y)
{
    auto p = figures.get();
    for (int i = p->size() - 1; i != 0; --i)
    {
        if (p->at(i)->checkPointInside(x, y))
        {
            return i;
        };
    }
    return -1;
}

class Model;
class View;

class Controller {
public:    
    Controller(Model& model, const View& view) : model(&model), view(&view) {};
        
    void CreateNewDocument() 
    {
        model->ClearDocument();
    };

    void ImportDocumentFromFile(const std::string&& filename) 
    {
        std::cout << "Import from " << filename << "\n";
        auto deserialized = std::make_shared<Document>();
        model->setDocument(deserialized);
    };
    void ExportDocumentToFile(const std::string&& filename) 
    {
        model->getDocument();
        std::cout << "Export to " << filename << "\n";
        //serialize(model->getDocument);
    };
    
    void AddShape(std::unique_ptr<IShape> shape) 
    {
        model->AddObject(move(shape));
    };
        
    void RemoveShape(int x, int y) 
    {
        int i = checkPointInFigure(model->getDocument(), x, y);
        if (i != -1 && i < static_cast<int>(model->getDocument()->size())) 
        {
            model->RemoveObject(i);
        }

    };
    
    void Update() {
        view->Draw(model->getDocument());
    }
private:
    Model* model;
    const View* view;
};

