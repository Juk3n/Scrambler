#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QDialog>

#include <map>
#include <unordered_set>
#include <algorithm>

namespace Ui {
class Histogram;
}

class Histogram : public QDialog
{
    Q_OBJECT

public:
    explicit Histogram(QWidget *parent = nullptr, std::vector<bool> data = std::vector<bool>());
    ~Histogram();

private:
    Ui::Histogram *ui;
    QVector<double> x;
    QVector<double> y;

    void prepareData(const std::vector<bool> &data);
    void createHistogram();
};

#endif // HISTOGRAM_H
