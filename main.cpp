#include <cstdlib>
#include <iostream>
#include "shape.h"
#include "types.h"
#include "view.h"
#include "model.h"
#include "controller.h"

void Model::setController(Controller& controller_) 
{
    controller = &controller_;
}

void Model::Update()
{
    controller->Update();
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
	View view;
	Model model;
	Controller controller(model, view);
	model.setController(controller);
    controller.ImportDocumentFromFile("test.bin");
    controller.CreateNewDocument();
    controller.AddShape(std::make_unique<Circle>(10, 20, 10));
    controller.AddShape(std::make_unique<Square>(10, 10, 5));
    controller.ExportDocumentToFile("test.bin");

	return EXIT_SUCCESS;
}
