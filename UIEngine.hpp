#pragma once
#include <QObject>
#include <QList>
#include "TacticalPluginInterface.hpp"

class UIEngine : public QObject {
    Q_OBJECT

public:
    UIEngine(QObject* parent = nullptr) : QObject(parent) {}

    void registerPlugin(TacticalPluginInterface* plugin) {
        if (!plugin) return;
        plugins.append(plugin);
    }

    const QList<TacticalPluginInterface*>& getPlugins() const {
        return plugins;
    }

private:
    QList<TacticalPluginInterface*> plugins;
};
