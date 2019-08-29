#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>
#include <iostream>

#include <QDialog>

#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
using namespace QtCharts;


class Histogram
{
	std::vector<int> numberOfRepetitionsOfEachSize;
public:
    Histogram() {
        QDialog *dialog = new QDialog();


        QLineSeries *series = new QLineSeries();
            *series << QPointF(0, 6) << QPointF(9, 4) << QPointF(15, 20) << QPointF(25, 12) << QPointF(29, 26);
            QChart *chart = new QChart();
            chart->legend()->hide();
            chart->addSeries(series);

            QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);

                dialog->setExtension(chartView);

        dialog->show();
    }


	void create(std::vector<bool> data, bool whatToCount)
	{
		numberOfRepetitionsOfEachSize.clear();
		auto longestSerie{ 0 };
		int sizeOfSerie{};

		//find the longest
		for (auto bit : data)
		{
			if (bit == whatToCount)
			{
				sizeOfSerie++;
			}
			else
			{
				if (sizeOfSerie > longestSerie) longestSerie = sizeOfSerie;
				sizeOfSerie = 0;
			}
		}
		if (sizeOfSerie > longestSerie) longestSerie = sizeOfSerie;
		sizeOfSerie = 0;		

		for (int i = 1; i <= longestSerie; i++)
		{
			numberOfRepetitionsOfEachSize.push_back(0);
		}

		for (auto bit : data)
		{
			if (bit == whatToCount)
			{
				sizeOfSerie++;
			}
			else if (sizeOfSerie > 0)
			{
				numberOfRepetitionsOfEachSize[sizeOfSerie - 1] = numberOfRepetitionsOfEachSize[sizeOfSerie - 1] + 1;
				sizeOfSerie = 0;
			}
		}

		if (sizeOfSerie > 0) numberOfRepetitionsOfEachSize[sizeOfSerie - 1] = numberOfRepetitionsOfEachSize[sizeOfSerie - 1] + 1;

		std::cout << "\nSize of series | How many\n";
	}

	void show()
	{
		int iterator{1};
		for (auto series : numberOfRepetitionsOfEachSize)
		{
			if (series == 0) break;
			std::cout << iterator << " | ";
			for (int i = 0; i < series/25; i++)
			{
				std::cout << (char)219;

				if (i > 190) break;
			}
			iterator++;
			std::cout << " " << series << std::endl;
		}
	}
	~Histogram() {}
};

#endif
