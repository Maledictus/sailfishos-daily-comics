/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "SafelyEndangered.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

SafelyEndangered::SafelyEndangered(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("safelyendangered");
    m_info.name           = QString("Safely Endangered");
    m_info.color          = QColor(71, 91, 130);
    m_info.authors        = QStringList("Chris McCoy");
    m_info.homepage       = QUrl("http://www.safelyendangered.com/");
    m_info.country        = QLocale::UnitedKingdom;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2012-11-11", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.safelyendangered.com/");
}

QUrl SafelyEndangered::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
