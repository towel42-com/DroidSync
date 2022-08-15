#include "DroidSync.h"
#include "ui_DroidSync.h"
#include <QDirModel>
#include <QPushButton>
#include "../modeltest/modeltest.h"

CDroidSync::CDroidSync(QWidget *parent)
    : QDialog(parent)
{
	fImpl = std::auto_ptr< Ui::CDroidSync >( new Ui::CDroidSync() );
	fImpl->setupUi(this);

	fSourceDirModel = new QDirModel( this );
	//ModelTest * mt = new ModelTest( fSourceDirModel, this );
	fImpl->sourceTree->setModel( fSourceDirModel );
	int ii = fSourceDirModel->rowCount();
	connect( fImpl->sourceTree->selectionModel(), SIGNAL( currentChanged( const QModelIndex & , const QModelIndex & ) ), this, SLOT( slotSourceSelected( const QModelIndex & ) ) );

	//fTargetModel = new QDirModel( this );
	//fImpl->destTree->setModel( fTargetModel );
	//connect( fImpl->destTree->selectionModel(), SIGNAL( currentChanged( const QModelIndex & , const QModelIndex & ) ), this, SLOT( slotTargetSelected( const QModelIndex & ) ) );

	QPushButton * pb = fImpl->buttonBox->addButton( tr( "Sync" ), QDialogButtonBox::ActionRole );
	connect( pb, SIGNAL( clicked() ), this, SLOT( slotSync() ) );

}

CDroidSync::~CDroidSync()
{
}

void CDroidSync::slotTargetSelected( const QModelIndex & idx )
{
	QFileInfo fi = fTargetModel->fileInfo( idx );
	fImpl->targetDir->setText( fi.absoluteFilePath() );
}

void CDroidSync::slotSourceSelected( const QModelIndex & idx )
{
	QFileInfo fi = fSourceDirModel->fileInfo( idx );
	fImpl->sourceDir->setText( fi.absoluteFilePath() );
}

void CDroidSync::slotSync()
{
}
