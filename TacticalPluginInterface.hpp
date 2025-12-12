
#pragma once
#include <QObject>
#include <QQuickItem>
#include <QQmlEngine>

class TacticalPluginInterface {
public:
    virtual QString pluginName() const = 0;
    virtual QQuickItem* createPanel(QQmlEngine* engine) = 0;
    virtual void onDataReceived(const QByteArray& msg) = 0;
    virtual ~TacticalPluginInterface() {}
};

#define TacticalPluginInterface_iid "org.navy.TacticalPluginInterface"
Q_DECLARE_INTERFACE(TacticalPluginInterface, TacticalPluginInterface_iid)
