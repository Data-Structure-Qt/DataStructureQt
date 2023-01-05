#include "SortCreator.h"

#include "QuickSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"


SortCreator::SortCreator(QObject *parent) : QObject(parent)
{

}

SortObejct *SortCreator::createSortObject(int row, QObject *parent)
{
	switch (row) {
	case 0: return new BubbleSort(parent);
	case 1: return new SelectionSort(parent);
	case 2: return new QuickSort(parent);
	default:
		break;
	}
	return nullptr;
}

QStringList SortCreator::getSortList()
{
	return { "√∞≈›≈≈–Ú","—°‘Ò≈≈–Ú","øÏÀŸ≈≈–Ú" };
}
