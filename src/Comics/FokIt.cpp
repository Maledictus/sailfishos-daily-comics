/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FokIt.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

FokIt::FokIt(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("fokit");
    m_info.name           = QString("Fok_it");
    m_info.color          = QColor(255, 138, 145);
    m_info.authors        = QStringList("Joonas Rinta-Kanto");
    m_info.homepage       = QUrl("https://fokit.wordpress.com/");
    m_info.country        = QLocale::Finland;
    m_info.language       = QLocale::Finnish;
    m_info.startDate      = QDate::fromString("2009", "yyyy");
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://nyt.fi/aihe/fokit/");
}

QUrl FokIt::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/webkuva/sarjis[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
