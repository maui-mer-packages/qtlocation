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
***************************************************************************/

#include <qnumeric.h>
#include "qdeclarativegeoboundingcircle_p.h"

QT_BEGIN_NAMESPACE

/*!
    \qmlclass BoundingCircle QDeclarativeGeoBoundingCircle
    \inqmlmodule QtLocation 5
    \ingroup qml-QtLocation5-positioning
    \since QtLocation 5.0

    \brief The BoundingCircle element represents a circular geographic area.
*/

QDeclarativeGeoBoundingCircle::QDeclarativeGeoBoundingCircle(QObject* parent)
    : QDeclarativeGeoBoundingArea(parent),
      m_center(0)
{
}

QDeclarativeGeoBoundingCircle::QDeclarativeGeoBoundingCircle(const QGeoBoundingCircle& circle, QObject* parent) :
    QDeclarativeGeoBoundingArea(parent),
    m_center(new QDeclarativeCoordinate(circle.center(), this)), m_circle(circle)
{
}

/*!
    \qmlproperty QGeoBoundingCircle BoundingCircle::circle

    This property is used to provide an interface between C++ and QML code.  First a pointer to a
    BoundingCircle object must be obtained from C++, then use the
    \l {QObject::property()}{property()} and \l {QObject::setProperty()}{setProperty()} functions
    to get and set the \c circle property.

    The following gets the QGeoBoundingCircle representing this object from C++:

    \snippet snippets/cpp/cppqml.cpp BoundingCircle get

    The following sets the properties of this object based on a QGeoBoundingCircle object from C++:

    \snippet snippets/cpp/cppqml.cpp BoundingCircle set
*/
void QDeclarativeGeoBoundingCircle::setCircle(const QGeoBoundingCircle& circle)
{
    if ((m_center && m_center->coordinate() != circle.center()) || !m_center) {
        if (m_center && m_center->parent() == this)
            m_center->setCoordinate(m_circle.center());
        else
            m_center = new QDeclarativeCoordinate(circle.center(), this);
        m_circle.setCenter(circle.center());

        emit centerChanged();
    }

    if (!qFuzzyCompare(m_circle.radius(), circle.radius())) {
        m_circle.setRadius(circle.radius());
        emit radiusChanged();
    }
}

QGeoBoundingCircle QDeclarativeGeoBoundingCircle::circle() const
{
    if (m_center)
        m_circle.setCenter(m_center->coordinate());
    else
        m_circle.setCenter(QGeoCoordinate());
    return m_circle;
}

QGeoBoundingArea *QDeclarativeGeoBoundingCircle::area() const
{
    return circle().clone();
}

Q_INVOKABLE bool QDeclarativeGeoBoundingCircle::contains(QDeclarativeCoordinate* coordinate)
{
    if (!coordinate || !m_center)
        return false;

    return m_circle.contains(coordinate->coordinate());
}

/*!
    \qmlproperty Coordinate BoundingCircle::center

    This property holds the coordinate of the center of the bounding circle.
*/
QDeclarativeCoordinate* QDeclarativeGeoBoundingCircle::center()
{
    return m_center;
}

void QDeclarativeGeoBoundingCircle::setCenter(QDeclarativeCoordinate *coordinate)
{
    if (m_center != coordinate) {
        if (m_center && m_center->parent() == this)
            delete m_center;
        m_center = coordinate;
        emit centerChanged();
    }
}

/*!
    \qmlproperty qreal BoundingCircle::radius

    This property holds the radius of the bounding circle in meters.

    The default value for the radius is -1 indicating an invalid bounding circle area.
*/
qreal QDeclarativeGeoBoundingCircle::radius() const
{
    return m_circle.radius();
}

void QDeclarativeGeoBoundingCircle::setRadius(const qreal radius)
{
    if (!qFuzzyCompare(m_circle.radius(),radius)) {
        m_circle.setRadius(radius);
        emit radiusChanged();
    }
}

#include "moc_qdeclarativegeoboundingcircle_p.cpp"

QT_END_NAMESPACE
