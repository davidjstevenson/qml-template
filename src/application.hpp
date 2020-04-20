#include <QGuiApplication>
#include <QQmlApplicationEngine>

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

    Application(int argc, char* argv[]);

    Q_INVOKABLE void clearComponentCache();

signals:
    void reload();

private slots:
    void fileChanged(const QString &);
};

