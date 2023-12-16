#include <filesystem>
#include <iostream>
#include <memory>

#include <sqlite_orm/sqlite_orm.h>

#include "database.h"
#include "routing.h"

using namespace gartic;
namespace sql = sqlite_orm;

int main()
{
    crow::SimpleApp app;

    UserHandler storage;

    Routing r;
    r.Run(storage);

    return 0;
}