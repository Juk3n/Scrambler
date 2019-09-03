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

    prepareData(data);
    createHistogram();
}

Histogram::~Histogram()
{
    delete ui;
}

void Histogram::prepareData(const std::vector<bool> &data)
{
    std::vector<int> numberOfRepetitionsOfEachSize;
    auto longestSerie{ 0 };
    int sizeOfSerie{};
    bool whatToCount{1};

    //find the longest
    for (const auto &bit : data)
    {
        if (bit == whatToCount) sizeOfSerie++;
        else {
            if (sizeOfSerie > longestSerie) longestSerie = sizeOfSerie;
            sizeOfSerie = 0;
        }
     }

     if (sizeOfSerie > longestSerie) longestSerie = sizeOfSerie;
     sizeOfSerie = 0;

     for (int i = 1; i <= longestSerie; i++) numberOfRepetitionsOfEachSize.push_back(0);


     for (auto bit : data) {
        if (bit == whatToCount) sizeOfSerie++;
        else if (sizeOfSerie > 0) {
            numberOfRepetitionsOfEachSize[sizeOfSerie - 1] = numberOfRepetitionsOfEachSize[sizeOfSerie - 1] + 1;
            sizeOfSerie = 0;
        }
     }

     if (sizeOfSerie > 0) numberOfRepetitionsOfEachSize[sizeOfSerie - 1] = numberOfRepetitionsOfEachSize[sizeOfSerie - 1] + 1;



     int iterator{};
     for (const auto &numOfSeries : numberOfRepetitionsOfEachSize) {
        x.append(iterator+1);
        y.append(numOfSeries);

        iterator++;
     }
}

void Histogram::createHistogram()
{
    int theBiggest{0};
    for (auto val : y) {
        if(val > theBiggest) theBiggest = val;
    }

    //set dark gradient background
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(40, 40, 40));
    gradient.setColorAt(0.38, QColor(70, 70, 70));
    gradient.setColorAt(1, QColor(50, 50, 50));
    ui->histogramChart->setBackground(QBrush(gradient));

    //create barchart objecct
    QCPBars *bar = new QCPBars(ui->histogramChart->xAxis, ui->histogramChart->yAxis);
    bar->setAntialiased(false);
    bar->setStackingGap(1);
    bar->setName("test");
    bar->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    bar->setBrush(QColor(111, 9, 176));
    bar->setData(x, y);

    // set axes ranges, so we see all data:
    ui->histogramChart->xAxis->setBasePen(QPen(Qt::white));
    ui->histogramChart->xAxis->setTickPen(QPen(Qt::white));
    ui->histogramChart->yAxis->setBasePen(QPen(Qt::white));
    ui->histogramChart->yAxis->setTickPen(QPen(Qt::white));

    ui->histogramChart->xAxis->setRange(0, x.size());
    ui->histogramChart->yAxis->setRange(0, theBiggest);
    ui->histogramChart->replot();
}
