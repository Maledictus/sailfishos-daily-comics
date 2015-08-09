/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "HagarTheHorrible.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

HagarTheHorrible::HagarTheHorrible(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("hagarthehorrible");
    m_info.name           = QString("Hägar the Horrible");
    m_info.color          = QColor(216, 164, 55);
    m_info.authors        = QStringList() << "Dik Browne" << "Chris Browne";
    m_info.homepage       = QUrl("http://hagarthehorrible.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("1973-02-04", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://hagarthehorrible.com/");
}

QUrl HagarTheHorrible::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*content\\.php[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
