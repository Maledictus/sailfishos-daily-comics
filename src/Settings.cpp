/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Settings.h"

#include <QDebug>

Settings* Settings::m_instance = NULL;

const QString Settings::_settingsFavoritesInfoHintField = QString("hints/settings_favorites_info");

Settings::Settings(QObject *parent) :
    QObject(parent)
{
    m_settings = new QSettings(this);
}

Settings* Settings::instance()
{
    if (!m_instance) {
        m_instance = new Settings();
    }

    return m_instance;
}

Settings::~Settings()
{
    delete m_settings;
}

void Settings::emitFavoritesChanged()
{
    emit favoritesChanged();
}

QStringList Settings::fullComicsList()
{
    return QStringList()
        << "calvinandhobbes"
        << "dilbert"
        << "garfield"
        << "lechat"
        << "peanuts"
        << "xkcd"
        << "dennisthemenace"
        << "fingerpori"
        << "foxtrot"
        << "cyanideandhappiness"
        << "hagarthehorrible"
        << "poyroot"
        << "shithappens"
        << "viivijawagner"
        << "smbc"
        << "phdcomics"
        << "fokit"
        << "dieselsweeties"
        << "commitstrip"
        << "tubeytoons";
}

bool Settings::settingsFavoritesInfoHint()
{
    if (!m_settings->contains(_settingsFavoritesInfoHintField)) {
        return true;
    }

    return value(_settingsFavoritesInfoHintField).toBool();
}

void Settings::hideSettingsFavoritesInfoHint()
{
    setValue(_settingsFavoritesInfoHintField, false);
}

QVariant Settings::value(const QString &key)
{
    return m_settings->value(key);
}

void Settings::setValue(const QString &key, const QVariant &value)
{
    m_settings->setValue(key, value);
}
