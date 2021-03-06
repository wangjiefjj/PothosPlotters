// Copyright (c) 2014-2016 Josh Blum
// SPDX-License-Identifier: BSL-1.0

#pragma once
#include <qwt_math.h> //_USE_MATH_DEFINES
#include <QObject>
#include <QVector>
#include <QPointF>
#include <memory>
#include <valarray>

class PothosPlotter;
class QwtPlotCurve;
class QwtPlotItem;

class PeriodogramChannel : QObject
{
    Q_OBJECT
public:
    PeriodogramChannel(const size_t index, PothosPlotter *plot);

    ~PeriodogramChannel(void);

    void update(const std::valarray<float> &powerBins, const double rate, const double freq, const double factor);

    void clearOnChange(QwtPlotItem *item);

private:

    void initBufferSize(const std::valarray<float> &powerBins, QVector<QPointF> &buff);

    QVector<QPointF> _channelBuffer;
    QVector<QPointF> _maxHoldBuffer;
    QVector<QPointF> _minHoldBuffer;
    std::unique_ptr<QwtPlotCurve> _channelCurve;
    std::unique_ptr<QwtPlotCurve> _maxHoldCurve;
    std::unique_ptr<QwtPlotCurve> _minHoldCurve;
};
