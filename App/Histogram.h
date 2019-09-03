#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QDialog>

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
};

#endif // HISTOGRAM_H
