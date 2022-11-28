#include <cstdlib>
#include <iostream>
#include "shape.h"
#include "types.h"
#include "view.h"
#include "model.h"
#include "controller.h"

void Model::setController(std::shared_ptr<Controller> controller_)
{
    controller = controller_;
}

void Model::Update()
{
    controller->Update();
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{    
    std::unique_ptr<View> view = std::unique_ptr<View>();
    std::shared_ptr<Model> model = std::make_shared<Model>();
    std::shared_ptr<Controller> controller = std::make_shared<Controller>(model, std::move(view));	

    model->setController(controller);
    controller->ImportDocumentFromFile("test.bin");
    controller->CreateNewDocument();
    controller->AddShape(std::make_unique<Circle>(10, 20, 10));
    controller->AddShape(std::make_unique<Square>(10, 10, 5));
    controller->ExportDocumentToFile("test.bin");	

    return EXIT_SUCCESS;
}
