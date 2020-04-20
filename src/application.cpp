#include <QQmlContext>
#include <QDir>
#include <QDebug>

#include "application.hpp"

#ifdef QML_DIR
#include <QFileSystemWatcher>
#include <QTimer>
#endif

Application::Application(int argc, char* argv[]) : QGuiApplication(argc, argv) {
#ifdef QML_DIR
    this->main_file = QUrl::fromLocalFile(QStringLiteral(QML_DIR "/main.qml"));
    watcher.addPath(QStringLiteral(QML_DIR "/main.qml"));
    watcher.addPath(QStringLiteral(QML_DIR));
    QObject::connect(&watcher, &QFileSystemWatcher::fileChanged, this, &Application::fileChanged);
    QObject::connect(&watcher, &QFileSystemWatcher::directoryChanged, this, &Application::fileChanged);
    reloadDedupTimer.setInterval(100);
    reloadDedupTimer.setSingleShot(true);
    QObject::connect(&this->reloadDedupTimer, &QTimer::timeout, this, &Application::reload);
#else
    this->main_file = QUrl(QStringLiteral("qrc:/qml/main.qml"));
#endif
    engine.rootContext()->setContextProperty("$App", this);
    engine.load(this->main_file);
}

void Application::clearComponentCache() {
    this->engine.clearComponentCache();
}

void Application::fileChanged(const QString &) {
#ifdef QML_DIR
    this->reloadDedupTimer.start();
#endif
}

