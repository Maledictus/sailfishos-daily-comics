/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Pigknit.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Pigknit::Pigknit(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("pigknit");
    m_info.name           = QString("Pigknit");
    m_info.color          = QColor(190, 175, 208);
    m_info.authors        = QStringList("Jessie Miller");
    m_info.homepage       = QUrl("https://pigknit.wordpress.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2014-10-28", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("https://pigknit.wordpress.com/");
}

QUrl Pigknit::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*pigknit.files.wordpress.com[^\"]*)\"");
    QRegularExpressionMatchIterator matchIterator = reg.globalMatch(html);

    if (!matchIterator.hasNext())
        return QUrl();

    matchIterator.next();

    if (!matchIterator.hasNext())
        return QUrl();

    QRegularExpressionMatch match = matchIterator.next();

    QString src = match.captured(1);

    return QUrl(src);
}
