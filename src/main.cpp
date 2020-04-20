#include <QGuiApplication>
#include "application.hpp"


int main(int argc, char* argv[]) {
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    Application app(argc, argv);

    return app.exec();
}
