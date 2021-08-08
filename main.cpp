#include "App.h"
#include "MainWindow.h"

using net::draconia::util::App;

int main(int argc, char *argv[])
{
    return(App(argc, argv).exec());
}
