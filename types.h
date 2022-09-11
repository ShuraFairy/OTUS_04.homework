#pragma once
#include <vector>
#include <memory>
#include "shape.h"

using Document = std::vector<std::unique_ptr<IShape>>;
