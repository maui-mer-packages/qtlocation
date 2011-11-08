/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtLocation module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QDECLARATIVERATING_P_H
#define QDECLARATIVERATING_P_H

#include <qplacerating.h>
#include <QtDeclarative/qdeclarative.h>

#include <QObject>

QT_BEGIN_NAMESPACE

class QDeclarativeRating : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QPlaceRating rating READ rating WRITE setRating)
    Q_PROPERTY(qreal value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(qreal maximum READ maximum WRITE setMaximum NOTIFY maximumChanged)
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)

public:
    explicit QDeclarativeRating(QObject* parent = 0);
    explicit QDeclarativeRating(const QPlaceRating &src, QObject* parent = 0);
    ~QDeclarativeRating();

    QPlaceRating rating() const;
    void setRating(const QPlaceRating &src);

    qreal value() const;
    void setValue(qreal value);

    qreal maximum() const;
    void setMaximum(qreal max);

    int count() const;
    void setCount(int count);

signals:
    void valueChanged();
    void maximumChanged();
    void countChanged();

private:
    QPlaceRating m_rating;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QT_PREPEND_NAMESPACE(QDeclarativeRating));

#endif // QDECLARATIVERATING_P_H
