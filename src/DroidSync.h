#ifndef _DROIDSYNC_H
#define _DROIDSYNC_H

#include <QDialog>
#include <memory>
class QDirModel;
class QModelIndex;
namespace Ui {class CDroidSync;};

class CDroidSync : public QDialog
{
    Q_OBJECT

public:
    CDroidSync(QWidget *parent = 0);
    ~CDroidSync();

public slots:
	void slotTargetSelected( const QModelIndex & idx );
	void slotSourceSelected( const QModelIndex & idx );
	void slotSync();

private:
	std::auto_ptr< Ui::CDroidSync > fImpl;
	QDirModel * fSourceDirModel;
	QDirModel * fTargetModel;
};

#endif // _DROIDSYNC_H
