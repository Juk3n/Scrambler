#include "histogram.h"
#include "ui_histogram.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QAreaSeries>

QT_CHARTS_USE_NAMESPACE

Histogram::Histogram(QWidget *parent, std::vector<bool> data) :
    QDialog(parent),
    ui(new Ui::Histogram)
{
    ui->setupUi(this);


}

Histogram::~Histogram()
{
    delete ui;
}
