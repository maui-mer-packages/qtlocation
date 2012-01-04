/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef QGEOBOUNDINGBOX_H
#define QGEOBOUNDINGBOX_H

#include "qgeoboundingarea.h"

#include <QSharedDataPointer>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE



class QGeoCoordinate;
class QGeoBoundingBoxPrivate;

class Q_LOCATION_EXPORT QGeoBoundingBox : public QGeoBoundingArea
{
public:
    QGeoBoundingBox();
    QGeoBoundingBox(const QGeoCoordinate &center, double degreesWidth, double degreesHeight);
    QGeoBoundingBox(const QGeoCoordinate &topLeft, const QGeoCoordinate &bottomRight);

    QGeoBoundingBox(const QGeoBoundingBox &other);
    ~QGeoBoundingBox();

    QGeoBoundingBox& operator = (const QGeoBoundingBox &other);

    bool operator == (const QGeoBoundingArea &other) const;
    bool operator == (const QGeoBoundingBox &other) const;

    bool operator != (const QGeoBoundingArea &other) const;
    bool operator != (const QGeoBoundingBox &other) const;

    QGeoBoundingArea::AreaType type() const;

    bool isValid() const;
    bool isEmpty() const;

    void setTopLeft(const QGeoCoordinate &topLeft);
    QGeoCoordinate topLeft() const;

    void setTopRight(const QGeoCoordinate &topRight);
    QGeoCoordinate topRight() const;

    void setBottomLeft(const QGeoCoordinate &bottomLeft);
    QGeoCoordinate bottomLeft() const;

    void setBottomRight(const QGeoCoordinate &bottomRight);
    QGeoCoordinate bottomRight() const;

    void setCenter(const QGeoCoordinate &center);
    QGeoCoordinate center() const;

    void setWidth(double degreesWidth);
    double width() const;

    void setHeight(double degreesHeight);
    double height() const;

    bool contains(const QGeoCoordinate &coordinate) const;
    bool contains(const QGeoBoundingBox &boundingBox) const;
    bool intersects(const QGeoBoundingBox &boundingBox) const;

    void translate(double degreesLatitude, double degreesLongitude);
    QGeoBoundingBox translated(double degreesLatitude, double degreesLongitude) const;

    QGeoBoundingBox united(const QGeoBoundingBox &boundingBox) const;
    QGeoBoundingBox operator | (const QGeoBoundingBox &boundingBox) const;
    QGeoBoundingBox& operator |= (const QGeoBoundingBox &boundingBox);

    QGeoBoundingArea *clone() const;

private:
    QSharedDataPointer<QGeoBoundingBoxPrivate> d_ptr;
};

inline QGeoBoundingBox QGeoBoundingBox::operator | (const QGeoBoundingBox &boundingBox) const
{
    return united(boundingBox);
}

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QGeoBoundingBox)

QT_END_HEADER

#endif

