#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>
#include <QDebug>

#ifdef QML_DIR
#include <QFileSystemWatcher>
#include <QTimer>
#endif

class Application : public QGuiApplication {
    Q_OBJECT;
    QQmlApplicationEngine engine;
    QUrl main_file;

#ifdef QML_DIR
    QFileSystemWatcher watcher;
    QTimer reloadDedupTimer;
#endif

public:

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

    Q_INVOKABLE void clearComponentCache() {
        this->engine.clearComponentCache();
    }

signals:
    void reload();

private slots:
    void fileChanged(const QString &file) {
#ifdef QML_DIR
        this->reloadDedupTimer.start();
#endif
    }
};


int main(int argc, char* argv[]) {
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    Application app(argc, argv);

    return app.exec();
}

#include "main.moc"
