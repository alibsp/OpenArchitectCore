#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>
#include <QPluginLoader>
#include <QDebug>
#include "TacticalPluginInterface.hpp"
#include "UIEngine.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QList<TacticalPluginInterface*> plugins;

    QDir pluginsDir(qApp->applicationDirPath() + "/Plugins");
    UIEngine uiEngine;
    for (const QString &fileName : pluginsDir.entryList(QDir::Files))
    {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject* plugin = loader.instance();
        if (plugin)
        {
            auto tacticalPlugin = qobject_cast<TacticalPluginInterface*>(plugin);
            if (tacticalPlugin)
            {
                qDebug() << "Loaded plugin:" << tacticalPlugin->pluginName();
                uiEngine.registerPlugin(tacticalPlugin);
            }

        }
    }
    // expose UIEngine to QML
    engine.rootContext()->setContextProperty("uiEngine", &uiEngine);

    engine.load(QUrl(QStringLiteral("qrc:/qml/MainWindow.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    // بعد از load، می‌توانیم پنل‌های پلاگین‌ها را اضافه کنیم
    QObject *rootObj = engine.rootObjects().first();
    QObject *container = rootObj->findChild<QObject*>("pluginContainer");

    if (container) {
        for (auto plugin : uiEngine.getPlugins()) {
            QQuickItem* panel = plugin->createPanel(&engine);
            if (panel) {
                panel->setParentItem(qobject_cast<QQuickItem*>(container));
            }
        }
    }


    return app.exec();
}
