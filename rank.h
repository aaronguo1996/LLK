#ifndef RANK_H
#define RANK_H

#include <QWIdget>
#include <QLabel>

class Rank : public QWidget
{
	Q_OBJECT;
public:
	Rank(QWidget *parent = 0);
	int getRanks(int i);
	void addScore(int i);

private:
	int highScores[4];
	void sort();
	void setLabels();
	QLabel *first;
	QLabel *second;
	QLabel *third;
};

#endif